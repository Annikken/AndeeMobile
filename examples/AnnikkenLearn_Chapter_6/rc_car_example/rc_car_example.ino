/************************************************************
  [Annikken Andee with AndeeMobile]
  ================
  rc(remote controlled) car example

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

AndeeHelper forward;
AndeeHelper reverse;
AndeeHelper left;
AndeeHelper right;
AndeeHelper eStop;

AndeeHelper driftL; //left drift button
AndeeHelper driftR; //right drift button

AndeeHelper speedSlider;

// enumerator used as a state to track the movement state of the AndeeMobile
enum {
  INACTIVE,
  FORWARD,
  REVERSE
};



int stateConnected = 0;       // default connection state
int makeUI = 1;               // default ui state
int movementState = INACTIVE; // default movement state 
int movementSpeed = 0;        // default movement speed

void setup() {
  Serial.begin(9600); // print out log
  Andee.begin();      // Setup communication between Andee and Arduino
  Andee.clear();      // Clear the screen of any previous displays
  setupScreen();      // Define object types and their appearance
  AndeeMobileSetup();
}

void loop() {
  // put your main code here, to run repeatedly:

  // load the UI once upon connect
  loadUIOnConnect();

  if (forward.isPressed()) {      // if forward button pressed
    Serial.println("forward");    // print 'forward' in logging
    straight();                   // straighten front wheels
    movementState = FORWARD;      // change movementState to FORWARD
  }

  if (reverse.isPressed()) {      // if reverse button pressed
    Serial.println("reverse");    // print 'reverse' in logging
    straight();                   // straighten wheels
    movementState = REVERSE;      // change movementState to BACKWARD
  }

  if (left.isPressed()) {         // if left button pressed
    Serial.println("left");       // print 'left' in logging
     turnLeft();                  // steer front wheels to the left
  }

  if (right.isPressed()) {        // if right button pressed
    Serial.println("right");      // print 'right' in logging
    turnRight();                  // steer front wheels to the right
  }
  
  if (eStop.isPressed() && movementState == FORWARD)  { // if eStop button pressed and movementState equal FORWARD
    Serial.println("stop");                             // print 'stop' in logging
    straight();                                         // straighten front wheels
    taillight(ON);                                      // switch taillight on
    moveBackward(125);                                  // move backward
    delay(500);                                         // move backward for 0.5s
    cutPower();                                         // cut power
    taillight(OFF);                                     // switch taillight off
    movementState = INACTIVE;                           // change movementState to INACTIVE
  }

  if (eStop.isPressed() && movementState == REVERSE) {  // if eStop button pressed and movementState equal BACKWARD
    Serial.println("stop");                             // print 'stop' in logging
    straight();                                         // straighten front wheels
    taillight(ON);                                      // switch taillight on
    moveForward(125);                                   // move backward
    delay(500);                                         // move backward for 0.5s
    cutPower();                                         // cut power
    taillight(OFF);                                     // switch taillight off
    movementState = INACTIVE;                           // change movementState to INACTIVE
  }

  if (driftL.isPressed()) {                             // driftL button pressed
    driftLeft();                                        // perform left drift
  } 

  if (driftR.isPressed()) {                             // ddriftR button pressed
    driftRight();                                       // perform right drift
  }
  
  if(speedSlider.getSliderValue(&movementSpeed, INT)) {         // get speedSlider value and check if it's not null
    Serial.print("slider value: ");                             // print 'slider value:' in log
    Serial.println(movementSpeed);                              // print movementSpeed value in the nextline on log
    movementSpeed = (movementSpeed/100.0) * 225;                // convert moveSpeed value to the range that AndeeMobile is using
    movementSpeed = movementSpeed > 255 ? 255 : movementSpeed;  // check if movementSpeed vaule is the speed range
  }

  if (movementState == FORWARD) {                               // if movementState equal to FORWARD
    moveForward(movementSpeed);                                 // move forward base on mvementSpeed value
  } else if (movementState == REVERSE) {                        // if movementState equal to REVERSE
    moveBackward(movementSpeed);                                // move backward base on movementSpeed value
  }
}

void driftLeft() {                                              
  if (movementState == INACTIVE) { return; }                    // if movementState equal INACTIVE, do nothing
  straight();                                                   // straighten front wheels
  if (movementState == FORWARD) { moveForward(255); }           // if movementStat equal FORWARD, move forward at max speed
  else { moveBackward(255); }                                   // else if equal BACKWARD, move backward at max speed
  turnLeft();                                                   // steer front wheel to the left
  delay(200);                                                   // hold left turn position for 0.2s
  if (movementState == FORWARD) { moveBackward(255); }          // if movementState equal FORWARD, move backward at max speed
  else { moveForward(255); }                                    // else if equal BACKWARD, move forward at max speed
  delay(600);                                                   // hold left turn position for 0.6s
  straight();                                                   // straighten front wheels
}

void driftRight() {
  if (movementState == INACTIVE) { return; }                    // if movementState equal INACTIVE, do nothing
  straight();                                                   // straighten front wheels
  if (movementState == FORWARD) { moveForward(255); }           // if movementStat equal FORWARD, move forward at max speed
  else { moveBackward(255); }                                   // else if equal BACKWARD, move backward at max speed
  turnRight();                                                  // steer front wheel to the right
  delay(200);                                                   // hold right turn position for 0.2s
  if (movementState == FORWARD) { moveBackward(255); }          // if movementState equal FORWARD, move backward at max speed
  else { moveForward(255); }                                    // else if equal BACKWARD, move forward at max speed
  delay(600);                                                   // hold left turn position for 0.6s
  straight();                                                   // straighten front wheels
}

void loadUIOnConnect() {                                        
  if (stateConnected == 0) {                                    // if connection state is false, connection is uncomplete
    if (Andee.isConnected() == 1)  {                            // if Andee is connected  
      if (makeUI == 1)  {                                       // if makeUI is required
        drawScreen();                                           // draw UI onto the application
        makeUI = 0;                                             // set makeUI not required
        stateConnected = 1;                                     // set connection state to true, connection completed
      }
    }
  }
}

void setupScreen() {

  forward.setId(0);                               // Assign a unique ID number
  forward.setType(BUTTON_IN);                     // Defines object as a button
  forward.setCoord(30, 1, 40, 20);                // Set the location and size of your button
  forward.requireAck(false);                      // Disable require acknowledgement 
  forward.setTitle("Forward");                    // Set button title
  forward.setColor("ff27ae60");                   // set button background color
  forward.setTextColor(WHITE);                    // set button text color

  reverse.setId(1);                               // Assign a unique ID number
  reverse.setType(BUTTON_IN);                     // Defines object as a button
  reverse.setCoord(30, 43, 40, 20);               // Set the location and size of your button
  reverse.requireAck(false);                      // Disable require acknowledgement 
  reverse.setTitle("Reverse");                    // Set button title
  reverse.setColor("ff27ae60");                   // set button background color
  
  left.setId(2);                                  // Assign a unique ID number
  left.setType(BUTTON_IN);                        // Defines object as a button
  left.setCoord(0, 22, 29, 20);                   // Set the location and size of your button
  left.requireAck(false);                         // Disable require acknowledgement 
  left.setTitle("Left");                          // Set button title
  left.setColor("ff1abc9c");                      // set button background color

  right.setId(3);                                 // Assign a unique ID number
  right.setType(BUTTON_IN);                       // Defines object as a button
  right.setCoord(71, 22, 29, 20);                 // Set the location and size of your button
  right.requireAck(false);                        // Disable require acknowledgement 
  right.setTitle("Right");                        // Set button title
  right.setColor("ff1abc9c");                     // set button background color

  eStop.setId(4);                                 // Assign a unique ID number
  eStop.setType(BUTTON_IN);                       // Defines object as a button
  eStop.setCoord(30, 22, 40, 20);                 // Set the location and size of your button
  eStop.requireAck(false);                        // Disable require acknowledgement 
  eStop.setTitle("Stop");                         // Set button title
  eStop.setColor("ffe74c3c");                     // set button background color

  speedSlider.setId(5);                           // Assign a unique ID number
  speedSlider.setType(SLIDER_IN);                 // Defines object as a slider
  speedSlider.setCoord(0, 64, 100, 20);           // Set the location and size of your slider
  speedSlider.setTitle("Speed");                  // Set slider title
  speedSlider.setSliderMinMax(0, 100);            // Set min to 0, max to 100
  speedSlider.setSliderNumIntervals(101);         // Set number of intervals to 101 for slider
  speedSlider.setSliderReportMode(ON_FINGER_UP);  // Set reporting mode to ON_FINGER_UP
  speedSlider.setActiveColor("ffc0392b");         // Set ActiveColor ffc0392b
  speedSlider.setBaseColor("ffe74c3c");           // Set BaseColor ffe74c3c
  speedSlider.moveSliderToValue(0);               // Move slider thumb to position 0

  driftL.setId(6);                                // Assign a unique ID number
  driftL.setType(BUTTON_IN);                      // Defines object as a button
  driftL.setCoord(1, 84, 49, 16);                 // Set the location and size of your button
  driftL.requireAck(false);                       // Disable require acknowledgement 
  driftL.setTitle("Drift Left");                  // Set button title
  driftL.setColor("ff9b59b6");                    // set button background color
  
  driftR.setId(7);                                // Assign a unique ID number
  driftR.setType(BUTTON_IN);                      // Defines object as a button
  driftR.setCoord(50, 84, 49, 16);                // Set the location and size of your button
  driftR.requireAck(false);                       // Disable require acknowledgement 
  driftR.setTitle("Drift Right");                 // Set button title
  driftR.setColor("ff9b59b6");                    // set button background color
}

void drawScreen() {
  // update ui
  forward.update();
  reverse.update();
  
  // A short delay is necessary to give Andee time to communicate with the smartphone
  delay(100);

  // update ui
  left.update();
  right.update();
  
  // A short delay is necessary to give Andee time to communicate with the smartphone
  delay(100);

  // update ui
  eStop.update();
  speedSlider.update();
  
  // A short delay is necessary to give Andee time to communicate with the smartphone
  delay(100);

  // update ui
  driftL.update();
  driftR.update();
}

