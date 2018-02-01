
#ifndef BB_RAINBOW_CYCLE_PATTERN
#define BB_RAINBOW_CYCLE_PATTERN

// Slightly different, this makes the rainbow equally distributed throughout
class RainbowCycle: public Pattern {
private:
  uint32_t m_waitInMs;

 public:
  // Constructor: number of LEDs, pin number, LED type
  RainbowCycle( Adafruit_NeoPixel &strip, uint32_t waitInMs = 500 ):
    Pattern( strip ),
    m_waitInMs( waitInMs )
    {};

  ~RainbowCycle() {};

  void update() {
    uint16_t i, j;

    for(j=0; j<256 * 5; j++) { // 5 cycles of all colors on wheel
      for(i=0; i< m_strip.numPixels(); i++) {
        m_strip.setPixelColor(i, wheel(((i * 256 / m_strip.numPixels()) + j) & 255));
      }
      m_strip.show();
      delay(m_waitInMs);
    }
  };
};

#endif // BB_RAINBOW_CYCLE_PATTERN
