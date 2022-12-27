#include <Arduino.h>
#include "LedOperations.h"

/*#define RELAY_1 53
#define RELAY_2 51
#define RELAY_3 49
#define RELAY_4 47
#define RELAY_5 45
#define RELAY_6 43
#define RELAY_7 41
#define RELAY_8 39
*/
LedOperations::LedOperations()
{
    LOG_LedOperations("LedOperations::LedOperations()");
    pinMode(RELAY_1, OUTPUT);
    pinMode(RELAY_2, OUTPUT);
    pinMode(RELAY_3, OUTPUT);
    pinMode(RELAY_4, OUTPUT);
    pinMode(RELAY_5, OUTPUT);
    pinMode(RELAY_6, OUTPUT);
    pinMode(RELAY_7, OUTPUT);
    pinMode(RELAY_8, OUTPUT);
    digitalWrite(RELAY_1, HIGH);    
    digitalWrite(RELAY_2, HIGH);    
    digitalWrite(RELAY_3, HIGH);    
    digitalWrite(RELAY_4, HIGH);    
    digitalWrite(RELAY_5, HIGH);    
    digitalWrite(RELAY_6, HIGH);    
    digitalWrite(RELAY_7, HIGH);    
    digitalWrite(RELAY_8, HIGH);
}

void LedOperations::setup()
{
    int dely_dw = 200;
    int dwStatus = LOW;
    LOG_LedOperations("LedOperations::setup()");
    digitalWrite(RELAY_1, dwStatus);
    delay(dely_dw);
    digitalWrite(RELAY_2, dwStatus);
    delay(dely_dw);
    digitalWrite(RELAY_3, dwStatus);
    delay(dely_dw);
    digitalWrite(RELAY_4, dwStatus);
    delay(dely_dw);
    digitalWrite(RELAY_5, dwStatus);
    delay(dely_dw);
    digitalWrite(RELAY_6, dwStatus);
    delay(dely_dw);
    digitalWrite(RELAY_7, dwStatus);
    delay(dely_dw);
    digitalWrite(RELAY_8, dwStatus);
    delay(dely_dw);

    dwStatus = HIGH;
    digitalWrite(RELAY_1, dwStatus);
    delay(dely_dw);
    digitalWrite(RELAY_2, dwStatus);
    delay(dely_dw);
    digitalWrite(RELAY_3, dwStatus);
    delay(dely_dw);
    digitalWrite(RELAY_4, dwStatus);
    delay(dely_dw);
    digitalWrite(RELAY_5, dwStatus);
    delay(dely_dw);
    digitalWrite(RELAY_6, dwStatus);
    delay(dely_dw);
    digitalWrite(RELAY_7, dwStatus);
    delay(dely_dw);
    digitalWrite(RELAY_8, dwStatus);
    delay(dely_dw);
}

void LedOperations::loop()
{
    LOG_LedOperations_LOOP("LedOperations::loop()");
}
void LedOperations::HendLightOn() { LOG_LedOperations_LOOP("LedOperations::FaontLightOn()"); }

void LedOperations::HendLightOff() { LOG_LedOperations_LOOP("LedOperations::FrontLightOff()"); }

void LedOperations::BackLightOn() { LOG_LedOperations_LOOP("LedOperations::BackLightOn()"); }

void LedOperations::BackLightOff() { LOG_LedOperations_LOOP("LedOperations::BackLightOff()"); }

void LedOperations::DeeparOn() { LOG_LedOperations_LOOP("LedOperations::DeeparOn()"); }

void LedOperations::DeeparOff() { LOG_LedOperations_LOOP("LedOperations::DeeparOff()"); }