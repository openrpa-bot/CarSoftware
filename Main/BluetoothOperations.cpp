#include "BluetoothOperations.h"

BluetoothOperations::BluetoothOperations()
{
  LOG_BluetoothOperations("BluetoothOperations::BluetoothOperations()");
  m_Bluetooth = new SoftwareSerial(BLUETOOTH_RX, BLUETOOTH_TX); // RX, TX
}

void BluetoothOperations::setup()
{
  LOG_BluetoothOperations("BluetoothOperations::setup()");
  m_Bluetooth->begin(BLUETOOTH_PORT);
}

void BluetoothOperations::loop()
{
  LOG_BluetoothOperations_LOOP("BluetoothOperations::loop()");
}

int BluetoothOperations::BluetoothTrueRoFalse()
{
  LOG_BluetoothOperations("BluetoothOperations::BluetoothTrueRoFalse()");
  OperationType operationType = OperationType::None;
  if (m_Bluetooth->available() > 0)
  {
    int command = m_Bluetooth->read();
    switch (command)
    {
    case 'F':
      operationType = OperationType::MoveForward;
      break;
    case 'B':
      operationType = OperationType::MoveBackword;
      break;
    case 'L':
      operationType = OperationType::LeftTurn;
      break;
    case 'R':
      operationType = OperationType::RightTurn;
      break;

    case 'D':
      operationType = OperationType::StopMoveing;
      break;

    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case 'q':
      operationType = OperationType::Speed;
      break;

    case 'X':
      operationType = OperationType::CruseControlMode;
      break;
    case 'x':
      operationType = OperationType::LineFollowerMode;
      break;
    case 'W':
      operationType = OperationType::HendLightOn;
      break;
    case 'w':
      operationType = OperationType::HendLightOff;
      break;
    case 'U':
      operationType = OperationType::BackLightOn;
      break;
    case 'u':
      operationType = OperationType::BackLightOff;
      break;

    case 'V':
      operationType = OperationType::DeeperOn;
      break;
    case 'v':
      operationType = OperationType::DeeperOff;
      break;

    default:
      operationType = OperationType::Undefined;
      break;
    }
  }
}
