#include <Arduino.h>
#include <IRremote.hpp>
#include "IRRemoteReceiver.h"

IRRemoteReceiver::IRRemoteReceiver()
{
  LOG_IRRemoteReceiver("IRRemoteReceiver::IRRemoteReceiver()");
}

void IRRemoteReceiver::setup()
{
  LOG_IRRemoteReceiver("IRRemoteReceiver::setup()");
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void IRRemoteReceiver::loop()
{
  LOG_IRRemoteReceiver_LOOP("IRRemoteReceiver::loop()");
}
int IRRemoteReceiver::CheckIRRemoteOperationRequest(OperationRequest *operationRequest)
{
  operationRequest->operationType = OperationType::None;
  if (IrReceiver.decode())
  {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.printIRResultShort(&Serial);
    switch (IrReceiver.decodedIRData.decodedRawData)
    {
    case TV_REMOTE_ForwardKey:
      operationRequest->operationType = OperationType::MoveForward;
      break;
    case TV_REMOTE_back:
      operationRequest->operationType = OperationType::MoveBackword;
      break;
    case TV_REMOTE_LeftKey:
      operationRequest->operationType = OperationType::LeftTurn;
      break;
    case TV_REMOTE_RightKey:
      operationRequest->operationType = OperationType::RightTurn;
      break;

    case TV_REMOTE_POWERKEY:
      operationRequest->operationType = OperationType::StopMoveing;
      break;

    case TV_REMOTE_0:
      operationRequest->operationRequestData.Speed = 0;
      operationRequest->operationType = OperationType::Speed;
      break;
    case TV_REMOTE_1:
      operationRequest->operationRequestData.Speed = 1;
      operationRequest->operationType = OperationType::Speed;
      break;
    case TV_REMOTE_2:
      operationRequest->operationRequestData.Speed = 2;
      operationRequest->operationType = OperationType::Speed;
      break;
    case TV_REMOTE_3:
      operationRequest->operationRequestData.Speed = 3;
      operationRequest->operationType = OperationType::Speed;
      break;
    case TV_REMOTE_4:
      operationRequest->operationRequestData.Speed = 4;
      operationRequest->operationType = OperationType::Speed;
      break;
    case TV_REMOTE_5:
      operationRequest->operationRequestData.Speed = 5;
      operationRequest->operationType = OperationType::Speed;
      break;
    case TV_REMOTE_6:
      operationRequest->operationRequestData.Speed = 6;
      operationRequest->operationType = OperationType::Speed;
      break;
    case TV_REMOTE_7:
      operationRequest->operationRequestData.Speed = 7;
      operationRequest->operationType = OperationType::Speed;
      break;
    case TV_REMOTE_8:
      operationRequest->operationRequestData.Speed = 8;
      operationRequest->operationType = OperationType::Speed;
      break;
    case TV_REMOTE_9:
      operationRequest->operationRequestData.Speed = 9;
      operationRequest->operationType = OperationType::Speed;
      break;
    case 'q':
      operationRequest->operationRequestData.Speed = 10;
      operationRequest->operationType = OperationType::Speed;
      break;
    case 'X':
      operationRequest->operationType = OperationType::CruseControlMode;
      break;
    case 'x':
      operationRequest->operationType = OperationType::LineFollowerMode;
      break;
    case 'W':
      operationRequest->operationType = OperationType::HendLightOn;
      break;
    case 'w':
      operationRequest->operationType = OperationType::HendLightOff;
      break;
    case 'U':
      operationRequest->operationType = OperationType::BackLightOn;
      break;
    case 'u':
      operationRequest->operationType = OperationType::BackLightOff;
      break;
    case 'V':
      operationRequest->operationType = OperationType::DeeperOn;
      break;
    case 'v':
      operationRequest->operationType = OperationType::DeeperOff;
      break;
    default:
      operationRequest->operationType = OperationType::Undefined;
      break;
    }
    IrReceiver.resume();
  }
  return operationRequest->operationType;
}
