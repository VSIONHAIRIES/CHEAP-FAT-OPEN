#pragma once

#include <AudioNode.h>
#include <AudioNodeInput.h>
#include <AudioNodeOutput.h>

#define BIT_32 4294967296

class Filter : public AudioNode {
public:

	Filter();
	virtual ~Filter(){}

// FILTER FUNCTIONS
	virtual void setCutoff(int cutoff);
	virtual int getCutoff();
	virtual void setResonance(int resonance);
	virtual int getResonance();

protected:

	int	_cutoff;
	int	_resonance;
	
};