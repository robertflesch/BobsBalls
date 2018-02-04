#ifndef bb_graph_h
#define bb_graph_h

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>

namespace bb {

  /** The LED identifier used to send instructions. */
  typedef uint16_t led_t;

  /** An ordered path of LEDs */
  typedef std::vector<led_t> path_t;

  /**
   * A graph of LEDs - the index of the vector is the LED, the path it's neighbors,
   * starting with the west neighbor and proceeding clockwise.
   */
  typedef std::vector<path_t> graph_t;

  /**
   * The graph of LEDs on a Bob ball.
   */
  extern const graph_t bob_ball;

  /**
   *
   * @param graph
   * @param neigbors - must be from the graph.
   * @return the LED (index) associated with the neighbors.
   */
  led_t led_of(const graph_t &graph, const path_t &neigbors) {
    return static_cast<led_t>(&neigbors - &graph[0]);
  }

  /** @return a string suitable for use as a path_t constructor argument. */
  std::string to_string(const path_t &path) {
    std::stringstream result;
    copy(path.begin(), path.end(), std::ostream_iterator<led_t>(result, ","));
    return '{' + result.str().substr(0, result.str().length() - 1) + '}';
  }

  /** @return a string suitable for use as a graph_t constructor argument. */
  std::string to_string(const graph_t &graph) {
    std::stringstream result;
    std::for_each(graph.begin(), graph.end(), [&](const path_t &p) { result << to_string(p) << ','; });
    return '{' + result.str().substr(0, result.str().length() - 1) + '}';
  }
}

std::ostream &operator<<(std::ostream &out, const bb::path_t &path) {
  return out << bb::to_string(path);
}

std::ostream &operator<<(std::ostream &out, const bb::graph_t &graph) {
  return out << bb::to_string(graph);
}

#endif