#include <Oscillator.h>

#define BIT_32 4294967296
#define PERIOD_MAX BIT_32 /// need to move this
#define SAMPLE_RATE 48000 /// need to move this

const float semiToneTable[] = {0.25,0.2648658,0.2806155,0.29730177,0.31498027,0.33370996,0.35355338,0.37457678,0.39685026,0.4204482,0.44544938,0.47193715,0.5,0.5297315,0.561231,0.59460354,0.62996054,0.6674199,0.70710677,0.74915355,0.7937005,0.8408964,0.8908987,0.9438743,1.0,1.0594631,1.122462,1.1892071,1.2599211,1.3348398,1.4142135,1.4983071,1.587401,1.6817929,1.7817974,1.8877486,2.0,2.1189263,2.244924,2.3784142,2.5198421,2.6696796,2.828427,2.9966142,3.174802,3.3635857,3.563595,3.7754972,4.0};

Oscillator::Oscillator() : AudioNode() {
	_period = 0;
	_phase = 0;
	_osc = 0;
	_accumulator = 0;
	_sample = 0;

	setFrequency(110.0f);
	setDetune(0.0f);
	setBend(0.0f);
	setPortamento(1);
	setSemitone(0);

	_gain = 0x7FFFFFFF;  // full gain is 0x7FFFFFFF

}


void Oscillator::accumulator() {
	_accumulator = _accumulator + _period;
	
}


// FREQUENCY AND DETUNE FUNCTIONS
void Oscillator::setFrequency(float freq) {
	_freq = freq;
	setFrequency();
}


void inline Oscillator::setFrequency() {
	_period = int(((_freq * _semi * (1 + _detune + _bend)) * PERIOD_MAX) / SAMPLE_RATE);
}


void Oscillator::setSemitone(int8_t semi) {
	if(-25 < semi && semi < 25){
		_semi = semiToneTable[semi+24];
	} else if (semi < -24) {
		_semi = semiToneTable[0];
	} else {
		_semi = semiToneTable[48];
	}
	setFrequency();

}


void Oscillator::setDetune(float detune) {
	_detune = detune;
	setFrequency();
}


void Oscillator::setBend(float bend) {
	_bend = bend;
	setFrequency();

}


void Oscillator::setPortamento(int32_t port) {
	if(port == 0) port = 1; // should this check for negative values?
	_portamento = port;
}


// GAIN FUNCTIONS
void Oscillator::setGain(float gain){
	if(gain < -1.0f) _gain = -0x80000000;
	else if(gain > 1.0f) _gain = 0x7FFFFFFF;
	else _gain = int(int64_t(gain * 0x7FFFFFFF) >> 32);
}


float Oscillator::getGain() {
	return float(_gain)/0x7FFFFFFF;
}        

