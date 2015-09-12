#pragma once

#include <Oscillator.h>
#include <stdint.h>

class OscillatorPWM : public Oscillator {
public:

	OscillatorPWM();
	~OscillatorPWM(){}

	void process() override;

	AudioNodeOutput* AudioOut;
	AudioNodeInput* PWMSourceIn;
	AudioNodeInput* PWMAmountIn;

protected:

	int64_t _pwm;
	int _pwmSourceIn;
	int _pwmAmountIn;

};