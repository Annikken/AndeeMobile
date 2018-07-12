/************************************************************
  [Annikken Andee with AndeeMobile]
  ================
  Experiment 2 example

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
AndeeHelper headLight;
AndeeHelper tailLight;
AndeeHelper horn;

int headLightState = 0;
int tailLightState = 0;

// The setup() function is meant to tell Arduino what to do 
// only when it starts up.
void setup()
{
  Andee.begin();        // Setup communication between Annikken Andee and Arduino
  Andee.clear();        // Clear the screen of any previous displays
  setInitialData();     // Define object types and their appearance
  AndeeMobileSetup();   // Setup code for AndeeMobile
}

// This is the function meant to define the types and the apperance of
// all the objects on your smartphone
void setInitialData()
{
  //// Let's draw the first object! //////////////////////////////////////////

  horn.setId(0);                          // Assign a unique ID number
  horn.setType(BUTTON_IN);                // Defines object as a button
  horn.setCoord(30, 21, 40, 20);          // Set the location and size of your button
  horn.setTitle("Horn");                  // Set button title
  horn.requireAck(false);                 // Disable require acknowledgement 

  headLight.setId(1);                     // Assign a unique ID number
  headLight.setType(BUTTON_IN);           // Defines object as a button
  headLight.setCoord(30, 42, 40, 20);     // Set the location and size of your button
  headLight.setTitle("HeadLight");        // Set button title
  headLight.requireAck(false);            // Disable require acknowledgement 

  tailLight.setId(2);                     // Assign a unique ID number
  tailLight.setType(BUTTON_IN);           // This defines your object as a display box
  tailLight.setCoord(30, 63, 40, 20);     // Defines object as a button
  tailLight.setTitle("BackLight");        // Set button title
  tailLight.requireAck(false);            // Disable require acknowledgement 
}

// Arduino will run instructions here repeatedly until you power it off.
void loop()
{
  /* 
   *  Call update() to refresh the display on your screen
   *  If you forgot to call update(), your object won't appear 
   */
  // works similar toggle button
  if(horn.isPressed()) {              // if horn button is pressed
    carHorn(ON);                      // call AndeeMobile to sound out it's horn
    delay(1000);                      // allow AndeeMobile to sound it's horn for 1s
    carHorn(OFF);                     // call AndeeMobile to stop it's horn
  } else if(headLight.isPressed()) {  // if headLight button pressed
    if(headLightState == 0) {         // if headLightState equal to 0
      headlight(ON);                  // call AndeeMobile to on it's headlight
      headLightState = 1;             // change the headLightState to 1
    } else {                          
      headlight(OFF);                 // call AndeeMobile to off it's headlight
      headLightState = 0;             // change the headLightState to 0
    }
  } else if(tailLight.isPressed()) {  // if tailight button pressed
    if(tailLightState == 0) {         // if tailLightState equal to 0
      taillight(ON);                  // call AndeeMobile to on it's tailight
      tailLightState = 1;             // change the tailLightState to 1
    } else {
      taillight(OFF);                 // call AndeeMobile to off it's tailLight
      tailLightState = 0;             // change the tailLightState to 0
    }
  }

  // Don't forget to call update() or else your objects won't show up
  horn.update();
  headLight.update();
  tailLight.update();

  // A short delay is necessary to give Andee time to communicate with the smartphone
  delay(500); 
}



