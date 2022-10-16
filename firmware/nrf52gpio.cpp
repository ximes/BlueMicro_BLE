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
#include "nrf52gpio.h"

// Keyboard Matrix
led_handler::led_handler(PersistentState *cfg, DynamicState *stat)
{
  config = cfg;
  status = stat;
  callback = defaultLedCallback;
  enabled = false;
};

void led_handler::setCallback(ledupdateCallback cb)
{
  callback = cb;
}

void led_handler::enable()
{
  if (config->enableBLELED)
  {
    pinMode(config->pinBLELED, OUTPUT);
  }
  if (config->enableKBLED)
  {
    pinMode(config->pinKBLED, OUTPUT);
  }
  enabled = true;
}
void led_handler::disable()
{
  if (config->enableBLELED)
  {
    pinMode(config->pinBLELED, INPUT);
  }
  if (config->enableKBLED)
  {
    pinMode(config->pinKBLED, INPUT);
  }
  enabled = false;
}

void led_handler::hello()
{
  if (!enabled)
  {
    enable();
  }
  if (config->enableBLELED)
  {
    digitalWrite(config->pinBLELED, (config->polarityBLELED));
  }
  if (config->enableKBLED)
  {
    digitalWrite(config->pinKBLED, (config->polarityKBLED));
  }
  delay(200);
  if (config->enableBLELED)
  {
    digitalWrite(config->pinBLELED, !(config->polarityBLELED));
  }
  if (config->enableKBLED)
  {
    digitalWrite(config->pinKBLED, !(config->polarityKBLED));
  }
  delay(200);
  if (config->enableBLELED)
  {
    digitalWrite(config->pinBLELED, (config->polarityBLELED));
  }
  if (config->enableKBLED)
  {
    digitalWrite(config->pinKBLED, (config->polarityKBLED));
  }
  delay(200);
  if (config->enableBLELED)
  {
    digitalWrite(config->pinBLELED, !(config->polarityBLELED));
  }
  if (config->enableKBLED)
  {
    digitalWrite(config->pinKBLED, !(config->polarityKBLED));
  }
  delay(200);
}

void led_handler::sleep()
{
  disable(); // put in high-z so that it doesn't turn on the LED when sleeping...
}

void led_handler::update()
{
  if (enabled)
  { // must be enabled
    if (callback != NULL)
    { // callback must be defined
      callback(config, status);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

void defaultLedCallback(PersistentState *config, DynamicState *status)
{

  // do something looking at config and status and adjust LED states...
  // BLE LED
  // (0 = 1) Fast Advertizing
  // (1 = 2) Slow Advertizing
  // (2 = 4) Advertizing running
  // (3 = 8) PRPH Connected
  // (4 = 16) CENT Connected
  // (5 = 32) Connected

  if (config->enableBLELED)
  {
    digitalWrite(config->pinBLELED, (status->statusble > 0 && status->statusble < 8) ? config->polarityBLELED : !(config->polarityBLELED));
  }
  // Keyboard Status LED
  // The LED bit map is as follows:
  // Kana (4) | Compose (3) | ScrollLock (2) | CapsLock (1) | Numlock (0)
  // KEYBOARD_LED_NUMLOCK
  // KEYBOARD_LED_CAPSLOCK
  // KEYBOARD_LED_SCROLLLOCK
  // KEYBOARD_LED_COMPOSE
  // KEYBOARD_LED_KANA
  if (config->enableKBLED)
  {
    digitalWrite(config->pinKBLED, ((status->statuskb) & KEYBOARD_LED_CAPSLOCK) ? config->polarityKBLED : !(config->polarityKBLED));
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
void setupGpio()
{
  // this code enables the NFC pins to be GPIO.
  if ((NRF_UICR->NFCPINS & UICR_NFCPINS_PROTECT_Msk) == (UICR_NFCPINS_PROTECT_NFC << UICR_NFCPINS_PROTECT_Pos))
  {
    // Serial.println("Fix NFC pins");
    NRF_NVMC->CONFIG = NVMC_CONFIG_WEN_Wen << NVMC_CONFIG_WEN_Pos;
    while (NRF_NVMC->READY == NVMC_READY_READY_Busy)
      ;
    NRF_UICR->NFCPINS &= ~UICR_NFCPINS_PROTECT_Msk;
    while (NRF_NVMC->READY == NVMC_READY_READY_Busy)
      ;
    NRF_NVMC->CONFIG = NVMC_CONFIG_WEN_Ren << NVMC_CONFIG_WEN_Pos;
    while (NRF_NVMC->READY == NVMC_READY_READY_Busy)
      ;
    // Serial.println("Done");
    delay(500);
    NVIC_SystemReset();
  } // end of NFC switch code.
}

/**************************************************************************************************************************/
void switchVCC(bool value)
{
#if VCC_ENABLE_GPIO == 1
  pinMode(VCC_PIN, OUTPUT);
  if (value)
  {
    digitalWrite(VCC_PIN, VCC_POLARITY_ON);
  }
  else
  {
    digitalWrite(VCC_PIN, !VCC_POLARITY_ON);
  }
#endif
}

void switchCharger(bool value)
{
#if VCC_ENABLE_CHARGER == 1
  pinMode(CHARGER_PIN, OUTPUT);
  if (value)
  {
    digitalWrite(CHARGER_PIN, CHARGER_POLARITY_ON);
  }
  else
  {
    digitalWrite(CHARGER_PIN, !CHARGER_POLARITY_ON);
  }
#endif
}

void setupWDT()
{
  // Configure WDT
  NRF_WDT->CONFIG = 0x00;       // stop WDT when sleeping
  NRF_WDT->CRV = 5 * 32768 + 1; // set timeout (5 sec)
  NRF_WDT->RREN = 0x01;         // enable the RR[0] reload register
  NRF_WDT->TASKS_START = 1;     // start WDT
}

void updateWDT()
{
  NRF_WDT->RR[0] = WDT_RR_RR_Reload; // pet watchdog
}