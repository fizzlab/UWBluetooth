/**
 *  TODO: Add summary info
 */

#ifndef UWBluetooth_h
#define UWBluetooth_h

#include <Arduino.h>

class UWBluetooth {
public:
  void begin(String name);
  bool print(String message);
  bool println(String message);
}
