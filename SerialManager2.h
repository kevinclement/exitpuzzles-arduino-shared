#pragma once

class SerialManager2 {
public:
  SerialManager2();
  void setup();
  void handle();
  void print(const char *fmt, ...);
  void printHelp();

private:
  void handleMessage(String msg);
  void readAnyBluetoothMessage();
  void readAnySerialMessage();
};
