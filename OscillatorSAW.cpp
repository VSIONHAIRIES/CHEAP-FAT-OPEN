#include "OscillatorSAW.h"

OscillatorSAW::OscillatorSAW(): Oscillator() {
	AudioOut = new AudioNodeOutput(this, &_osc);
}

void OscillatorSAW::process() {
	getExpFrequency();
	_osc = SIGNED_BIT_32_HIGH - _accumulator;
	_osc = int((int64_t(_osc) * int64_t(_gain)) >> 31);
}

