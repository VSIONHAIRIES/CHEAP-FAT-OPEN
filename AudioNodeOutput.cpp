#include <Arduino.h>
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
//	Serial.println("process running");
	_value = 0;
	_owner->process();
	_value = *_ptr;
	// if(_value > 0x7FFFFFFF) _value = 0x7FFFFFFF; //truncate to upper limit of 32bit signed integers
	// else if(_value < -0x80000000) _value = -0x80000000; //truncate to lower limit of 32bit signed integers
	// Serial.println(_value);
	sample = _value;
}


int AudioNodeOutput::getValue() {
	return _value;
}

AudioNode* AudioNodeOutput::getOutput() {
	return _output;
}