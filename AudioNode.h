#pragma once

#include <vector>
#include <stddef.h>
#include <stdint.h>

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
	virtual void shouldProcess();	

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