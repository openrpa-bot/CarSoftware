#include <Arduino.h>
#include "MotorMovement.h"

MotorMovement::MotorMovement()
{
  LOG_MotorMovement("MotorMovement::MotorMovement()");

  this->m_DCMotor_Left_Front = new AF_DCMotor(DCMOTER_LEFT_FRONT, MOTOR12_64KHZ);
  this->m_DCMotor_Left_Back = new AF_DCMotor(DCMOTER_LEFT_BCAK, MOTOR12_64KHZ);
  this->m_DCMotor_Right_Front = new AF_DCMotor(DCMOTER_RIGHT_FRONT, MOTOR34_64KHZ);
  this->m_DCMotor_Right_Back = new AF_DCMotor(DCMOTER_RIGHT_BACK, MOTOR34_64KHZ);
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
  int speed = 200;
  int delay_ms = 500;

  m_DCMotor_Left_Front->setSpeed(speed);
  m_DCMotor_Left_Front->run(FORWARD);
  delay(delay_ms);
  m_DCMotor_Left_Front->run(BACKWARD);
  delay(delay_ms);
  m_DCMotor_Left_Front->run(RELEASE);
  m_DCMotor_Left_Front->setSpeed(0);

  m_DCMotor_Left_Back->setSpeed(speed);
  m_DCMotor_Left_Back->run(FORWARD);
  delay(delay_ms);
  m_DCMotor_Left_Back->run(BACKWARD);
  delay(delay_ms);
  m_DCMotor_Left_Back->run(RELEASE);
  m_DCMotor_Left_Back->setSpeed(0);

  m_DCMotor_Right_Front->setSpeed(speed);
  m_DCMotor_Right_Front->run(FORWARD);
  delay(delay_ms);
  m_DCMotor_Right_Front->run(BACKWARD);
  delay(delay_ms);
  m_DCMotor_Right_Front->run(RELEASE);
  m_DCMotor_Right_Front->setSpeed(0);

  m_DCMotor_Right_Back->setSpeed(speed);
  m_DCMotor_Right_Back->run(FORWARD);
  delay(delay_ms);
  m_DCMotor_Right_Back->run(BACKWARD);
  delay(delay_ms);
  m_DCMotor_Right_Back->run(RELEASE);
  m_DCMotor_Right_Back->setSpeed(0);
}

void MotorMovement::loop()
{
  LOG_MotorMovement_LOOP("MotorMovement::loop()");
}

void MotorMovement::Stop()
{
  LOG_MotorMovement("MotorMovement::Stop()");

  m_DCMotor_Left_Front->run(RELEASE);
  m_DCMotor_Left_Back->run(RELEASE);
  m_DCMotor_Right_Front->run(RELEASE);
  m_DCMotor_Right_Back->run(RELEASE);
}

void MotorMovement::Speed(OperationRequest *operationRequest)
{
  // LOG_MotorMovement("MotorMovement::Speed()");

  m_DCMotor_Left_Front->setSpeed(operationRequest->operationRequestData.Speed * SPEED_WEIGHT);
  m_DCMotor_Left_Back->setSpeed(operationRequest->operationRequestData.Speed * SPEED_WEIGHT);
  m_DCMotor_Right_Front->setSpeed(operationRequest->operationRequestData.Speed * SPEED_WEIGHT);
  m_DCMotor_Right_Back->setSpeed(operationRequest->operationRequestData.Speed * SPEED_WEIGHT);
  delay(500);
}

void MotorMovement::moveForward()
{
  LOG_MotorMovement("MotorMovement::moveForward()");

  if (!this->goesForward)
  {
    LOG_MotorMovement("It was not moving forward.");
    goesForward = true;
    m_DCMotor_Left_Front->run(FORWARD);
    m_DCMotor_Left_Back->run(FORWARD);
    m_DCMotor_Right_Front->run(FORWARD);
    m_DCMotor_Right_Back->run(FORWARD);
  }
}

void MotorMovement::moveBackward()
{
  LOG_MotorMovement("MotorMovement::moveBackward()");

  goesForward = false;
  m_DCMotor_Left_Front->run(BACKWARD);
  m_DCMotor_Left_Back->run(BACKWARD);
  m_DCMotor_Right_Front->run(BACKWARD);
  m_DCMotor_Right_Back->run(BACKWARD);
}

void MotorMovement::turnRight()
{
  LOG_MotorMovement("MotorMovement::turnRight()");

  m_DCMotor_Left_Front->run(FORWARD);
  m_DCMotor_Left_Back->run(FORWARD);
  m_DCMotor_Right_Front->run(RELEASE);
  m_DCMotor_Right_Back->run(RELEASE);
  delay(3000);
  m_DCMotor_Left_Front->run(FORWARD);
  m_DCMotor_Left_Back->run(FORWARD);
  m_DCMotor_Right_Front->run(FORWARD);
  m_DCMotor_Right_Back->run(FORWARD);
}

void MotorMovement::turnLeft()
{
  LOG_MotorMovement("MotorMovement::turnLeft()");

  m_DCMotor_Left_Front->run(RELEASE);
  m_DCMotor_Left_Back->run(RELEASE);
  m_DCMotor_Right_Front->run(FORWARD);
  m_DCMotor_Right_Back->run(FORWARD);
  delay(3000);
  m_DCMotor_Left_Front->run(FORWARD);
  m_DCMotor_Left_Back->run(FORWARD);
  m_DCMotor_Right_Front->run(FORWARD);
  m_DCMotor_Right_Back->run(FORWARD);
}
