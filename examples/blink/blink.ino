#include "SimpleScheduler.h"

void ledOn();
void ledOff();

void ledOn() {
  digitalWrite(LED_BUILTIN, HIGH);
  schedule(500, ledOff);
}
void ledOff() {
  digitalWrite(LED_BUILTIN, LOW);
  schedule(500, ledOn);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  ledOn();
}

void loop() {
  scheduler_run();
}
