#pragma once

#include <Oscillator.h>
#include <AudioNodeInput.h>
#include <AudioNodeOutput.h>
#include <stdint.h>

class OscillatorPWM : public Oscillator {
public:

	OscillatorPWM();
	~OscillatorPWM(){}

	void process() override;

	int _pwm;

	AudioNodeOutput* AudioOut;
	AudioNodeInput* PWMIn;

protected:

};