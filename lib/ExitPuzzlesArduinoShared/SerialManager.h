#pragma once

class SerialManager {
public:
  SerialManager();
  void setup();
  void handle();
  void print(const char *fmt, ...);
  void printHelp();

private:
  void handleMessage(String msg);
  void readAnyBluetoothMessage();
  void readAnySerialMessage();
};

