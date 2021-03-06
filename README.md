# range-finding-with-sonar-
Range finding using ultrasonic sensor HC-SR04 and array of individual addressable RGB LED strip

Uses ultrasonic sensor to calculate distance to an object. If the object is within some threshold, program will trigger an array of LED lights. The idea here is to use the range finder as a "smart" bike light. The light will flash if some object gets too close to the bicycle.

## Main Hardware
Arduino Uno or any compatable Arduino based [microprocessor.](https://www.amazon.com/Elegoo-ATmega328P-ATMEGA16U2-Compatible-Arduino/dp/B01EWOE0UU/ref=sr_1_sc_1?ie=UTF8&qid=1497814687&sr=8-1-spell&keywords=elengoo+uno)

Individually addressable [RGB LED light strip.](https://www.amazon.com/gp/product/B01B1I21OM/ref=oh_aui_detailpage_o02_s00?ie=UTF8&psc=1)


## Installation Instructions
Download and install [Arduino IDE.](https://www.arduino.cc/en/Main/Software)
After installing you'll need to add FastLed and NewPing libraries to Arduino IDE by opening IDE > Sketch > Include Library > Add .ZIP Library... The libraries are included in the master.

In sonar_blink_with_led.ino modify #define parameters to match your hardware
* NUM_LEDS specify the number of leds you want to light up
* COLOR_ORDER specify the led order your light strip is set in
* CHIPSET model of the led chip your light strip uses
* DATA_PIN data pin on arduino that the ultrasonic sensor is connected to
* TRIGPIN trigger pin on arduino that the ultrasonic sensor is connected to
* ECHOPIN echo pin on arduino that the ultrasonic sensor is connected to
* MAX_DISTANCE specify the max distance in centimeters that the ultrasonic sensor will read. Note max is 400, lower the distance more accurate the reading.
