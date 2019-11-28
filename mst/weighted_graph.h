#ifndef _WEIGHTED_GRAPH_H_
#define _WEIGHTED_GRAPH_H_

#include <stddef.h>
#include <stdbool.h>

struct graph;

struct vertex {
    // struct representing a vertex of a graph
    size_t label; // which vertex is this
    size_t n_edges; // how many edges this vertex has
    size_t *edges; // a list of edges
    struct graph *graph; // pointer to the graph this vertex belongs to
};

typedef struct vertex Vertex;

struct edge {
    size_t v1;
    size_t v2;
    double weight;
    struct graph *graph; // pointer to the graph this edge belongs to
};

typedef struct edge Edge;

struct graph {
    size_t n_vertices;
    // an array of vertices
    struct vertex *vertices;
    size_t n_edges;
    // an array of edges: edges are stored here!
    struct edge *edges; 
};

typedef struct graph Graph;

Graph *new_graph();

Vertex *add_vertex(struct graph *g);

Edge *add_edge(
    struct vertex *v1,
    struct vertex *v2,
    double weight
);

Vertex *get_vertex(
    struct graph *g,
    size_t n
);

void free_graph(Graph *g);

Edge *find_edge(
    struct vertex *v1,
    struct vertex *v2
);

Edge *get_vertex_edge(Vertex *v, size_t idx);

double total_weight(Graph * graph);

Vertex *get_v1(Edge *e);

Vertex *get_v2(Edge *e);

Vertex *get_other(Vertex *, Edge *);

#endif /* _WEIGHTED_GRAPH_H_ */
