#include "functions.h"

#include <sstream>

std::string bb::to_string(const bb::path_t &path) {
  std::stringstream result;
  copy(path.begin(), path.end(), std::ostream_iterator<led_t>(result, ","));
  return '{' + result.str().substr(0, result.str().length() - 1) + '}';
}

std::string bb::to_string(const bb::graph_t &graph) {
  std::stringstream result;
  std::for_each(graph.begin(), graph.end(), [&](const path_t &p) { result << to_string(p) << ','; });
  return '{' + result.str().substr(0, result.str().length() - 1) + '}';
}

std::ostream &operator<<(std::ostream &out, const bb::path_t &path) {
  return out << bb::to_string(path);
}

std::ostream &operator<<(std::ostream &out, const bb::graph_t &graph) {
  return out << bb::to_string(graph);
}


