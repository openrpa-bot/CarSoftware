#ifndef BluetoothOperations_h
#define BluetoothOperations_h
#include <Arduino.h> 
#include <SoftwareSerial.h>
#include "CommonInclude.h"

class BluetoothOperations {
public:
BluetoothOperations();
int BluetoothTrueRoFalse( );
void setup();
void loop();
private:
SoftwareSerial *m_Bluetooth = NULL;

};
#endif