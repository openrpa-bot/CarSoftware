#ifndef IRRemoteReceiver_h
#define IRRemoteReceiver_h
#include <Arduino.h>
#include "CommonInclude.h"

class IRRemoteReceiver
{
public:
    IRRemoteReceiver();
    void setup();
    void loop();
    int CheckIRRemoteOperationRequest(OperationRequest* operationRequest);

private:
};
#endif