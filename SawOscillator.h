#pragma once

#include <Oscillator.h>
#include <stdint.h>

class SawOscillator : public Oscillator {
public:

	SawOscillator(float freq);
	~SawOscillator(){}

	void process(int64_t& sample) override;
	
};