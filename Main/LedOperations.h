#ifndef LedOperations_h
#define LedOperations_h
#include <Arduino.h>
#include "CommonInclude.h"

class LedOperations
{
public:
    LedOperations();
    void setup();
    void loop();
    
    void FaontLightOn();
    void FrontLightOff();
    void BackLightOn();
    void BackLightOff();
    void DeeparOn();
    void DeeparOff();
    
private:
};
#endif