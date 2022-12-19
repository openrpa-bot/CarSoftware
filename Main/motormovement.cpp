#include <Arduino.h>
#include "MotorMovement.h"

MotorMovement::MotorMovement() {
    this->m1 = new AF_DCMotor(DCMOTER_LEFT_FRONT, MOTOR12_64KHZ);
    this->m2 = new AF_DCMotor(DCMOTER_LEFT_BCAK, MOTOR12_64KHZ);
    this->m3 = new AF_DCMotor(DCMOTER_RIGHT_FRONT, MOTOR34_64KHZ);
    this->m4 = new AF_DCMotor(DCMOTER_RIGHT_BACK, MOTOR34_64KHZ);

}

MotorMovement::MotorMovement(int iSpeed, int iMaxSpeed, int iSpeedIncrement) {
    this->m_iSpeed = iSpeed;
    this->m_iMaxSpeed = iMaxSpeed;
    this->m_iSpeedIncrement = iSpeedIncrement    ;
    MotorMovement();
}

void MotorMovement::Stop() {
  if (LOG) {
    Serial.write("moveStop\n");
  }
  m1->run(RELEASE);
  m2->run(RELEASE);
  m3->run(RELEASE);
  m4->run(RELEASE);
}

void MotorMovement::Speed() {
  if (LOG) {
    Serial.write("Speed\n");
  }
  m1->setSpeed(this->m_iSpeed);
  m2->setSpeed(this->m_iSpeed);
  m3->setSpeed(this->m_iSpeed);
  m4->setSpeed(this->m_iSpeed);
  delay(5);
}
void MotorMovement::moveForward() {
  if (LOG) {
    Serial.write("moveForward\n");
  }
  if (!this->goesForward) {
    if (LOG) {
      Serial.write("moveForward 1\n");
    }
    goesForward = true;
    m1->run(FORWARD);
    m2->run(FORWARD);
    m3->run(FORWARD);
    m4->run(FORWARD);
  }
}

void MotorMovement::moveBackward() {
  if (LOG) {
    Serial.write("moveBackward\n");
  }
  goesForward = false;
  m1->run(BACKWARD);
  m2->run(BACKWARD);
  m3->run(BACKWARD);
  m4->run(BACKWARD);
}

void MotorMovement::turnRight() {
  if (LOG) {
    Serial.write("turnRight\n");
  }
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

void MotorMovement::turnLeft() {
  if (LOG) {
    Serial.write("turnLeft\n");
  }
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
