#include "catch.hpp"

#include "bb/graph.h"
#include <iostream>
#include <algorithm>

using namespace std;

//
//         1 - 2 - 3
//        / \ / \  /\
//       4 - 5 - 6 - 7
//        \ / \ / \ /
//         8 - 9 - 0
//

static const bb::graph_t graph({{9, 6, 7},          // 0 // NOLINT
                                {2, 5, 4},          // 1
                                {1, 3, 6, 5},       // 2
                                {2, 7, 6},          // 3
                                {1, 5, 8},          // 4
                                {4, 1, 2, 6, 9, 8}, // 5
                                {5, 2, 3, 7, 0, 9}, // 6
                                {6, 3, 0},          // 7
                                {4, 5, 9},          // 8
                                {8, 5, 6, 0}});     // 9

TEST_CASE("led of") {
  REQUIRE(bb::led_of(graph, graph[0]) == 0);
  REQUIRE(bb::led_of(graph, graph[2]) == 2);
  REQUIRE(bb::led_of(graph, graph[6]) == 6);
  REQUIRE(bb::led_of(graph, graph[9]) == 9);
}

TEST_CASE("path to string") {
  REQUIRE(bb::to_string(graph[0]) == "{9,6,7}");
  REQUIRE(bb::to_string(graph[5]) == "{4,1,2,6,9,8}");
}

TEST_CASE("graph to string") {
  REQUIRE(bb::to_string(graph) == "{"
      "{9,6,7},"
      "{2,5,4},"
      "{1,3,6,5},"
      "{2,7,6},"
      "{1,5,8},"
      "{4,1,2,6,9,8},"
      "{5,2,3,7,0,9},"
      "{6,3,0},"
      "{4,5,9},"
      "{8,5,6,0}}");
}
