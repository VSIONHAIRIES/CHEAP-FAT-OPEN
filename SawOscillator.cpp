#include "SawOscillator.h"


SawOscillator::SawOscillator(float freq): Oscillator() {
	setFrequency(freq);
}


void SawOscillator::process(int64_t& sample) {
	_phase = _phase + (_period - _phase) / _portamento;
	_accumulator = _accumulator + _phase;
	_osc = _accumulator >> 16;
	_osc -= 32767;
	_sample = (_osc * _gain);  
	
	_sample >>= 16;

	sample = _sample;

}

