#include <Arduino.h> 
#include "LineFollower.h"

void LineFollower::setup() {
    #ifdef LOG_LedOperations
    Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__func__); Serial.write("\n");   
    #endif

}    

LineFollower::LineFollower() {

    #ifdef LOG_LedOperations
    Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__func__); Serial.write("\n");   
    #endif

}    