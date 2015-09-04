#include "OscillatorWAVE.h"
#include <Arduino.h>

const uint8_t waveTable[] = { 
	#include <waveTable8bit.inc>
};

OscillatorWAVE::OscillatorWAVE(): Oscillator() {
	_waveForm = 0;
}


void OscillatorWAVE::process(int64_t& sample) {
	_phase = _phase + (_period - _phase) / _portamento;
	_accumulator = _accumulator + _phase;
	_indx = _accumulator >> 24;
	_indx += 128; 
	_osc = waveTable[_indx + _waveForm];
	_osc -= 128;
	_osc <<= 8;
	_sample = (_osc * _gain);  	
	_sample >>= 16;
	sample = _sample;
}

void OscillatorWAVE::setWaveForm(uint8_t waveform) {
	if(waveform < 16) _waveForm = waveform<<8;
}

