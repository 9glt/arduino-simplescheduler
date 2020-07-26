#include "SimpleScheduler.h"

void ledOn();
void ledOff();

void ledOn() {
  digitalWrite(LED_BUILTIN, HIGH);
  schedule(300, ledOff); // turn off after 300ms
}
void ledOff() {
  digitalWrite(LED_BUILTIN, LOW);
  schedule(500, ledOn); // turn on after 500ms
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  ledOn();
}

void loop() {
  scheduler_run();
}
