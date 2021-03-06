/************************************************************
  [Annikken Andee with AndeeMobile]
  ================
  Add data display example

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
  button.setId(0);                              // Assign a unique ID number
  button.setType(BUTTON_IN);                    // Defines object as a button
  button.setCoord(5, 20, 90, 20);               // Set the location and size of your button
  button.setTitle("Press me!");                 // Set button title
  button.requireAck(false);                     // Disable require acknowledgement 
  
  dataDisplay.setId(1);                         // Assign a unique ID number
  dataDisplay.setType(DATA_OUT);                // Defines object as a data display
  dataDisplay.setCoord(5, 41, 90, 20);          // Set the location and size of your data display
  dataDisplay.setTitle("Read the data below!"); // Set data display title
  dataDisplay.setData("Hello!");                // Set data display data
}

void loop() {
  // put your main code here, to run repeatedly:

  // Don't forget to call update() or else your objects won't show up
  button.update();      
  dataDisplay.update();

  // Always leave a short delay for Bluetooth communication
  delay(500);           
}


 
