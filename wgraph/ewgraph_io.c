#include "ewgraph_io.h"
#include "debugging.h"


static EWGraph read_graph_size() {
    // read the size from the input
    size_t n_vertices = 0;
    scanf("%zu", &n_vertices);
    ASSERT(n_vertices != 0);
    
    // construct an EWGraph of that size
    // construct a new EWGraph
    EWGraph g = new_ew_graph();
    for (size_t i = 0; i < n_vertices; i++) {
        add_vertex(&g);
    }
}

static void read_edge_weight(
    Graph *g,
    size_t row,
    size_t col
            ) {
    // read from stdin
    double weight = 0;
    int r = scanf("%lf", &weight);
    ASSERT(r == 1);
    
    // if its not negative
    if (weight >= 0) {
        // store it
        add_edge(g, row, col, weight);
    }
}

static void read_matrix_row(Graph *g, size_t row) {
    for (size_t j = 0; j < g->n_vertices; j++) {
        read_edge_weight(g, row, j);
    }
}

static void read_matrix_entries(Graph *g) {
    for (size_t i = 0; i < g->n_vertices; i++) {
        read_matrix_row(g, i);
    }
}

EWGraph read_ew_graph() {
    // read the size of the matrix
    EWGraph g = read_graph_size();
    
    // read the entries of the matrix
    read_matrix_entries(&g);
    
    return g;
}
