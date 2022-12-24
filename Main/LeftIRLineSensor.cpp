#include <Arduino.h>
#include "LeftIRLineSensor.h"

LeftIRLineSensor::LeftIRLineSensor()
{
    LOG_LeftIRLineSensor("LeftIRLineSensor::LeftIRLineSensor()");
}

void LeftIRLineSensor::setup()
{
    LOG_LeftIRLineSensor("LeftIRLineSensor::setup()");
    pinMode(LEFT_LINE_FOLLOW_IR, INPUT);
}

void LeftIRLineSensor::loop()
{
    LOG_LeftIRLineSensor_LOOP("LeftIRLineSensor::loop()");
}
int LeftIRLineSensor::GetValue(){
    return digitalRead(LEFT_LINE_FOLLOW_IR);
}