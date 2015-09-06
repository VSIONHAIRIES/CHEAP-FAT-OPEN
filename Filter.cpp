#include <Filter.h>


Filter::Filter() : AudioNode() {

	_cutoff = SIGNED_BIT_32_HIGH;
	_resonance = 0;
	_sample = 0;
}


void Filter::setCutoff(int cutoff) {
	_cutoff = cutoff;
}


int Filter::getCutoff() {
	return _cutoff;
}


void Filter::setResonance(int resonance) {
	_resonance = resonance;
}


int Filter::getResonance() {
	return _resonance;
}
