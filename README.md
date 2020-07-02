# arduino-simplescheduler
Simple as possible func scheduler

example

```cpp
#include "SimpleScheduler.h"

void loop1();
void loop2();

void loop1() {
  schedule(1000, loop2);
  Serial.println("loop 1. scheduling loop2");
}
void loop2() {
  schedule(1000, loop1);
  Serial.println("loop 2. scheduling loop1");
}

void setup() {
  Serial.begin(9600);
  schedule(1000, loop1);
}

void loop() {
  scheduler_run();
}
```
