#include <AudioContext.h>
#include <InputDevice.h>
#include <OscillatorWAVE.h>
#include <OscillatorDPW.h>
#include <FilterLP6.h>

AudioContext audioCtx;
InputDevice* value0= new InputDevice();
InputDevice* knob0 = new InputDevice();
InputDevice* knob1 = new InputDevice();
OscillatorWAVE* wave0 = new OscillatorWAVE();
OscillatorDPW* dpw0 = new OscillatorDPW();
FilterLP6* fltr0 = new FilterLP6();

void setup() {
  cli();
  value0->ValueOut->connect(dpw0->FrequencyIn);
  knob0->ValueOut->connect(wave0->FrequencyIn);
  knob1->ValueOut->connect(wave0->FMAmountIn);
  dpw0->AudioOut->connect(wave0->FMSourceIn);
  wave0->AudioOut->connect(fltr0->AudioIn);
  fltr0->AudioOut->connect(audioCtx.destination());

  sei();  
}

void loop() {
  
  int pot0 = analogRead(A0);
  int pot1 = analogRead(A1);
  knob0->setValue10bit(pot0);
  knob1->setValue10bit(pot1);

  dpw0->_lfo = true;
  value0->setValue10bit(835); // we'll fix this :)

  wave0->setWaveform(SINE);
//  wave0->setFrequency(0.01);
    
}
