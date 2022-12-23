#include <Arduino.h> 
#include "LedOperations.h"

LedOperations::LedOperations() {
    #ifdef LOG_MotorMovement
    Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__func__); Serial.write("\n");   
    #endif
    
}

void LedOperations::setup() {
    #ifdef LOG_LedOperations
    Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__func__); Serial.write("\n");   
    #endif

}    
void LedOperations::loop() {
    #ifdef LOG_IRLineSensor
    Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__func__); Serial.write("\n");   
    #endif

}    




