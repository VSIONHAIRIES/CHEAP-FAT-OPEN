#pragma once

#include <AudioNode.h>
#include <stdint.h>

class Oscillator : public AudioNode {
public:

	Oscillator();
	virtual ~Oscillator();

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

	float 			_freq;
	float 			_detune;
	float			_semi;
	float			_bend;
	int32_t 		_portamento;
	uint16_t		_gain;

	int32_t 		_period;
	int32_t			_phase;
	int32_t			_osc;	
	uint32_t 		_accumulator;
	int32_t			_index;
	int64_t			_sample;

	bool			_processing = false;

	
};