### Visual Zoom Mute Status Indicator

This sketch will give you a visual notification of your Zoom mute status.

### Requirements

1. An arduino compatible device with one or more LEDs
2. A copy of [arduino-serial](https://github.com/todbot/arduino-serial/) somewhere in your path

### How to use this

1. Save the applescript somewhere useful like $HOME
2. Load the sketch onto your device and take note of what the serial device name is (e.g. /dev/cu.usbserial-ASDFASDFASDFASDF)
3. Update the applescript and replace all instances of the serial device with yours. Update the arduino-serial path too.
4. Trigger the applescript somehow. I use skhd for this with the following command in my ~/.skhdrc file:
        
        lshift + lalt + lcmd - 0x2E : osascript /Users/tony/zoomstatus.scpt
        

