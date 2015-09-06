#include "OscillatorPWM.h"
#include <Arduino.h>

OscillatorPWM::OscillatorPWM(): Oscillator() {
	AudioOut = new AudioNodeOutput(this, &_osc);
	PWMIn = new AudioNodeInput();
	_pwm = 0;
}


void OscillatorPWM::process() {
	accumulator();
	PWMIn->process(_pwm);
	// _pwm = pwm;
	if(_accumulator < _pwm) _osc = SIGNED_BIT_32_HIGH;
	else _osc = SIGNED_BIT_32_LOW;
	// Serial.println(_osc);
//	_osc = int((int64_t(_osc) * int64_t(_gain)) >> 32);
}

