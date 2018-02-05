#include "lib/neopixel.h"
#include "bb/graph.h"

SYSTEM_MODE(AUTOMATIC);

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D2
#define PIXEL_COUNT 100
#define PIXEL_TYPE WS2812B

static Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

void setup() {
  Particle.publish(__FILE__);
  strip.begin();
  strip.setBrightness(64);


  strip.show();
}

void loop() {

}
