#include <Arduino.h>
#include "LedOperations.h"

LedOperations::LedOperations()
{
    LOG_LedOperations("LedOperations::LedOperations()");
}

void LedOperations::setup()
{
    LOG_LedOperations("LedOperations::setup()");
}

void LedOperations::loop()
{
    LOG_LedOperations_LOOP("LedOperations::loop()");
}
void LedOperations::FaontLightOn() { LOG_LedOperations_LOOP("LedOperations::FaontLightOn()"); }

void LedOperations::FrontLightOff() { LOG_LedOperations_LOOP("LedOperations::FrontLightOff()"); }

void LedOperations::BackLightOn() { LOG_LedOperations_LOOP("LedOperations::BackLightOn()"); }

void LedOperations::BackLightOff() { LOG_LedOperations_LOOP("LedOperations::BackLightOff()"); }

void LedOperations::DeeparOn() { LOG_LedOperations_LOOP("LedOperations::DeeparOn()"); }

void LedOperations::DeeparOff() { LOG_LedOperations_LOOP("LedOperations::DeeparOff()"); }