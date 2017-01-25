// joshua goldberg 2017

// Power plugged into +5V port on Arduino
// GND plugged into any GND port

#include <Adafruit_NeoPixel.h>
 
#define PIN    6 // signal plugged into port 6
#define N_LEDS 24 // 24 item ring
#define SCALE_FACTOR .5 // how bright is the color (range 0.-1.)
#define PSPEED 15 // how many 5msec cycles between advance

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
// this defines the code object for the strip

int dotSpeed = PSPEED; // # of cycles (5ms timing) between advance
int dotPosition = 0; // where on the ring is the dot

void setup() {
  // put your setup code here, to run once:
  strip.begin();
}

void loop() {


  for (int i=0; i<N_LEDS; i++) {
    // for each pixel, this reads the current color and fades it down a little every cycle
    
    uint32_t currentColor = strip.getPixelColor(i);
    char currentR = splitColor(currentColor, 'r');
    char currentG = splitColor(currentColor, 'g');
    char currentB = splitColor(currentColor, 'b');
    if (currentR != 0) { currentR--;} 
    if (currentG != 0) { currentG--;} 
    if (currentB != 0) { currentB--;} 
    strip.setPixelColor(i, currentR, currentG, currentB);    
  }

  dotSpeed--;
  if (dotSpeed == 0) {
    dotSpeed = PSPEED;
    dotPosition++;
    dotPosition = dotPosition % 24;
    strip.setPixelColor(dotPosition, 255, 255, 255);
  }
  delay(5);
  strip.show();
}

/**
 * splitColor() - Receive a uint32_t value, and spread into bits.
 */
uint8_t splitColor ( uint32_t c, char value )
{
  switch ( value ) {
    case 'r': return (uint8_t)(c >> 16);
    case 'g': return (uint8_t)(c >>  8);
    case 'b': return (uint8_t)(c >>  0);
    default:  return 0;
  }
}

