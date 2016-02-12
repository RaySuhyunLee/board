#include <SoftwareSerial.h>

/* bluetooth */
#define RX 2
#define TX 3
SoftwareSerial bluetoothSerial(RX, TX);

/* sensor */
#define TRIGGER_PIN 0

/* data send interval */
unsigned long lastTime;
#define SEND_INTERVAL 10

void setup() {
  bluetoothSerial.begin(9600);
}

void loop() {
  unsigned long currentTime = millis();
  if (currentTime - lastTime >= SEND_INTERVAL) {
    lastTime = currentTime;
    int trigger_value = analogRead(TRIGGER_PIN);
    int output = map(trigger_value, 0, 1024); // FIXME change map value

    bluetoothSerial.println(output);
  }
}
