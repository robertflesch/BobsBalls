#ifndef lib_node_h
#define lib_node_h

#include <vector>

namespace bb {

  class Node {
    id_t id;
    std::vector<Node> neighbors;
  };

}

#endif
