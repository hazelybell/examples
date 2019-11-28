#include "weighted_graph.h"
#include "debugging.h"

#include <stdlib.h>

Graph *new_graph() {
    Graph *new = malloc(1 * sizeof(Graph));
    new->n_vertices = 0;
    new->vertices = NULL;
    new->n_edges = 0;
    new->edges = NULL;
    return new;
}

Vertex *get_vertex(
    Graph *g,
    size_t n
) {
    ASSERT(n < g->n_vertices);
    Vertex *v;
    v = &g->vertices[n];
    ASSERT(n == v->label);
    return v;
}

Edge *get_edge(Graph *g, size_t idx) {
    ASSERT(idx < g->n_edges);
    return &(g->edges[idx]);
}

Edge *get_vertex_edge(Vertex *v, size_t idx) {
    ASSERT(idx < v->n_edges);
    ASSERT(v->graph != NULL);
    ASSERT(v->label < v->graph->n_vertices);
    ASSERT(v == &(v->graph->vertices[v->label]));
    return get_edge(v->graph, v->edges[idx]);
}

Vertex *get_v1(Edge *e) {
    return get_vertex(e->graph, e->v1);
}

Vertex *get_v2(Edge *e) {
    return get_vertex(e->graph, e->v2);
}

Vertex *get_other(Vertex *v, Edge *e) {
    ASSERT(v->graph == e->graph);
    Vertex * other;
    if (e->v1 == v->label) {
        other = get_v2(e);
    } else if (e->v2 == v->label) {
        other = get_v1(e);
    } else {
        UNREACHABLE;
    }
    return other;
}

Vertex *add_vertex(Graph *g) {
    size_t new_idx = g->n_vertices;
    g->n_vertices += 1;
    g->vertices = realloc(g->vertices,
        g->n_vertices * sizeof(Vertex)
    );
    Vertex *v
        = &g->vertices[new_idx];
    v->label = new_idx;
    v->n_edges = 0;
    v->edges = NULL;
    v->graph = g;
    return v;
}

static void add_edge_to_vertex(
    size_t edge_idx,
    Vertex *v
) {
    Graph *graph = v->graph;
    Edge *e = get_edge(graph, edge_idx);
    ASSERT(e->graph == v->graph);
    ASSERT(
        (e->v1 == v->label) || (e->v2 == v->label)
    );
    size_t new_idx = v->n_edges;
    v->n_edges += 1;
    v->edges = realloc(v->edges,
        v->n_edges * sizeof(size_t)
    );
    v->edges[new_idx] = edge_idx;
//     debug("vertex %zu degree %zu\n", v->label, v->n_edges);
}

Edge *add_edge(
    Vertex *v1,
    Vertex *v2,
    double weight
) {
    ASSERT(v1 != NULL);
    ASSERT(v2 != NULL);
    ASSERT(v1->graph == v2->graph);
    Graph * g = v1->graph;
    size_t new_idx = g->n_edges;
    g->n_edges += 1;
    g->edges = realloc(
        g->edges,
        g->n_edges * sizeof(Edge)
    );
    Edge *e
        = &(g->edges[new_idx]);
    e->v1 = v1->label;
    e->v2 = v2->label;
    e->weight = weight;
    e->graph = g;
    add_edge_to_vertex(new_idx, v1);
    add_edge_to_vertex(new_idx, v2);
    ASSERT(v1->edges[v1->n_edges - 1] == new_idx);
    ASSERT(v2->edges[v2->n_edges - 1] == new_idx);
    return e;
}

static void free_vertex(Vertex *v) {
    free(v->edges);
    v->edges = NULL;
    v->n_edges = 0;
}

void free_graph(Graph *g) {
    for (size_t i = 0; i < g->n_vertices; i++) {
        free_vertex(get_vertex(g, i));
    }
    free(g->vertices);
    g->vertices = NULL;
    g->n_vertices = 0;
    free(g->edges);
    g->edges = NULL;
    g->n_vertices = 0;
    free(g);
}

Edge *find_edge(
    Vertex *v1,
    Vertex *v2
) {
    for (
        size_t i = 0; 
        i < v1->n_edges;
        i++
    ) {
        Edge *e = get_vertex_edge(v1, i);
        if (
            (v1->label == e->v1 
                && v2->label == e->v2)
            || (v2->label == e->v1 
                && v1->label == e->v2)
        ) {
            return e;
        }
    }
    return NULL;
}

double total_weight(Graph *graph) {
    size_t n_edges = graph->n_edges;
    double total = 0.0;
    for (size_t i = 0; i < n_edges; i++) {
        total += graph->edges[i].weight;
    }
    return total;
}
