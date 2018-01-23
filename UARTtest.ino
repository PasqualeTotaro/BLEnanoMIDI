int blender=8;
int wm=9;
int noteb=26; //note to trigger blender
int notem=25; //note to trigger washing machine
int ccb=1; //midi control for blender
int ccm=2; //midi control for washing machine
int pos_mb=0; //target position of motor that controls blender
int pos_mm=0; //target position of motor that controls washing machine
int pos_mbc=0; //current position of motor that controls blender
int pos_mmc=0; //current position of motor that controls washing machine


#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

void HandleNoteOn(byte channel, byte pitch, byte velocity) 
{ 

  if (pitch == noteb){
  digitalWrite(blender, LOW);   // turn the LED on (HIGH is the voltage level)
  }
  if (pitch == notem){
  digitalWrite(wm, LOW);   // turn the LED on (HIGH is the voltage level)
  }
}
  

void HandleCC(byte channel, byte pitch, byte velocity) 
{
  // Do something here with your data!
  if (pitch==ccb){
    pos_mb=velocity;
  }

  if (pitch==ccm){
    pos_mm=velocity;
  }
  

}

void HandleNoteOff(byte channel, byte pitch, byte velocity) 
{
if (pitch == noteb){
  digitalWrite(blender, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
if (pitch == notem){
  digitalWrite(wm, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(blender, OUTPUT);
  digitalWrite(blender, HIGH);
  
  MIDI.begin(MIDI_CHANNEL_OMNI); 
  MIDI.setHandleNoteOn(HandleNoteOn); 
  MIDI.setHandleControlChange(HandleCC);
  MIDI.setHandleNoteOff(HandleNoteOff);
}

// the loop function runs over and over again forever
void loop() {
  MIDI.read();
}
