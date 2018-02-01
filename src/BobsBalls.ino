/*
 * This is a minimal example, see extra-examples.cpp for a version
 * with more explantory documentation, example routines, how to
 * hook up your pixels and all of the pixel types that are supported.
 *
 */
 /*
  * This is a RGB+W NeoPixel example, see extra-examples.cpp for a version
  * with more explantory documentation, example routines, how to
  * hook up your pixels and all of the pixel types that are supported.
  *
  */

 /* ======================= includes ================================= */

 #include "Particle.h"
 #include "neopixel.h"
 #include "pattern.h"
 #include "rainbow.h"
 //#include "whiteOverRainbow.h"

 /* ======================= prototypes =============================== */

 uint32_t wheel(byte WheelPos);
 uint8_t red(uint32_t c);
 uint8_t green(uint32_t c);
 uint8_t blue(uint32_t c);
 void colorWipe(uint32_t c, uint8_t wait);
 void pulseWhite(uint8_t wait);
 void rainbowFade2White(uint8_t wait, int rainbowLoops, int whiteLoops);
 //void whiteOverRainbow(uint8_t wait, uint8_t whiteSpeed, uint8_t whiteLength);
 void fullWhite();
 void rainbowCycle(uint8_t wait);
 void rainbow(uint8_t wait);

 Pattern* m_pat = NULL;

 // ======================= rgbw-strandtest.cpp ======================

 SYSTEM_MODE(AUTOMATIC);

 // IMPORTANT: Set pixel COUNT, PIN and TYPE
 #define PIXEL_PIN D2
 #define PIXEL_COUNT 50
 #define PIXEL_TYPE WS2811
 #define BRIGHTNESS 50 // 0 - 255

 Adafruit_NeoPixel m_strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

 int gamma[] = {
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
     1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
     2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
     5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
    10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
    17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
    25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
    37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
    51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
    69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
    90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
   115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
   144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
   177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
   215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };

 void setup() {
   m_strip.setBrightness(BRIGHTNESS);
   m_strip.begin();
   m_strip.show(); // Initialize all pixels to 'off'
   // Warning
   // Warning function name is limited to 12 characters
   // Warning
   Particle.function("choosePat",choosePattern);
   m_pat = new Rainbow( m_strip, 500 );
 }

int choosePattern(String command) {
  // I suspect I can pass multi parameters here in the string, so I need to understand pattern, or use a json object stringified
  if ( command == "Rainbow")
    m_pat = new Rainbow( m_strip, 500 );
//  else
//    m_pat = new WhiteOverRainbow( m_strip, 20,75,5 );
  return 1;
}

 void loop() {
   m_pat->update();
   // Some example procedures showing how to display to the pixels:
   // Do not run more than 15 seconds of these, or the b/g tasks
   // will be blocked.
   // --------------------------------------------------------------
   //colorWipe(m_strip.Color(255, 0, 0), 50); // Red
   //colorWipe(m_strip.Color(0, 255, 0), 50); // Green
   //colorWipe(m_strip.Color(0, 0, 255), 50); // Blue
   //colorWipe(m_strip.Color(0, 0, 0, 255), 50); // White

   //pulseWhite(5);

   // fullWhite();
   // delay(2000);

   //rainbowFade2White(3,3,1);
 }

 uint8_t red(uint32_t c) {
   return (c >> 8);
 }
 uint8_t green(uint32_t c) {
   return (c >> 16);
 }
 uint8_t blue(uint32_t c) {
   return (c);
 }

 // Fill the dots one after the other with a color
 void colorWipe(uint32_t c, uint8_t wait) {
   for(uint16_t i=0; i<m_strip.numPixels(); i++) {
     m_strip.setPixelColor(i, c);
     m_strip.show();
     delay(wait);
   }
 }

 void pulseWhite(uint8_t wait) {
   for(int j = 0; j < 256 ; j++) {
     for(uint16_t i=0; i<m_strip.numPixels(); i++) {
       m_strip.setPixelColor(i, m_strip.Color(0,0,0, gamma[j] ) );
     }
     delay(wait);
     m_strip.show();
   }

   for(int j = 255; j >= 0 ; j--){
     for(uint16_t i=0; i<m_strip.numPixels(); i++) {
       m_strip.setPixelColor(i, m_strip.Color(0,0,0, gamma[j] ) );
     }
     delay(wait);
     m_strip.show();
   }
 }


 void rainbowFade2White(uint8_t wait, int rainbowLoops, int whiteLoops) {
   float fadeMax = 100.0;
   int fadeVal = 0;
   uint32_t wheelVal;
   int redVal, greenVal, blueVal;

   for(int k = 0 ; k < rainbowLoops ; k ++) {
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
       else if(k == rainbowLoops - 1 && j > 255 - fadeMax ) {
         fadeVal--;
       }

       m_strip.show();
       delay(wait);
     }
   }

   delay(500);

   for(int k = 0 ; k < whiteLoops ; k ++) {
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
 }

 void fullWhite() {
   for(uint16_t i=0; i<m_strip.numPixels(); i++) {
     m_strip.setPixelColor(i, m_strip.Color(0,0,0, 255 ) );
   }
   m_strip.show();
 }

 // Slightly different, this makes the rainbow equally distributed throughout
 void rainbowCycle(uint8_t wait) {
   uint16_t i, j;

   for(j=0; j<256 * 5; j++) { // 5 cycles of all colors on wheel
     for(i=0; i< m_strip.numPixels(); i++) {
       m_strip.setPixelColor(i, wheel(((i * 256 / m_strip.numPixels()) + j) & 255));
     }
     m_strip.show();
     delay(wait);
   }
 }
/*
void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<m_strip.numPixels(); i++) {
      m_strip.setPixelColor(i, wheel((i+j) & 255));
    }
    m_strip.show();
    delay(wait);
  }
}
*/
