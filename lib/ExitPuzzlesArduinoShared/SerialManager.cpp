#include "Arduino.h"
#include "SerialManager.h"
// #include "consts.h"
// #include "Logic.h"
// #include "BluetoothSerial.h"

// BluetoothSerial SerialBT;

SerialManager::SerialManager()
{  
}

void SerialManager::setup() {
}

void SerialManager::print(const char *fmt, ...) {
}

void SerialManager::handle() {
}

void SerialManager::readAnyBluetoothMessage() {
}

void SerialManager::readAnySerialMessage() {
}

void SerialManager::handleMessage(String msg) {
}

void SerialManager::printHelp() {
  Serial.println("Available commands:");
  Serial.println("  enable         - turns device on");
  Serial.println("  foo N          - set foo to value N");
  Serial.println("  status         - prints the status of the device variables");
  Serial.println("  reset          - software reset the device");
}