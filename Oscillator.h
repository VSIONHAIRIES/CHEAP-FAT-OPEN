#pragma once

#include <AudioNode.h>
#include <AudioNodeInput.h>
#include <AudioNodeOutput.h>
#include <stdint.h>
#include <math.h>

#define BIT_32 4294967296
#define PERIOD_MAX BIT_32 /// need to move this
#define SAMPLE_RATE 48000 /// need to move this

class Oscillator : public AudioNode {
public:

	Oscillator();
	virtual ~Oscillator(){}

	void accumulator();

	// FREQUENCY AND DETUNE FUNCTIONS
	void setFrequency(float frequency);
	void inline setFrequency();
	void setFrequencyInt32();
	void setExpFrequencyInt32(int freqIndex);
	void setSemitone(int8_t semi);
	void setDetune(float detune);
	void setBend(float bend);
	void setPortamento(int32_t port);
	
	// GAIN FUNCTIONS
	void setGain(float value); // 0.0 - 1.0
	float getGain();       // 0.0 - 1.0         

protected:

	int64_t		_expFrequency[256];

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

//variables for direct audiorate calculation of frequency
	int64_t		_dir;
	int64_t 	_indx;
	int64_t 	_ifrac;
	int64_t		_freq0;
	int64_t 	_freq1;
	int64_t		_dfreq;
	int64_t 	_ffrac;
	int 		_dPhase;
	

};