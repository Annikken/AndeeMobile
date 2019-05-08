/************************************************************
  [Annikken Andee with AndeeMobile]
  ================

  Check out our Resources section for more information and 
  ideas on what you can do with the Annikken Andee or the 
  AndeeMobile!
  https://annikken.gitbooks.io/annikken-andee/content/

  Contact us at andee@annikken.com if there are 
  bugs in this sketch or if you need help with either the 
  Annikken Andee or AndeeMobile
  
************************************************************/

// Always include these libraries. Annikken Andee needs them
// to work with the Arduino!
#include <SPI.h>
#include <Andee.h>
#include <AndeeMobile.h>

// Every object that appears on your smartphone's screen
// needs to be declared like this:
AndeeHelper button;

int lightState = 0; // light state, 0 = OFF/1 = ON

// The setup() function is meant to tell Arduino what to do 
// only when it starts up.
void setup()
{
  Andee.begin();      // Setup communication between Annikken Andee and Arduino
  Andee.clear();      // Clear the screen of any previous displays
  AndeeMobileSetup(); // Setup code for AndeeMobile
  setInitialData();   // Define object types and their appearance
}

// This is the function meant to define the types and the appearance of
// all the objects on your smartphone
void setInitialData()
{
  //// Let's draw the first object! //////////////////////////////////////////

  button.setId(0);                 // Assign a unique ID number
  button.setType(BUTTON_IN);       // Defines object as a button
  button.setCoord(30, 41, 40, 20); // Set the location and size of your button
  button.setTitle("Blink");        // Set button title
  button.requireAck(true);         // Enable require acknowlegdement
}

// method check whether to blink both headlight and taillight or not
void blinkCondition() {
  // check current light state 
   if(lightState == 1) {  // If light state = 1
    headlight(ON);        // API method to on the head lights
    taillight(ON);        // API method to on the tail lights
    delay(500);
    headlight(OFF);       // API method to off the head lights
    taillight(OFF);       // API method to off the tail lights
   } else {               // If light state = 0
    headlight(OFF);       // API method to off the head lights
    taillight(OFF);       // API method to off the tail lights
   } 
}

// Arduino will run instructions here repeatedly until you power it off.
void loop() {
  /* 
   *  Call update() to refresh the display on your screen
   *  If you forgot to call update(), your object won't appear 
   */
  // works similar toggle button
  if(button.isPressed()) {              // If button is pressed
    if(lightState == 0) {               // If current light state is off switch it on
      button.setTitle("Stop Blinking"); // Set button set title to 'Stop Blinking'
      lightState = 1;                   // Change lightState to 1 which is ON
    } else {                            // Else current light state is on switch it off
      button.setTitle("Blink");         // Set button set title to 'Blink'
      lightState = 0;                   // Change lightState to 0 which is OFF
    }
    button.ack();                       // Send acknowledgement to Annikken Andee 
  }

  button.update();                      // Update button UI

  blinkCondition();                     // Always checking the condition whether to blink or not
  
  // A short delay is necessary to give Andee time to communicate with the smartphone
  delay(500); 
}



