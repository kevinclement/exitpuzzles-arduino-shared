#include "Arduino.h"
#include "SerialManager.h"
#include "consts.h"

#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

SerialManager::SerialManager()
{  
}

void SerialManager::setup(String btName) {
  Serial.begin(115200);

    // set read timeout to something really low so we don't hang
  Serial.setTimeout(10);

  while (!Serial); // Wait untilSerial is ready 

  // Bluetooth device name
  SerialBT.begin(btName);
}
void SerialManager::registerCommand(SerialCommand cmd) {
  Serial.println(cmd.command);
  commands[cmdIndex++] = cmd;

  unsigned int cmdLen = cmd.args.length() + 1;
  if (cmdLen > longestCmd) {
    longestCmd = cmdLen;
  }
}

void SerialManager::print(const char *fmt, ...) {
  char buf[256];     // resulting string limited to 128 chars
  va_list args;
  va_start(args, fmt);
  vsnprintf(buf, 256, fmt, args);
  va_end(args);

  // print to serial
  Serial.print(buf);

  // print to bluetooth if available
  SerialBT.print(buf);
}

void SerialManager::handle() {
  // read bluetooth messages
  readAnyBluetoothMessage();

  // read serial messages
  readAnySerialMessage();
}

void SerialManager::readAnyBluetoothMessage() {
  if (!SerialBT.available()) {
    return;
  }

  // read and handle message from bluetooth
  String str = SerialBT.readStringUntil('\n');
  handleMessage(str);
}

void SerialManager::readAnySerialMessage() {
  if (!Serial.available()) {
    return;
  }

  // read and handle message from serial
  String str = Serial.readStringUntil('\n');
  handleMessage(str);
}

void SerialManager::handleMessage(String msg) {
  Serial.print("got '");
  Serial.print(msg);
  Serial.println("' command");

  String command = msg;
  int value = -1;

  // check if we need to split on space for advance commands
  for (int i = 0; i <= msg.length(); i++) {
      if (msg.charAt(i) == ' ') {         
          command = msg.substring(0, i);
          value = msg.substring(i+1, msg.length()).toInt();
      }
  }
 
  if (command == "enable") {
    print("enabling device to drop now...%s", CRLF);
    //ENABLED = true;
  }
  else if (command == "disable") {
    print("disabling device now...%s", CRLF);
    //ENABLED = false;
  }
  else if (command == "drop") {
    //FORCE_DROP = true;
    print("dropping bottom now...%s", CRLF);
  }
  else if (command == "threshold") {
    print("setting threshold to '%d'...%s", value, CRLF);
    // LIGHT_THRESHOLD = value;
    // EEPROM.put(LIGHT_THRESHOLD_ADDR, value);
    // EEPROM.commit();    
  }
  else if (command == "status") {
    //printVariables();
  }
  else if (command == "reset") {
    ESP.restart();
  } else {
    int str_len = command.length() + 1; 
    char char_array[str_len];
    command.toCharArray(char_array, str_len);
    print("unknown command: %s%s", char_array, CRLF);
  } 
}

void SerialManager::printHelp() {
  Serial.println("Available commands:");

  for (int i=0; i<cmdIndex; i++) {
    Serial.print("  ");
    Serial.print(commands[i].args);
    for(int j=commands[i].args.length(); j<longestCmd; j++) {
      Serial.print(" ");
    }
    Serial.print("- ");
    Serial.println(commands[i].desc);
  }
}