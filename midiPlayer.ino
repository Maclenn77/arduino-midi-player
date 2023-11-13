/**
   Midi Player Arduino
*/

#include "pitches.h"
#include "melodies.h"
#include "changeState.h"
#define SPEAKER_PIN 8

const int numTones = sizeof(controlPins) / sizeof(controlPins[0]);

void setup()
{
  for (uint8_t i = 0; i < numTones; i++)
  {
    pinMode(controlPins[i], INPUT_PULLUP);
  }
  pinMode(SPEAKER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int action = 0;
  int nextState = 0;
  if (digitalRead(rightPin) == LOW)
  {
    nextState = 1;
    changeState(buttonState, nextState);
    delay(200);
  }
  else if (digitalRead(leftPin) == LOW)
  {
    nextState = -1;
    changeState(buttonState, nextState);
    delay(200);
  }

  if (digitalRead(playPin) == LOW)
  {
    sing(buttonState, SPEAKER_PIN);
  }
  else
  {
    noTone(SPEAKER_PIN);
  }
}