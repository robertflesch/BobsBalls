#include "catch/catch.hpp"

#include "bb/functions.h"
#include "simple-graph.h"

using namespace std;

TEST_CASE("path to string") {
  REQUIRE(bb::to_string(simple_graph[0]) == "{9,6,7}");
  REQUIRE(bb::to_string(simple_graph[5]) == "{4,1,2,6,9,8}");
}

TEST_CASE("graph to string") {
  REQUIRE(bb::to_string(simple_graph) == "{"
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
