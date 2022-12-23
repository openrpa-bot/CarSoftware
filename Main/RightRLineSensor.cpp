#include <Arduino.h>
#include "RightIRLineSensor.h"

void RightIRLineSensor::setup() {
    #ifdef LOG_LeftIRLineSensor
    Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__func__); Serial.write("\n");   
    #endif
 pinMode(RIGHT_LINE_FOLLOW_IR, INPUT);
}    

RightIRLineSensor::RightIRLineSensor() {
    #ifdef LOG_LeftIRLineSensor
    Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__func__); Serial.write("\n");   
    #endif
}