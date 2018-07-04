void inputScreen() {
  if(forwardTimingInput.isPressed()) {                  // if forwardTimingInput button pressed
    memset(userInput,0x00,5);                           // memset(address of memory to fill, value to be filled, size to fill)
    forwardTimingInput.ack();                           // send acknowledgement to Andee
    forwardTimingInput.getKeyboardMessage(userInput);   // get message keyed in by user
    tempValue = atoi(userInput);                        // convert string to integer
    if(tempValue > 99)                                  // making sure value is less than 100
    {
      maxForwardValue = 99;
    }
    else if(tempValue < 1)
    {
      maxForwardValue = 1;
    }
    else
    {
      maxForwardValue = tempValue;
    }   
    moveValueDisplay.setData(maxForwardValue);          // set maxForwardValue to moveValueDisplay data
    moveValueDisplay.update();                          // update moveValueDisplay on Andee
  }
  
  if (idleTimingInput.isPressed()) {                    // if idleTimingInput button pressed
    memset(userInput,0x00,5);                           // memset(address of memory to fill, value to be filled, size to fill)
    idleTimingInput.ack();                              // send acknowledgement to Andee
    idleTimingInput.getKeyboardMessage(userInput);      // get message keyed in by user
    tempValue = atoi(userInput);                        // convert string to integer
    if(tempValue > 99)                                  // making sure value is less than 100
    {
      maxIdleValue = 99;
    }
    else if(tempValue < 1)
    {
      maxIdleValue = 1;
    }
    else
    {
      maxIdleValue = tempValue;
    }   
    idleValueDisplay.setData(maxIdleValue);             // set maxIdleValue to idleValueDisplay data
    idleValueDisplay.update();                          // update idleValueDisplay
  }
  
  if (brakeTimingInput.isPressed()) {                   // if brakeTimingInput button pressed
    memset(userInput,0x00,5);                           // memset(address of memory to fill, value to be filled, size to fill)
    brakeTimingInput.ack();                             // send acknowledgement to Andee
    brakeTimingInput.getKeyboardMessage(userInput);     // get message keyed in by user
    tempValue = atoi(userInput);                        // convert string to integer
    if(tempValue > 99)                                  // making sure value is less than 100
    {
      maxBrakeValue = 99;
    }
    else if(tempValue < 1)
    {
      maxBrakeValue = 1;
    }
    else
    {
      maxBrakeValue = tempValue;
    }   
    brakeValueDisplay.setData(maxBrakeValue);           // set maxIdleValue to brakeValueDisplay data
    brakeValueDisplay.update();                         // update brakeValueDisplay
  }
  
  if (backToMain.isPressed()) {                         // if backToMain button pressed
       changeToMainPage();                              // change to Main Page
       switchUI = 1;
  }
  
  moveValueDisplay.update(30);    // update moveValueDisplay  
  idleValueDisplay.update(30);    // update idleValueDisplay  
  brakeValueDisplay.update(30);   // update brakeValueDisplay
  forwardTimingInput.update(20);  // load forwardTimingInput onto screen
  idleTimingInput.update(20);     // load idleTimingInput onto screen
  brakeTimingInput.update(20);    // load brakeTimingInput onto screen
  backToMain.update(40);          // load backToMain onto screen
}

void changeToMainPage() {
  forwardTimingInput.remove();  // remove forwardTimingInput from screen
  delay(10);
  idleTimingInput.remove();     // remove idleTimingInput from screen
  delay(10);
  brakeTimingInput.remove();    // remove brakeTimingInput from screen
  delay(10);
  backToMain.remove();          // remove backToMain from screen
  delay(10);
  statePage = MAINSCREEN;       // set statePage to MAINPAGE
}

void setupInputUI() {
  forwardTimingInput.setId(8);                             // Assign a unique ID number
  forwardTimingInput.setType(KEYBOARD_IN);                 // Defines object as a keyboard
  forwardTimingInput.setKeyboardType(NUMERIC);             // Set the type of keyboard
  forwardTimingInput.setCoord(1, 20, 98, 18);              // Set the location and size of your keyboard
  forwardTimingInput.setTitle("Set Forward Timing (1-99)");// Set keyboard title
  forwardTimingInput.setColor("FF2A623D");                 // Set keyboard color  
  
  idleTimingInput.setId(9);                              // Assign a unique ID number
  idleTimingInput.setType(KEYBOARD_IN);                  // Defines object as a keyboard
  idleTimingInput.setKeyboardType(NUMERIC);              // Set the type of keyboard
  idleTimingInput.setCoord(1, 40, 98, 18);               // Set the location and size of your keyboard
  idleTimingInput.setTitle("Set Idle Timing (1-99)");    // Set keyboard title
  idleTimingInput.setColor("fff39c12");                  // Set keyboard color

  brakeTimingInput.setId(10);                            // Assign a unique ID number
  brakeTimingInput.setType(KEYBOARD_IN);                 // Defines object as a keyboard
  brakeTimingInput.setKeyboardType(NUMERIC);             // Set the type of keyboard
  brakeTimingInput.setCoord(1, 60, 98, 18);              // Set the location and size of your keyboard
  brakeTimingInput.setTitle("Set Brake Timing (1-99)");  // Set keyboard title
  brakeTimingInput.setColor("ffc0392b");                 // Set keyboard color
  
  backToMain.setId(11);                                 // Assign a unique ID number
  backToMain.setType(BUTTON_IN);                        // Defines object as a button
  backToMain.setCoord(1, 80, 98, 18);                   // Set the location and size of your button
  backToMain.requireAck(false);                         // Disable require acknowledgement 
  backToMain.setTitle("Back To Main");                  // Set keyboard title
  backToMain.setColor("ff3498db");                      // Set keyboard color
}
