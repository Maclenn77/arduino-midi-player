#define rightPin 12
#define leftPin 9
#define playPin 10

const uint8_t controlPins[] = {rightPin, leftPin, playPin};
int buttonState = 1;

void changeState(int currentState, int nextState)
{
  Serial.print("Current State:");
  Serial.println(currentState);
  buttonState = currentState + nextState;
  Serial.print("buttonState: ");
  Serial.println(buttonState);
  if (buttonState >= 3)
  {
    Serial.print("Next State: ");
    Serial.println(1);
    buttonState = 1;
  }
  else if (buttonState <= 0)
  {
    Serial.print("Next State: ");
    Serial.println(2);
    buttonState = 2;
  }
}