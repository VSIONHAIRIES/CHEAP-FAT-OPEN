#include "OscillatorSAW.h"



OscillatorSAW::OscillatorSAW(): Oscillator() {
	AudioOut = new AudioNodeOutput(this, &_osc);
}

void OscillatorSAW::process() {
	accumulator();
	_osc = int((int64_t(_accumulator) * int64_t(_gain)) >> 32);
}

