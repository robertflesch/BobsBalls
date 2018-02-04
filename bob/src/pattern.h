#ifndef BB_PATTERN
#define BB_PATTERN

class Pattern {
  #define PIXEL_PIN D2
  #define PIXEL_COUNT 50
  #define PIXEL_TYPE WS2811

 protected:
   Adafruit_NeoPixel& m_strip;
 public:

  // Constructor: number of LEDs, pin number, LED type
  Pattern( Adafruit_NeoPixel &strip ):m_strip(strip) {};
  Pattern(Pattern const &pat):m_strip(pat.m_strip) {};

  // ??? Have to initialize the default constructor, but would like it never be called - RSF 1.31.18
  Pattern():m_strip( *(new Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE)) ) {};
  ~Pattern() {};

  virtual void update() = 0;

protected:
  // Input a value 0 to 255 to get a color value.
  // The colours are a transition r - g - b - back to r.
  uint32_t wheel(byte WheelPos) {
    if(WheelPos < 85) {
     return m_strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
    } else if(WheelPos < 170) {
     WheelPos -= 85;
     return m_strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    } else {
     WheelPos -= 170;
     return m_strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
  }

};

#endif // BB_PATTERN
