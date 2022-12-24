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
    AF_DCMotor *m1 = NULL;
    AF_DCMotor *m2 = NULL;
    AF_DCMotor *m3 = NULL;
    AF_DCMotor *m4 = NULL;

    int m_iMaxSpeed = 0;
    int m_iSpeedIncrement = 0;

    boolean goesForward = false;
};
#endif