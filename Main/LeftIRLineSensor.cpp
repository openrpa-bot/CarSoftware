#include <Arduino.h>
#include "LeftIRLineSensor.h"

void LeftIRLineSensor::setup() {
    #ifdef LOG_LeftIRLineSensor
    Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__func__); Serial.write("\n");   
    #endif

}    

LeftIRLineSensor::LeftIRLineSensor() {
    #ifdef LOG_LeftIRLineSensor
    Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__func__); Serial.write("\n");   
    #endif
}