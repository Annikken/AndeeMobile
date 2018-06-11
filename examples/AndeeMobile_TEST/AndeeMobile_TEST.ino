#include <SPI.h>
#include <Andee.h>
#include <AndeeMobile.h>

AndeeHelper Front;
AndeeHelper Back;
AndeeHelper Left;
AndeeHelper Right;
AndeeHelper Stop;
AndeeHelper carDoorButton;
AndeeHelper Headlights;
AndeeHelper Horn;

enum{
  FAST,
  SLOW,
  FORWARD,
  BACKWARD,
  STOPPED,
  LEFT,
  STRAIGHT,
  RIGHT
};

int stateConnected = 0;
int makeUI = 1;
int stateMoving = STOPPED;
int stateLight = 0;

void setup() {
  Serial.begin(9600);
  
  Andee.begin();  // Setup communication between Andee and Arduino
  Andee.setName("AndeeMobile 01");
  Andee.clear();  // Clear the screen of any previous displays
  setInitialData();  // Define object types and their appearance
  
  AndeeMobileSetup();

  makeUI = 1;
}

void loop() {  
  if (stateConnected == 0)
  {
    if (Andee.isConnected() == 1) 
    {
      if (makeUI == 1) 
      {
        for(int b = 0; b < 3;b++)
        {
          Front.update();
          Back.update();
          Left.update();
          Right.update();
          Stop.update();
          carDoorButton.update();
          Headlights.update();
          Horn.update();
          makeUI = 0;
          stateConnected = 1;
        }
      }
    }
  }

  if (Front.isPressed()) {
    stateMoving = FORWARD;
    straight();
    moveForward(150);
  }

  if (Back.isPressed()) {
    straight();
    moveBackward(150);
  }

  if (Left.isPressed()) {
    turnLeft();
  }

  if (Right.isPressed()) {
    turnRight();
  }

  if (Stop.isPressed()) {
    cutPower();
    stateMoving = STOPPED;
    
    Serial.println("stopping");
  }

  if (Horn.isPressed()) {
    carHorn(HIGH);
    delay(400);
    carHorn(LOW);
  }

  if (Headlights.isPressed()) {
    if(stateLight == 0)
    {
      headlight(ON);
      taillight(ON);
      stateLight = 1;
    }
    else
    {
      headlight(OFF);
      taillight(OFF);
      stateLight = 0;
    }    
  }

  if(carDoorButton.isPressed())
  {
    carDoor(ON);
    delay(4000);
    carDoor(OFF);
  }   
  delay(100);
}

void setInitialData()
{
  Front.setId(4);
  Front.setType(BUTTON_IN);
  Front.setLocation(0, 1, ONE_THIRD);
  Front.requireAck(false);
  Front.setTitle("Forward");
  Front.setColor(DARK_GREEN);

  Back.setId(5);
  Back.setType(BUTTON_IN);
  Back.setLocation(2, 1, ONE_THIRD);
  Back.requireAck(false);
  Back.setTitle("Backward");
  Back.setColor(DARK_GREEN);
  
  Left.setId(0);
  Left.setType(BUTTON_IN);
  Left.setLocation(1, 0, HALF);
  Left.requireAck(false);
  Left.setTitle("Left");
  Left.setColor(DARK_BLUE);

  Right.setId(1);
  Right.setType(BUTTON_IN);
  Right.setLocation(1, 1, HALF);
  Right.requireAck(false);
  Right.setTitle("Right");
  Right.setColor(DARK_BLUE);

  Stop.setId(2);
  Stop.setType(BUTTON_IN);
  Stop.setLocation(3, 0, FULL);
  Stop.requireAck(false);
  Stop.setTitle("Stop");
  Stop.setColor(RED);

  carDoorButton.setId(3);
  carDoorButton.setType(CIRCLE_BUTTON);
  carDoorButton.setLocation(2, 0, ONE_THIRD);
  carDoorButton.requireAck(false);
  carDoorButton.setTitle("Open/Close Door");
  carDoorButton.setColor(DARK_ORANGE);

  Headlights.setId(6);
  Headlights.setType(CIRCLE_BUTTON);
  Headlights.setLocation(0, 0, ONE_THIRD);
  Headlights.requireAck(false);
  Headlights.setTitle("Lights");
  Headlights.setColor(GOLD);

  Horn.setId(7);
  Horn.setType(CIRCLE_BUTTON);
  Horn.setLocation(0, 2, ONE_THIRD);
  Horn.requireAck(false);
  Horn.setTitle("Horn");
  Horn.setColor(PURPLE);
}

