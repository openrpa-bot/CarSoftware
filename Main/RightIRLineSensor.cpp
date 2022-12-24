#include <Arduino.h>
#include "RightIRLineSensor.h"

RightIRLineSensor::RightIRLineSensor()
{
    LOG_RightIRLineSensor("RightIRLineSensor::RightIRLineSensor()");
}

void RightIRLineSensor::setup()
{
    LOG_RightIRLineSensor("RightIRLineSensor::setup()");
    pinMode(RIGHT_LINE_FOLLOW_IR, INPUT);
}

void RightIRLineSensor::loop()
{
    LOG_RightIRLineSensor_LOOP("RightIRLineSensor::loop()");
}
int RightIRLineSensor::GetValue(){
    return digitalRead(RIGHT_LINE_FOLLOW_IR);
}