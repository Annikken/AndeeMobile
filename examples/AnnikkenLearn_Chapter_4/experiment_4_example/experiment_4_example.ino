/************************************************************
  [Annikken Andee with AndeeMobile]
  ================
  Experiment 4 example

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
AndeeHelper steerLeft;
AndeeHelper steerRight;

bool connectionState = false;
bool makeUI = true;

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

  forward.setId(0);                       // Assign a unique ID number
  forward.setType(BUTTON_IN);             // Defines object as a button
  forward.setCoord(35, 21, 30, 20);       // Set the location and size of your button
  forward.setTitle("Forward");            // Set button title
  forward.requireAck(false);              // Disable require acknowledgement 

  eStop.setId(1);                         // Assign a unique ID number
  eStop.setType(BUTTON_IN);               // Defines object as a button
  eStop.setCoord(35, 42, 30, 20);         // Set the location and size of your button
  eStop.setTitle("Stop");                 // Set button title
  eStop.requireAck(false);                // Disable require acknowledgement 

  backward.setId(2);                      // Assign a unique ID number
  backward.setType(BUTTON_IN);            // Defines object as a button
  backward.setCoord(35, 63, 30, 20);      // Set the location and size of your button
  backward.setTitle("Backward");          // Set button title
  backward.requireAck(false);             // Disable require acknowledgement 

  steerLeft.setId(3);                     // Assign a unique ID number
  steerLeft.setType(BUTTON_IN);           // Defines object as a button
  steerLeft.setCoord(4, 42, 30, 20);      // Set the location and size of your button
  steerLeft.setTitle("Left");             // Set button title
  steerLeft.requireAck(false);            // Disable require acknowledgement 

  steerRight.setId(4);                    // Assign a unique ID number
  steerRight.setType(BUTTON_IN);          // Defines object as a button
  steerRight.setCoord(66, 42, 30, 20);    // Set the location and size of your button
  steerRight.setTitle("Right");           // Set button title
  steerRight.requireAck(false);           // Disable require acknowledgement 
}

// Arduino will run instructions here repeatedly until you power it off.
void loop() {
  // put your main code here, to run repeatedly:
  
  // load the UI once upon connect
  loadUIOnConnect();
 
  if(forward.isPressed() == true) {           // if forward button pressed
    straight();                               // straighten front wheels
    moveForward(100);                         // move forward
  } else if(eStop.isPressed() == true) {      // if eStop pressed
    cutPower();                               // cut power              
  } else if(backward.isPressed() == true) {   // if backward button pressed
    straight();                               // straighten front wheels
    moveBackward(100);                        // move backward     
  } if(steerLeft.isPressed() == true) {       // if steerLeft button is pressed
    turnLeft();                               // steer front wheels to the left
  } else if(steerRight.isPressed() == true) { // if steerRight button is pressed
    turnRight();                              // steer front wheels to the right
  }
}

void loadUIOnConnect() {
  if(connectionState == false) {              // if connection state is false, connection is incomplete
    if(Andee.isConnected() == true) {         // if Andee is connected
      if(makeUI == true) {                    // if makeUI is required
        drawUI();                             // draw UI onto the application
        makeUI = false;                       // set makeUI not required
        connectionState = true;               // set connection state to true, connection completed
      }
    }
  }
}

void drawUI() {
  // A short delay is necessary to give Andee time to communicate with the smartphone
  delay(1000);
  
  // Don't forget to call update() or else your objects won't show up
  forward.update();
  backward.update();
  steerRight.update();
  steerLeft.update();
  eStop.update(); 
}



