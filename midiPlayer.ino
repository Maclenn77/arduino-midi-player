/**
   Mini piano for Arduino.

   You can control the colorful buttons with your keyboard:
   After starting the simulation, click anywhere in the diagram to focus it.
   Then press any key between 1 and 8 to play the piano (1 is the lowest note,
   8 is the highest).

   Copyright (C) 2021, Uri Shaked. Released under the MIT License.
*/

#include "pitches.h"
#include "melodies.h"
#define SPEAKER_PIN 8

const uint8_t buttonPins[] = {12, 11};
const int buttonMelodies[] = {
    1, 2};
const int numTones = sizeof(buttonPins) / sizeof(buttonPins[0]);

void setup()
{
  for (uint8_t i = 0; i < numTones; i++)
  {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  pinMode(SPEAKER_PIN, OUTPUT);
}

void loop()
{
  int song = 0;
  for (uint8_t i = 0; i < numTones; i++)
  {
    if (digitalRead(buttonPins[i]) == LOW)
    {
      song = buttonMelodies[i];
    }
  }
  if (song)
  {
    sing(song);
  }
  else
  {
    noTone(SPEAKER_PIN);
  }
}