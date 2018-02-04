#ifndef BB_COLOR_WIPE_PATTERN
#define BB_COLOR_WIPE_PATTERN

// Slightly different, this makes the rainbow equally distributed throughout
class ColorWipe: public Pattern {
private:
  uint32_t m_waitInMs;
  uint32_t m_color;

 public:
  // Constructor: number of LEDs, pin number, LED type
  ColorWipe( Adafruit_NeoPixel &strip, uint32_t waitInMs, uint32_t color ):
    Pattern( strip ),
    m_waitInMs( waitInMs ),
    m_color( color )
    {};

  ~ColorWipe() {};

  void update() {
    for(uint16_t i=0; i<m_strip.numPixels(); i++) {
      m_strip.setPixelColor(i, m_color);
      m_strip.show();
      delay(m_waitInMs);
    }
  };
};

#endif // BB_COLOR_WIPE_PATTERN
