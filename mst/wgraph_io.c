#include "wgraph_io.h"
#include "weighted_graph.h"
#include "debugging.h"
#include "checked_io.h"

void print_edge_list(
    FILE * stream,
    Graph *g
) {
    for (size_t i = 0; i < g->n_edges; i++) {
        Edge e = g->edges[i];
        fprintf(stream, "(%zu,%zu,%g)\n",
            e.v1,
            e.v2,
            e.weight
        );
    }
}

Graph *read_edge_list(FILE * stream) {
    Graph *graph = new_graph();
    char * line;
    while (
        (line = checked_getline(stream))
        != NULL
    ) {
        size_t v1_label;
        size_t v2_label;
        double weight;
        int r = sscanf(line,
            "(%zu,%zu,%lf)",
            &v1_label,
            &v2_label,
            &weight
        );
        DASSERT(r == 3,
                "Couldn't read edge triplet: %s", line);
        while (
            v1_label >= graph->n_vertices
        ) {
            add_vertex(graph);
        }
        while (
            v2_label >= graph->n_vertices
        ) {
            add_vertex(graph);
        }
        Vertex * v1 = get_vertex(graph, v1_label);
        Vertex * v2 =
        get_vertex(graph, v2_label);
        add_edge(v1, v2, weight);
        free(line);
    }
    return graph;
}

