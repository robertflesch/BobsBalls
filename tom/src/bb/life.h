#ifndef BB_LIFE_H
#define BB_LIFE_H

#include <random>
#include "graph.h"

namespace bb {

  typedef std::vector<color_t> colony_t;

  colony_t new_colony(size_t size) {
    std::default_random_engine generator;

    std::uniform_int_distribution<unsigned> ip_distribution(0, 99);
    auto random_percentage = std::bind(ip_distribution, generator);

    colony_t colony(size);
    while (size--) {
      colony[size] = random_percentage() > 75 ? RED : BLACK;
    }
    return colony;
  }

  colony_t &next_generator(const graph_t &graph, colony_t &colony) {
    for (size_t i = 0; i < colony.size(); ++i) {
      long count = std::count_if(graph[i].begin(), graph[i].end(), [&](const led_t &i) { colony[i]; });
      if (colony[i]) {
        if (count == 1 || count > 4) { colony[i] = BLACK; }
      }
      else if (count == 3 || count == 4) { colony[i] = RED; }
    }
    return colony;
  }
}

#endif //BB_LIFE_H
