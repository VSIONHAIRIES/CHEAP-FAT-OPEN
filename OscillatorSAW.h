#pragma once

#include <Oscillator.h>
#include <AudioNodeInput.h>
#include <AudioNodeOutput.h>
#include <stdint.h>

class OscillatorSAW : public Oscillator {
public:

	OscillatorSAW();
	~OscillatorSAW(){}

	void process() override;

	// AudioNodeInput Frequency;
	AudioNodeOutput* AudioOut;
	
};