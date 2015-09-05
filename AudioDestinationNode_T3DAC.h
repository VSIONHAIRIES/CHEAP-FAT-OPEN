#pragma once

#include <AudioDestinationNode.h>
#include <stdint.h>

class AudioDestinationNode_T3DAC : public AudioDestinationNode {
public:

	AudioDestinationNode_T3DAC();

	void isr(void) override;

	int sample_rate() override; 

	uint64_t sample_clock() override;

private:
	volatile int64_t _sample;
	int64_t _accum;
	uint64_t _clock;

};

extern AudioDestinationNode_T3DAC t3dac_destinationNode;

