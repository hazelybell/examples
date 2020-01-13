#include "ewgraph.h"

EWGraph new_ew_graph() {
    EWGraph new = {
        0,
        NULL,
        0,
        NULL
    };
    return new;
}

void add_vertex(EWGraph *g) {
    g->n_vertices += 1;
    g->vertices = realloc(
        g->vertices,
        g->n_vertices 
            * sizeof(struct vertex)
    );
    // initialize the new vertex ds
    Vertex * new = &(g->vertices[g->n_vertices-1]);
    new->label = g->n_vertices-1;
    new->n_edges = 0;
    new->edges = NULL;
}

void add_edge(
    EWGraph *g,
    size_t from,
    size_t to,
    double weight
     ) {
    ASSERT(weight >= 0);
    ASSERT(from < g->n_vertices);
    ASSERT(to < g->n_vertices);
    ASSERT(!is_edge(g, from, to));
    
}
