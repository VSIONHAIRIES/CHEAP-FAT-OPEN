#pragma once

// http://www.w3.org/TR/webaudio/#AudioContext-section

#include <AudioNode.h>
#include <AudioDestinationNode.h>
#include <vector>

class AudioContext {
public:
	AudioContext();
	~AudioContext() {} /// need to finish

	AudioDestinationNode* destination();

	int sample_rate();

	uint64_t sample_clock();

private:

	AudioDestinationNode* destination_ptr;

	std::vector<AudioNode*> _nodes;

};