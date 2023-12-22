#include <MIDI.h>
#include <SoftwareSerial.h>

const int startStopButtonPin = 4;
bool isPlaying = false;


SoftwareSerial midiSerial(10, 11);

MIDI_CREATE_INSTANCE(SoftwareSerial, midiSerial, MIDI);


void setup() {
  pinMode(startStopButtonPin, INPUT_PULLUP);
  midiSerial.begin(31250);
}

void loop() {
  if (digitalRead(startStopButtonPin) == LOW) {
    if (!isPlaying) {
      MIDI.sendRealTime(0xFA);
      isPlaying = true;
    } else {
      MIDI.sendRealTime(0xFC);
      isPlaying = false;
    }
    delay(200);
  }

}
 