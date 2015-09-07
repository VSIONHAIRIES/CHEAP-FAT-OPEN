#include "AudioContext.h"

#include "AudioDestinationNode_T3DAC.h"

AudioDestinationNode_T3DAC t3dac_destinationNode;

AudioContext::AudioContext() {
	destination_ptr = &t3dac_destinationNode;	
}

AudioDestinationNode* AudioContext::destination() {
	return destination_ptr;
}

int AudioContext::sample_rate() {
	return 	destination_ptr->sample_rate();
}

uint64_t AudioContext::sample_clock() {
	return 	destination_ptr->sample_clock();
}