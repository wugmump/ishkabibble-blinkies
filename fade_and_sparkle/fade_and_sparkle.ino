

// A simple sketch for a color fade with sparkles on a Neopixel ring
// joshua goldberg 2017

// Power plugged into +5V port on Arduino
// GND plugged into any GND port
 
#include <Adafruit_NeoPixel.h>
 
#define PIN    6 // signal plugged into port 6
#define N_LEDS 24 // 24 item ring
#define SCALE_FACTOR .5 // how bright is the color (range 0.-1.)
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
// this defines the code object for the strip

double red;
double green;
double blue;
// red green and blue values are generated using floating point math, 
// so we need a double to define the values. by default they start at 0.
 
void setup() {
  // this is the initialization area. it's run when the Arduino initially gets power.
  // all we need to do is set up the Neopixel object with begin().
  strip.begin();
}


void loop() {
  // this code is run over and over again after the initial setup()
  
  red = red + .0021;
  green  = green + .0022;
  blue = blue + .0023;
  // the above lines very slightly increment RGB values out of phase.
  // the smaller the difference between the three numbers, the slower the color change
  
  double ared = sin(red);
  double agreen = sin(green);
  double ablue = sin(blue);
  // no matter what the current value of the incremented RGB, a sine will be clamped
  // between -1. and 1, and will add a smooth sinusoidal curve to the color change.

  ared = (ared * 128.0) + 128;
  ablue = (ablue * 128.0) + 128;
  agreen = (agreen * 128.0) + 128;
  // this pushes the range of the color from -1. - 1. to 0. - 255.
  
  ared = ared * SCALE_FACTOR;
  ablue = ablue * SCALE_FACTOR;
  agreen = agreen * SCALE_FACTOR;
  // this is where the brightness is scaled back

  int ired = int(ared);
  int igreen = int(agreen);
  int iblue = int(ablue);
  // color values can't be floats. this rounds to nearest integer.

  for (int i=0; i<N_LEDS; i++) { // do a loop the length of pixel count
    strip.setPixelColor(i, strip.Color(ired,igreen,iblue));
    // set the color to the generated RGB
    if (random(0,2000) == 0) { // every pixel has a 1 in N chance of changing to white for sparkle
      strip.setPixelColor(i, strip.Color(255,255,255));
    }
    
  }
  delay(1); // wait for n milliseconds. 
  strip.show(); // you need this to push the colors to the neopixel array.
}
 




