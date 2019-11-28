#include <string.h>
#include <stdbool.h>

#include "weighted_graph.h"
#include "wgraph_io.h"
#include "prim.h"
#include "kruskal.h"
#include "debugging.h"
#include "checked_io.h"

static const char * argv0 = "mst";

static void print_usage() {
    fprintf(stderr, "\n");
    fprintf(stderr,
    "Usage: %s -i[b] inputfilename "
    "-o outputfilename\n",
    argv0);
    fprintf(stderr,
            "%20s   %s\n",
            "-i inputfilename",
            "Specify a file to read a graph from. Specify - for standard input.");
    fprintf(stderr,
            "%20s   %s\n",
            "-ib inputfilename",
            "Specify a binary file to read a graph from.");
    fprintf(stderr,
            "%20s   %s\n",
            "-o outputfilename",
            "Specify a file to write the minimum spanning tree to. Specify - for standard output.");
    fprintf(stderr,
            "%20s   %s\n",
            "-ob outputfilename",
            "Specify a binary file to write the minimum spanning tree to.");
    fprintf(stderr, "\n");
}

static void error_usage() {
    print_usage();
    abort();
}

struct graph_file {
    FILE * stream;
    bool binary;
};

typedef struct graph_file GraphFile;

static void select_input(
    GraphFile * input,
    char * path,
    bool binary
) {
    if (strcmp(path, "-") == 0) {
        input->stream = stdin;
    } else {
        input->stream
            = checked_fopen_read(path, binary);
    }
    input->binary = binary;
}

static void select_output(
    GraphFile * output,
    char * path,
    bool binary
            ) {
    if (strcmp(path, "-") == 0) {
        output->stream = stdout;
    } else {
        output->stream = checked_fopen_write(path, binary);
    }
    output->binary = binary;
}

int main(int argc, char **argv) {
    if (0 < argc) {
        argv0 = argv[0];
    }
    GraphFile input = {
        .stream = NULL,
        .binary = false
    };
    GraphFile output = {
        .stream = NULL,
        .binary = false
    };
    enum {
        NONE,
        PRIM,
        KRUSKAL
    } algo = NONE;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0) {
            i++;
            if (!(i < argc)) {
                fprintf(stderr, "-i requires an argument!\n");
                error_usage();
            }
            select_input(&input, argv[i], false);
        } else if (
            strcmp(argv[i], "-ib") == 0
        ) {
            i++;
            if (!(i < argc)) {
                fprintf(stderr, "-ib requires an argument!\n");
                error_usage();
            }
            select_input(&input, argv[i], true);
        } else if (
            strcmp(argv[i], "-o") == 0
        ) {
            i++;
            if (!(i < argc)) {
                fprintf(stderr, "-o requires an argument!\n");
                error_usage();
            }
            select_output(&output, argv[i], false);
        } else if (
            strcmp(argv[i], "-ob") == 0
        ) {
            i++;
            if (!(i < argc)) {
                fprintf(stderr, "-ob requires an argument!\n");
                error_usage();
            }
            select_output(&output, argv[i], true);
        } else if (
            strcmp(argv[i], "-p") == 0
        ) {
            algo = PRIM;
        } else if (
            strcmp(argv[i], "-k") == 0
        ) {
            algo = KRUSKAL;
        } else {
            fprintf(stderr, "Unrecognized argument: %s\n", argv[i]);
            error_usage();
        }
    }
    if (output.stream == NULL) {
        fprintf(stderr, "No output specified: printing result.\n");
        output.stream = stdout;
        output.binary = false;
    }
    if (input.stream == NULL) {
        fprintf(stderr, "No input specified: enter a list of edges along with their weights:\n");
        input.stream = stdin;
        input.binary = false;
    }
    Graph *in;
    if (input.binary) {
        debug("Reading binary weighted graph...\n");
        DIE("Binary I/O is unimplemented.");
    } else {
        debug("Reading weighted graph...\n");
        in = read_edge_list(input.stream);
    }
    debug("Input graph: %zu vertices, %zu edges, total weight: %g\n",
        in->n_vertices,
        in->n_edges,
        total_weight(in)
    );
    Graph *out;
    switch (algo) {
        case PRIM:
            out = prim_mst(in);
            free_graph(in);
            break;
        case KRUSKAL:
            out = kruskal_mst(in);
            free_graph(in);
            break;
        default:
            fprintf(stderr, "You didn't choose a MST algorithm. Copying the original graph.\n");
            out = in;
    }
    in = NULL;
    debug("Output graph: %zu vertices, %zu edges, total weight: %g\n",
        out->n_vertices,
        out->n_edges,
        total_weight(out)
    );
    if (output.binary) {
        DIE("Binary I/O is unimplemented.");
    } else {
        print_edge_list(output.stream, out);
    }
    free_graph(out);
    if (input.stream != stdin) {
        checked_fclose(input.stream);
    }
    if (output.stream != stdout) {
        checked_fclose(output.stream);
    }
}
