#include "AudioNodeOutput.h"

AudioNodeOutput::AudioNodeOutput(AudioNode* owner, int* ptr) : AudioNode() {
	_owner = owner;
	_ptr = ptr;
	_output = NULL;
	_value = 0;
}


void AudioNodeOutput::connect(AudioNode* destination) {
	_output = destination;
	destination->hook(this);
}

void AudioNodeOutput::disconnect(AudioNode* destination) {
	if(destination == _output) destination->unhook(this);
}



void AudioNodeOutput::process(int& sample) {
	_value = 0;
	_owner->process();
	_value = *_ptr;
	sample = _value;
}


int AudioNodeOutput::getValue() {
	return _value;
}

AudioNode* AudioNodeOutput::getOutput() {
	return _output;
}