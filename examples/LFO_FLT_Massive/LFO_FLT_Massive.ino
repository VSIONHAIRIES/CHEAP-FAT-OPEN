#include <AudioContext.h>
#include <InputDevice.h>
#include <OscillatorSAW.h>
#include <OscillatorWAVE.h>
#include <OscillatorPWM.h>
#include <FilterLP6.h>

AudioContext audioCtx;
InputDevice* knob0 = new InputDevice();
InputDevice* knob1 = new InputDevice();
OscillatorSAW* saw0 = new OscillatorSAW();
OscillatorWAVE* wave0 = new OscillatorWAVE();
OscillatorWAVE* wave1 = new OscillatorWAVE();
OscillatorPWM* pwm0 = new OscillatorPWM();
FilterLP6* fltr0 = new FilterLP6();

void setup() {
  cli();
  knob0->ValueOut->connect(fltr0->CutoffIn);
  knob1->ValueOut->connect(fltr0->CutoffModAmountIn);
  wave0->AudioOut->connect(fltr0->CutoffModSourceIn);
  wave1->AudioOut->connect(pwm0->PWMIn);
  pwm0->AudioOut->connect(fltr0->AudioIn);
  fltr0->AudioOut->connect(audioCtx.destination());
  sei();  
}

void loop() {

  pwm0->setFrequency(55);  
  
  int pot0 = analogRead(A0);
  int pot1 = analogRead(A1);
  knob0->setValue10bit(pot0);
  knob1->setValue10bit(pot1);
    
  wave0->setWaveform(TRIANGLE);
  wave0->setFrequency(2.754893544);
  wave0->setGain(0.9999);

  wave1->setWaveform(TRIANGLE);
  wave1->setFrequency(0.1);
  wave1->setGain(0.8);
}
