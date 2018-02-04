#ifndef BB_FULL_WHITE_PATTERN
#define BB_FULL_WHITE_PATTERN

// Slightly different, this makes the rainbow equally distributed throughout
class FullWhite: public Pattern {
 public:
  // Constructor: number of LEDs, pin number, LED type
  FullWhite( Adafruit_NeoPixel &strip ):
    Pattern( strip )
    {};

  ~FullWhite() {};

  void update() {
    for(uint16_t i=0; i<m_strip.numPixels(); i++) {
      m_strip.setPixelColor(i, m_strip.Color(0,0,0, 255 ) );
    }
    m_strip.show();
  };
};

#endif // BB_FULL_WHITE_PATTERN
