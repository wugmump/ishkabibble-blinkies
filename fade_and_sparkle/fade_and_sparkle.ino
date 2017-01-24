
 
#include <Adafruit_NeoPixel.h>
 
#define PIN    6
#define N_LEDS 24 // 24 item ring
#define SCALE_FACTOR .5
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
double red;
double green;
double blue;
int pixel;
int offpixel;
 
void setup() {
  strip.begin();
}


void loop() {
  red = red + .001;
  green  = green + .002;
  blue = blue + .003;
  
  double ared = sin(red);
  double agreen = sin(green);
  double ablue = sin(blue);

  ared = (ared * 64.0) + 64;
  ablue = (ablue * 64.0) + 64;
  agreen = (agreen * 64.0) + 64;

  ared = ared * SCALE_FACTOR;
  ablue = ablue * SCALE_FACTOR;
  agreen = agreen * SCALE_FACTOR;

  int ired = int(ared);
  int igreen = int(agreen);
  int iblue = int(ablue);

  for (int i=0; i<N_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(ired,igreen,iblue));
    if (random(0,2000) == 0) {
      strip.setPixelColor(i, strip.Color(255,255,255));
    }
    
  }
  delay(5);
  strip.show();
}
 




