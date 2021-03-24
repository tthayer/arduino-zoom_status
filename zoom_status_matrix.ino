#include <FastLED.h>

#define NUM_LEDS 25
#define DATA_PIN 27

int zoom_mute_status;

CRGB leds[NUM_LEDS];
void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(18);
}

void loop() {
  if (Serial.available() > 0) {
    String serial_input = Serial.readString();
    zoom_mute_status = serial_input.toInt();
    Serial.print("prior zoom status: ");
    Serial.println(zoom_mute_status);
    Serial.println(zoom_mute_status);
    switch (zoom_mute_status) {
      case 0: { fill_solid(leds, NUM_LEDS, CRGB::Blue); FastLED.show(); break; }
      case 1: { fill_solid(leds, NUM_LEDS, CRGB::Red); FastLED.show(); break; }
      case 2: { fill_solid(leds, NUM_LEDS, CRGB::Black); FastLED.show(); break; }
    }
  }
}
