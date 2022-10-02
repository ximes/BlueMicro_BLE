/*
Copyright 2020-2021 <Pierre Constantineau>

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
#ifndef HARDWARE_CONFIG_H
#define HARDWARE_CONFIG_H
#include "hardware_variants.h"

  #define ARDUINO_NRF52_COMMUNITY 1
#define VCC_ENABLE_GPIO 1
/* HARDWARE DEFINITION*/
/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 6
// ROW0, ROW1, ROW2, ROW3, ROW4, #
#define MATRIX_ROW_PINS { 20, 13, 24, 9, 10 }
// COL5, COL4, COL0, COL2, COL1, COL3
#define MATRIX_COL_PINS { 45, 28, 3, 43, 2, 29 }

// NOTE ONLY A SINGLE ENCODER IS POSSIBLE.
#define ENCODER_PAD_A  26 
#define ENCODER_PAD_B  30
#define ENCODER_RESOLUTION 2 // This doesn't do anything.

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

   #define BATTERY_TYPE BATT_LIPO
        // #define VBAT_PIN  4
        #define VCC_PIN 12
#define VCC_POLARITY_ON 1
#define VCC_DEFAULT_ON 1

  #define BACKLIGHT_PWM_ON 0
  #define WS2812B_LED_PIN 6
  
  #define WS2812B_LED_COUNT 29
  #define WS2812B_LED_ON 1 

#define  STATUS_BLE_LED_PIN  19  //blue = 0.19
#define  STATUS_KB_LED_PIN 17  //red = 0.17

//  OLED DEFINITION
#define I2C_SDA_PIN 15
#define I2C_SCK_PIN 17
#define DISPLAY_U8G2_CONSTRUCTOR U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C // see https://github.com/olikraus/u8g2/wiki/u8g2setupcpp for reference

   /*     #define D3      6  
        #define D2      8   
        #define D1      15  
        #define D0      17  
        #define D4      20
        #define C6      13
        #define D7      24
        #define E6      9
        #define B4      10
        #define B5      38 //1.06 = 32+6

        #define F4      30
        #define F5      26  
        #define F6      29
        #define F7      2
        #define B1      45 //1.13  = 32+13
        #define B3      3
        #define B2      28
        #define B6      43 //1.11 = 32+11
        #define NC      32 //1.00 = 32+0 // NC is for not connected....*/

#endif /* HARDWARE_CONFIG_H */



