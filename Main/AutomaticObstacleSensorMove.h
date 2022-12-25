#ifndef AutomaticObstacleSensorMove_h
#define AutomaticObstacleSensorMove_h
#include <Arduino.h>
#include "CommonInclude.h"
#include "MotorMovement.h"
#include "UltrasonicOperations.h"

class AutomaticObstacleSensorMove
{
public:
    AutomaticObstacleSensorMove(MotorMovement *motorMovement, UltrasonicOperations *ultrasonicOperations);
    void setup();
    void loop();

    void CruseControlModeStart();
    void CruseControlModeRelease()
    {
        m_IsCruseControlModeActive = false;
    }

private:
    void automatic();
    MotorMovement *m_MotorMovement;
    UltrasonicOperations *m_UltrasonicOperations;
    bool m_IsCruseControlModeActive;
};
#endif