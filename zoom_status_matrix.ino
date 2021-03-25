#include "M5Atom.h"
#include <BleKeyboard.h>

BleKeyboard bleKeyboard("M5AtomButton");

int zoom_mute_status = 1;
CRGB leds[NUM_LEDS];

void setup() {
  M5.begin(true, true, true);
  bleKeyboard.begin();
  Serial.begin(9600);
  M5.dis.drawpix(0, 0xf00000);
}

void loop() {
  delay(10);
  M5.update();
  if (bleKeyboard.isConnected()) {
    if (M5.Btn.pressedFor(20)) {
      bleKeyboard.press(KEY_LEFT_SHIFT);
      delay(100);
      bleKeyboard.press(KEY_LEFT_ALT);
      delay(100);
      bleKeyboard.press(KEY_LEFT_GUI);
      delay(100);
      bleKeyboard.press('m');
      delay(100);
      bleKeyboard.releaseAll();
    }
  }
  if (Serial.available() > 0) {
    String serial_input = Serial.readString();
    zoom_mute_status = serial_input.toInt();
    switch (zoom_mute_status) {
      case 0: { M5.dis.drawpix(0, 0xFF0000); break; }
      case 1: { M5.dis.drawpix(0, 0x00FF00); break; }
      case 2: { M5.dis.drawpix(0, 0xf00000); break; }
    }
    Serial.flush();
  }
}
