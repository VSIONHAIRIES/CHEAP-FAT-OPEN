#pragma once

#include <AudioNode.h>
#include <AudioNodeOutput.h>
#include <stdint.h>

class InputDevice : public AudioNode {
public:

	InputDevice();
	virtual ~InputDevice(){}

	// this function (virtual void process(){}) doesn't do nothing because you are using 
	// AudioNodeOutput* ValueOut;
	// ideally, since the InputDevice is an AudioNode it already has the functionality
	// of an "ValueOut" as per InputDevice::connect() through AudioNode 

	// hence -- knob0->ValueOut->connect(fltr0->CutoffIn);
	// becomes - knob0->connect(fltr0->CutoffIn);
	// and would have the same functionality
	// yet through AudioNode we could connect more outputs (without needing a demux)
	// knob0->connect(fltr0->CutoffIn);
	// knob0->connect(pwm0->PWMIn);

	// the same comment goes to all the AudioOut and AudioIn defined in other files
	// i.e: AudioOut and AudioIn functionality is already there through AudioNode
	// if we assume a "dedicated meaning" of Audio (In and Out) for AudioNode's 
	// input and output connections (we've talked about that last weekend)

	// hence -- wave0->AudioOut->connect(fltr0->CutoffModSourceIn);
	// becomes -- wave0->connect(fltr0->CutoffModSourceIn);
	//
	// or -- pwm0->AudioOut->connect(fltr0->AudioIn);
	// becomes -- pwm0->connect(fltr0);	
	//
	// or with multiple outputs
	// wave0->connect(fltr0->CutoffModSourceIn);
	// wave0->connect(pwm);

	// for this particular InputDevice class there's no need for it to be an 
	// AudioNode per se if it has an AudioNodeOutput* ValueOut member, since these 
	// two are a little bit misleading and competing as explained above
	// (so does most of the classes with AudioIn and/or AudioOut - re: Oscillator, Filter)


	virtual void process(){}
		
	virtual void setValue(float value);
	virtual void setValue10bit(int value);

	AudioNodeOutput* ValueOut;

protected:

	int _value;	
};