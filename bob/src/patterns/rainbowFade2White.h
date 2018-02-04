#ifndef BB_RAINBOW_FADE_2_WHITE_PATTERN
#define BB_RAINBOW_FADE_2_WHITE_PATTERN

class RainbowFade2White: public Pattern {

 protected:
   uint8_t m_rainbowLoops;
   uint8_t m_whiteLoops;
   uint8_t m_waitInMs;
 public:

  // Constructor: number of LEDs, pin number, LED type
  RainbowFade2White( Adafruit_NeoPixel &strip, uint8_t wait, uint8_t rainbowLoops, uint8_t whiteLoops )
  : Pattern( strip ),
  m_rainbowLoops( rainbowLoops),
  m_whiteLoops( whiteLoops ),
  m_waitInMs( wait )
  {};

  ~RainbowFade2White() {};

// void rainbowFade2White(uint8_t wait, int rainbowLoops, int whiteLoops) {
  void update() {
  float fadeMax = 100.0;
  int fadeVal = 0;
  uint32_t wheelVal;
  int redVal, greenVal, blueVal;

  for(int k = 0 ; k < m_rainbowLoops ; k ++) {
    for(int j=0; j<256; j++) { // 5 cycles of all colors on wheel
      for(int i=0; i< m_strip.numPixels(); i++) {
        wheelVal = wheel(((i * 256 / m_strip.numPixels()) + j) & 255);

        redVal = red(wheelVal) * float(fadeVal/fadeMax);
        greenVal = green(wheelVal) * float(fadeVal/fadeMax);
        blueVal = blue(wheelVal) * float(fadeVal/fadeMax);

        m_strip.setPixelColor( i, m_strip.Color( redVal, greenVal, blueVal ) );
      }

      // First loop, fade in!
      if(k == 0 && fadeVal < fadeMax-1) {
        fadeVal++;
      }
      // Last loop, fade out!
      else if(k == m_rainbowLoops - 1 && j > 255 - fadeMax ) {
        fadeVal--;
      }

      m_strip.show();
      delay(m_waitInMs);
    }
  }

  delay(500);

  for(int k = 0 ; k < m_whiteLoops ; k ++) {
    for(int j = 0; j < 256 ; j++) {
      for(uint16_t i=0; i < m_strip.numPixels(); i++) {
        m_strip.setPixelColor(i, m_strip.Color(0,0,0, gamma[j] ) );
      }
      m_strip.show();
    }

    delay(2000);
    for(int j = 255; j >= 0 ; j--) {
      for(uint16_t i=0; i < m_strip.numPixels(); i++) {
        m_strip.setPixelColor(i, m_strip.Color(0,0,0, gamma[j] ) );
      }
      m_strip.show();
    }
  }

  delay(500);
  };
};
#endif // BB_RAINBOW_FADE_2_WHITE_PATTERN
