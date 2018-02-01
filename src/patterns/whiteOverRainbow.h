#ifndef BB_WHITE_OVER_RAINBOW_PATTERN
#define BB_WHITE_OVER_RAINBOW_PATTERN

class WhiteOverRainbow: public Pattern {
 protected:
   uint8_t m_whiteLength;
   uint8_t m_whiteSpeed;
   uint8_t m_waitInMs;
 public:

  // Constructor: number of LEDs, pin number, LED type
  WhiteOverRainbow( Adafruit_NeoPixel &strip, uint8_t wait, uint8_t whiteSpeed, uint8_t whiteLength )
  : Pattern( strip ),
  m_whiteLength( whiteLength),
  m_whiteSpeed( whiteSpeed ),
  m_waitInMs( wait )
  {};

  ~WhiteOverRainbow() {};

  void update() {

    if(m_whiteLength >= m_strip.numPixels()) m_whiteLength = m_strip.numPixels() - 1;

    int head = m_whiteLength - 1;
    int tail = 0;
    int loops = 3;
    int loopNum = 0;
    static unsigned long lastTime = 0;

    while(true) {
      for(int j=0; j<256; j++) {
        for(uint16_t i=0; i<m_strip.numPixels(); i++) {
          if( (i >= tail && i <= head)
            || (tail > head && i >= tail)
            || (tail > head && i <= head) ) {
            m_strip.setPixelColor(i, m_strip.Color(0,0,0, 255 ) );
          } else {
            m_strip.setPixelColor(i, wheel(((i * 256 / m_strip.numPixels()) + j) & 255));
          }
        }

        if(millis() - lastTime > m_whiteSpeed) {
          head++;
          tail++;
          if(head == m_strip.numPixels()) {
            loopNum++;
          }
          lastTime = millis();
        }

        if(loopNum == loops) return;

        head %= m_strip.numPixels();
        tail %= m_strip.numPixels();
        m_strip.show();
        delay(m_waitInMs);
      }
    }
  }
};

#endif // BB_WHITE_OVER_RAINBOW_PATTERN
