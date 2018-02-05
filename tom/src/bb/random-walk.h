#ifndef BB_ITERATOR_H
#define BB_ITERATOR_H

#include <cstdlib>
#include "graph.h"

namespace bb {

  class random_walk : public std::iterator<std::input_iterator_tag, path_t> {

    const graph_t &graph;
    led_t current;

  public:
    random_walk(const graph_t &graph, led_t current) : graph(graph), current(current) {}

    random_walk(const random_walk &that) : graph(that.graph), current(that.current) {}

    random_walk &operator++() {
      current = graph[current][(rand() % graph[current].size())];
      return *this;
    }

    random_walk operator++(int) {
      random_walk old_value(*this);
      ++(*this);
      return old_value;
    }

    led_t &operator*() { return current; }

    bool operator==(const iterator &rhs) const { return true; }
    bool operator!=(const iterator &rhs) const { return false; }
  };
}

#endif //BB_ITERATOR_H
