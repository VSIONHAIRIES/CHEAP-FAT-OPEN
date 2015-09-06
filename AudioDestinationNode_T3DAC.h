#pragma once

#include "AudioDestinationNode.h"
#include <stdint.h>

class AudioDestinationNode_T3DAC : public AudioDestinationNode {
public:

	AudioDestinationNode_T3DAC();

	void isr(void) override;

	int sample_rate() override; 

private:
	int _accum;
	int outputSample;

};

extern AudioDestinationNode_T3DAC t3dac_destinationNode;

