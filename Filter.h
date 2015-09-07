#pragma once

#include <AudioNode.h>
#include <AudioNodeInput.h>
#include <AudioNodeOutput.h>

class Filter : public AudioNode {
public:

	Filter();
	virtual ~Filter(){}

// FILTER FUNCTIONS
	virtual void setCutoff(float cutoff);
	virtual float getCutoff();
	virtual void setResonance(float resonance);
	virtual float getResonance();
	virtual void setCutoffModAmount(float cutoff);
	virtual float getCutoffModAmount();

    AudioNodeInput* AudioIn;
	AudioNodeInput* CutoffIn;
	AudioNodeInput* CutoffModSourceIn;
	AudioNodeInput* CutoffModAmountIn;

	AudioNodeOutput* AudioOut;	

protected:

	int _audioIn;
	int _audioOut;
	int _cutoffIn;
	int _cutoffModSourceIn;
	int _cutoffModAmountIn;

	int	_cutoff;
	int	_resonance;
    int _cutoffModSource;
    int _cutoffModAmount;
	
};