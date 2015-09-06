#pragma once

#include <AudioNode.h>
#include <AudioNodeInput.h>

#define BIT_32 4294967296

class Filter : public AudioNode {
public:

	Filter() {
		_cutoff = BIT_32-1;
		_resonance = 0;
		_sample = 0;
	}
	virtual ~Filter(){}

// FILTER FUNCTIONS
	virtual void setCutoff(uint32_t cutoff) {_cutoff = cutoff;}
	virtual int64_t getCutoff() {return _cutoff;}
	virtual void setResonance(uint32_t resonance) {_resonance = resonance;}
	virtual int64_t getResonance() {return _resonance;}

protected:

	int64_t	_cutoff;
	int64_t	_resonance;
	int64_t	_sample;
	
};