/* Trackball_BlueMicro.ino
    Sketch that is an adaptation of the pimoroni trackball's Leonardo trackball example
    and nRF52 hid_mouse example.

    Written by William
    Created: 9/26/2022
    Last Modified: 9/29/2022
*/

#include "trackball.h"

#ifdef BLUEMICRO_CONFIGURED_TRACKBALL
// Define trackball variables
uint8_t mouseSpeed = 15; // Change this to alter the mouse speed
int16_t x = 0;
int16_t y = 0;

Trackball::Trackball(PersistentState *cfg, DynamicState *stat)
{ // Constructor
    config = cfg;
    status = stat;
}

void Trackball::begin(void)
{

    // Initialize I2C and trackball
    Wire.begin();
    trackball.begin();

    while (!trackball.isConnected())
        ;
}

/**************************************************************************************************************************/
void Trackball::update(void)
{
    if (trackball.changed())
    {
        if (trackball.down() > 0)
        {
            triggerPress(KC_MS_WH_DOWN);
        }
        if (trackball.up() > 0)
        {
            triggerPress(KC_MS_WH_UP);
        }
        if (trackball.click())
        {
            trackball.setRed(70);
            addKeycodeToQueue(KC_MS_BTN1);
            delay(50);
            addKeycodeToQueue(KC_MS_OFF);
            trackball.setRed(0);
            trackball.setBlue(0);
        }
        if (trackball.release())
        {
            triggerPress(KC_MS_OFF);
            trackball.setBlue(0);
            trackball.setRed(0);
        }
    }
}

void Trackball::triggerPress(uint16_t keycode)
{
    trackball.setBlue(70);
    addKeycodeToQueue(keycode);
    delay(200);
    trackball.setBlue(0);
}
#endif