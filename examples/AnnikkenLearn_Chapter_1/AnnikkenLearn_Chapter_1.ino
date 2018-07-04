/************************************************************
  [Annikken Andee with AndeeMobile]
  ================
  AndeeMobile Chapter 1

  Contact us at andee@annikken.com if there are 
  bugs in this sketch or if you need help with either the 
  Annikken Andee or AndeeMobile
  
************************************************************/

//libraries that we required
#include <SPI.h>
#include <Andee.h>
#include <AndeeMobile.h>

/*
   PREPROCESSORS
*/
#define FORWARDSPEED 210       
#define REVERSESPEED 210

/*
   Main Page Initialisers
*/
AndeeHelper moveValueDisplay;   // Display the maximum forward timing
AndeeHelper idleValueDisplay;   // Display the maximum glide timing
AndeeHelper brakeValueDisplay;  // Display the maximum brake timing
AndeeHelper changeSettings;     // change to settings screen

AndeeHelper sliderMoveTiming;   // Set the percentage of maximum forward timing
AndeeHelper sliderIdleTiming;   // Set the percentage of maximum glide timing
AndeeHelper sliderBrakeTiming;  // Set the percentage of maximum brake timing
AndeeHelper start;              // start moving

/*
   Input Page Initialisers
*/
AndeeHelper forwardTimingInput; // set the maximum forward timing
AndeeHelper idleTimingInput;    // set the maximum glide timing
AndeeHelper brakeTimingInput;   // set the maximum brakerd timing
AndeeHelper backToMain;         // return to main screen

enum {                          // enum hold a list of named elements that makes it more readable
  MAINSCREEN,                   // MAINPAGE value is 0   
  INPUTSCREEN                   // INPUTPAGE value is 1
};

/*
   Program Vars
*/
int stateConnected = 0;       // stateConnected default value 0
int switchUI = 1;             // switchUI default value 1
int statePage = MAINSCREEN;   // statePage default value MAINPAGE

int maxForwardValue = 10;     // maxForwarValue default value 10
int maxIdleValue = 10;        // maxIdleValue default value 10
int maxBrakeValue = 10;       // maxBrakeValue default value 10
int tempValue = 0;
char userInput[5];            // userInput size of 5

int forwardDelay = 0;         // forwardDelay default 
int reverseDelay = 0;         // reverseDelay default 0
int glideDelay = 0;           // glideDelay default 0

/*
   Main Sketch
*/
void setup() {
  Andee.begin();                    // Setup communication between Andee and Arduino
  Andee.setName("AndeeMobile");     // Set Andee Name
  Andee.clear();                    // Clear the screen of any previous displays
  
  setupMainScreen();                // MainView UI setup
  setupInputUI();                   // SettingView UI setup
  AndeeMobileSetup();               // AndeeMobile setup
}

void loop() {
  // put your main code here, to run repeatedly:
  if(statePage == MAINSCREEN)
  {
    if(switchUI == 1)
    {
      changeToMainPage();
      switchUI = 0;      
    }    
    mainScreen();
  }
  else if(statePage == INPUTSCREEN)
  {
    if(switchUI == 1)
    {
      changeToMoveInputPage();
      switchUI = 0;
    }
    inputScreen();
  }
}



