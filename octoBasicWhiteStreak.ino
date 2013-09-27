
/** @(#)octoBasicWhiteStreak.ino 1.0.0 2013-09-25

  Purpose     : Software for a OCTOWS2811 LED array that pushes a single white
                dot down the length of each strip attached.
  Author      : Liana Bandziulis
  Description : A loop iterates through the number of LEDs in the system.
                First, it sets everything to black.
                Then, it sets a single LED on to white, based on the loop's i.
  Specifics   : Assumes there are 8 strips attached, and runs down them as a
                one-line array.
  Known Bugs  : (none)

*/

/** 
~~~ Revision History ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 Version:  Date:        Modified by:   Description of change/modification:
 --------  -----------  ------------   -----------------------------------------
 1.0.0     2013 Sep 25  Liana          Initial version/release
 
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

// -------------------------------
//  CONFIG
// -------------------------------

#include <OctoWS2811.h>

const int ledsPerStrip = 60; 
const int duration = 3;   // seconds it takes to run; aka, speed.

DMAMEM int displayMemory[ledsPerStrip*6];
int drawingMemory[ledsPerStrip*6];

const int config = WS2811_GRB | WS2811_800kHz;
OctoWS2811 leds(ledsPerStrip, displayMemory, drawingMemory, config);

// -------------------------------
//		SETUP
// -------------------------------

void setup() {
  leds.begin();
  leds.show();

// Gives names to the hex colors used

  #define WHITE 0xFFFFFF;
  #define BLACK 0x000000;

}

// -------------------------------
//		MAIN
// -------------------------------

void loop() {

// creates interval b/w frames based on duration (in config) and the number
// of pixels (or frames) it needs to go through to complete the sequence. 
// Each sequence runs for 'duration' # of seconds.

  int microsec = 1000000 * duration / leds.numPixels();

  for (int i = 0; i < leds.numPixels(); i++) {
 
  // First, sets ALL to black in buffer...
        for (int j = 0; j < leds.numPixels(); j++) {
          leds.setPixel(j, 0x000000);
        }
 // Then, sets 'i' to white in buffer.
    	leds.setPixel(i, 0xFFFFFF);
 // Updates LEDs according to what's in buffer.
  	leds.show();
  	delayMicroseconds (microsec);
  }
  
}
