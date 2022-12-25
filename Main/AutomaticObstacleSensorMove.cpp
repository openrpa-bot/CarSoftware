#include <Arduino.h>
#include "AutomaticObstacleSensorMove.h"

AutomaticObstacleSensorMove::AutomaticObstacleSensorMove(MotorMovement *motorMovement, UltrasonicOperations *ultrasonicOperations)
{
  LOG_AutomaticObstacleSensorMove("AutomaticObstacleSensorMove::AutomaticObstacleSensorMove()");
  this->m_MotorMovement = motorMovement;
  this->m_UltrasonicOperations = ultrasonicOperations;
  this->m_IsCruseControlModeActive = false;
}

void AutomaticObstacleSensorMove::setup()
{
  LOG_AutomaticObstacleSensorMove("AutomaticObstacleSensorMove::setup()");
  this->m_IsCruseControlModeActive = false;
}

void AutomaticObstacleSensorMove::loop()
{
  LOG_AutomaticObstacleSensorMove_LOOP("AutomaticObstacleSensorMove::loop()");
  if (m_IsCruseControlModeActive)
  {
    this->automatic();
  }
}
void AutomaticObstacleSensorMove::CruseControlModeStart()
{
  m_IsCruseControlModeActive = true;
  this->automatic();
}

void AutomaticObstacleSensorMove::automatic()
{
  LOG_AutomaticObstacleSensorMove("AutomaticObstacleSensorMove::automatic()");

  if (!m_IsCruseControlModeActive)
  {
    return;
  }

  int distance = this->m_UltrasonicOperations->UltrasonicRead();
  int distanceR = 0;
  int distanceL = 0;

  delay(1000);

  if (distance <= REVERCE_DISTANCE)
  {

    m_MotorMovement->Stop();
    delay(100);
    m_MotorMovement->moveBackward();
    delay(200);
    m_MotorMovement->Stop();
    delay(200);
    distanceR = this->m_UltrasonicOperations->lookRight();
    delay(200);
    distanceL = this->m_UltrasonicOperations->lookLeft();
    delay(200);
    Serial.print(distance);
    Serial.print(",");
    Serial.print(distanceL);
    Serial.print(",");
    Serial.print(distanceR);
    Serial.println(".");
    if (distanceR >= distanceL)
    {
      m_MotorMovement->turnRight();
      m_MotorMovement->Stop();
    }
    else
    {
      m_MotorMovement->turnLeft();
      m_MotorMovement->Stop();
    }
  }
  else
  {
    m_MotorMovement->moveForward();
  }
}