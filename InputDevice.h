#pragma once

#include <AudioNode.h>
#include <AudioNodeOutput.h>
#include <stdint.h>

class InputDevice : public AudioNode {
public:

	InputDevice();
	virtual ~InputDevice(){};

	virtual void process();
		
	virtual void setValue(float value);
	virtual void setValue10bit(int value);

	AudioNodeOutput* ValueOut;

protected:

	int _value;	
};