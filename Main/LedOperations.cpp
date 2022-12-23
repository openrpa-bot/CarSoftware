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
