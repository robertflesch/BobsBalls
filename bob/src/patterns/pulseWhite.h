#ifndef BB_PULSE_WHITE_PATTERN
#define BB_PULSE_WHITE_PATTERN

// Slightly different, this makes the rainbow equally distributed throughout
class PulseWhite: public Pattern {
private:
  uint32_t m_waitInMs;

 public:
  // Constructor: number of LEDs, pin number, LED type
  PulseWhite( Adafruit_NeoPixel &strip, uint32_t waitInMs = 500 ):
    Pattern( strip ),
    m_waitInMs( waitInMs )
    {};

  ~PulseWhite() {};

  void update() {
    for(int j = 0; j < 256 ; j++) {
      for(uint16_t i=0; i<m_strip.numPixels(); i++) {
        m_strip.setPixelColor(i, m_strip.Color(0,0,0, gamma[j] ) );
      }
      delay(m_waitInMs);
      m_strip.show();
    }

    for(int j = 255; j >= 0 ; j--){
      for(uint16_t i=0; i<m_strip.numPixels(); i++) {
        m_strip.setPixelColor(i, m_strip.Color(0,0,0, gamma[j] ) );
      }
      delay(m_waitInMs);
      m_strip.show();
    }
  };
};

#endif // BB_PULSE_WHITE_PATTERN
