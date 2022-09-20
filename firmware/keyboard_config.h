/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#ifndef KEYBOARD_CONFIG_H
#define KEYBOARD_CONFIG_H
#include "hardware_config.h"

//#define KEYBOARD_SIDE SINGLE
//#define KEYBOARD_SIDE LEFT
#define KEYBOARD_SIDE RIGHT

#define DEVICE_NAME_R "Orion's Split Right"
#define DEVICE_NAME_L  "Orion's Split Left"
#define DEVICE_MODEL "Orion's Split"
#define MANUFACTURER_NAME "Orion"

#if KEYBOARD_SIDE == RIGHT
#define KEYMAP( \
      R00, R01, R02, R03, R04, R05, \
      R06, R07, R08, R09, R10, R11, \
      R12, R13, R14, R15, R16, R17, \
      R18, R19, R20, R21, R22, R23, \
      R24, R25, R26, R27, R28, R29 \
  ) \
  { \
    { R00, R01, R02, R03, R04, R05 }, \
    { R06, R07, R08, R09, R10, R11 }, \
    { R12, R13, R14, R15, R16, R17 }, \
    { R18, R19, R20, R21, R22, R23 }, \
    { KC_NO, R25, R26, R27, R28, R29 }, \
  }
#else
#define KEYMAP( \
      L00, L01, L02, L03, L04, L05, \
      L06, L07, L08, L09, L10, L11, \
      L12, L13, L14, L15, L16, L17, \
      L18, L19, L20, L21, L22, L23, \
      L24, L25, L26, L27, L28, L29 \
  ) \
  { \
    { L00, L01, L02, L03, L04, L05 }, \
    { L06, L07, L08, L09, L10, L11 }, \
    { L12, L13, L14, L15, L16, L17 }, \
    { L18, L19, L20, L21, L22, L23 }, \
    { L24, L25, L26, L27, L28, KC_NO }, \
  } 

#endif

#endif /* KEYBOARD_CONFIG_H */
