#pragma once
#include <AudioNode.h>

class AudioNodeInput : public AudioNode {
public:

	AudioNodeInput();
	virtual ~AudioNodeInput() {}

	void connect(AudioNode* destination) override {}
	void disconnect(AudioNode* destination) override {}

	void process(int64_t& sample) override;

	int nbr_inputs() override {return 1;}
	int nbr_outputs() override {return 0;}

	void hook(AudioNode* input) override;
	void unhook(AudioNode* input) override;

	int getValue();
	AudioNode* getInput();


protected:
	
	AudioNode* _input;
	int64_t _value;
};