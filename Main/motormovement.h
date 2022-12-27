#ifndef MotorMovement_h
#define MotorMovement_h

#include "CommonInclude.h"
#include <Arduino.h>
#include <AFMotor.h>

class MotorMovement
{
public:
    MotorMovement();
    MotorMovement( int iMaxSpeed, int iSpeedIncrement);
    void setup();
    void loop();

    void myFunction(int blinkRate);
    void Stop();
    void Speed(OperationRequest *operationRequest);
    void moveForward();
    void moveBackward();
    void turnRight();
    void turnLeft();

private:
    AF_DCMotor *m_DCMotor_Left_Front = NULL;
    AF_DCMotor *m_DCMotor_Left_Back = NULL;
    AF_DCMotor *m_DCMotor_Right_Front = NULL;
    AF_DCMotor *m_DCMotor_Right_Back = NULL;

    int m_iMaxSpeed = 0;
    int m_iSpeedIncrement = 0;

    boolean goesForward = false;
};
#endif