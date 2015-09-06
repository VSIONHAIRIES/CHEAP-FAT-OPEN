#include "AudioNodeInput.h"

AudioNodeInput::AudioNodeInput() : AudioNode() {
	_input = NULL;
	_value = 0;
}

void AudioNodeInput::process(int64_t& sample) {
	_value = 0;
	if(_input != NULL) {
		_input->process(_value);
		if(_value > 0x7FFFFFFF) _value = 0x7FFFFFFF; //truncate to upper limit of 32bit signed integers
		else if(_value < -0x80000000) _value = -0x80000000; //truncate to lower limit of 32bit signed integers
	}
	sample = _value;
}


int AudioNodeInput::getValue() {
	return _value;
}

AudioNode* AudioNodeInput::getInput() {
	return _input;
}


void AudioNodeInput::hook(AudioNode* input) {
	_input = input;
}


void AudioNodeInput::unhook(AudioNode* input) {
	_input = NULL;
}
