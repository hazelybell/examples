#ifndef _WGRAPH_IO_H_
#define _WGRAPH_IO_H_

#include "weighted_graph.h"

#include <stdio.h>

void print_edge_list(
    FILE * stream,
    Graph *g
);

Graph *read_edge_list(FILE * stream);

#endif /* _WGRAPH_IO_H_ */
