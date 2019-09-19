#include "Arduino.h"
#include <SerialManager.h>
#include <SerialCommand.h>

SerialManager sm;

void testCB(int v) {
  Serial.println("test cb 2");
}

void setFoo(int v) {
  Serial.print("Setting foo to ");
  Serial.println(v);
}

void setup() {
  sm.setup("mySampleBTName");

  sm.registerCommand(SerialCommand("debug",  'd', &testCB, "debug",  "turns device debugging on"));
  sm.registerCommand(SerialCommand("enable", 'e', &testCB, "enable", "turns device on"));
  sm.registerCommand(SerialCommand("foo",    'f', &setFoo, "foo N",  "set foo to value N"));
  sm.registerCommand(SerialCommand("status", 's', &testCB, "status", "prints the status of the device variables"));
  sm.registerCommand(SerialCommand("reset",  'r', &testCB, "reset",  "software reset the device"));

  sm.printHelp();
}

void loop() {
  sm.handle();
}