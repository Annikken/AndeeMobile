void mainScreen(){
  if (changeSettings.isPressed()) {   // check for button presses
    changeToMoveInputPage();          // change screen to change settings
    switchUI = 1;
  }

  if (start.isPressed()) {            // if start button pressed

    // FORWARD
    headlight(ON);                                          // call AndeeMobile to switch on headlight
    moveForward(FORWARDSPEED);                              // call AndeeMobile to move forward
    sliderMoveTiming.getSliderValue(&forwardDelay, INT);    // get sliderMoveTiming value
    delay((forwardDelay/ 100.0) * maxForwardValue * 1000);  // calaculate the delay base on the percentage value against the maximum value
       
    // GLIDING
    cutPower();                                             // call AndeeMobile to cutpower
    sliderIdleTiming.getSliderValue(&glideDelay, INT);      // get sliderIdleTiming value
    delay((glideDelay/ 100.0) * maxIdleValue * 1000);       // calaculate the delay base on the percentage value against the maximum value
    
    // REVERSE
    taillight(ON);                                          // call AndeeMobile to switch on tailllight
    moveBackward(REVERSESPEED);                             // call AndeeMobile to move backward
    sliderBrakeTiming.getSliderValue(&reverseDelay, INT);   // get sliderIdleTiming value
    delay((reverseDelay/ 100.0) * maxBrakeValue * 1000);    // calaculate the delay base on the percentage value against the maximum value
    
    cutPower();                                             // call AndeeMobile to cutpower
    headlight(OFF);                                         // call AndeeMobile to switch off headlight
    taillight(OFF);                                         // call AndeeMobile to switch off taillight
  }

  moveValueDisplay.update(20);    // update moveValueDisplay  
  idleValueDisplay.update(20);    // update idleValueDisplay  
  brakeValueDisplay.update(30);   // update brakeValueDisplay
  changeSettings.update(30);      // update changeSettings
  sliderMoveTiming.update(40);    // update sliderMoveTiming
  sliderIdleTiming.update(40);    // update sliderIdleTiming
  sliderBrakeTiming.update(50);   // update sliderBrakeTiming
  start.update(50);               // update start
}

void changeToMoveInputPage() {
  sliderMoveTiming.remove();    // remove sliderMoveTiming from screen
  delay(10);
  sliderIdleTiming.remove();    // remove sliderIdleTiming from screen
  delay(10);
  sliderBrakeTiming.remove();   // remove sliderBrakeTiming from screen
  delay(10);
  start.remove();               // remove start from screen
  delay(10);
  changeSettings.remove();
  statePage = INPUTSCREEN;      // set statePage to INPUTPAGE
}

void setupMainScreen() {
  moveValueDisplay.setId(0);                        // Assign a unique ID number
  moveValueDisplay.setType(DATA_OUT_CIRCLE);        // Defines object as a data display
  moveValueDisplay.setCoord(5, 2, 28, 18);          // Set the location and size of your data display
  moveValueDisplay.setTitle("Forward");             // Set data display title
  moveValueDisplay.setData(maxForwardValue);        // Set data display data
  moveValueDisplay.setUnit("Seconds");              // Set data display unit
  moveValueDisplay.setTitleTextColor("ff009696");   // Set data display title text color
  moveValueDisplay.setTextColor(WHITE);             // Set data display text color
  moveValueDisplay.setColor("ff009696");            // Set data display background color 

  idleValueDisplay.setId(1);                        // Assign a unique ID number
  idleValueDisplay.setType(DATA_OUT_CIRCLE);        // Defines object as a data display
  idleValueDisplay.setCoord(30, 2, 28, 18);         // Set the location and size of your data display
  idleValueDisplay.setTitle("Glide");               // Set data display title
  idleValueDisplay.setData(maxIdleValue);           // Set data display data
  idleValueDisplay.setUnit("Seconds");              // Set data display unit
  idleValueDisplay.setTitleTextColor("ffFFBC77");   // Set data display title text color
  idleValueDisplay.setTextColor(WHITE);             // Set data display text color
  idleValueDisplay.setColor("ffFFBC77");            // Set data display background color 

  brakeValueDisplay.setId(2);                       // Assign a unique ID number
  brakeValueDisplay.setType(DATA_OUT_CIRCLE);       // Defines object as a data display
  brakeValueDisplay.setCoord(55, 2, 28, 18);        // Set the location and size of your data display
  brakeValueDisplay.setTitle("Reverse");            // Set data display title
  brakeValueDisplay.setData(maxBrakeValue);         // Set data display data
  brakeValueDisplay.setUnit("Seconds");             // Set data display unit
  brakeValueDisplay.setTitleTextColor("FFe74c3c");  // Set data display title text color
  brakeValueDisplay.setTextColor(WHITE);            // Set data display text color
  brakeValueDisplay.setColor("FFe74c3c");           // Set data display background color 

  changeSettings.setId(3);                          // Assign a unique ID number
  changeSettings.setType(BUTTON_IN);                // Defines object as a button
  changeSettings.setCoord(89, 1, 10, 18);           // Set the location and size of your button
  changeSettings.requireAck(false);                 // Disable require acknowledgement 
  changeSettings.setTitle(">");                     // Set button title
  changeSettings.setColor("ff3498db");              // Set button background color

  sliderMoveTiming.setId(4);                          // Assign a unique ID number
  sliderMoveTiming.setType(SLIDER_IN);                // Defines object as a slider
  sliderMoveTiming.setCoord(1, 20, 98, 18);           // Set the location and size of your slider 
  sliderMoveTiming.setTitle("Forward Timing (%)");    // Set slider title
  sliderMoveTiming.setSliderMinMax(0, 100);           // Set slider min and max value
  sliderMoveTiming.setSliderNumIntervals(100);        // Set slider interval
  sliderMoveTiming.setSliderReportMode(ON_FINGER_UP); // Set slider reporting mode
  sliderMoveTiming.setActiveColor("FF2A623D");        // Set slider active color
  sliderMoveTiming.setBaseColor("FF1abc9c");          // Set slider base color

  sliderIdleTiming.setId(5);                          // Assign a unique ID number
  sliderIdleTiming.setType(SLIDER_IN);                // Defines object as a slider
  sliderIdleTiming.setCoord(1, 40, 98, 18);           // Set the location and size of your slider 
  sliderIdleTiming.setTitle("Glide Timing (%)");      // Set slider title
  sliderIdleTiming.setSliderMinMax(0, 100);           // Set slider min and max value
  sliderIdleTiming.setSliderNumIntervals(100);        // Set slider interval
  sliderIdleTiming.setSliderReportMode(ON_FINGER_UP); // Set slider reporting mode
  sliderIdleTiming.setActiveColor("fff39c12");        // Set slider active color
  sliderIdleTiming.setBaseColor("fff1c40f");          // Set slider base color
  
  sliderBrakeTiming.setId(6);                         // Assign a unique ID number
  sliderBrakeTiming.setType(SLIDER_IN);               // Defines object as a slider
  sliderBrakeTiming.setCoord(1, 60, 98, 18);          // Set the location and size of your slider 
  sliderBrakeTiming.setTitle("Reverse Timing (%)");   // Set slider title
  sliderBrakeTiming.setSliderMinMax(0, 100);          // Set slider min and max value
  sliderBrakeTiming.setSliderNumIntervals(100);       // Set slider interval
  sliderBrakeTiming.setSliderReportMode(ON_FINGER_UP);// Set slider reporting mode
  sliderBrakeTiming.setActiveColor("ffc0392b");       // Set slider active color
  sliderBrakeTiming.setBaseColor("ffe74c3c");         // Set slider base color

  start.setId(7);                                     // Assign a unique ID number
  start.setType(BUTTON_IN);                           // Defines object as a button
  start.setCoord(1, 80, 98, 18);                      // Set the location and size of your button
  start.requireAck(false);                            // Disable require acknowledgement 
  start.setTitle("Start");                            // Set button title
  start.setColor("ff2ecc71");                         // Set button background color
  
  sliderMoveTiming.moveSliderToValue(0);              // move sliderMoveTiming thumb to 0
  sliderIdleTiming.moveSliderToValue(0);              // move sliderIdleTiming thumb to 0
  sliderBrakeTiming.moveSliderToValue(0);             // move sliderBrakeTiming thumb to 0  
}
