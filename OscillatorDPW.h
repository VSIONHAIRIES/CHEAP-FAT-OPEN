#pragma once

#include <Oscillator.h>
#include <stdint.h>

class OscillatorDPW : public Oscillator {
public:

	OscillatorDPW();
	~OscillatorDPW(){}

	void process() override;

	AudioNodeOutput* AudioOut;

protected:
	int64_t _acc;
	int64_t _fs;
	int64_t _f0;
	int64_t _x0;
	int64_t _y0;
	int64_t _z1;
	int64_t _c;
	
};