#include "OscillatorWAVE.h"
#include <Arduino.h>

const uint8_t waveTable[] = { 
	#include <waveTable8bit.inc>
};

OscillatorWAVE::OscillatorWAVE(): Oscillator() {
	AudioOut = new AudioNodeOutput(this, &_osc);
	_waveform = 0;
}


void OscillatorWAVE::process() {
	accumulator();
	_indx = _accumulator >> 24;
	_indx += 128; // make wavetables signed
	_osc = waveTable[_indx + _waveform];
	_osc -= 128; // make wavetables signed
	_osc <<= 24;
	// _osc = int((int64_t(_osc) * int64_t(_gain)) >> 32);
}

void OscillatorWAVE::setWaveform(uint8_t waveform) {
	if(waveform < 16) _waveform = waveform<<8;
}

