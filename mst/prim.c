#include "prim.h"
#include "debugging.h"
#include "spanning_tree.h"

#include <stddef.h>
#include <stdbool.h>

struct state {
    enum {
        FAR,
        NEAR,
        IN_TREE
    } state;
    Edge * minimum;
};

typedef struct state State;

static void update_states_edge(
    State *states,
    Edge *e,
    Vertex *v
) {
    double weight = e->weight;
    size_t v_idx = v->label;
    State *state = &(states[v_idx]);
    if (state->state == FAR) {
        debug("%zu is now reachable with (%zu,%zu,%g)\n",
              v_idx,
              e->v1,
              e->v2,
              e->weight
        );
        state->state = NEAR;
        state->minimum = e;
    } else if (state->state == NEAR) {
        if (weight < state->minimum->weight) {
            debug("%zu has a better option with (%zu,%zu,%g)\n",
                v_idx,
                e->v1,
                e->v2,
                e->weight
            );
            state->minimum = e;
        }
    } else if (state->state == IN_TREE) {
        // do nothing
    } else {
        UNREACHABLE;
    }
}

static void update_states(
    State *states,
    Vertex *last
) {
    for (
        size_t j = 0;
        j < last->n_edges;
        j++
    ) {
        Edge * e = get_vertex_edge(last, j);
        
        Vertex * other = get_other(last, e);
        
        debug("Can now reach %zu\n", other->label);
        update_states_edge(
            states,
            e,
            other
        );
    }
}

static void prim_init(
    size_t n_vertices,
    State * states,
    Graph * tree
) {
    for (
        size_t i = 0;
        i < n_vertices;
        i++
    ) {
        add_vertex(tree);
        states[i].state = FAR;
        states[i].minimum = NULL;
    }
}

static Edge * pick_next(
    size_t n_vertices,
    State *states
) {
#ifdef DEBUG
    debug("vertices: ");
    for (size_t i = 0;
        i < n_vertices;
        i++
    ) {
        if (states[i].state == IN_TREE) {
            debug("%zu ", i);
        }
    }
    debug("\b\n");
#endif
    Edge * minimum = NULL;
    debug("options: ");
    for (size_t i = 0;
        i < n_vertices;
        i++
    ) {
        State *s = &states[i];
        Edge *e = s->minimum;
        if (s->state != NEAR) {
            // if its already in the tree or we can't reach it at all (and don't have a minimum) skip it
            continue;
        }
        debug("(%zu,%zu,%g),",
                e->v1,
                e->v2,
                e->weight
        );
        if (
            minimum == NULL
            || e->weight < minimum->weight
        ) {
            minimum = e;
        }
    }
    debug("\b\n");
    ASSERT(minimum != NULL);
    return minimum;
}

static Vertex *copy_edge(
    State *state,
    Graph *tree,
    Edge *edge
) {
    /* copies an edge from whatever graph its in to tree tree and updates state */
    ASSERT(!(edge->graph == tree));
    
    size_t v1_idx = edge->v1;
    size_t v2_idx = edge->v2;
    
    Vertex *tree_v1 = get_vertex(tree, v1_idx);
    Vertex *tree_v2 = get_vertex(tree, v2_idx);
    double weight = edge->weight;
    
    add_edge(tree_v1, tree_v2, weight);
    
    Vertex *added = NULL;
    if (
        state[v1_idx].state == IN_TREE
        && state[v2_idx].state == NEAR
    ) {
        state[v2_idx].state = IN_TREE;
        state[v2_idx].minimum = NULL;
        added = get_v2(edge);
    } else if (
        state[v1_idx].state == NEAR
        && state[v2_idx].state == IN_TREE
    ) {
        state[v1_idx].state = IN_TREE;
        state[v1_idx].minimum = NULL;
        added = get_v1(edge);
    } else {
        UNREACHABLE;
    }
    return added;
}

Graph *prim_mst(Graph * graph)
{
    size_t n_vertices = graph->n_vertices;
    State *states = malloc(
        n_vertices 
            * sizeof(State)
    );
    Graph *tree = new_graph();
    
    prim_init(n_vertices, states, tree);
 
    debug("Iteration 0:\n");
    states[0].state = IN_TREE;
    Vertex *last 
        = get_vertex(graph, 0);
    ASSERT(last->graph == graph);
    for (
        size_t i = 1;
        i < n_vertices;
        i++
    ) {
        debug("\nIteration %zu:\n", i);
        update_states(states, last);
        Edge *next = pick_next(n_vertices, states);
        last = copy_edge(states, tree, next);
    }
    ASSERT(tree->n_edges == n_vertices - 1);
    ASSERT(is_spanning_tree(tree));
    free(states);
    return tree;
}
