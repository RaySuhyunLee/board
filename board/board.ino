#include <SoftwareSerial.h>
#include "constants.h"
#include "battery.h"
#include "receiver.h"
#include "leds.h"

/* motor */
Servo motor(MOTOR_PIN);

void initMotor() {
  motor.writeMicroseconds(MOTOR_INIT);
  delay(MOTOR_INIT_TIME);
}

boolean isNewConnection = true;

void setup() {
  initMotor();
}

void loop() {
  int buf = receive();
  if (isConnected() > 0) {
    if (isNewConnection) {
    }
    motor.writeMicroseconds(constrain(buf, MOTOR_IDLE, MOTOR_MAX));
  } else {
    isInit = true;
    motor.writeMicroseconds(MOTOR_INIT);
  }
}
