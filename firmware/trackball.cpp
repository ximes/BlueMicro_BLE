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
uint8_t mouseSpeed = 15; // Change this to alter the mouse speed
int16_t x = 0;
int16_t y = 0;

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

Trackball::Trackball(PersistentState *cfg, DynamicState *stat)
{ // Constructor
  config = cfg;
  status = stat;
}

void Trackball::begin(void)
{
#ifdef BLUEMICRO_CONFIGURED_TRACKBALL
  // Initialize I2C and trackball
  Wire.begin();
  trackball.begin();

  while (!trackball.isConnected())
    ;
#endif
}

/**************************************************************************************************************************/
void Trackball::update(void)
{
#ifdef BLUEMICRO_CONFIGURED_TRACKBALL
  if (trackball.changed())
  {

    x = (trackball.right() - trackball.left()) * mouseSpeed;
    y = (trackball.down() - trackball.up()) * mouseSpeed;
    if (x != 0 || y != 0)
    {
      trackball.setBlue(50);
      sendMouseMovement(-x, y);
    }
    else
    {
      trackball.setBlue(0);
    }
    // if (trackball.click())
    // {
    //   trackball.setBlue(70);
    //   bluetooth_sendMouseKey(KC_MS_BTN1);
    //   addKeycodeToQueue(KC_MS_BTN1);
    //   delay(10);
    //   bluetooth_sendMouseKey(KC_MS_OFF);
    //   addKeycodeToQueue(KC_MS_OFF);
    //   // blehid.mouseButtonPress(MOUSE_BUTTON_LEFT);
    // }
    // else if (trackball.release())
    // {
    //   trackball.setBlue(0);
    //   bluetooth_sendMouseKey(KC_MS_OFF);
    //   addKeycodeToQueue(KC_MS_OFF);
    //   // blehid.mouseButtonRelease();
    // }
  }

#endif
}