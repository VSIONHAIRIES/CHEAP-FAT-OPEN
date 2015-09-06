#pragma once
#include <AudioNode.h>

class AudioNodeOutput : public AudioNode {
public:

	AudioNodeOutput(AudioNode* owner, int* ptr);
	virtual ~AudioNodeOutput() {}

	void connect(AudioNode* destination) override;
	void disconnect(AudioNode* destination) override;

	void process(int& sample) override;

	int nbr_inputs() override {return 0;}
	int nbr_outputs() override {return 1;}

	void hook(AudioNode* input) override {}
	void unhook(AudioNode* input) override {}

	int getValue();
	AudioNode* getOutput();


protected:
	AudioNode* _owner;
	AudioNode* _output;
	int _value;
	int* _ptr;
};