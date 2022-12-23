#include <Arduino.h> 
#include "BluetoothOperations.h"

BluetoothOperations::BluetoothOperations(){
    m_Bluetooth= new SoftwareSerial(BLUETOOTH_RX, BLUETOOTH_TX);  // RX, TX
};
void BluetoothOperations::setup(){
  m_Bluetooth->begin(BLUETOOTH_PORT);
}
int BluetoothOperations::BluetoothTrueRoFalse( ){
  char command;
  if (m_Bluetooth->available() > 0){
    command = m_Bluetooth->read();

    /*if (LOG) { Serial.write(command); }
    //moveStop();
    Serial.write(command);
    switch (command) {
      case 'F':
        isAutomatic = false;
        motorMovement.moveForward();
        break;
      case 'B':
        isAutomatic = false;
        motorMovement.moveBackward();
        break;
      case 'L':
        isAutomatic = false;
        motorMovement.turnLeft();
        break;
      case 'R':
        isAutomatic = false;
        motorMovement.turnRight();
        break;
      case 'X':
        isAutomatic = true;
        break;
      case 'x':
        isAutomatic = false;
        break;
      case '0':
        motorMovement.setSpeed(0);
        break;
     /* case '1':
        //speedSet = 20;
        Speed();
        break;
      case '2':
        speedSet = 40;
        Speed();
        break;
      case '3':
        speedSet = 60;
        Speed();
        break;
      case '4':
        speedSet = 80;
        Speed();
        break;
      case '5':
        speedSet = 100;
        Speed();
        break;
      case '6':
        speedSet = 120;
        Speed();
        break;
      case '7':
        speedSet = 140;
        Speed();
        break;
      case '8':
        speedSet = 160;
        Speed();
        break;
      case '9':
        speedSet = 180;
        Speed();
        break;
      case 'q':
        speedSet = 200;
        Speed();
        break;
      case 'D':
        moveStop();
        break;*/
    }
}