#pragma once

#include <Oscillator.h>
#include <stdint.h>

class OscillatorSAW : public Oscillator {
public:

	OscillatorSAW();
	~OscillatorSAW(){}

	void process() override;

	AudioNodeOutput* AudioOut;
};