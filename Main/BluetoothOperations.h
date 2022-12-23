#ifndef BluetoothOperations_h
#define BluetoothOperations_h
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "CommonInclude.h"

class BluetoothOperations
{
public:
    BluetoothOperations();
    void setup();
    void loop();
    int CheckBluetoothOperationRequest(OperationRequest* operationRequest);

private:
    SoftwareSerial *m_Bluetooth = NULL;
};
#endif