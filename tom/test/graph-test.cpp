#include "catch/catch.hpp"
#include "simple-graph.h"

TEST_CASE("led of") {
  REQUIRE(bb::led_of(simple_graph, simple_graph[0]) == 0);
  REQUIRE(bb::led_of(simple_graph, simple_graph[2]) == 2);
  REQUIRE(bb::led_of(simple_graph, simple_graph[6]) == 6);
  REQUIRE(bb::led_of(simple_graph, simple_graph[9]) == 9);
}
