/**
 * @file main.cpp
 * @author Paulo Sérgio do Nascimento (paulosergionas@gmail.com)
 * @brief Control remoto televisor samsung
 * @version 0.1
 * @date 2024-07-12
 *
 * @copyright Copyright (c) 2024
 *
 *
 * docs: https://github.com/lepiaf/IR-Remote-Code/blob/master/README.md
 */

#include <Arduino.h>
#include <IRremote.h>

#define PIN_SEND 3
#define PIN_POWER A0
#define PIN_SOURCE A1
#define PIN_CH_UP A2
#define PIN_CH_DOWN A3
#define PIN_VOL_UP A4
#define PIN_VOL_DOWN A5

#define MESSAGE_ON_OFF 0xE0E040BF
#define MESSAGE_SOURCE 0xE0E0807F
#define MESSAGE_CH_UP 0xE0E048B7
#define MESSAGE_CH_DOWN 0xE0E008F7
#define MESSAGE_VOL_UP 0xE0E0E01F
#define MESSAGE_VOL_DOWN 0xE0E0D02F

IRsend irsend(PIN_SEND);

byte flag_power = false;
byte flag_source = false;
byte flag_ch_up = false;
byte flag_ch_down = false;
byte flag_vol_up = false;
byte flag_vol_down = false;

// implementação futura ?!?
// uint32_t old_message = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(PIN_POWER, INPUT_PULLUP);
  pinMode(PIN_SOURCE, INPUT_PULLUP);
  pinMode(PIN_CH_UP, INPUT_PULLUP);
  pinMode(PIN_CH_DOWN, INPUT_PULLUP);
  pinMode(PIN_VOL_UP, INPUT_PULLUP);
  pinMode(PIN_VOL_DOWN, INPUT_PULLUP);
}

void loop()
{
  if (!digitalRead(PIN_POWER))
    flag_power = true;

  if (digitalRead(PIN_POWER) && flag_power == 1)
  {
    irsend.sendSAMSUNG(MESSAGE_ON_OFF, SAMSUNG_BITS), flag_power = 0;
    Serial.println("POWER");
  }

  // ------------------------------------
  if (!digitalRead(PIN_SOURCE))
    flag_source = true;

  if (digitalRead(PIN_SOURCE) && flag_source == 1)
  {
    irsend.sendSAMSUNG(MESSAGE_SOURCE, SAMSUNG_BITS), flag_source = 0;
    Serial.println("SOURCE");
  }

  // ------------------------------------
  if (!digitalRead(PIN_CH_UP))
    flag_ch_up = true;

  if (digitalRead(PIN_CH_UP) && flag_ch_up == 1)
  {
    irsend.sendSAMSUNG(MESSAGE_CH_UP, SAMSUNG_BITS), flag_ch_up = 0;
    Serial.println("CHANNEL ++");
  }

  // ------------------------------------
  if (!digitalRead(PIN_CH_DOWN))
    flag_ch_down = true;

  if (digitalRead(PIN_CH_DOWN) && flag_ch_down == 1)
  {
    irsend.sendSAMSUNG(MESSAGE_CH_DOWN, SAMSUNG_BITS), flag_ch_down = 0;
    Serial.println("CHANNEL --");
  }

  // ------------------------------------
  if (!digitalRead(PIN_VOL_UP))
    flag_vol_up = true;

  if (digitalRead(PIN_VOL_UP) && flag_vol_up == 1){
    irsend.sendSAMSUNG(MESSAGE_VOL_UP, SAMSUNG_BITS), flag_vol_up = 0;
    Serial.println("VOLUME ++");
  }

  // ------------------------------------
  if (!digitalRead(PIN_VOL_DOWN))
    flag_vol_down = true;

  if (digitalRead(PIN_VOL_DOWN) && flag_vol_down == 1){
    irsend.sendSAMSUNG(MESSAGE_VOL_DOWN, SAMSUNG_BITS), flag_vol_down = 0;
    Serial.println("VOLUME --");
  }
}