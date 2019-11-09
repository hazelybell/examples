#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct graph;

struct vertex {
    // struct representing a vertex of a graph
    size_t label; // which vertex is this
    size_t n_edges; // how many edges this vertex has
    struct vertex **edges; // a list of vertices that this vertex is connected to by edges
    struct graph *g; // pointer to the graph this vertex belongs to
};

struct graph {
    size_t n_vertices;
    // an array of vertices
    struct vertex *vertices;
};

struct graph new_graph() {
    struct graph new = {
        0,
        NULL
    };
    return new;
}

struct vertex *add_vertex(struct graph *g) {
    g->n_vertices += 1;
    g->vertices = realloc(
        g->vertices,
        g->n_vertices
            * sizeof(struct vertex)
    );
    struct vertex *v
        = &g->vertices[g->n_vertices-1];
    v->label = g->n_vertices-1;
    v->n_edges = 0;
    v->edges = NULL;
    v->g = g;
    return v;
}

void free_vertex(struct vertex *v) {
    free(v->edges);
    v->n_edges = 0;
}

struct vertex *get_vertex(
    struct graph *g,
    size_t n
               ) {
    if (n >= g->n_vertices) abort();
    struct vertex *v;
    v = &g->vertices[n];
    if (n != v->label) abort();
    return v;
}

void free_graph(struct graph *g) {
    for (size_t i = 0; i < g->n_vertices; i++) {
        free_vertex(get_vertex(g, i));
    }
    free(g->vertices);
    g->vertices = NULL;
    g->n_vertices = 0;
}

int is_edge(
    struct vertex *from,
    struct vertex *to
) {
    for (size_t i; i < from->n_edges; i++) {
        if (from->edges[i] == to) {
            return 1;
        }
    }
    return 0;
}

void add_edge(
    struct vertex *from,
    struct vertex *to
     ) {
    if (is_edge(from, to)) abort();
    from->n_edges += 1;
    from->edges = realloc(
        from->edges,
        from->n_edges * sizeof(struct vertex *)
    );
    from->edges[from->n_edges - 1] =
        to;
}

void new_edge(
    struct vertex *v,
    struct vertex *w
     ) {
    add_edge(v, w);
    add_edge(w, v);
}

void print_vertex_al(struct vertex *v) {
    // prints an adjacency LIST for a vertex
    printf("Vertex %zu is connected to: ",
           v->label);
    for (size_t i = 0; i < v->n_edges; i++) {
        printf("%zu ", v->edges[i]->label);
    }
    printf("\b\n");
}

void print_graph_al(struct graph *g) {
    for (size_t i = 0; i < g->n_vertices; i++) {
        print_vertex_al(
            get_vertex(g, i)
        );
    }
}

void print_vertex_am(struct vertex *v) {
    // prints a ROW of the adjacency MATRIX for a vertex
    size_t cols = v->g->n_vertices;
    size_t *row = malloc(
        cols * sizeof(size_t)
                  );
    for (size_t i = 0; i < cols; i++) {
        row[i] = 0;
    }
    for (size_t i = 0; i < v->n_edges; i++) {
        row[v->edges[i]->label] = 1;
    }
}

char *new_empty_string() {
        char *line = (char *) malloc(1 * sizeof(char));
        line[0] = '\0';
        return line;
}

char *read_line() {
    char * line = NULL;
    int r = scanf("%m[^\n]", &line);
    if (r == EOF) {
        return new_empty_string();
    }
    char c = 0;
    int nl = scanf("%c", &c);
    if (r == 1 && nl == 1 && c == '\n') {
        return line;
    }
    if (r == 0 && nl == 1 && c == '\n') {
        // this must be an empty line
        return new_empty_string();
    }
    printf("%d %d %d\n", r, nl, c);
    abort();
    return NULL;
}

size_t count_line(char * line) {
    double value;
    size_t count = 0;
    int chars_consumed = 0;
    if (line == NULL) abort();
    while (sscanf(line, "%lf%n", &value, &chars_consumed) == 1) {
        line += chars_consumed;
        count += 1;
    }
    return count;
}

size_t read_row(char * line,
              struct vertex *v
             ) {
    int adjacent;
    size_t col = 0;
    int chars_consumed = 0;
    while (sscanf(
        line, 
        "%d%n", 
        &adjacent, 
        &chars_consumed
    ) == 1) {
        if (adjacent > 1 || adjacent < 0) {
            printf("element in adjacency matrix is not 0 or 1!\n");
            abort();
        }
        if (adjacent) {
            add_edge(
                v, 
                get_vertex(v->g, col)
            );
        }
        line += chars_consumed;
        col += 1;
    }
    return col;
}

void add_vertices(
    struct graph *g,
    size_t cols
) {
    if (g->n_vertices > 0) abort();
    for (size_t i = 0; i < cols; i++) {
        add_vertex(g);
    }
}

struct graph read_matrix() {
    size_t rows = 0;
    size_t cols = 0;
    struct graph g = new_graph();
    while (1) {
        char *line = read_line();
        if (line == NULL) abort();
        size_t line_cols = count_line(line);
        if (line_cols == 0) {
            free(line);
            break;
        }
        if (line_cols == 1) {
            // this must be the line that indicates the number of vertices
            free(line);
            continue;
        }
        if (cols == 0) {
            cols = line_cols;
            add_vertices(&g, cols);
        }
        if (cols != line_cols) {
            printf("Inconsistent number of columns on row %zu\n", rows);
            abort();
        }
        struct vertex *v
            = get_vertex(&g, rows);
        size_t cols_read 
            = read_row(line, v);
        if (cols != cols_read) abort();
        free(line);
        rows++;
    }
    if (rows == 0 || cols == 0) {
        printf("Rows or cols was 0?\n");
        abort();
    }
    if (rows != cols) {
        printf("Adjacency matrix must have same number of rows and columns.\n");
        abort();
    }
    return g;
}

int main(int argc, char **argv) {
    struct graph g;
    g = read_matrix();
    print_graph_al(&g);
}

