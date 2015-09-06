#pragma once

#include <vector>
#include <stddef.h>
#include <stdint.h>

class AudioNode {
public:

	AudioNode() {}
	virtual ~AudioNode();

	virtual void connect(AudioNode* destination);
	virtual void disconnect(AudioNode* destination);

	virtual void process(int& sample) {}
	virtual void process() {}

	virtual int nbr_inputs(); 
	virtual int nbr_outputs();

	virtual void hook(AudioNode* input);
	virtual void unhook(AudioNode* input);

protected:
	
	std::vector<AudioNode*> _node_inputs;
	std::vector<AudioNode*> _node_outputs;

	int _sample;
};