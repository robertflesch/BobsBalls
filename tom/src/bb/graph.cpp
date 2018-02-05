#include "graph.h"

const bb::graph_t bb::bob_ball(
    {{1,  4,  5,  6,  7},       //  0
     {0,  7,  8,  9,  2},       //  1
     {1,  9,  10, 11, 3},       //  2
     {2,  11, 12, 13, 4},       //  3
     {0,  3,  13, 14, 5},       //  4
     {0,  4,  14, 15, 16, 6},   //  5
     {0,  5,  16, 17, 14, 7},   //  6
     {0,  6,  18, 19, 8,  1},   //  7
     {1,  7,  19, 20, 21, 9},   //  8
     {1,  8,  21, 22, 10, 2},   //  9
     {2,  9,  22, 23, 24, 11},  // 10
     {2,  10, 24, 25, 12, 3},   // 11
     {3,  11, 25, 26, 27, 13},  // 12
     {3,  12, 27, 28, 14, 4},   // 13
     {4,  13, 28, 29, 15, 5},   // 14
     {5,  14, 29, 31, 32, 16},  // 15
     {5,  15, 32, 33, 17, 6},   // 16
     {6,  16, 33, 34, 35, 14},  // 17
     {3,  6,  17, 35, 36, 19},  // 18
     {7,  18, 36, 37, 20, 8},   // 19
     {8,  19, 37, 38, 39, 21},  // 20
     {9,  8,  20, 39, 40, 22},  // 21
     {9,  21, 40, 41, 23, 10},  // 22
     {10, 22, 41, 42, 43, 24},  // 23
     {10, 23, 43, 44, 25, 11},  // 24
     {11, 24, 44, 45, 26, 12},  // 25
     {12, 25, 45, 46, 47, 27},  // 26
     {12, 26, 47, 48, 28, 13},  // 27
     {13, 27, 48, 49, 29, 14},  // 28
     {14, 28, 49, 30, 31, 15},  // 29
     {29, 49, 31},              // 30
     {15, 29, 30, 32},          // 31
     {15, 31, 33, 15},          // 32
     {16, 33, 34, 17},          // 33
     {17, 33, 35},              // 34
     {17, 34, 36, 18},          // 35
     {18, 35, 37, 19},          // 36
     {19, 36, 38, 20},          // 37
     {20, 37, 39},              // 38
     {20, 38, 40, 21},          // 39
     {21, 39, 41, 22},          // 40
     {22, 40, 42, 23},          // 41
     {23, 41, 43},              // 42
     {23, 42, 44, 24},          // 43
     {24, 43, 45, 25},          // 44
     {25, 44, 46, 26},          // 45
     {26, 45, 47},              // 46
     {26, 46, 48, 27},          // 47
     {27, 47, 49, 28},          // 48
     {28, 48, 30, 29},          // 49
    });

bb::led_t bb::led_of(const bb::graph_t &graph, const bb::path_t &neigbors) {
  return static_cast<led_t>(&neigbors - &graph[0]);
}
