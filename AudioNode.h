#pragma once

#include <vector>
#include <stddef.h>
#include <stdint.h>

#define SIGNED_BIT_32_HIGH 2147483647
#define SIGNED_BIT_32_LOW -2147483648
#define UNSIGNED_BIT_32_HIGH 4294967295
#define UNSIGNED_BIT_32_LOW 0 

class AudioContext;

class AudioNode {
public:

	AudioNode() : _audioCtx(0) {}
	AudioNode(AudioContext* audioContext) : _audioCtx(audioContext) {}
	virtual ~AudioNode();

	inline void set_context(AudioContext* audioContext) { _audioCtx = audioContext; }

	virtual void connect(AudioNode* destination);
	virtual void disconnect(AudioNode* destination);

	virtual void process(int& sample) {}
	virtual void process() {}
	
	virtual bool shouldProcess();	

	virtual int nbr_inputs(); 
	virtual int nbr_outputs();

	virtual void hook(AudioNode* input);
	virtual void unhook(AudioNode* input);

protected:
	
	AudioContext*	_audioCtx;
	std::vector<AudioNode*> _node_inputs;
	std::vector<AudioNode*> _node_outputs;

	int _sample;
	uint64_t _clock;
};