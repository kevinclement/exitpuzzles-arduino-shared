#include "Arduino.h"
#include <SerialManager.h>

void setup() {
  SerialManager sm;
  sm.setup("mySampleBTName");
  sm.printHelp();
}

void loop() {
  // not used in this example
}
