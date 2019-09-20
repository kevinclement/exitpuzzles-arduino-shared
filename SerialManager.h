#pragma once
#include "SerialCommand.h"

class SerialManager {
public:
  SerialManager();
  void setup(String btName);
  void registerCommand(SerialCommand cmd);
  void handle();
  void print(const char *fmt, ...);
  void printHelp();

private:
  void handleMessage(String msg);
  void readAnyBluetoothMessage();
  void readAnySerialMessage();

  SerialCommand commands[20]; // max 20 for now, i dont like malloc
  unsigned int cmdIndex = 0;
  unsigned int longestCmd = 0;
};

