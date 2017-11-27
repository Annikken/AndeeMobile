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

unsigned long AndeeMobileGlobalTime = 0;

/*
Functions
*/
void AndeeMobileSetup()
{
	AndeeMobileGlobalTime = millis();
	
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

void moveForward(int speed)//speed is from 0 to 255,time is in milliseconds
{
	analogWrite(motorFBSpeedPin,speed);
	digitalWrite(motorFBDirectionPin,LOW);
	//TODO time	
}

void moveBackward(int speed)
{
	analogWrite(motorFBSpeedPin,speed);
	digitalWrite(motorFBDirectionPin,HIGH);
	//TODO time
}

void turnLeft()
{
	digitalWrite(motorLRPin,HIGH);
	digitalWrite(motorLRDirectionPin,LOW);
}

void turnRight()
{
	digitalWrite(motorLRPin,HIGH);
	digitalWrite(motorLRDirectionPin,HIGH);
}

void Straight()
{
	digitalWrite(motorLRPin,LOW);
	digitalWrite(motorLRDirectionPin,LOW);
}

void headlight(int mode)
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

void taillight(int mode)
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

void carHorn(int mode)
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

void carDoor(int mode)
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

void cutPower()
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

