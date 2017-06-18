#include <NewPing.h>
#include "FastLED.h"

#define NUM_LEDS     60
#define COLOR_ORDER  GRB
#define CHIPSET      WS2811
#define DATA_PIN     6
#define TRIGPIN      2
#define ECHOPIN      3
#define MAX_DISTANCE 200

// define sonar
NewPing sonar(TRIGPIN, ECHOPIN, MAX_DISTANCE);

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
  delay(3000); // sanity delay
  Serial.begin(115200);
  LEDS.addLeds<CHIPSET,DATA_PIN,COLOR_ORDER>(leds,NUM_LEDS);
  LEDS.setBrightness(84);
}

void loop() { 
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");

  while(sonar.ping_cm() != 0 && sonar.ping_cm() <= MAX_DISTANCE) {
    // turn all LED on, then pause
    for(int i = 0; i < NUM_LEDS; i++){
      leds[i] = CRGB::Orange;
    }
    FastLED.show();
    delay(250);
    
    // turn LED off
    for(int i = 0; i < NUM_LEDS; i++){
      leds[i] = CRGB::Black;
    }
    FastLED.show();
    delay(250);
  }
  
  // Now turn the LED off, then pause
  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(250);
}
