#ifndef PnDetails_h
#define PnDetails_h

#define RELAY_1 53
#define RELAY_2 51
#define RELAY_3 49
#define RELAY_4 47
#define RELAY_5 45
#define RELAY_6 43
#define RELAY_7 41
#define RELAY_8 39

#define NRF24L01_WIRE1 35
#define NRF24L01_WIRE2 33
#define NRF24L01_WIRE3 31
#define NRF24L01_WIRE4 29
#define NRF24L01_WIRE5 27

#define NRF24L01_CE 35
#define NRF24L01_SCK 33
#define NRF24L01_MISO 31
#define NRF24L01_CSN 29
#define NRF24L01_MOSI 27

#define ULTRASONIC_ECHO_PIN 23
#define ULTRASONIC_TRIG_PIN 25

#define IR_RECEIVE_PIN A5

#define LEFT_LINE_FOLLOW_IR A1
#define SOUND_PIN A2
#define RIGHT_LINE_FOLLOW_IR A0

#define BLUETOOTH_TX 14
#define BLUETOOTH_RX 15

#define RELAY_MODULE_PIN_1_HEAD_LAMP RELAY_1
#define RELAY_MODULE_PIN_2_TAIL_LAMP RELAY_2

#define SERVO_PIN_FREE 9
#define SERVO_PIN_IN_USE 10
/**While using this shield 6 analog Pins (which can be used as digital pins too), pin 2 and pin 13 of arduino are free.

In the case of using Servo motor, pins 9, 10, 2 are in use.

In the case of using DC motor, pin11 for #1, pin3 for #2, pin5 for #3, pin6 for #4 and pins 4, 7, 8 and 12 for all of them are in use.

In the case of using Stepper motor, pins 11 and 3 for #1, pins 5 and 6 for #2 and pins 4, 7, 8 and 12 for all of them are in use.

You can use free pins by wired connections.
*/
// Pins 4, 7, 8, and 12 may also all be used
#define RELAY_MODULE_PIN_3_LEFT_INDECATOR RELAY_3
#define RELAY_MODULE_PIN_4_RIGHT_INDECATOR RELAY_4

#define DCMOTER_LEFT_FRONT 1
#define DCMOTER_LEFT_BCAK 2
#define DCMOTER_RIGHT_FRONT 3
#define DCMOTER_RIGHT_BACK 4





#endif