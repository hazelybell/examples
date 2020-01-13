#include "ewgraph_io.h"
#include "prim.h"
#include "debugging.h"

int main() {
    // read in edge weighted graph
    EWGraph g = read_ew_graph();
    
    // run prim's algorithm to get mst
    EWGraph mst = prim_mst(&g);
    
    // output graph in specific format
    print_edge_list(&mst);
    
    // free some datastructures
    free(&g);
    free(&mst);
    return 0;
}
