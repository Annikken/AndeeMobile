/************************************************************
  [Annikken Andee with AndeeMobile]
  ================
  Experiment 1 example

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
AndeeHelper steerLeft;
AndeeHelper steerRight;
AndeeHelper steerstraight;

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

  steerstraight.setId(0);                 // Assign a unique ID number
  steerstraight.setType(BUTTON_IN);       // Defines object as a button
  steerstraight.setCoord(30, 21, 40, 20); // Set the location and size of your button
  steerstraight.setTitle("straight");     // Set button title
  steerstraight.requireAck(false);        // Disable require acknowledgement 

  steerLeft.setId(1);                     // Assign a unique ID number
  steerLeft.setType(BUTTON_IN);           // Defines object as a button
  steerLeft.setCoord(9, 42, 40, 20);      // Set the location and size of your button
  steerLeft.setTitle("Left");             // Set button title
  steerLeft.requireAck(false);            // Disable require acknowledgement 

  steerRight.setId(2);                    // Assign a unique ID number
  steerRight.setType(BUTTON_IN);          // Defines object as a button
  steerRight.setCoord(50, 42, 40, 20);    // Set the location and size of your button
  steerRight.setTitle("Right");           // Set button title
  steerRight.requireAck(false);           // Disable require acknowledgement 
}

// Arduino will run instructions here repeatedly until you power it off.
void loop()
{
  /* 
   *  Call update() to refresh the display on your screen
   *  If you forgot to call update(), your object won't appear 
   */
  // works similar toggle button
  if(steerstraight.isPressed()) {     // if button is pressed
    straight();                       // call AndeeMobile to steer it's wheels straight
  } else if(steerLeft.isPressed()) {  // if button is pressed
    turnLeft();                       // call AndeeMobile to steer it's wheels left
  } else if(steerRight.isPressed()) { // if button is pressed
    turnRight();                      // call AndeeMobile to steer it's wheels right
  }
  
  // Don't forget to call update() or else your objects won't show up
  steerLeft.update();                
  steerRight.update();                
  steerstraight.update();             

  // A short delay is necessary to give Andee time to communicate with the smartphone
  delay(500); 
}



