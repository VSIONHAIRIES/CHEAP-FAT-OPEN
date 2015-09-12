#include <AudioContext.h>
#include <InputDevice.h>
#include <OscillatorSAW.h>
#include <OscillatorWAVE.h>
//#include <FilterLP6.h>

AudioContext audioCtx;
InputDevice* value0= new InputDevice();
InputDevice* knob0 = new InputDevice();
InputDevice* knob1 = new InputDevice();
OscillatorSAW* saw0 = new OscillatorSAW();
OscillatorWAVE* wave0 = new OscillatorWAVE();
//FilterLP6* fltr0 = new FilterLP6();

void setup() {
  cli();
  value0->ValueOut->connect(wave0->FrequencyIn);
  knob0->ValueOut->connect(saw0->FrequencyIn);
  knob1->ValueOut->connect(saw0->FMAmountIn);
  wave0->AudioOut->connect(saw0->FMSourceIn);
  saw0->AudioOut->connect(audioCtx.destination());
//  fltr0->AudioOut->connect(audioCtx.destination());

  sei();  
}

void loop() {
  
  int pot0 = analogRead(A0);
  int pot1 = analogRead(A1);
  knob0->setValue10bit(pot0);
  knob1->setValue10bit(pot1);

  wave0->_lfo = true;
  wave0->setWaveform(TRIANGLE);
  value0->setValue10bit(835);
    
}
