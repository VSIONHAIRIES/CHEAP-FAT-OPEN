#pragma once

#include "AudioDestinationNode.h"
#include <stdint.h>

class AudioDestinationNode_T3DAC : public AudioDestinationNode {
public:

	AudioDestinationNode_T3DAC();

	void isr(void) override;

	int sample_rate() override; 

private:
	int64_t _accum;
	uint64_t outputSample;

};

extern AudioDestinationNode_T3DAC t3dac_destinationNode;

