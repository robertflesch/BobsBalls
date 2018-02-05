#include "lib/neopixel.h"
#include "bb/graph.h"
#include "bb/random-walk.h"

SYSTEM_MODE(AUTOMATIC);

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D2
#define PIXEL_COUNT 100
#define PIXEL_TYPE WS2812B

static Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);
static bb::random_walk iterator(bb::bob_ball, 0);

const uint32_t GREEN  = 0xff0000;
const uint32_t RED    = 0x00ff00;
const uint32_t BLUE   = 0x0000ff;
const uint32_t YELLOW = 0x808000;
const uint32_t CYAN   = 0x800080;
const uint32_t PURPLE = 0x008080;

void loop() {
  strip.show();
  strip.setPixelColor(*iterator, YELLOW);
  ++iterator;
  delay(100);
}

void setup() {
  Particle.publish(__FILE__);
  strip.begin();
  strip.setBrightness(64);
  for (bb::led_t led = 0; led < PIXEL_COUNT + 1; ++led) {
    strip.setPixelColor(led, PURPLE);
  }
  loop();
}
