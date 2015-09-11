#include "OscillatorDPW.h"

OscillatorDPW::OscillatorDPW(): Oscillator() {
	AudioOut = new AudioNodeOutput(this, &_osc);
	_acc = 0;
	_f0 = 1; // we should not divide by zero!!!!
	_fs = (int64_t(48000) << 32); // placeholder until the below works // bitshift up with 32 then divide by 4, is the same as bitshifting up with 30
	// _fs = _audioCtx->sample_rate() << 30; // this throws and error. Something with implementation of audioContext.
	_x0 = 0;
	_z1 = 0;
	_c = 0;
}

void OscillatorDPW::process() {
	getExpFrequency();
	_accumulator += _dPhase;
	// _x0 = _accumulator;
//	_period = int(((_freq * _semi * (1 + _detune + _bend)) * PERIOD_MAX) / SAMPLE_RATE);


	_x0 = (int64_t(_accumulator) * int64_t(_accumulator)) >> 31;
	_y0 = _x0 - _z1;
	// _y0 = ((_x0 - _z1) * (_x0 + _z1)) >> 1;
	_z1 = _x0;
	_f0 = _freq0 * SAMPLE_RATE;  // placeholder, develop a way of getting the 
	// if(_f0 == 0) _f0 = 1;
	_f0 = (_f0 * ((BIT_32 - _dPhase) >> 16)) >> 16;
	_c = _fs / _f0;
	// _cprint = _c;
	_y0 = (_y0 * _c) >> 2;
	_osc = _y0;
	// _osc = SIGNED_BIT_32_HIGH - _accumulator;
	// _osc = int((int64_t(_accumulator) * int64_t(_gain)) >> 31);
}

