#include "Arduino.h"
#include "SerialManager2.h"
// #include "consts.h"
// #include "Logic.h"
// #include "BluetoothSerial.h"

// BluetoothSerial SerialBT;

SerialManager2::SerialManager2()
{  
}

void SerialManager2::setup() {
}

void SerialManager2::print(const char *fmt, ...) {
}

void SerialManager2::handle() {
}

void SerialManager2::readAnyBluetoothMessage() {
}

void SerialManager2::readAnySerialMessage() {
}

void SerialManager2::handleMessage(String msg) {
}

void SerialManager2::printHelp() {
  Serial.println("Available commands:");
  Serial.println("  enable         - turns device on");
  Serial.println("  foo N          - set foo to value N");
  Serial.println("  status         - prints the status of the device variables");
  Serial.println("  reset          - software reset the device");
}