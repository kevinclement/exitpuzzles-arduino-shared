#include "Arduino.h"
#include <SerialManager.h>
#include <SerialCommand.h>

void testCB() {
  Serial.println("test cb 2");
}

void setup() {
  SerialManager sm;
  sm.setup("mySampleBTName");

  sm.registerCommand(SerialCommand("debug", 'd', &testCB, "debug", "turns device debugging on"));
  sm.registerCommand(SerialCommand("enable", 'e', &testCB, "enable", "turns device on"));
  sm.registerCommand(SerialCommand("foo", 'f', &testCB, "foo N", "set foo to value N"));
  sm.registerCommand(SerialCommand("status", 's', &testCB, "status", "prints the status of the device variables"));
  sm.registerCommand(SerialCommand("reset", 'r', &testCB, "reset", "software reset the device"));
  
  sm.printHelp();
}

void loop() {
  // not used in this example
}
