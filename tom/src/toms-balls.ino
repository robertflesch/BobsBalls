#include <vector>
#include "lib/neopixel.h"

SYSTEM_MODE(AUTOMATIC);

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D2
#define PIXEL_COUNT 100
#define PIXEL_TYPE WS2812B

static Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

static const uint32_t BLACK =   Adafruit_NeoPixel::Color( 0  , 0  , 0   );
static const uint32_t GREEN =   Adafruit_NeoPixel::Color( 255, 0  , 0   );
static const uint32_t RED =     Adafruit_NeoPixel::Color( 0  , 255, 0   );
static const uint32_t BLUE =    Adafruit_NeoPixel::Color( 0  , 0  , 255 );

typedef uint32_t color_t;
typedef uint16_t offset_t;
typedef std::vector<offset_t> path_t;

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

void setup()
{
  Particle.publish( __FILE__ );
  strip.begin();
  strip.setBrightness( 64 );
  for (auto line : lines) {
    for (auto offset : line) {
      strip.setPixelColor(offset, GREEN);
    }
  }
  strip.show();
}

void loop() {
  //setColorGlobal( 0 );
  //strip.show();
  //pingPong();
  // strip.show();
  //circulatingTriangles();
  //rainbow( 25 );
}
