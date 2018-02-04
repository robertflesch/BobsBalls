#ifndef BB_RAINBOW_PATTERN
#define BB_RAINBOW_PATTERN

class Rainbow: public Pattern {
private:
  uint32_t m_waitInMs;
  
 public:
  // Constructor: number of LEDs, pin number, LED type
  Rainbow( Adafruit_NeoPixel &strip, uint32_t waitInMs = 500 ):
    Pattern( strip ),
    m_waitInMs( waitInMs )
    {};

  ~Rainbow() {};

  void update() {
    uint16_t i, j;

    for(j=0; j<256; j++) {
      for(i=0; i<m_strip.numPixels(); i++) {
        m_strip.setPixelColor(i, wheel((i+j) & 255));
      }
      m_strip.show();
      delay( m_waitInMs );
    }
  };
};

#endif // BB_RAINBOW_PATTERN
