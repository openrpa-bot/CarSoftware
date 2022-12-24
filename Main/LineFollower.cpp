#include <Arduino.h>
#include "LineFollower.h"

LineFollower::LineFollower(LeftIRLineSensor *leftIRLineSensor, RightIRLineSensor *rightIRLineSensor, MotorMovement *motorMovement)
{
  LOG_LineFollower("LineFollower::LineFollower()");
  m_LeftIRLineSensor = leftIRLineSensor;
  m_RightIRLineSensor = rightIRLineSensor;
  m_MotorMovement = motorMovement;
}

void LineFollower::setup()
{
  LOG_LineFollower("LineFollower::setup()");
}

void LineFollower::loop()
{
  LOG_LineFollower_LOOP("LineFollower::loop()");
  if (m_LineFollowerModeActiveState)
  {
    LineFollowedMove();
  }
}
void LineFollower::LineFollowerModeActivate()
{
  m_LineFollowerModeActiveState = true;
  LineFollowedMove();
}

void LineFollower::LineFollowedMove()
{

  if (!m_LineFollowerModeActiveState)
  {
    return;
  }
  int state = 0;
  int flag = 0;

  int rightIRSensorValue = m_RightIRLineSensor->GetValue();
  int leftIRSensorValue = m_LeftIRLineSensor->GetValue();
  
  Serial.print(leftIRSensorValue); Serial.print("<-Left:Right->"); Serial.println(rightIRSensorValue); 

  if (rightIRSensorValue == LOW && leftIRSensorValue == LOW)
  {
    // if(LOG){ Serial.write("Skipped\n"); }
    // automatic();
  }
  else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW)
  {
    m_MotorMovement->turnRight();
  }

  else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH)
  {
    m_MotorMovement->turnLeft();
  }
  else
  {
    m_MotorMovement->moveForward();
  }
}