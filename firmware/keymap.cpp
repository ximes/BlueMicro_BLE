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
     * ,-------------------------------------------------.
     * | Esc  |   1  |   2  |   3  |   4    |     5      |
     * |------+------+------+------+--------+------------|
     * | Tab  |   Q  |   W  |   E  |   R    |     T      |
     * |------+------+------+------+--------+------------|
     * | Shift|   A  |   S  |   D  |   F    |     G      |
     * |------+------+------+------+--------+------------|
     * | Ctrl |   Z  |   X  |   C  |   V    |     B      |
     * |------+------+------+------+--------+------------+
     * |      |      | Alt  | GUI  |  Space  | UP   | Play/Pause |
     * `-------------------------------------------------'
     */

    uint32_t qwerty_layer[MATRIX_ROWS][MATRIX_COLS] = KEYMAP(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
        KC_LSHIFT, KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_LCTRL, KC_Z, KC_X, KC_C, KC_V, KC_B,
        LAYER_1, HELP_MODE, KC_LALT, KC_LGUI, KC_BSPACE, KC_MEDIA_PLAY_PAUSE);

    uint32_t symbol_layer[MATRIX_ROWS][MATRIX_COLS] = KEYMAP(
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,
        _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,
        _______, KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR,
        _______, _______, _______, _______, _______, _______);

    uint32_t control_layer[MATRIX_ROWS][MATRIX_COLS] = KEYMAP(
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______);

    // for (int row = 0; row < MATRIX_ROWS; ++row) {
    //     for (int col = 0; col < MATRIX_COLS; ++col) {
    //         matrix[row][col].addActivation(_QWERTY, Method::PRESS, qwerty_layer[row][col]);
    //     }
    // }

    ADDLAYER(_QWERTY, Method::PRESS, qwerty_layer);
    ADDLAYER(_SYMBOLS, Method::PRESS, symbol_layer);
    ADDLAYER(_CONTROL, Method::PRESS, control_layer);

    setupEncoder();
}
#endif

#if KEYBOARD_SIDE == RIGHT
void encoder_callback(int step)
{
    if (step < 0)
    {
        // KeyScanner::add_to_encoderKeys(KC_MS_WH_DOWN);
        KeyScanner::add_to_encoderKeys(KC_AUDIO_VOL_DOWN);
    }
    else
    {
        KeyScanner::add_to_encoderKeys(KC_AUDIO_VOL_UP);
        // KeyScanner::add_to_encoderKeys(KC_MS_WH_UP);
    }
}

void setupKeymap()
{
    startup();

    /* Qwerty RIGHT
     * ,-------------------------------------------------.
     * |   6  |   7   |   8  |   9  |   0  | KC_MINUS    |
     * |------+-------+------+------+------+-------------|
     * |   Y  |   U   |   I  |   O  |   P  | Bksp        |
     * |------+-------+------+------+------+-------------|
     * |   H  |   J   |   K  |   L  |   ;  |  '          |
     * |------+-------+------+------+------+-------------|
     * |   N  |   M   |   ,  |   .  |   /  | Shift       |
     * `------+-------+------+------+------+-------------|
     * | Help | Space | DOWN | Bksp | Del  | Enter       |
     * `-------------------------------------------------'
     */

    uint32_t qwerty_layer[MATRIX_ROWS][MATRIX_COLS] = KEYMAP(
        KC_6, KC_7, KC_8, KC_9, KC_0, LAYER_1,
        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRACKET,
        KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE,
        KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLSH, KC_RSHIFT,
        HELP_MODE, KC_SPC, KC_ENT, _______, KC_DEL, HELP_MODE);

    uint32_t symbol_layer[MATRIX_ROWS][MATRIX_COLS] = KEYMAP(
        _______, _______, KC_MS_UP, _______, _______, KC_MS_WH_UP,
        _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______, KC_MS_WH_DOWN,
        KC_PGUP, _______, KC_UP, _______, _______, _______,
        KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, _______,
        _______, _______, _______, _______, _______, _______);

    uint32_t control_layer[MATRIX_ROWS][MATRIX_COLS] = KEYMAP(
        _______, _______, _______, _______, _______, KC_SPC,
        KC_PGUP, _______, KC_UP, _______, _______, KC_BSPC,
        KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, KC_BSPC,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, LAYER_0, _______);

    ADDLAYER(_QWERTY, Method::PRESS, qwerty_layer);
    ADDLAYER(_SYMBOLS, Method::PRESS, symbol_layer);
    ADDLAYER(_CONTROL, Method::PRESS, control_layer);

    setupEncoder();
}
#endif
