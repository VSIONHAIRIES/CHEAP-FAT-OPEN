#pragma once

#include <AudioNode.h>
#include <AudioNodeInput.h>
#include <AudioNodeOutput.h>
#include <stdint.h>

class Oscillator : public AudioNode {
public:

	Oscillator();
	virtual ~Oscillator(){}

	void accumulator();

	// FREQUENCY AND DETUNE FUNCTIONS
	void setFrequency(float frequency);
	void inline setFrequency();
	void setSemitone(int8_t semi);
	void setDetune(float detune);
	void setBend(float bend);
	void setPortamento(int32_t port);
	
	// GAIN FUNCTIONS
	void setGain(float value); // 0.0 - 1.0
	float getGain();       // 0.0 - 1.0         

protected:

	float 		_freq;
	float 		_detune;
	float		_semi;
	float		_bend;
	int32_t 	_portamento;
	int			_gain;

	int 		_period;
	int			_phase;
	int 		_accumulator;
	int			_osc;	
	
};