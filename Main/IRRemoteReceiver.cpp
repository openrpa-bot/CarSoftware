#include <Arduino.h> 
#include "IRRemoteReceiver.h"

void IRRemoteReceiver::setup() {
    #ifdef LOG_IRRemoteReceiver
    Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__func__); Serial.write("\n");   
    #endif

}    

IRRemoteReceiver::IRRemoteReceiver() {
    #ifdef LOG_IRLineSensor
    Serial.write(__FILE__); Serial.write(":"); Serial.write(__LINE__); Serial.write(":"); Serial.write(__func__); Serial.write("\n");   
    #endif
}