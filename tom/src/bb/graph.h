#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <vector>
//#include <cstdint>


typedef uint8_t path_t[6];
typedef uint8_t graph_t[142][6];

extern const graph_t ball;
//extern const int ball_size;

//class led_neigborhood {
//    const led_t* const begin;
//    const led_t* const end;
//    const led_t* current;
//
//public:
//
//    explicit led_neigborhood(path_t& path) : begin(path), current(begin), end(path + (path[5] == 0xff ? 5 : 6)) {}
//
//    led_neigborhood(const led_neigborhood &that) : begin(that.begin), current(that.current), end(that.end) {}
//
//    led_neigborhood &operator++() {
//        return *this;
//    }
//
//    led_neigborhood operator++(int) {
//        led_neigborhood old_value(*this);
//        ++(*this);
//        return old_value;
//    }
//
//    uint8_t &operator*() { return *current; }
//};



#endif //GRAPH_GRAPH_H
