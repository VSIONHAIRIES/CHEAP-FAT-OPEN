#pragma once

// http://www.w3.org/TR/webaudio/#AudioNode-section

#include <vector>
#include <stdint.h>

class AudioNode {
public:

	AudioNode() {}
	virtual ~AudioNode();

	virtual void connect(AudioNode* destination);
	virtual void disconnect(AudioNode* destination);

	virtual void process(int64_t& sample) = 0;

	virtual int nbr_inputs(); 
	virtual int nbr_outputs();

	virtual void hook(AudioNode* input);
	virtual void unhook(AudioNode* input);

protected:
	
	std::vector<AudioNode*> _node_inputs;
	std::vector<AudioNode*> _node_outputs;
};