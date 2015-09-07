#include <AudioContext.h>
#include <OscillatorSAW.h>
#include <OscillatorWAVE.h>
#include <OscillatorPWM.h>
#include <FilterLP6.h>

AudioContext audioCtx;
OscillatorSAW* saw0 = new OscillatorSAW();
OscillatorWAVE* wave0 = new OscillatorWAVE();
OscillatorWAVE* wave1 = new OscillatorWAVE();
OscillatorPWM* pwm0 = new OscillatorPWM();
FilterLP6* fltr0 = new FilterLP6();

void setup() {
  cli();
  wave0->AudioOut->connect(fltr0->CutoffIn);
  wave1->AudioOut->connect(pwm0->PWMIn);
  pwm0->AudioOut->connect(fltr0->AudioIn);
  fltr0->AudioOut->connect(audioCtx.destination());
  sei();  
}

void loop() {

  pwm0->setFrequency(55);  
  
  float pot0 = analogRead(A0);
  float pot1 = analogRead(A1);
  
  wave0->setWaveform(TRIANGLE);
  wave0->setFrequency(pot0 / 64.0);
  wave0->setGain(pot1 / 1024.0f);

  wave1->setWaveform(SINE);
  wave1->setFrequency(pot0 / 1246.7);
  wave1->setGain(0.8);
}
