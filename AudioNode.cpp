#include <AudioNode.h>
#include <AudioContext.h>
#include <algorithm>

#include <Arduino.h>

AudioNode::~AudioNode() {
	for(unsigned int i = 0; i < _node_inputs.size(); i++) {
		_node_inputs[i]->unhook(this);
	}
	_node_inputs.clear();
	_node_outputs.clear();

	_sample = 0;
}


bool AudioNode::shouldProcess() {
	uint64_t clock = _audioCtx->sample_clock();
	if (_clock < clock) {
		_clock = clock;
		return true;
	}
	return false;
}

void AudioNode::connect(AudioNode* destination) {
	if(std::find(_node_outputs.begin(), _node_outputs.end(), destination) == _node_outputs.end()) {
		_node_outputs.push_back(destination);
		destination->hook(this);
	}
}


void AudioNode::disconnect(AudioNode* destination) {
	_node_outputs.erase(std::remove(_node_outputs.begin(), _node_outputs.end(), destination), _node_outputs.end());
	destination->unhook(this); // no lookup first??
}


int AudioNode::nbr_inputs() {
	return _node_inputs.size();
}


int AudioNode::nbr_outputs() {
	return _node_outputs.size();
}


void AudioNode::hook(AudioNode* input) {
	if(std::find(_node_inputs.begin(), _node_inputs.end(), input) == _node_inputs.end()) {
		_node_inputs.push_back(input);
	}
}


void AudioNode::unhook(AudioNode* destination) {
	_node_inputs.erase(std::remove(_node_inputs.begin(), _node_inputs.end(), destination), _node_inputs.end());
}
