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

#if KEYBOARD_SIDE == SINGLE
    std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix = {KEYMAP(
        KC_ESC,     KC_2,       KC_3,    KC_4,      KC_5,       KC_6, 
        KC_TAB,     KC_Q,       KC_W,    KC_E,      KC_R,       KC_T,  
        KC_LSHIFT,  KC_A,       KC_S,    KC_D,      KC_F,       KC_G,  
        KC_LCTRL,   KC_Z,       KC_X,    KC_C,      KC_V,       KC_B,
        KC_LALT,    KC_LGUI,    KC_5,    LAYER_0,  _______,    _______
    )};

    void setupKeymap() {
       // no layers for master keymap
       // this is a keymap that's used for testing that each key is responding properly to key presses
       // flash this keymap to both left and right to test whether each half works properly.
       // once tested, you can flash the left and right to their respective halves.
    }
#endif

#if KEYBOARD_SIDE == LEFT
    std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix = {KEYMAP(
        KC_ESC,     KC_1,       KC_2,       KC_3,      KC_4,      KC_5,
        KC_GRAVE,   KC_Q,       KC_W,       KC_E,      KC_R,       KC_T,
        KC_TAB,     KC_A,       KC_S,       KC_D,      KC_F,       KC_G,
        KC_LSHIFT,  KC_Z,       KC_X,       KC_C,      KC_V,       KC_B,
        KC_LCTRL,   KC_LALT,    KC_LGUI,    _______,   KC_MEDIA_PLAY_PAUSE,    _______
    )};
 
     void encoder_callback(int step)
    {
      uint8_t layer = keyboardstate.layer;
      if ( step > 0 )
      {
          switch(layer)
          {
              case _QUERTY: KeyScanner::add_to_encoderKeys(KC_AUDIO_VOL_DOWN); break;
              case _LOWER: KeyScanner::add_to_encoderKeys(KC_RIGHT); break;
              case _RAISE: KeyScanner::add_to_encoderKeys(LSFT(KC_RIGHT)); break;
              default: ;
          }
      }else
      {
          switch(layer)
          {
              case _QUERTY: KeyScanner::add_to_encoderKeys(KC_AUDIO_VOL_UP); break;
              case _LOWER: KeyScanner::add_to_encoderKeys(KC_LEFT);break;
              case _RAISE: KeyScanner::add_to_encoderKeys(LSFT(KC_LEFT));break;
              default: ;
          }
      }  
    }

    void setupKeymap() {
        uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] = KEYMAP( \
            KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,  \
            KC_GRAVE,KC_1,    KC_2,    KC_3,    KC_4,   KC_5,  \
            KC_DEL  ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,    \
            KC_LSFT ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
            KC_SPC,  LAYER_3,      LAYER_3, LAYER_1, KC_SPC,_______ \
        );

        uint32_t layer2[MATRIX_ROWS][MATRIX_COLS] = KEYMAP( \
                KC_TILD ,KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,  \
          KC_TILD ,KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,  \
          KC_DEL  ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,    \
          KC_LSFT ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11, KC_SPC , \
            LAYER_3,LAYER_3, LAYER_1, KC_SPC,_______ \
        );

        uint32_t layer3[MATRIX_ROWS][MATRIX_COLS] = KEYMAP( \
                KC_GRAVE,KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,  \
          KC_GRAVE,KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,  \
         _______, _______,_______,_______, _______, _______,    \
          KC_LSFT,_______,_______,_______, _______, _______, _______, \
           LAYER_3, LAYER_3, LAYER_1,KC_SPC ,_______\
        );

        /*
         * add the other layers on the regular presses.
         */
        for (int row = 0; row < MATRIX_ROWS; ++row)
        {
            for (int col = 0; col < MATRIX_COLS; ++col)
            {
                matrix[row][col].addActivation(_LOWER, Method::PRESS, layer1[row][col]);
                matrix[row][col].addActivation(_RAISE, Method::PRESS, layer2[row][col]);
                matrix[row][col].addActivation(_CONTROL, Method::PRESS, layer3[row][col]);
            }
        }

        // if you want to add Tap/Hold or Tap/Doubletap activations, then you add them below.
        RotaryEncoder.begin(ENCODER_A_PIN, ENCODER_B_PIN);    // Initialize Encoder
        RotaryEncoder.setCallback(encoder_callback);    // Set callback
        RotaryEncoder.start();    // Start encoder
    }
#endif  // left

#if KEYBOARD_SIDE == RIGHT
    std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix = {KEYMAP(
        KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINUS,
        KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRACKET, 
        KC_H,       KC_J,       KC_K,       KC_L,       KC_SCOLON,  KC_QUOTE,
        KC_SPC,     KC_N,       KC_M,       KC_COMMA,   KC_DOT,     KC_SLSH,   
        _______,    _______,    KC_SPC,     KC_ENT ,    KC_BSPACE,  KC_DEL
    )};

     

    void setupKeymap() {


        uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] =
            KEYMAP( \
             KC_6,    KC_7,    KC_8,    KC_9,     KC_0,      KC_DEL,  \
        KC_6,    KC_7,    KC_8,    KC_9,     KC_0,      KC_DEL,  \
        KC_F6,   KC_MINS, KC_EQL,  KC_LBRC,  KC_RBRC,   KC_BSLS,   \
     KC_SPC,    KC_F12,  KC_NUHS, KC_NUBS, _______,  _______,   _______,  \
        KC_SPC,   LAYER_2, LAYER_4, LAYER_3,_______\
    );


        uint32_t layer2[MATRIX_ROWS][MATRIX_COLS] =
            KEYMAP( \
             KC_6,    KC_7,    KC_8,    KC_9,     KC_0,      KC_DEL,  \
      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,  \
      KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,   \
    KC_SPC,  KC_F12,  KC_NUTL, KC_NUPI,_______, _______, _______,  \
      KC_SPC,  LAYER_2, LAYER_4, LAYER_3,_______ \
    );


        uint32_t layer3[MATRIX_ROWS][MATRIX_COLS] =
            KEYMAP( \
             KC_6,    KC_7,    KC_8,    KC_9,     KC_0,      KC_DEL,  \
      KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_INS,  \
      _______,  _______,  _______,  _______,  _______,  _______,   \
     KC_SPC,   _______,  _______,  _______,  _______,  _______,  _______,  \
      KC_SPC,   LAYER_2,  LAYER_4, LAYER_3 ,_______\
    );

        /*
         * add the other layers
         */
        for (int row = 0; row < MATRIX_ROWS; ++row)
        {
            for (int col = 0; col < MATRIX_COLS; ++col)
            {
                matrix[row][col].addActivation(_LOWER, Method::PRESS, layer1[row][col]);
                matrix[row][col].addActivation(_RAISE, Method::PRESS, layer2[row][col]);
                matrix[row][col].addActivation(_CONTROL, Method::PRESS, layer3[row][col]);
            }
        }

    }
#endif
