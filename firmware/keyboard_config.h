/*
Copyright 2018-2021 <Pierre Constantineau>

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

// HAND PIN: 32+6
#define KEYBOARD_SIDE RIGHT
// CHANGE THIS FOR THE KEYBOARD TO MATCH WHAT IS BEING FLASHED. OPTIONS: LEFT  RIGHT  SINGLE

#define DEVICE_NAME_R "KB Right"   /**< Name of device. Will be included in the advertising data. */
#define DEVICE_NAME_L "KB Left"    /**< Name of device. Will be included in the advertising data. */
#define DEVICE_NAME_M "Orion's KB" /**< Name of device. Will be included in the advertising data. */

#define DEVICE_MODEL "Lotus58" /**< Name of device. Will be included in the advertising data. */

#define MANUFACTURER_NAME "Orion" /**< Manufacturer. Will be passed to Device Information Service. */

#if KEYBOARD_SIDE == LEFT
#define KEYMAP(                             \
    k00, k01, k02, k03, k04, k05,           \
    k06, k07, k08, k09, k10, k11,           \
    k12, k13, k14, k15, k16, k17,           \
    k18, k19, k20, k21, k22, k23, k24,      \
    k25, k26, k27, k28, k29)                \
    {                                       \
        {k00, k01, k02, k03, k04, k05},     \
            {k06, k07, k08, k09, k10, k11}, \
            {k12, k13, k14, k15, k16, k17}, \
            {k18, k19, k20, k21, k22, k23}, \
        {                                   \
            k29, k25, k26, k27, k28, k24    \
        }                                   \
    }

#else

#ifndef BLUEMICRO_CONFIGURED_TRACKBALL
#define BLUEMICRO_CONFIGURED_TRACKBALL 1
#endif

#define KEYMAP(                             \
    k00, k01, k02, k03, k04, k05,           \
    k06, k07, k08, k09, k10, k11,           \
    k12, k13, k14, k15, k16, k17,           \
    k18, k19, k20, k21, k22, k23,           \
    k24, k25, k26, k27, k28, k29)           \
    {                                       \
        {k05, k04, k03, k02, k01, k00},     \
            {k11, k10, k09, k08, k07, k06}, \
            {k17, k16, k15, k14, k13, k12}, \
            {k24, k23, k22, k21, k20, k19}, \
        {                                   \
            k25, k29, k28, k27, k26, k18    \
        }                                   \
    }

#endif

#endif /* KEYBOARD_CONFIG_H */
