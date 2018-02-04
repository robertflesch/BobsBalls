#include "Particle.h"
#include "neopixel.h"

SYSTEM_MODE(AUTOMATIC);

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D2
#define PIXEL_COUNT 100
#define PIXEL_TYPE WS2812B

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

// Prototypes for local build, ok to leave in for Build IDE
void rainbow(uint8_t wait);
uint32_t Wheel(byte WheelPos);

void setup()
{
  Particle.publish( "BobsBalls.setup - 10:25AM - Chasing" );
  strip.begin();
  strip.setBrightness( 64 );
  strip.show();
}

// NOTE Instantaneous vs OverTime
// A pattern is a set of transformations executed over time
// Lets say a rampUp is one time element,
// another time element is a spiral
// how do we run both elements at the same time?
// So elements which act on all pixels must execute first
// I could create a list of elements and sort them by type

// NOTE linear vs small triangles vs large triangles vs hexagonal
// ???
static const uint32_t BLACK =   Adafruit_NeoPixel::Color( 0  , 0  , 0   );
static const uint32_t GREEN =   Adafruit_NeoPixel::Color( 255, 0  , 0   );
static const uint32_t RED =     Adafruit_NeoPixel::Color( 0  , 255, 0   );
static const uint32_t BLUE =    Adafruit_NeoPixel::Color( 0  , 0  , 255 );

void circulatingTriangles() {
  uint8_t index = 5;
  for( uint8_t j = 1; j <= 5; j++ ) {
    for ( uint8_t i = 0; i < 3; i++ ) {
      setColorGlobal( BLACK );
      if ( j < 5 ) {
        if ( i < 2 ) {
          strip.setPixelColor( j, RED );
          strip.setPixelColor( j + index + i, RED );
          strip.setPixelColor( j + index + i + 1, RED );
        } else {
          strip.setPixelColor( j, RED );
          strip.setPixelColor( j + index + i, RED );
          strip.setPixelColor( j + 1, RED );
          index++;
        }
      } else {
        if ( i == 0 ) {
          strip.setPixelColor( j, RED );
          strip.setPixelColor( j + index + i, RED );
          strip.setPixelColor( j + index + i + 1, RED );
        } else if ( i == 1 ) {
          strip.setPixelColor( j, RED );
          strip.setPixelColor( j + index + i, RED );
          strip.setPixelColor( j + 1, RED );
        } else if ( i == 2 ) {
          strip.setPixelColor( j, RED );
          strip.setPixelColor( j + 1, RED );
          strip.setPixelColor( 1, RED );
        }
      }
      strip.show();
      delay(500);
    }
  }
}

void rampUp( uint8_t r, uint8_t g, uint8_t b, uint8_t a = 127, uint16_t wait = 50 ) {
  uint16_t j;

  for(j=0; j<a; j++) {
    setColorGlobal( j*g/a, j*r/a, j*b/a );
    strip.show();
    delay(wait);
  }
}


void setColorGlobal( uint8_t r, uint8_t g, uint8_t b ) {
  for(uint16_t i=0; i<strip.numPixels(); i++)
    strip.setPixelColor( i, 0, 0, 0 );
}

void setColorGlobal( uint32_t c ) {
  for(uint16_t i=0; i<strip.numPixels(); i++)
    strip.setPixelColor( i, c );
}

bool m_initialized = false;
void lines() {
  if ( m_initialized ){
    return;
  }
  m_initialized = true;
  strip.setBrightness( 32 );
  uint32_t color = Adafruit_NeoPixel::Color( 0, 255, 0 );
  uint16_t i, j;
  setColorGlobal( 0 );
  strip.setPixelColor( 0, color );
  strip.setPixelColor( 6, color );
  strip.setPixelColor( 17, color );
  strip.setPixelColor( 33, color );

  strip.setPixelColor( 1, color );
  strip.setPixelColor( 8, color );
  strip.setPixelColor( 20, color );
  strip.setPixelColor( 37, color );

  strip.setPixelColor( 2, color );
  strip.setPixelColor( 10, color );
  strip.setPixelColor( 23, color );
  strip.setPixelColor( 41, color );

  strip.setPixelColor( 3, color );
  strip.setPixelColor( 12, color );
  strip.setPixelColor( 26, color );
  strip.setPixelColor( 45, color );

  strip.setPixelColor( 4, color );
  strip.setPixelColor( 14, color );
  strip.setPixelColor( 29, color );
  strip.setPixelColor( 49, color );

  strip.setPixelColor( 99, color );
  strip.setPixelColor( 93, color );
  strip.setPixelColor( 82, color );
  strip.setPixelColor( 67, color );

  strip.setPixelColor( 98, color );
  strip.setPixelColor( 91, color );
  strip.setPixelColor( 79, color );
  strip.setPixelColor( 63, color );

  strip.setPixelColor( 97, color );
  strip.setPixelColor( 89, color );
  strip.setPixelColor( 76, color );
  strip.setPixelColor( 59, color );

  strip.setPixelColor( 96, color );
  strip.setPixelColor( 87, color );
  strip.setPixelColor( 73, color );
  strip.setPixelColor( 55, color );

  strip.setPixelColor( 95, color );
  strip.setPixelColor( 85, color );
  strip.setPixelColor( 70, color );
  strip.setPixelColor( 51, color );

  strip.show();
  delay(500);
}


void singleSpiral( uint32_t color, uint16_t wait = 50 ) {
  strip.setBrightness( 255 );
  uint16_t i, j;
  for(j=0; j<strip.numPixels(); j++) {
    setColorGlobal( 0 );
    //setColorScaled(uint16_t aLedNumber, byte aRed, byte aGreen, byte aBlue, byte aScaling) {
    if ( j-3 >= 0 )
      strip.setColorScaled( j-2, color, 8 );
    if ( j-2 >= 0 )
      strip.setColorScaled( j-2, color, 16 );
    if ( j-1 >= 0 )
      strip.setColorScaled( j-1, color, 32 );
    strip.setPixelColor( j, color );
    strip.show();
    delay(wait);
  }
}

void reverseSingleSpiral( uint32_t color, uint16_t wait = 50 ) {
  for( int16_t j = strip.numPixels(); j>=0; j--) {
    setColorGlobal( 0 );
    //setColorScaled(uint16_t aLedNumber, byte aRed, byte aGreen, byte aBlue, byte aScaling) {
    // if ( j-3 >= 0 )
    //   strip.setColorScaled( j-2, color, 8 );
    // if ( j-2 >= 0 )
    //   strip.setColorScaled( j-2, color, 16 );
    // if ( j-1 >= 0 )
    //   strip.setColorScaled( j-1, color, 32 );
    strip.setPixelColor( j, color );
    strip.show();
    delay(wait);
  }
}

 void pingPong() {
   uint16_t i, j;
//   for(j=0; j<256; j++) {
     for(i=0; i<strip.numPixels(); i++) {
       uint32_t color = Wheel((i+j) & 255);
       reverseSingleSpiral( color, 10 );
       singleSpiral( color, 10 );
     }
//   }
 }
void loop() {
  //setColorGlobal( 0 );
  //strip.show();
  //pingPong();
  lines();
  strip.show();
  //circulatingTriangles();
  //rainbow( 25 );
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
