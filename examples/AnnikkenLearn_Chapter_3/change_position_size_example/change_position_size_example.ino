/************************************************************
  [Annikken Andee with AndeeMobile]
  ================

  Check out our Resources section for more information and 
  ideas on what you can do with the Annikken Andee or the 
  AndeeMobile!
  https://annikken.gitbooks.io/annikken-andee/content/

  Contact us at andee@annikken.com if there are 
  bugs in this sketch or if you need help with either the 
  Annikken Andee or AndeeMobile
  
************************************************************/

//libraries that we required
#include <SPI.h>
#include <Andee.h>

//AndeeHelper object called button
AndeeHelper button;
AndeeHelper dataDisplay;
AndeeHelper slider;

void setup() {
  // put your setup code here, to run once:
  Andee.begin();    // Setup communication between Annikken Andee and Arduino
  Andee.clear();    // Clear the screen of any previous displays
  setInitialData(); // Define object types and their appearance
}

// This is the function meant to define the types and the apperance of
// all the objects on your smartphone
void setInitialData()
{
  button.setId(0);                                  // Assign a unique ID number
  button.setType(BUTTON_IN);                        // Defines object as a button
  button.setCoord(15, 45, 20, 15);                  // Set the location and size of your button
  button.setTitle("Press me!");                     // Set button title
  button.requireAck(false);                         // Disable require acknowledgement 

  dataDisplay.setId(1);                             // Assign a unique ID number
  dataDisplay.setType(DATA_OUT);                    // Defines object as a data display
  dataDisplay.setCoord(55, 32, 30, 20);             // Set the location and size of your data display
  dataDisplay.setTitle("Read the data below!");     // Set data display title
  dataDisplay.setData("Hello!");                    // set data display data
  
  slider.setId(2);                                  // Assign a unique ID number
  slider.setType(SLIDER_IN);                        // Defines object as a slider
  slider.setCoord(5, 63, 90, 20);                   // Set the location and size of your slider
  slider.setTitle("Slide me!");                     // Set slider title
  slider.setSliderMinMax(0, 100, 2);                // Display 2 decimal places
  slider.setSliderInitialValue(0);                  // Set slider inital thumb position to 0
  slider.setSliderNumIntervals(0);                  // Set intervals to 0 for slider
}

void loop() {
  // put your main code here, to run repeatedly:

  // Don't forget to call update() or else your objects won't show up
  button.update(); 
  dataDisplay.update();
  slider.update();

  // Always leave a short delay for Bluetooth communication
  delay(500); 
}


 
