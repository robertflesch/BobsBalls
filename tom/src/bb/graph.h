#ifndef BB_GRAPH_H
#define BB_GRAPH_H

#include <vector>
#include <cstdint>

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
   * @param graph
   * @param neigbors - must be from the graph.
   * @return the LED (index) associated with the neighbors.
   */
  led_t led_of(const graph_t &graph, const path_t &neigbors);


}

#endif
