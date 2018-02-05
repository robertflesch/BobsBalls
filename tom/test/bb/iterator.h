#ifndef BB_ITERATOR_H
#define BB_ITERATOR_H

#include "graph.h"

namespace bb {

  class path_iterator : public std::iterator<std::forward_iterator_tag, path_t> {
    const graph_t &graph;
    const led_t first;
    const led_t last;
    std::set<led_t> visited;
    graph_t candidates;


  public:
    path_iterator(const graph_t &graph, led_t first, led_t last) : graph(graph), first(first), last(last) {
      std::for_each(graph[first].begin(), graph[first].end(), [&](led_t *i) { candidates.emplace_back(*i); });

      candidates.push_back(graph[first]);
    }
    path_iterator(const path_iterator &that) : graph(that.graph), first(that.first), last(that.last) {}

    path_iterator &operator++() {

      return *this;
    }

    path_iterator operator++(int) {
      return *this;
    }

    bool operator==(const iterator &rhs) const { return true; }
    bool operator!=(const iterator &rhs) const { return false; }
  };
}


#endif //BB_ITERATOR_H
