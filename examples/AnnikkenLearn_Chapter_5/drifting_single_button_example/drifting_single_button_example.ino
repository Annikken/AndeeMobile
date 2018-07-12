/************************************************************
  [Annikken Andee with AndeeMobile]
  ================
  drifting single button example

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

AndeeHelper startButton;

void setup()
{
  Andee.begin();        // Setup communication between Annikken Andee and Arduino
  Andee.clear();        // Clear the screen of any previous displays
  setInitialData();     // Define object types and their appearance
  AndeeMobileSetup();   // Setup code for AndeeMobile
}

void setInitialData()
{
  startButton.setId(0);                   // Assign a unique ID number
  startButton.setType(BUTTON_IN);         // Defines object as a button
  startButton.setCoord(35, 21, 30, 20);   // Set the location and size of your button
  startButton.setTitle("Start");          // Set button title
  startButton.requireAck(false);          // Disable require acknowledgement 
}

void loop() {
  // put your main code here, to run repeatedly:
  startButton.update();           // update widget
  
  if(startButton.isPressed()) {   // if startButton pressed
    straight();                   // straighten front wheels
    moveForward(255);             // move forward at max speed
    delay(1500);                  // move forward for 1.5s
    turnLeft();                   // steer front wheels to left to make a left turn
    delay(500);                   // turn left for 0.5s
    moveBackward(255);            // move backward at max speed 
    delay(400);                   // move backward for 0.4s
    moveForward(255);             // move forward at max speed
    delay(400);                   // move forward for 0.4s
    cutPower();                   // cut power
  }
}



