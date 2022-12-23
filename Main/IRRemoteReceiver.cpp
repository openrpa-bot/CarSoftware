#include <Arduino.h>
#include <IRremote.h>

#include "IRRemoteReceiver.h"

IRRemoteReceiver::IRRemoteReceiver()
{
    LOG_IRRemoteReceiver("IRRemoteReceiver::IRRemoteReceiver()");
}

void IRRemoteReceiver::setup()
{
    LOG_IRRemoteReceiver("IRRemoteReceiver::setup()");
    // IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void IRRemoteReceiver::loop()
{
    LOG_IRRemoteReceiver_LOOP("IRRemoteReceiver::loop()");
}
