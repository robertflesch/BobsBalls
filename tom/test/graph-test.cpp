#include "catch/catch.hpp"
#include "simple-graph.h"

TEST_CASE("led of") {
  REQUIRE(bb::led_of(graph, graph[0]) == 0);
  REQUIRE(bb::led_of(graph, graph[2]) == 2);
  REQUIRE(bb::led_of(graph, graph[6]) == 6);
  REQUIRE(bb::led_of(graph, graph[9]) == 9);
}
