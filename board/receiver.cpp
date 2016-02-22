#include "Arduino.h"
#include <SoftwareSerial.h>
#include "constants.h"

unsigned long lastRecvTime;

SoftwareSerial btSerial(BT_RX_PIN, BT_TX_PIN);

void initReceiver() {
  btSerial.begin(9600);
}

int isConnected() {
  return (millis() - lastRecvTime) < DISCONNECT_TIME;
}

int receive() {
  if (btSerial.available() > 0) {
    byte[2] buffer;
    int len = btSerial.readBytes(buffer, 2);
    if (len == 2) {
      lastRecvTime = millis();
    }
    return (buffer[1]) | (buffer[0] << 8);
  } else {
    return -1;
  }
}

void send(byte[] buffer) {
  btSerial.write(buffer);
}
