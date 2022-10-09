/* Trackball_BlueMicro.ino
    Sketch that is an adaptation of the pimoroni trackball's Leonardo trackball example
    and nRF52 hid_mouse example.

    Written by William
    Created: 9/26/2022
    Last Modified: 9/29/2022
*/

#include "datastructures.h"

// #ifdef BLUEMICRO_CONFIGURED_TRACKBALL
#include <bluefruit.h>
#include <Wire.h>
#include "bluetooth.h"
#include <pimoroniTrackball.h> //From https://github.com/ncmreynolds/pimoroniTrackball
// #endif

// void buttonA_Event (uint8_t btnStatus);
// void buttonB_Event (uint8_t btnStatus);
extern void addKeycodeToQueue(const uint16_t keycode);
extern void addKeycodeToQueue(const uint16_t keycode, const uint8_t modifier);
extern void sendMouseMovement(uint16_t x, uint16_t y);
class Trackball
{
public:
    Trackball(PersistentState *cfg, DynamicState *stat);

    void begin(void);
    void update(void);
private:
    PersistentState *config;
    DynamicState *status;
};