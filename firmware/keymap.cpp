/*
Copyright 2018-2021 <Pierre Constantineau>

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

// Initialize matrix with nothing...
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    KEYMAP2ARRAY(KEYMAP(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO
    ));

void updateDisplay(PersistentState* cfg, DynamicState* stat)
{
    #ifdef BLUEMICRO_CONFIGURED_DISPLAY
    u8g2.setFontMode(1);    // Transparent
    u8g2.setFontDirection(0);
    battery(0, 28, stat->vbat_per);
    printline(0,28, stat->peer_name_prph);

    char buffer [50];
    // u8g2.setFont(u8g2_font_helvB12_tf); // choose a suitable font
    switch(stat->layer)
    {
        case _L0:     u8g2.drawStr(0,128,"L0"); break;
        case _L1:      u8g2.drawStr(0,128,"L1");break;
        case _L2:     u8g2.drawStr(0,128,"L2");break; 
    }
    #endif
}

void setupKeymap() {

  #ifdef BLUEMICRO_CONFIGURED_DISPLAY
    OLED.setStatusDisplayCallback(updateDisplay);
    #endif



   // no layers for single keymap
   // this is a keymap that's used for testing that each key is responding properly to key presses
   // flash this keymap to both left and right to test whether each half works properly.
   // once tested, you can flash the left and right to their respective halves.
   uint32_t layer0_single[MATRIX_ROWS][MATRIX_COLS] = KEYMAP(
        KC_LCTL ,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        PRINT_BLE,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, 
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
        KC_1, KC_LGUI, KC_LALT, KC_DOWN, KC_UP, KC_SPC
    );


/* Qwerty LEFT
 * ,------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y* | 
 * |------+------+------+------+------+-------------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H* |
 * |------+------+------+------+------+------|------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |Space |
 * |------+------+------+------+------+------+------'
 * | Ctrl | GUI  | Alt  | L(3) | L(1) |Space |
 * `-----------------------------------------'
 */

uint32_t layer0_left[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
        KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        PRINT_BLE,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, 
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
        KC_LCTL, KC_LGUI, KC_LALT, KC_DOWN, KC_UP, KC_SPC
    );

 /* Qwerty RIGHT
 * ,------------------------------------------------.
 * |   =  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------|
 * |   \  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------|
 * | Space|   N  |   M  |   ,  |   .  |   /  |Enter |
 * `------+------+------+------+------+------+------|
 *        | Space| L(2) | Left | Down |  Up  |Right |
 *        `-----------------------------------------'
 */

uint32_t layer0_right[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_DEL,
        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      PRINT_BLE, 
        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCOLON, KC_QUOTE,
        KC_N,    KC_M,    KC_COMMA,KC_DOT,  KC_SLSH,   KC_ENT,
        KC_SPC,  KC_LEFT, KC_LEFT, KC_UP,   KC_DOWN,   KC_RIGHT
    );


    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            #if KEYBOARD_SIDE == SINGLE
                matrix[row][col].addActivation(_L0, Method::PRESS, layer0_single[row][col]);
            #endif
            #if KEYBOARD_SIDE == LEFT
                matrix[row][col].addActivation(_L0, Method::PRESS, layer0_left[row][col]);
            #endif
            #if KEYBOARD_SIDE == RIGHT
                matrix[row][col].addActivation(_L0, Method::PRESS, layer0_right[row][col]);
            #endif
            // if you want to add Tap/Hold or Tap/Doubletap activations, then you add them below.

        }
    }


   // no layers for master keymap
   // this is a keymap that's used for testing that each key is responding properly to key presses
   // flash this keymap to both left and right to test whether each half works properly.
   // once tested, you can flash the left and right to their respective halves.

  // Code below makes sure that the encoder gets configured.  
  RotaryEncoder.begin(ENCODER_PAD_A, ENCODER_PAD_B);    // Initialize Encoder
  RotaryEncoder.setCallback(encoder_callback);    // Set callback
  RotaryEncoder.start();    // Start encoder
}

void encoder_callback(int step)
{
  if ( step > 0 )
  {
    KeyScanner::add_to_encoderKeys(KC_AUDIO_VOL_DOWN);
  }else
  {
    KeyScanner::add_to_encoderKeys(KC_AUDIO_VOL_UP);
  }  
}







