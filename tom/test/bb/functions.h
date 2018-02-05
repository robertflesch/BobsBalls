#ifndef BB_FUNCTIONS_H
#define BB_FUNCTIONS_H

#include "bb/graph.h"
#include <string>

namespace bb {
  /** @return a string suitable for use as a path_t constructor argument. */
  std::string to_string(const path_t &path);

  /** @return a string suitable for use as a graph_t constructor argument. */
  std::string to_string(const graph_t &graph);
}

std::ostream &operator<<(std::ostream &out, const bb::path_t &path);

std::ostream &operator<<(std::ostream &out, const bb::graph_t &graph);

#endif //BB_FUNCTIONS_H
