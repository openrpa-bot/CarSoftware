#ifndef PnDetails_h
#define PnDetails_h

#define ULTRASONIC_ECHO_PIN A0
#define ULTRASONIC_TRIG_PIN A1

#define IR_SENSOR_LEFT A2

#define LEFT_LINE_FOLLOW_IR A3
#define SOUND_PIN A4
#define RIGHT_LINE_FOLLOW_IR A5

#define BLUETOOTH_TX 0
#define BLUETOOTH_RX 1

#define RELAY_MODULE_PIN_1_HEAD_LAMP 2
#define RELAY_MODULE_PIN_2_TAIL_LAMP 13

#define SERVO_PIN_FREE 9
#define SERVO_PIN_IN_USE 10
/**While using this shield 6 analog Pins (which can be used as digital pins too), pin 2 and pin 13 of arduino are free.

In the case of using Servo motor, pins 9, 10, 2 are in use.

In the case of using DC motor, pin11 for #1, pin3 for #2, pin5 for #3, pin6 for #4 and pins 4, 7, 8 and 12 for all of them are in use.

In the case of using Stepper motor, pins 11 and 3 for #1, pins 5 and 6 for #2 and pins 4, 7, 8 and 12 for all of them are in use.

You can use free pins by wired connections.
*/
// Pins 4, 7, 8, and 12 may also all be used
#define RELAY_MODULE_PIN_3_LEFT_INDECATOR SERVO_PIN_FREE
// #define RELAY_MODULE_PIN_4_RIGHT_INDECATOR 13

#define DCMOTER_LEFT_FRONT 1
#define DCMOTER_LEFT_BCAK 2
#define DCMOTER_RIGHT_FRONT 3
#define DCMOTER_RIGHT_BACK 4

#endif