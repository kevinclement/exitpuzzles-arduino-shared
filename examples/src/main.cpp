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
  // not used in this example
  sm.handle();
}

  // if (command == "enable") {
  //   print("enabling device to drop now...%s", CRLF);
  //   //ENABLED = true;
  // }
  // else if (command == "disable") {
  //   print("disabling device now...%s", CRLF);
  //   //ENABLED = false;
  // }
  // else if (command == "drop") {
  //   //FORCE_DROP = true;
  //   print("dropping bottom now...%s", CRLF);
  // }
  // else if (command == "threshold") {
  //   print("setting threshold to '%d'...%s", value, CRLF);
  //   // LIGHT_THRESHOLD = value;
  //   // EEPROM.put(LIGHT_THRESHOLD_ADDR, value);
  //   // EEPROM.commit();    
  // }
  // else if (command == "status") {
  //   //printVariables();
  // }
  // else if (command == "reset") {
  //   ESP.restart();