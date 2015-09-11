#include <AudioContext.h>
#include <InputDevice.h>
#include <OscillatorDPW.h>
#include <OscillatorWAVE.h>
#include <FilterLP6.h>

AudioContext audioCtx;
InputDevice* value0= new InputDevice();
InputDevice* knob0 = new InputDevice();
InputDevice* knob1 = new InputDevice();
OscillatorDPW* dpw0 = new OscillatorDPW();
OscillatorWAVE* wave0 = new OscillatorWAVE();
FilterLP6* fltr0 = new FilterLP6();

void setup() {
  cli();
  
//  value0->ValueOut->connect(dpw0->FrequencyIn);
  knob0->ValueOut->connect(dpw0->FrequencyIn);
  knob1->ValueOut->connect(dpw0->FMAmountIn);
  wave0->AudioOut->connect(dpw0->FMSourceIn);
  dpw0->AudioOut->connect(audioCtx.destination());
//  fltr0->AudioOut->connect(audioCtx.destination());
  sei();  
}

void loop() {
    
  int pot0 = analogRead(A0);
  int pot1 = analogRead(A1);
  knob0->setValue10bit(pot0);
  knob1->setValue10bit(pot1);

  wave0->setWaveform(SAW);
  wave0->setFrequency(2.0);

}
