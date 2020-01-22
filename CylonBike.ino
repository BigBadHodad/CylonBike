#include <Adafruit_NeoPixel.h>
 
#define N_LEDS 8
#define PIN     11
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
 
void setup() {
  strip.begin();
}
 
int pos = 0, dir = 1; // Position, direction of "eye"
 
void loop() {
  int j;
 
  // Draw 3 pixels centered on pos.  setPixelColor() will clip any
  // pixels off the ends of the strip, we don't need to watch for that.
 
  strip.setPixelColor(pos - 1, 0xff2700); // Medium 
  strip.setPixelColor(pos    , 0xff2700); // Center pixel is brightest
  strip.setPixelColor(pos + 1, 0xff2700); // Medium 
 
 
  strip.show();
  delay(125);
 
  // Rather than being sneaky and erasing just the tail pixel,
  // it's easier to erase it all and draw a new one next time.
  for(j=-2; j<= 2; j++) strip.setPixelColor(pos+j, 0);
 
  // Bounce off ends of strip
  pos += dir;
  if(pos < 0) {
    pos = 1;
    dir = -dir;
  } else if(pos >= strip.numPixels()) {
    pos = strip.numPixels() - 2;
    dir = -dir;
  }
}
