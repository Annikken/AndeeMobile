/************************************************************
  [Annikken Andee with AndeeMobile]
  ================
  Blink without Andee

  Check out our Resources section for more information and 
  ideas on what you can do with the Annikken Andee or the 
  AndeeMobile!
  https://annikken.gitbooks.io/annikken-andee/content/

  Contact us at andee@annikken.com if there are 
  bugs in this sketch or if you need help with either the 
  Annikken Andee or AndeeMobile
  
************************************************************/

// Always include these libraries. AndeeMobile needs them
// to work with the Arduino!
#include <SPI.h>
#include <AndeeMobile.h>

void setup() {
  // put your setup code here, to run once:
  AndeeMobileSetup(); // Setup code for AndeeMobile
}


// Arduino will run instructions here repeatedly until you power it off.
void loop() {
  // put your main code here, to run repeatedly:
  headlight(ON);  // Call headlight(ON) to turn on AndeeMobile headlight on.
  taillight(ON);  // Call taillight(ON) to turn on AndeeMobile taillight on.
  delay(1000);    // A short delay is necessary for AndeeMobile to switch between on and off.
  headlight(OFF); // Call headlight(OFF) to turn on AndeeMobile headlight off.
  taillight(OFF); // Call taillight(OFF) to turn on AndeeMobile taillight off.
  delay(1000);    // A short delay is necessary for AndeeMobile to switch between on and off.
}
