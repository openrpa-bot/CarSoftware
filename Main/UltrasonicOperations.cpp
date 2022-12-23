#include <Arduino.h>
#include "UltrasonicOperations.h"

UltrasonicOperations::UltrasonicOperations()
{
  LOG_UltrasonicOperations("UltrasonicOperations::UltrasonicOperations()");
  
  m_Distance = 100;
  m_NewPing = new NewPing(ULTRASONIC_TRIG_PIN, ULTRASONIC_ECHO_PIN, MAX_DISTANCE);
}

void UltrasonicOperations::setup()
{
  LOG_UltrasonicOperations("UltrasonicOperations::setup()");

  delay(2000);
  m_Distance = UltrasonicRead();
  delay(100);
  m_Distance = UltrasonicRead();
  delay(100);
  m_Distance = UltrasonicRead();
  delay(100);
  m_Distance = UltrasonicRead();
  delay(100);
}
void UltrasonicOperations::loop()
{
  LOG_UltrasonicOperations_LOOP("UltrasonicOperations::loop()");
}

int UltrasonicOperations::UltrasonicRead()
{
  LOG_UltrasonicOperations("UltrasonicOperations::UltrasonicRead()");

  delay(100);
  int cm = m_NewPing->ping_cm();

  if (cm == 0)
  {
    cm = 250;
  }
  return cm;
}
int UltrasonicOperations::lookRight()
{
  LOG_UltrasonicOperations("UltrasonicOperations::lookRight()");

  // myservo.write(50);
  delay(500);
  int m_Distance = UltrasonicRead();
  delay(100);
  // myservo.write(90);
  return m_Distance;
}

int UltrasonicOperations::lookLeft()
{
  LOG_UltrasonicOperations("UltrasonicOperations::lookLeft()");

  // myservo.write(130);
  delay(500);
  int m_Distance = UltrasonicRead();
  delay(100);
  // myservo.write(90);
  return m_Distance;
  delay(100);
}
