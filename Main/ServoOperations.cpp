#include <Arduino.h>
#include "ServoOperations.h"

ServoOperations::ServoOperations()
{
  LOG_ServoOperations("ServoOperations::ServoOperations()");
  m_MyServo = new Servo();
}

void ServoOperations::setup()
{
  LOG_ServoOperations("ServoOperations::setup()");
  m_MyServo->attach(SERVO_PIN_IN_USE);
  m_MyServo->write(0);
  delay(SERVO_ALLIGN_DELAY);
  m_MyServo->write(90);
  delay(SERVO_ALLIGN_DELAY);
  m_MyServo->write(180);
  delay(SERVO_ALLIGN_DELAY);
  m_MyServo->write(90);
}

void ServoOperations::loop()
{
  LOG_ServoOperations_LOOP("ServoOperations::loop()");
}

void ServoOperations::rotate(int angle)
{
  LOG_ServoOperations("ServoOperations::rotate(int angle)");
  m_MyServo->write(angle);
}
