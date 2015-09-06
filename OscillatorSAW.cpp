#include "OscillatorSAW.h"



OscillatorSAW::OscillatorSAW(): Oscillator() {
	AudioOut = new AudioNodeOutput(this, &_osc);
}

void OscillatorSAW::process() {
	accumulator();
	_osc = int((_int64_t(accumulator) * int64_t(_gain)) >> 32);
}

