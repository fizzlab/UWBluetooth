/**
 *  TODO: Add summary info
 */

#include <SoftwareSerial.h>
#include "BluefruitConfig.h"
#include "Adafruit_BluefruitLE_UART.h"

SoftwareSerial bluefruitSS = SoftwareSerial(BLUEFRUIT_SWUART_TXD_PIN,
                                            BLUEFRUIT_SWUART_RXD_PIN);

Adafruit_BluefruitLE_UART ble(bluefruitSS,
                              BLUEFRUIT_UART_MODE_PIN,
                              BLUEFRUIT_UART_CTS_PIN,
                              BLUEFRUIT_UART_RTS_PIN);

UWBluetooth::UWBluetooth {
}

void error(const __FlashStringHelper*err) {
  Serial.println(err);
  while (1);
}

void UWBluetooth::begin(String name) {
  bool didBegin, didReset;

  didBegin = ble.begin(VERBOSE_MODE);

  if (!didBegin) {
    error(F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));
  }

  if (FACTORYRESET_ENABLE) {
    didReset = ble.factoryReset();
    if (!didReset){
      error(F("Couldn't factory reset"));
    }
  }

  ble.echo(false);
  ble.info();
  ble.reset();
}

bool UWBluetooth::print(String message) {
  ble.sendCommandCheckOK(F(message));
}

bool UWBluetooth::println(String message) {
  String withNewline = message + '\n';
  ble.sendCommandCheckOK(F(withNewline));
}
