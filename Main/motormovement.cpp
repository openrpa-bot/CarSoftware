#include <Arduino.h>
#include "MotorMovement.h"

MotorMovement::MotorMovement()
{
  LOG_MotorMovement("MotorMovement::MotorMovement()");

  this->m1 = new AF_DCMotor(DCMOTER_LEFT_FRONT, MOTOR12_64KHZ);
  this->m2 = new AF_DCMotor(DCMOTER_LEFT_BCAK, MOTOR12_64KHZ);
  this->m3 = new AF_DCMotor(DCMOTER_RIGHT_FRONT, MOTOR34_64KHZ);
  this->m4 = new AF_DCMotor(DCMOTER_RIGHT_BACK, MOTOR34_64KHZ);
}

MotorMovement::MotorMovement(int iMaxSpeed, int iSpeedIncrement)
{
  LOG_MotorMovement("MotorMovement::MotorMovement(int iSpeed, int iMaxSpeed, int iSpeedIncrement)");

  
  this->m_iMaxSpeed = iMaxSpeed;
  this->m_iSpeedIncrement = iSpeedIncrement;
  MotorMovement();
}

void MotorMovement::setup()
{
  LOG_MotorMovement("MotorMovement::setup()");
  m1->setSpeed(200);
  m2->setSpeed(200);
  m3->setSpeed(200);
  m4->setSpeed(200);

  m1->run(FORWARD);
  m2->run(FORWARD);
  m3->run(FORWARD);
  m4->run(FORWARD);
  delay(500);
  m1->run(BACKWARD);
  m2->run(BACKWARD);
  m3->run(BACKWARD);
  m4->run(BACKWARD);
  delay(500);
  m1->setSpeed(0);
  m2->setSpeed(0);
  m3->setSpeed(0);
  m4->setSpeed(0);
}

void MotorMovement::loop()
{
  LOG_MotorMovement_LOOP("MotorMovement::loop()");
}

void MotorMovement::Stop()
{
  LOG_MotorMovement("MotorMovement::Stop()");

  m1->run(RELEASE);
  m2->run(RELEASE);
  m3->run(RELEASE);
  m4->run(RELEASE);
}

void MotorMovement::Speed(OperationRequest *operationRequest)
{
  LOG_MotorMovement("MotorMovement::Speed()");

  m1->setSpeed(operationRequest->operationRequestData.Speed * SPEED_WEIGHT);
  m2->setSpeed(operationRequest->operationRequestData.Speed * SPEED_WEIGHT);
  m3->setSpeed(operationRequest->operationRequestData.Speed * SPEED_WEIGHT);
  m4->setSpeed(operationRequest->operationRequestData.Speed * SPEED_WEIGHT);
  delay(500);
}

void MotorMovement::moveForward()
{
  LOG_MotorMovement("MotorMovement::moveForward()");

  if (!this->goesForward)
  {
    LOG_MotorMovement("It was not moving forward.");
    goesForward = true;
    m1->run(FORWARD);
    m2->run(FORWARD);
    m3->run(FORWARD);
    m4->run(FORWARD);
  }
}

void MotorMovement::moveBackward()
{
  LOG_MotorMovement("MotorMovement::moveBackward()");

  goesForward = false;
  m1->run(BACKWARD);
  m2->run(BACKWARD);
  m3->run(BACKWARD);
  m4->run(BACKWARD);
}

void MotorMovement::turnRight()
{
  LOG_MotorMovement("MotorMovement::turnRight()");

  m1->run(FORWARD);
  m2->run(FORWARD);
  m3->run(BACKWARD);
  m4->run(BACKWARD);
  delay(500);
  m1->run(FORWARD);
  m2->run(FORWARD);
  m3->run(FORWARD);
  m4->run(FORWARD);
}

void MotorMovement::turnLeft()
{
  LOG_MotorMovement("MotorMovement::turnLeft()");

  m1->run(BACKWARD);
  m2->run(BACKWARD);
  m3->run(FORWARD);
  m4->run(FORWARD);
  delay(500);
  m1->run(FORWARD);
  m2->run(FORWARD);
  m3->run(FORWARD);
  m4->run(FORWARD);
}
