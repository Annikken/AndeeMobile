/* AndeeMobile.cpp - Annikken Andee Mobile Library for Arduino
Annikken Pte Ltd
Author: Muhammad Hasif

The Annikken Andee Mobile Library is to allow users to control the AndeeMobile using a simplified API

This library is free software
*/
#include <stdlib.h>

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <AndeeMobile.h>


/*
Functions
*/
void AndeeMobileClass::setup()
{	
	pinMode(headLightPin,OUTPUT);
    pinMode(tailLightPin,OUTPUT);
    pinMode(carDoorPin,OUTPUT);
    pinMode(buzzerPin,OUTPUT);
    pinMode(motorFBSpeedPin,OUTPUT);
    pinMode(motorFBDirectionPin,OUTPUT);
    pinMode(motorLRPin,OUTPUT);
    pinMode(motorLRDirectionPin,OUTPUT);
	
	digitalWrite(headLightPin,LOW);
    digitalWrite(tailLightPin,LOW);
    digitalWrite(carDoorPin,LOW);
    digitalWrite(buzzerPin,LOW);
    digitalWrite(motorFBSpeedPin,LOW);
    digitalWrite(motorFBDirectionPin,LOW);
	digitalWrite(motorLRPin,LOW);
	digitalWrite(motorLRDirectionPin,LOW);
}

void AndeeMobileClass::moveForward(int speed)//speed is from 0 to 255,time is in milliseconds
{
	analogWrite(motorFBSpeedPin,speed);
	digitalWrite(motorFBDirectionPin,LOW);
	//TODO time	
}

void AndeeMobileClass::moveBackward(int speed)
{
	analogWrite(motorFBSpeedPin,speed);
	digitalWrite(motorFBDirectionPin,HIGH);
	//TODO time
}

void AndeeMobileClass::turnLeft()
{
	digitalWrite(motorLRPin,HIGH);
	digitalWrite(motorLRDirectionPin,LOW);
}

void AndeeMobileClass::turnRight()
{
	digitalWrite(motorLRPin,HIGH);
	digitalWrite(motorLRDirectionPin,HIGH);
}

void AndeeMobileClass::straight()
{
	digitalWrite(motorLRPin,LOW);
	digitalWrite(motorLRDirectionPin,LOW);
}

void AndeeMobileClass::headlight(int mode)
{
	if(mode == OFF)
	{
		digitalWrite(headLightPin,LOW);
	}
	else
	{
		digitalWrite(headLightPin,HIGH);
	}	
}

void AndeeMobileClass::taillight(int mode)
{
	if(mode == OFF)
	{
		digitalWrite(tailLightPin,LOW);
	}
	else
	{
		digitalWrite(tailLightPin,HIGH);
	}		
}

void AndeeMobileClass::carHorn(int mode)
{
	if(mode == OFF)
	{
		digitalWrite(buzzerPin,LOW);
	}
	else
	{
		digitalWrite(buzzerPin,HIGH);
	}	
}

void AndeeMobileClass::carDoor(int mode)
{
	if(mode == OFF)
	{
		digitalWrite(carDoorPin,LOW);
	}
	else
	{
		digitalWrite(carDoorPin,HIGH);
	}
}

void AndeeMobileClass::cutPower()
{
	digitalWrite(headLightPin,LOW);
	digitalWrite(tailLightPin,LOW);
	digitalWrite(carDoorPin,LOW);
	digitalWrite(buzzerPin,LOW);
	analogWrite(motorFBSpeedPin,0);
	digitalWrite(motorFBDirectionPin,LOW);
	digitalWrite(motorLRPin,LOW);
	digitalWrite(motorLRDirectionPin,LOW);	
}

