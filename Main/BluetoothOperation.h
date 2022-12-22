#ifndef BluetoothOperation_h
#define BluetoothOperation_h
#include <Arduino.h> 
#include <SoftwareSerial.h>
#include "CommonInclude.h"

class BluetoothOperation {
public:
BluetoothOperation();
int BluetoothTrueRoFalse( );
void setup();

private:
SoftwareSerial *m_Bluetooth = NULL;

};
#endif