#ifndef BB_SIMPLE_GRAPH_H
#define BB_SIMPLE_GRAPH_H

#include "bb/graph.h"

//
//         1 - 2 - 3
//        / \ / \  /\
//       4 - 5 - 6 - 7
//        \ / \ / \ /
//         8 - 9 - 0
//

const bb::graph_t graph({{9, 6, 7},          // 0 // NOLINT
                         {2, 5, 4},          // 1
                         {1, 3, 6, 5},       // 2
                         {2, 7, 6},          // 3
                         {1, 5, 8},          // 4
                         {4, 1, 2, 6, 9, 8}, // 5
                         {5, 2, 3, 7, 0, 9}, // 6
                         {6, 3, 0},          // 7
                         {4, 5, 9},          // 8
                         {8, 5, 6, 0}});     // 9
#endif //BB_SIMPLE_GRAPH_H
