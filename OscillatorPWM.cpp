#include "OscillatorPWM.h"

OscillatorPWM::OscillatorPWM(): Oscillator() {
	AudioOut = new AudioNodeOutput(this, &_osc);
	PWMSourceIn = new AudioNodeInput();
	PWMAmountIn = new AudioNodeInput();
	_pwm = 0;
	// _gain = SIGNED_BIT_32_HIGH;
}


void OscillatorPWM::process() {
//	accumulator();
	PWMSourceIn->process(_pwmSourceIn);
	PWMAmountIn->process(_pwmAmountIn);
	_pwm = (int64_t(_pwmSourceIn) * int64_t(_pwmAmountIn)) >> 31;
	getExpFrequency();
	if(_accumulator < _pwm) _osc = SIGNED_BIT_32_HIGH;
	else _osc = SIGNED_BIT_32_LOW + 1;
	_osc = int((int64_t(_osc) * int64_t(_gain)) >> 31);
}

