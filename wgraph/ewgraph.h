#ifndef _EWGRAPH_H_
#define _EWGRAPH_H_

struct vertex {
    size_t label;
    size_t n_edges;
    size_t * edges; // example: 1, 7, 5
    // g->edge[1], g->edge[7], g->edge[5]
}

typedef struct vertex Vertex;

struct ew_graph {
    size_t n_edges;
    struct edge * edges;
    size_t n_vertices;
    struct vertex * vertices;
}

typedef struct ew_graph EWGraph;

#endif /* _EWGRAPH_H_ */
