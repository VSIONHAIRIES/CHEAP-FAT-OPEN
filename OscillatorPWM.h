#pragma once

#include <Oscillator.h>
#include <stdint.h>

class OscillatorPWM : public Oscillator {
public:

	OscillatorPWM();
	~OscillatorPWM(){}

	void process(int64_t& sample) override;

	int32_t _pwm;

protected:


};