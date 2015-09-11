#include <AudioContext.h>
#include <InputDevice.h>
#include <OscillatorSAW.h>
#include <OscillatorWAVE.h>
#include <FilterLP6.h>

AudioContext audioCtx;
InputDevice* knob0 = new InputDevice();
InputDevice* knob1 = new InputDevice();
OscillatorSAW* saw0 = new OscillatorSAW();
OscillatorSAW* saw1 = new OscillatorSAW();
OscillatorWAVE* wave0 = new OscillatorWAVE();
FilterLP6* fltr0 = new FilterLP6();

void setup() {
  cli();
  knob0->ValueOut->connect(fltr0->CutoffIn);
  knob1->ValueOut->connect(saw0->FrequencyIn);
  saw0->AudioOut->connect(saw1->FrequencyIn);
  saw1->AudioOut->connect(fltr0->AudioIn);
  fltr0->AudioOut->connect(audioCtx.destination());
  sei();  
}

void loop() {
  
  int pot0 = analogRead(A0);
  int pot1 = analogRead(A1);
  knob0->setValue10bit(pot0);
  knob1->setValue10bit(pot1);
    
}
