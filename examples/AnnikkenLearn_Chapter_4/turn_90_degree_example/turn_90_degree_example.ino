/************************************************************
  [Annikken Andee with AndeeMobile]
  ================
  Turn 90 degree example

  Check out our Resources section for more information and 
  ideas on what you can do with the Annikken Andee or the 
  AndeeMobile!
  http://resources.annikken.com

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

void setup() {
  // put your setup code here, to run once:
  Andee.begin();      // Setup communication between Annikken Andee and Arduino
  Andee.clear();      // Clear the screen of any previous displays
  setInitialData();   // Define object types and their appearance
  AndeeMobileSetup(); // Setup code for AndeeMobile
}

void setInitialData() {  
  startButton.setId(0);                   // Assign a unique ID number
  startButton.setType(BUTTON_IN);         // Defines object as a button
  startButton.setCoord(30, 21, 40, 20);   // Set the location and size of your button
  startButton.setTitle("Start");          // Set button title
  startButton.requireAck(false);          // Disable require acknowledgement 
}

void loop() {
  // put your main code here, to run repeatedly:
  startButton.update(); // update widget
  
  if(startButton.isPressed()) {
    indicateStart();    // execute indicateStart() method
    leftAngleTurn();    // execute leftAngleTurn() method
    brake();            // execute brake() method
    indicateStop();     // execute indicateStop() method
    startButton.ack();  // execute ack() method to acknowledge button isPressed() to the application
  }
}

void indicateStart() {  // show headlight for 1 sec before moving off
  headlight(ON);        // turn on headlight 
  delay(1000);          // delay for 1000 ms/1 s, headlight will remain on for 1000 ms
  headlight(OFF);       // turn on headlight
}

void indicateStop() {   // show taillight for 1 sec before complete stop
  taillight(ON);        // turn on taillight
  delay(1000);          // delay for 1000 ms/1 s, taillight will remain on for 1000 ms
  taillight(OFF);       // turn off taillight
}

void leftAngleTurn() {
  moveForward(255);     // move forward at max speed
  delay(500);           // delay for 500 ms hence Andeemobile will travel forward for 500 ms
  turnLeft();           // steer front wheel to the left
  delay(1000);          // delay for 1000 ms/1 s hence Andeemobile will turn for 1000 ms
  straight();           // straighten front wheel
}

void brake() {
  moveBackward(255);    // move backward at max speed
  delay(500);           // delay for 500 ms hence Andeemobile will travel backward for 500 ms
  cutPower();           // cut power
}

