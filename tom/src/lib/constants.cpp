#include "constants.h"

const color_t BLACK = Adafruit_NeoPixel::Color( 0  , 0  , 0   );
const color_t GREEN = Adafruit_NeoPixel::Color( 255, 0  , 0   );
const color_t RED   = Adafruit_NeoPixel::Color( 0  , 255, 0   );
const color_t BLUE  = Adafruit_NeoPixel::Color( 0  , 0  , 255 );

std::vector<path_t> lines{path_t({0, 6, 17, 33}),
                          path_t({1, 8, 20, 37}),
                          path_t({2, 10, 23, 41}),
                          path_t({3, 12, 26, 45}),
                          path_t({4, 14, 29, 49}),
                          path_t({99, 93, 82, 67}),
                          path_t({98, 91, 79, 63}),
                          path_t({97, 89, 76, 59}),
                          path_t({96, 87, 73, 55}),
                          path_t({95, 85, 70, 51})};
