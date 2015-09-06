#include "OscillatorPWM.h"

OscillatorPWM::OscillatorPWM(): Oscillator() {
	AudioOut = new AudioNodeOutput(this, &_osc);
	_pwm = 0;
}


void OscillatorPWM::process() {
	accumulator();
	if(_accumulator < _pwm) _osc = 0x7FFFFFFF;
	else _osc = -0x80000000;
	_osc = int((_int64_t(_osc) * int64_t(_gain)) >> 32);
}

