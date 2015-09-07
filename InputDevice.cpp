#include <InputDevice.h>

InputDevice::InputDevice() : AudioNode() {
	ValueOut = new AudioNodeOutput(this, &_value);
	_value = 0;
}


void InputDevice::process() {	// this function needs to here although it doesn't do anything.
}


void InputDevice::setValue(float value) {
	_value = int(value * float(SIGNED_BIT_32_HIGH));	
}


void InputDevice::setValue10bit(int value) {
	_value = (value << 22) + SIGNED_BIT_32_LOW;	
}