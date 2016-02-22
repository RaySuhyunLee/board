#ifndef CONSTANTS_H_
#define CONSTANTS_H_

/* pins */
#define BT_RX_PIN 2 // bluetooth RX
#define BT_TX_PIN 3 // bluetooth TX
#define BATT_PIN 0 // battery voltage(analog)
#define MOTOR_PIN 4 // motor pwm output pin
#define HEADLAMP_PIN 5
#define BRAKE_LIGHT_PIN 6
#define STATUS_LIGHT_PIN 7

#define BATT_VOLTAGE_MIN 3.6

#define DISCONNECT_TIME 50 // consider as disconnected after 50 ms

/* motor */
#define MOTOR_IDLE 1000
#define MOTOR_START 1200
#define MOTOR_MAX 1700
#define MOTOR_INIT_TIME 5000

#endif
