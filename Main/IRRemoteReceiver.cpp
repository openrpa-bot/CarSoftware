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
  if (IrReceiver.decode())
  {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.printIRResultShort(&Serial);
    if(IrReceiver.decodedIRData.decodedRawData == TV_REMOTE_POWERKEY){
        Serial.println("Power Putton Cliced");
    }
    IrReceiver.resume();
  }

  /*LOG_IRRemoteReceiver("IRRemoteReceiver::CheckIRRemoteOperationRequest()");

   operationRequest->operationType = OperationType::None;

   if (IrReceiver.decode()) {
       Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);

   }
    IrReceiver.resume();


 f (IrReceiver.decode()){
         Serial.println(m_IRrecv->, HEX);
         m_IRrecv->resume();
   }
     if (IrReceiver.decode())
     {
     //int signalReceived = IrReceiver.decodedIRData;
     Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
     IrReceiver.printIRResultShort(&Serial);
     //Serial.print("Code: "); Serial.print(signalReceived, HEX); Serial.println(",\n");
     IrReceiver.resume();
     } else {
         Serial.println("else");
     }

   if (m_Bluetooth->available() > 0)
   {
     int command = m_Bluetooth->read();

     Serial.print(command); Serial.print(": Received the BlueTooth Command\n");

     switch (command)
     {
     case 'F':
       operationRequest->operationType = OperationType::MoveForward;
       break;
     case 'B':
       operationRequest->operationType = OperationType::MoveBackword;
       break;
     case 'L':
       operationRequest->operationType = OperationType::LeftTurn;
       break;
     case 'R':
       operationRequest->operationType = OperationType::RightTurn;
       break;

     case 'D':
       operationRequest->operationType = OperationType::StopMoveing;
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
       operationRequest->operationRequestData.Speed = command - '0';
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
   }
   return operationRequest->operationType;*/
}
