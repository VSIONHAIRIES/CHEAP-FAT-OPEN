#include <AudioContext.h>
#include <InputDevice.h>
#include <OscillatorPWM.h>
#include <OscillatorDPW.h>
#include <FilterLP6.h>

AudioContext audioCtx;
InputDevice* value0= new InputDevice();
InputDevice* knob0 = new InputDevice();
InputDevice* knob1 = new InputDevice();
OscillatorPWM* pwm0 = new OscillatorPWM();
OscillatorDPW* dpw0 = new OscillatorDPW();
FilterLP6* fltr0 = new FilterLP6();

void setup() {
  cli();
  value0->ValueOut->connect(dpw0->FrequencyIn);
  knob0->ValueOut->connect(pwm0->FrequencyIn);
  knob1->ValueOut->connect(pwm0->PWMAmountIn);
  dpw0->AudioOut->connect(pwm0->PWMSourceIn);
  pwm0->AudioOut->connect(audioCtx.destination());
//  fltr0->AudioOut->connect(audioCtx.destination());

  sei();  
}

void loop() {
  
  int pot0 = analogRead(A0);
  int pot1 = analogRead(A1);
  knob0->setValue10bit(pot0);
  knob1->setValue10bit(pot1);

  dpw0->_lfo = true;
  value0->setValue10bit(834); // we'll fix this :)

//  wave0->setWaveform(TRIANGLE);
//  wave0->setFrequency(0.01);
    
}
