/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include "keymap.h"
#include "RotaryEncoder.h"
#include "pimoroniTrackball.h"

// Initialize matrix with nothing...
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    KEYMAP2ARRAY(KEYMAP(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO));

void updateDisplay(PersistentState *cfg, DynamicState *stat)
{
#ifdef BLUEMICRO_CONFIGURED_DISPLAY
    u8g2.setFontMode(1); // Transparent

    // Battery info
    if (stat->vbat_per > 0)
    {
        u8g2.setFontDirection(0);
        u8g2.setFont(u8g2_font_helvB12_tf);
        battery(11, 19, stat->vbat_per);

        u8g2.setFontDirection(1);
        u8g2.setFont(u8g2_font_helvB08_tf);
        char batteryStateBuffer[50];
        sprintf(batteryStateBuffer, "%d%%", (stat->vbat_per - 1));
        u8g2.drawStr(23, 0, batteryStateBuffer);
    }

    //  Connection status
    u8g2.setFontDirection(0);

    bool connected;

    if (stat->connectionState == CONNECTION_BT)
    {
        u8g2.setFont(u8g2_font_open_iconic_embedded_1x_t);
        u8g2.drawStr(0, 10, "J"); // Bluetooth icon
        connected = bluetooth_isConnected();
    }

    if (stat->connectionState == CONNECTION_USB)
    {
        u8g2.setFont(u8g2_font_open_iconic_other_1x_t);
        u8g2.drawStr(0, 10, "B"); // USB icon
        connected = usb_isConnected();
    }

    u8g2.setFont(u8g2_font_m2icon_5_tf);
    if (connected == true)
    {
        u8g2.drawStr(0, 18, "D"); // connection ok
    }
    else
    {
        u8g2.drawStr(0, 18, "C"); // no connection
    }

    u8g2.setFont(u8g2_font_helvB08_tf);

    // Help mode
    if (stat->helpmode == 1)
    {
        u8g2.setFont(u8g2_font_helvB08_tf);
        u8g2.drawStr(4, 40, "HELP");
        u8g2.drawStr(2, 50, "MODE");

        // u8g2.setFont(u8g2_font_twelvedings_t_all);
        // u8g2.drawStr(15, 70, "?");
        u8g2.setFont(u8g2_font_helvB08_tf);
        u8g2.setFontDirection(1);
        u8g2.setFont(u8g2_font_helvB08_tf);
        u8g2.drawStr(20, 60, keynameByKeycode(stat->last_pressed_keycode));
    }

    u8g2.setFontDirection(1);
    u8g2.setFont(u8g2_font_helvB08_tf);
    switch (stat->layer)
    {
    case _QWERTY:
        u8g2.drawStr(0, 60, "Qwerty");
        break;
    case _SYMBOLS:
        u8g2.drawStr(0, 60, "Symbols");
        break;
    case _CONTROL:
        u8g2.drawStr(0, 60, "Settings");
        break;
    }
#endif
}
void startup()
{
#ifdef BLUEMICRO_CONFIGURED_DISPLAY
    OLED.setStatusDisplayCallback(updateDisplay);
#endif
}

void setupEncoder()
{
    // Code below makes sure that the encoder gets configured.
    RotaryEncoder.begin(ENCODER_PAD_A, ENCODER_PAD_B); // Initialize Encoder
    RotaryEncoder.setCallback(encoder_callback);       // Set callback
    RotaryEncoder.start();                             // Start encoder
}

#if KEYBOARD_SIDE == LEFT
void encoder_callback(int step)
{
    if (step > 0)
    {
        KeyScanner::add_to_encoderKeys(KC_AUDIO_VOL_DOWN);
    }
    else
    {
        KeyScanner::add_to_encoderKeys(KC_AUDIO_VOL_UP);
    }
}

void setupKeymap()
{
    startup();

    /* Qwerty LEFT
     * +-----------------------------------------------+
     * |  Esc  |  1  |  2  |    3    |   4   |    5    |
     * |-------+-----+-----+---------+-------+---------|
     * |  Tab  |  Q  |  W  |    E    |   R   |    T    |
     * |-------+-----+-----+---------+-------+---------|
     * | Shift |  A  |  S  |    D    |   F   |    G    |
     * |-------+-----+-----+---------+-------+---------|------------+
     * | Ctrl  |  Z  |  X  |    C    |   V   |    `    | Play/Pause |
     * +-------+-----+-----+---------+-------+---------+------------+------------+
     *                     | LAYER 3 |  Alt  |   GUI   |    Enter   |  LAYER 2   |
     *                     +-----------------------------------------------------+
     */

    uint32_t qwerty_layer[MATRIX_ROWS][MATRIX_COLS] = KEYMAP(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
        KC_LSHIFT, KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_LCTRL, KC_Z, KC_X, KC_C, KC_V, KC_GRAVE, KC_MEDIA_PLAY_PAUSE,
        LAYER_2, KC_LALT, KC_LGUI, KC_ENT, LAYER_1);

    /* Symbols LEFT
     * +-----------------------------------------+
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |
     * |------+------+------+------+------+------|
     * |      |      |  7   |  8   |  9   |      |
     * |------+------+------+------+------+------|
     * |      |      |  4   |  5   |  6   |      |
     * |------+------+------+------+------+------|-------+
     * |      |      |  1   |  2   |  3   |  0   |       |
     * +------+------+------+------+------+------+-------+-----+
     *                      |      |      |      |       |     |
     *                      +----------------------------------+
     */

    uint32_t symbol_layer[MATRIX_ROWS][MATRIX_COLS] = KEYMAP(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
        KC_UNDEFINED, KC_UNDEFINED, KC_KP_7, KC_KP_8, KC_KP_9, KC_UNDEFINED,
        KC_UNDEFINED, KC_UNDEFINED, KC_KP_4, KC_KP_5, KC_KP_6, KC_UNDEFINED,
        KC_UNDEFINED, KC_UNDEFINED, KC_KP_1, KC_KP_2, KC_KP_3, KC_0, KC_UNDEFINED,
        _______, _______, _______, _______, _______);

    /* Control LEFT
     * +-------------------------------------------------------+
     * |  System Sleep |     |  ?  |  ?  |  ?  |   KB reset    |
     * |---------------+-----+-----+-----+-----+---------------+
     * |   Display +   |  ?  |  ?  |  ?  |  ?  |  Flash reset  |
     * |---------------+-----+-----+-----+-----+---------------+
     * |   Display -   |     |  ?  |  ?  |  ?  |      ?        |
     * |---------------+-----+-----+-----+-----+---------------+-----+
     * |      ?        |  ?  |  ?  |  ?  |  ?  |      ?        |  ?  |
     * +---------------+-----+-----+-----+-----+---------------+-----+-----+
     *                       |  ?  |  ?  |  ?  |      ?        |  ?  |     |
     *                       +---------------------------------------------+
     */

    uint32_t control_layer[MATRIX_ROWS][MATRIX_COLS] = KEYMAP(
        KC_SYSTEM_SLEEP, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED, RESET,
        KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED, EEP_RST,
        KC_DISPLAY_BRIGHTI, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED,
        KC_DISPLAY_BRIGHTD, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED,
        KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED);

    // Default activations
    ADDLAYER(_QWERTY, Method::PRESS, qwerty_layer);
    ADDLAYER(_SYMBOLS, Method::PRESS, symbol_layer);
    ADDLAYER(_CONTROL, Method::PRESS, control_layer);

    // Custom key activations
    // none

    setupEncoder();
}
#endif

#if KEYBOARD_SIDE == RIGHT
void encoder_callback(int step)
{
    if (step > 0)
    {
        KeyScanner::add_to_encoderKeys(KC_MEDIA_NEXT_TRACK);
    }
    else
    {
        KeyScanner::add_to_encoderKeys(KC_MEDIA_PREV_TRACK);
    }
}

void setupKeymap()
{
    startup();

    /* Qwerty RIGHT
     *                           +-------------------------------------+
     *                           |  6   |  7  |  8   |  9  |  0  |  -  |
     *                           |------+-----+------+-----+-----+-----|
     *                           |  Y   |  U  |  I   |  O  |  P  | tbd |
     *                           |------+-----+------+-----+-----+-----|
     *                           |  H   |  J  |  K   |  L  |  ;  |  '  |
     *                   +-------+------+-----+------+-----+-----+-----|
     *                   | mute  |  B   |  N  |  M   |  ,  |  .  |  /  |
     * +-----------+-----+-------+------+-----+------+-----+-----+-----+
     * | Help mode | n/a | Space | Bksp | Del | Mode |
     * +---------------------------------------------+
     */

    uint32_t qwerty_layer[MATRIX_ROWS][MATRIX_COLS] = KEYMAP(
        KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS,
        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_UNDEFINED,
        KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE,
        KC_AUDIO_MUTE, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLSH,
        HELP_MODE, KC_SPC, KC_BSPC, KC_DEL, OS(LAYER_2));

    /* Symbols RIGHT
     *                     +-----------------------------------------+
     *                     |  F7  |  F8  |  F9  | F10  | F11  | F12  |
     *                     |------+------+------+------+------+------|
     *                     | Home |  PG↑ | Ins  |  =   |  (   |  )   |
     *                     |------+------+------+------+------+------|
     *                     | End  |  PG↓ |  ↑   |  +   |  [   |  ]   |
     *               +-----+------+------+------+------+------+------|
     *               |     |      |   ←  |  ↓   |  →   |  {   |  }   |
     * +-----+-------+-----+------+------+------+------+------+------+
     * |     |  n/a  |     | Sc ↑ | Sc ↓ |      |
     * +----------------------------------------+
     */

    uint32_t symbol_layer[MATRIX_ROWS][MATRIX_COLS] = KEYMAP(
        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        KC_HOME, KC_PGUP, KC_INS, KC_EQL, KC_LPRN, KC_RPRN,
        KC_END, KC_PGDN, KC_UP, KC_PLUS, KC_LBRC, KC_RBRC,
        KC_UNDEFINED, KC_UNDEFINED, KC_LEFT, KC_DOWN, KC_RIGHT, KC_LCBR, KC_RCBR,
        KC_UNDEFINED, KC_UNDEFINED, KC_MS_WH_UP, KC_MS_WH_DOWN, KC_UNDEFINED);

    /* Control RIGHT
     *                     +-------------------------------------------------------+
     *                     |   RESET   |  ?  |  ?  |  ?  |     |  KC_SYSTEM_SLEEP  |
     *                     |-----------+-----+-----+-----+-----+-------------------+
     *                     |  EEP_RST  |  ?  |  ?  |  ?  |     |     RGB_TOG       |
     *                     |-----------+-----+-----+-----+-----+-------------------+
     *                     |     ?     |  ?  |  ?  |  ?  |  ?  |     RGB_INC       |
     *               +-----+-----------+-----+-----+-----+-----+-------------------|
     *               |  ?  |     ?     |  ?  |  ?  |  ?  |  ?  |     RGB_DEC       |
     * +-----+-------+-----+-----------+-----+-----+-----+-----+-------------------+
     * |  ?  |  n/a  |  ?  |     ?     |  ?  |  ?  |
     * +-------------------------------------------+
     */

    uint32_t control_layer[MATRIX_ROWS][MATRIX_COLS] = KEYMAP(
        RESET, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED, KC_SYSTEM_SLEEP,
        EEP_RST, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED,
        KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED,
        KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED, KC_UNDEFINED,
        KC_UNDEFINED, _______, _______, _______, _______);

    // Default activations
    ADDLAYER(_QWERTY, Method::PRESS, qwerty_layer);
    ADDLAYER(_SYMBOLS, Method::PRESS, symbol_layer);
    ADDLAYER(_CONTROL, Method::PRESS, control_layer);

    // Custom key activations
    // none

    setupEncoder();
}
#endif
