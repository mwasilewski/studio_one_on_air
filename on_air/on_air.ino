#include <MIDI.h>

#if defined(USBCON)
#include <midi_UsbTransport.h>

static const unsigned sUsbTransportBufferSize = 16;
typedef midi::UsbTransport<sUsbTransportBufferSize> UsbTransport;

UsbTransport sUsbTransport;

MIDI_CREATE_INSTANCE(UsbTransport, sUsbTransport, UsbMidi);

#else
#error "No USB available"
#endif

int RXLED = 10;

 void handleUsbNoteOn(byte channel, byte pitch, byte velocity)
 {
  
  if(pitch == 95){
    if(velocity == 0){
      digitalWrite(RXLED, LOW);
    }else{
      digitalWrite(RXLED, HIGH);
    }
  }
    
 }

 void handleUsbNoteOff(byte channel, byte pitch, byte velocity)
 {
  
  if(pitch == 95){
    if(velocity == 0){
      digitalWrite(RXLED, LOW);
    }else{
      digitalWrite(RXLED, HIGH);
    }
  }
    
 }

 void setup()
 {
     pinMode(RXLED, OUTPUT);
     UsbMidi.begin();
     UsbMidi.setHandleNoteOn(handleUsbNoteOn);
     UsbMidi.setHandleNoteOff(handleUsbNoteOff);

     digitalWrite(RXLED, LOW);
 }

 void loop()
 {
     UsbMidi.read();
 }
