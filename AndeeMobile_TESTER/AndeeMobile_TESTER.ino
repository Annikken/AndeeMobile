#include <SPI.h>
#include <Andee.h>
#include <AndeeMobile.h>

AndeeHelper Front;
AndeeHelper Back;
AndeeHelper Left;
AndeeHelper Right;
AndeeHelper Stop;
AndeeHelper carDoor;
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
  Andee.clear();  // Clear the screen of any previous displays
  setInitialData();  // Define object types and their appearance
  
  AndeeMobile.setup();

  makeUI = 1;
}

void loop() {  
  Andee.checkButtons();
  if (stateConnected == 0)
  {
    if (Andee.isConnected() == 1) 
    {
      if (makeUI == 1) 
      {
        Front.update();
        Back.update();
        Left.update();
        Right.update();
        Stop.update();
        carDoor.update();
        Headlights.update();
        Horn.update();
        makeUI = 0;
        stateConnected = 1;
      }
    }
  }

  if (Front.isPressed2()) {
    stateMoving = FORWARD;
    AndeeMobile.straight();
    AndeeMobile.moveForward(150);
  }

  if (Back.isPressed2()) {
    AndeeMobile.straight();
    AndeeMobile.moveBackward(150);
  }

  if (Left.isPressed2()) {
    AndeeMobile.turnLeft();
  }

  if (Right.isPressed2()) {
    AndeeMobile.turnRight();
  }

  if (Stop.isPressed2()) {
    AndeeMobile.cutPower();
    stateMoving = STOPPED;
    
    Serial.println("stopping");
  }

  if (Horn.isPressed2()) {
    AndeeMobile.carHorn(HIGH);
    delay(400);
    AndeeMobile.carHorn(LOW);
  }

  if (Headlights.isPressed2()) {
    if(stateLight == 0)
    {
      AndeeMobile.headlight(ON);
      AndeeMobile.taillight(ON);
      stateLight = 1;
    }
    else
    {
      AndeeMobile.headlight(OFF);
      AndeeMobile.taillight(OFF);
      stateLight = 0;
    }    
  }

  if(carDoor.isPressed2())
  {
    AndeeMobile.carDoor(ON);
    delay(4000);
    AndeeMobile.carDoor(OFF);
  }   
  delay(100);
}

void setInitialData()
{
  Front.setId(4);
  Front.setType(BUTTON_IN);
  Front.setCoord(5, 5, 200, 150);
  Front.requireAck(false);
  Front.setTitle("Forward");

  Back.setId(5);
  Back.setType(BUTTON_IN);
  Back.setCoord(210, 5, 200, 150);
  Back.requireAck(false);
  Back.setTitle("Backward");
  
  Left.setId(0);
  Left.setType(BUTTON_IN);
  Left.setCoord(415, 5, 200, 150);
  Left.requireAck(false);
  Left.setTitle("Left");

  Right.setId(1);
  Right.setType(BUTTON_IN);
  Right.setCoord(620, 5 , 200, 150);
  Right.requireAck(false);
  Right.setTitle("Right");

  Stop.setId(2);
  Stop.setType(BUTTON_IN);
  Stop.setCoord(5, 160, 200, 150);
  Stop.requireAck(false);
  Stop.setTitle("Stop");

  carDoor.setId(3);
  carDoor.setType(BUTTON_IN);
  carDoor.setCoord(210, 160, 200, 150);
  carDoor.requireAck(false);
  carDoor.setTitle("Open/Close Door");

  Headlights.setId(6);
  Headlights.setType(BUTTON_IN);
  Headlights.setCoord(415, 160, 200, 150);
  Headlights.requireAck(false);
  Headlights.setTitle("Lights");

  Horn.setId(7);
  Horn.setType(BUTTON_IN);
  Horn.setCoord(620, 160, 200, 150);
  Horn.requireAck(false);
  Horn.setTitle("Horn");
}

