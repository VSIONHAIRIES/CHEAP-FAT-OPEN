#include "OscillatorSAW.h"

OscillatorSAW::OscillatorSAW(): Oscillator() {
	AudioOut = new AudioNodeOutput(this, &_osc);
}

void OscillatorSAW::process() {
	// FrequencyIn->process(_frequencyIn);
	// setExpFrequencyInt32(_frequencyIn);
	// accumulator();
	getExpFrequency();
	_accumulator += _dPhase;	
	_osc = SIGNED_BIT_32_HIGH - _accumulator;
	_osc = int((int64_t(_osc) * int64_t(_gain)) >> 31);
}

