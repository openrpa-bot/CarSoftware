#include <Arduino.h>
#include "LeftIRLineSensor.h"

void LeftIRLineSensor::setup() {
    #ifdef LOG_LeftIRLineSensor
    Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__func__); Serial.write("\n");   
    #endif
pinMode(LEFT_LINE_FOLLOW_IR, INPUT);
}    

LeftIRLineSensor::LeftIRLineSensor() {
    #ifdef LOG_LeftIRLineSensor
    Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__func__); Serial.write("\n");   
    #endif
}
void LeftIRLineSensor::loop() {
    #ifdef LOG_IRLineSensor
    Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__func__); Serial.write("\n");   
    #endif

}    
