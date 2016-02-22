#include "Arduino.h"
#include "constants.h"

double getBatteryVoltage() {
  int battery_raw = analogRead(BATT_PIN);
  return battery_raw;
}

int isBatteryOk() {
  return getBatteryVoltage > BATT_VOLTATE_MIN;
}
