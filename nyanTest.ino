#include <Adafruit_NeoPixel.h>
//#include <avr/sleep.h>    // Sleep Modes

#define PIN 3
#define NUM_PXLS 7
#define BRIGHTS 128
// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PXLS, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.


// Change these to set speed (lower is faster)

#define ROTATION_RATE  100
 
// Change these to be whatever color you want
// Use color picker to come up with hex values
#define FLASH_COLOR   0xFF0000
#define SPIN_COLOR    0xFF0000
#define CYLON_COLOR   0xFF0000

int colorIndex;
int startIndex;

// Define 10 colors here.
// Must be 10 entries.
// Use 0x000000 if you want a blank space.
uint32_t RAINBOW_COLORS[7] = {
  strip.Color(255, 0, 0),  //red
  strip.Color(255, 255, 10),  //yellowish
  strip.Color(0, 255, 0),  //green
  strip.Color(0, 30, 255), //blue
  strip.Color(128, 0, 255),  //purple
  strip.Color(0, 0, 0),  
  strip.Color(0, 0, 0)
};


void setup() {
  ADCSRA &= ~(1<<ADEN); //Disable ADC, saves ~230uA
  strip.setBrightness(BRIGHTS); 
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  startIndex=0;
}

void loop() { 
    rainbowChase();
  }

void rainbowChase()
{
  strip.clear();
  strip.show();
  colorIndex = startIndex;
  for (int p=0; p<NUM_PXLS; p++)
  {
    strip.setPixelColor(p, RAINBOW_COLORS[colorIndex]);
    //strip.setPixelColor(p, (0,   0, 127));
    strip.show();
    colorIndex++;
    if (colorIndex>NUM_PXLS)
       colorIndex = 0;
  }
  startIndex++;
  if(startIndex>NUM_PXLS)
      startIndex = 0;
  delay(ROTATION_RATE);  
  }


