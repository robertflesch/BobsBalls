#include "catch/catch.hpp"
#include "bb/random-walk.h"
#include "simple-graph.h"
#include <set>
#include <iostream>

TEST_CASE("1000 random trials") {
  bb::random_walk iterator(simple_graph, 0);
  std::set<bb::led_t> results;

  for (int i = 0; i < 1000; ++i) {
    results.emplace(*iterator++);
  }

  REQUIRE(results.size() > 9);
}