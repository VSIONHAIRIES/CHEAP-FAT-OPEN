#pragma once

// http://www.w3.org/TR/webaudio/#AudioDestinationNode

#include <AudioNode.h>

class AudioDestinationNode : public virtual AudioNode {
public:
	AudioDestinationNode() {}

	inline void connect(AudioNode* destination) override {}
	inline void disconnect(AudioNode* destination) override {}

	inline void process(int& sample) override {}

	inline int nbr_outputs() override { return 0; }

	// hardware driven interrupt
	virtual void isr() = 0;

	virtual int sample_rate() = 0;

	virtual uint64_t sample_clock() = 0;

};