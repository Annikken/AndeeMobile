/*
AndeeMobile.h - Annikken Andee Mobile Library for Arduino
Annikken Pte Ltd
Author: Muhammad Hasif

The Annikken Andee Mobile Library is to allow users to control the AndeeMobile using a simplified API

This library is free software
*/

/*
 * FunduMoto Motor Shield
 * Pin 10 is Motor A Speed Control(PWM required)
 * Pin 11 is Motor B Speed Control(PWM required)
 * Pin 12 is Motor A Direction Control(LOW is one side|HIGH is the other)
 * Pin 13 is Motor B Direction Control(LOW is one side|HIGH is the other)
*/

/*
PIN DEFINITIONS
*/


/* #define headLightPin A1
#define tailLightPin 5
#define carDoorPin  A5
#define buzzerPin 4
#define motorFBSpeedPin 10
#define motorFBDirectionPin 3
#define motorLRPin 9
#define motorLRDirectionPin 6  */


#define headLightPin 5
#define tailLightPin A4
#define carDoorPin  A5
#define buzzerPin 4
#define motorFBSpeedPin 10
#define motorFBDirectionPin 3
#define motorLRPin A2
#define motorLRDirectionPin A3


/*
Function Definitions
*/
#define OFF 0
#define ON 1

/*
Functions
*/
class AndeeMobileClass
{
	public:	
	AndeeMobileClass();
	
	//This function has to be used everytime a new sketch for the Andee Mobile is made. This function initialises the pins used for the Andee Mobile
	void setup();

	//This function moves the Andee Mobile forward at a specified speed. Speed is from 0 to 255.
	void moveForward(int);

	//This function moves the Andee Mobile backward at a specified speed. Speed is from 0 to 255.
	void moveBackward(int);

	//This function turns the wheels to make the Andee Mobile to turn left
	void turnLeft();

	//This function turns the wheels to make the Andee Mobile to turn right
	void turnRight();

	//This function turns the wheels back forward so that the Andee Mobile can continue moving forward or backward
	void straight();

	//Turns on/off the headlights. Input is ON or OFF
	void headlight(int);

	//Turns on/off the taillights. Input is ON or OFF
	void taillight(int);

	//Turns on/off the Andee Mobile horn. Input is ON or OFF
	void carHorn(int);

	//Turns the car door motor on/off. Needs around 3 to 4 seconds to get the door open or close. Input is ON or OFF
	void carDoor(int);

	//Turns off all pins used for the Andee Mobile
	void cutPower();
};
extern AndeeMobileClass AndeeMobile;



	


