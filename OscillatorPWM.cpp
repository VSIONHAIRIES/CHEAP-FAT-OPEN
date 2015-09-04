#include "OscillatorPWM.h"

OscillatorPWM::OscillatorPWM(): Oscillator() {

	_pwm = 4675342;
}


void OscillatorPWM::process(int64_t& sample) {
	_phase = _phase + (_period - _phase) / _portamento;
	_accumulator = _accumulator + _phase;
	if(_accumulator < _pwm) _osc = 32767;
	else _osc = -32768;
	_sample = (_osc * _gain);  	
	_sample >>= 16;
	sample = _sample;

}

