/* Trackball_BlueMicro.ino
    Sketch that is an adaptation of the pimoroni trackball's Leonardo trackball example
    and nRF52 hid_mouse example.

    Written by William
    Created: 9/26/2022
    Last Modified: 9/29/2022
*/

#include "trackball.h"

// #ifdef BLUEMICRO_CONFIGURED_TRACKBALL
// BLEHidAdafruit blehid;
// byte multiHit = 2; // May change to allow for various multi-hits

// Define trackball variables
// uint8_t mouseSpeed = 10; //Change this to alter the mouse speed
// int16_t x = 0;
// int16_t y = 0;

// DailyStruggleButton buttonA;
// DailyStruggleButton buttonB;


// #endif

// Button A event handling
// void buttonA_Event (uint8_t btnStatus) {
//   // We can use switch/case to run through what happens for each event
//   switch (btnStatus){

//     case onPress:
//       blehid.mouseButtonPress(MOUSE_BUTTON_RIGHT);
//       break;
      
//     case onRelease:
//       blehid.mouseButtonRelease();
//       break;
      
//     case onLongPress:
      
//       break;

//     case onMultiHit:
      
//       break;
//   }
// }

// // Button B event handling
// void buttonB_Event (uint8_t btnStatus)
// {
//   // We can use switch/case to run through what happens for each event
//   switch (btnStatus){

//     case onPress:
//       blehid.mouseButtonPress(MOUSE_BUTTON_MIDDLE);
//       break;
      
//     case onRelease:
//       blehid.mouseButtonRelease();
//       break;
      
//     case onLongPress:
      
//       break;

//     case onMultiHit:
      
//       break;
//   }
// }


Trackball::Trackball(PersistentState* cfg, DynamicState* stat) {    // Constructor
    config=cfg;
    status=stat;
}

void Trackball::begin(void)
{
  #ifdef BLUEMICRO_CONFIGURED_TRACKBALL
    // Initialize I2C and trackball
    Wire.begin();
    trackball.begin();

    while(!trackball.isConnected()) delay(100);
// addKeycodeToQueue(KC_ENTER);
    // buttonA.set(38, buttonA_Event, INT_PULL_UP);
    // buttonB.set(43, buttonB_Event, INT_PULL_UP);
  #endif
}
/**************************************************************************************************************************/
void Trackball::update(void)
{
    // #ifdef BLUEMICRO_CONFIGURED_TRACKBALL
      // Poll buttons
      // buttonA.poll();
      // buttonB.poll();
      
      // Trackball checking
      // if(trackball.changed()) {
      //   x = (trackball.right() - trackball.left()) * mouseSpeed;
      //   y = (trackball.down() - trackball.up()) * mouseSpeed;
      //   if(x != 0 || y != 0) {
      //     bt_sendMouseKey(KC_MS_UP);
      //     addKeycodeToQueue(KC_ENTER);
      //     // blehid.mouseMove(x, y);
      //   }
      //   if(trackball.click())
      //   {
      //     bt_sendMouseKey(KC_MS_BTN1);
      //     addKeycodeToQueue(KC_ENTER);
      //     // blehid.mouseButtonPress(MOUSE_BUTTON_LEFT);
      //   }
      //   else if(trackball.release())
      //   {
      //     bt_sendMouseKey(KC_MS_OFF);
      //     addKeycodeToQueue(KC_ENTER);
      //     // blehid.mouseButtonRelease();
      //   }
      // }
    // #endif
}