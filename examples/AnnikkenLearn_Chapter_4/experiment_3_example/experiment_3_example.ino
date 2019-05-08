/************************************************************
  [Annikken Andee with AndeeMobile]
  ================
  Experiment 3 example

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
AndeeHelper forward;
AndeeHelper backward;
AndeeHelper eStop;

// The setup() function is meant to tell Arduino what to do 
// only when it starts up.
void setup()
{
  Andee.begin();      // Setup communication between Annikken Andee and Arduino
  Andee.clear();      // Clear the screen of any previous displays
  setInitialData();   // Define object types and their appearance
  AndeeMobileSetup(); // Setup code for AndeeMobile
}

// This is the function meant to define the types and the appearance of
// all the objects on your smartphone
void setInitialData()
{
  //// Let's draw the first object! //////////////////////////////////////////

  forward.setId(0);                     // Assign a unique ID number
  forward.setType(BUTTON_IN);           // Defines object as a button
  forward.setCoord(30, 21, 40, 20);     // Set the location and size of your button
  forward.setTitle("Forward");          // Set button title
  forward.requireAck(false);            // Disable require acknowledgement 

  eStop.setId(1);                       // Assign a unique ID number
  eStop.setType(BUTTON_IN);             // Defines object as a button
  eStop.setCoord(30, 42, 40, 20);       // Set the location and size of your button
  eStop.setTitle("Stop");               // Set button title
  eStop.requireAck(false);              // Disable require acknowledgement 

  backward.setId(2);                    // Assign a unique ID number
  backward.setType(BUTTON_IN);          // Defines object as a button
  backward.setCoord(30, 63, 40, 20);    // Set the location and size of your button
  backward.setTitle("Backward");        // Set button title
  backward.requireAck(false);           // Disable require acknowledgement 
}

// Arduino will run instructions here repeatedly until you power it off.
void loop()
{
  /* 
   *  Call update() to refresh the display on your screen
   *  If you forgot to call update(), your object won't appear 
   */
  // works similar toggle button
  if(forward.isPressed()) {           // if forward button pressed
    moveForward(100);                 // move forward
  } else if(eStop.isPressed()) {      // if eStop button pressed
    cutPower();                       // cut power
  } else if(backward.isPressed()) {   // if backward button pressed
    moveBackward(100);                // move backward
  }

  // Don't forget to call update() or else your objects won't show up
  forward.update();
  backward.update();
  eStop.update();

  // A short delay is necessary to give Andee time to communicate with the smartphone
  delay(500); 
}



