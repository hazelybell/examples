#include "kruskal.h"
#include "debugging.h"
#include "spanning_tree.h"

#include <stdlib.h>
#include <stdbool.h>

static int compare_edges(
    const void *p1,
    const void *p2
) {
    Edge * e1 = *((Edge **) p1);
    Edge * e2 = *((Edge **) p2);
    if (e1->weight < e2->weight) {
        return -1;
    } else if (e1->weight == e2->weight) {
        return 0;
    } else if (e1->weight > e2->weight) {
        return 1;
    }
    UNREACHABLE;
}

static Edge **sort_edges_by_weight(Graph * graph) {
    size_t n_edges = graph->n_edges;
    Edge **list  = malloc(
        sizeof(Edge *)
        * graph->n_edges);
    
    // initialize
    for (size_t i = 0; i < n_edges; i++) {
        list[i] = &(graph->edges[i]);
    }
    
    // sort
    qsort(
        list,
        n_edges,
        sizeof(Edge *),
        &compare_edges
    );
    return list;
}

static bool is_path_rec(
    bool *visited,
    Vertex * cur,
    Vertex * end
) {
    // base case #1: we've already been here
    if (visited[cur->label]) return false;
    
    // base case #2: we found a path
    if (cur == end) return true;

    // mark vertex as visited
    visited[cur->label] = true;
    
    Graph *g = cur->graph;
    
    for (
        size_t i = 0;
        i < cur->n_edges;
        i++
    ) {
        Edge *e = get_vertex_edge(cur, i);
        Vertex * next;
        if (e->v1 == cur->label) {
            next = get_vertex(g, e->v2);
        } else if (e->v2 == cur->label) {
            next = get_vertex(g, e->v1);
        }
        if (is_path_rec(visited, next, end)) {
            debug("%zu ", next->label);
            return true;
        }
        // otherwise keep looking
    }
    return false;
}

static bool is_path(
    Vertex * start,
    Vertex * end
) {
    ASSERT(start->graph == end->graph);
    size_t n_vertices = start->graph->n_vertices;
    bool *visited = malloc(
        sizeof(bool) 
        * n_vertices
    );
    for (size_t i = 0; i < n_vertices; i++) {
        visited[i] = false;
    }
    
    debug("looking for a path... ");

    // do depth-first search
    bool found = is_path_rec(visited, start, end);
    
    if (found) {
        debug("%zu found!\n", start->label);
    } else {
        debug("no path.\n");
    }
        
    free(visited);
    return found;
}

Graph *kruskal_mst(Graph * graph) {
    size_t n_vertices = graph->n_vertices;
    
    Graph *tree = new_graph();
    for (size_t i = 0; i < n_vertices; i++) {
        add_vertex(tree);
    }
    
    Edge **sorted
        = sort_edges_by_weight(graph);
    
    size_t n_edges = graph->n_edges;
    for (size_t i = 0; i < n_edges; i++) {
        Edge *e = sorted[i];
        debug("Considering: (%zu,%zu,%g)\n",
              e->v1,
              e->v2,
              e->weight
        );
        size_t v1_idx = e->v1;
        size_t v2_idx = e->v2;
        Vertex *v1_tree = get_vertex(tree, v1_idx);
        Vertex *v2_tree = get_vertex(tree, v2_idx);
        
        bool already_connected = is_path(v1_tree, v2_tree);
        
        // these two vertices are already connected, so skip this edge
        if (already_connected) {
            debug("skipping: %zu and %zu are already connected!\n", v1_idx, v2_idx);
            continue;
        }
        debug("adding!\n");
        
        // copy edge from graph to tree
        add_edge(v1_tree, v2_tree, e->weight);
        
        if (tree->n_edges == n_vertices - 1) {
            debug("We have one fewer edge than vertex in our tree. We 'ᴙ' done!\n");
            // we've made a tree!
            break;
        }
    }
    
    ASSERT(tree->n_edges == n_vertices - 1);
    ASSERT(is_spanning_tree(tree));
    
    free(sorted);
    return tree;
}
