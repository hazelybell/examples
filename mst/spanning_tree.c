#include "spanning_tree.h"

#include <stdlib.h>

static void visit(
    bool * visited,
    Vertex * v
) {
    if (visited[v->label]) return;
    visited[v->label] = true;
    Graph *g = v->graph;
    for (
        size_t i = 0;
        i < v->n_edges;
        i++
    ) {
        Edge *e = get_vertex_edge(v, i);
        Vertex * next;
        if (e->v1 == v->label) {
            next = get_vertex(g, e->v2);
        } else if (e->v2 == v->label) {
            next = get_vertex(g, e->v1);
        }
        visit(visited, next);
    }
}

bool is_spanning_tree(Graph * graph) {
    size_t n_vertices = graph->n_vertices;
    
    if (graph->n_edges != n_vertices - 1)
        return false;
    
    bool *visited = malloc(
        sizeof(bool) 
        * n_vertices
    );
    for (size_t i = 0; i < n_vertices; i++) {
        visited[i] = false;
    }

    // do depth-first search
    visit(visited, get_vertex(graph, 0));
    
    bool spanning = true;
    
    for (size_t i = 0; i < n_vertices; i++) {
        spanning = (spanning && visited[i]);
    }
    
    free(visited);
    return spanning;
}

