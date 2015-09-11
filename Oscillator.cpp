#include <Oscillator.h>

#include <Arduino.h>

const float semiToneTable[] = {0.25,0.2648658,0.2806155,0.29730177,0.31498027,0.33370996,0.35355338,0.37457678,0.39685026,0.4204482,0.44544938,0.47193715,0.5,0.5297315,0.561231,0.59460354,0.62996054,0.6674199,0.70710677,0.74915355,0.7937005,0.8408964,0.8908987,0.9438743,1.0,1.0594631,1.122462,1.1892071,1.2599211,1.3348398,1.4142135,1.4983071,1.587401,1.6817929,1.7817974,1.8877486,2.0,2.1189263,2.244924,2.3784142,2.5198421,2.6696796,2.828427,2.9966142,3.174802,3.3635857,3.563595,3.7754972,4.0};

Oscillator::Oscillator() : AudioNode() {

	FrequencyIn = new AudioNodeInput(); 
	FMSourceIn = new AudioNodeInput(); 
	FMAmountIn = new AudioNodeInput(); 

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
	setGain(1.0f);

	// this extends the standard midi frequencies from 128 to 256 discrete values,
	// extending the frequency range with -117 positions below to 0.00949 Hz
	// and +11 above to 23679 Hz.
	for (int i=0; i<=256; i++) {
		_expFrequency[i] = (int64_t(pow(2,((float(i) - 117.0 - 69.0) / 12.0)) * 440.0) << 32) / SAMPLE_RATE;  // divide by sample rate?
	}

	_dir = 1;
	_indx = 0;
	_ifrac = 0;
	_freq0 = 0;
	_freq1 = 0;
	_dfreq = 0;
	_ffrac = 0;
	_dPhase = 0;
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
	// setFrequencyIbt32();
}

// int Oscillator::getIndx(int indx){
// 	int dir = 1;
// 	if(indx < 0) {
// 		indx = -indx;
// 		dir = -1;
// 	}
// 	if(indx > SIGNED_BIT_32_HIGH) indx = SIGNED_BIT_32_HIGH;
// 	return indx * dir;	
// }


void Oscillator::getExpFrequency() {
	FrequencyIn->process(_frequencyIn);
	FMSourceIn->process(_fmSourceIn);
	FMAmountIn->process(_fmAmountIn);
	int64_t mod = (int64_t(_fmSourceIn) * int64_t(_fmAmountIn)) >> 32;
	int indx = int64_t(_frequencyIn) + mod;

	// setExpFrequencyInt32(_frequencyIn);


	_dir = 1;
	if(indx < 0) {
		indx = -indx;
		_dir = -1;
	}
	if(indx > SIGNED_BIT_32_HIGH) indx = SIGNED_BIT_32_HIGH;

	_indx = indx >> 24;  // take it down to the range 0-127
	_ifrac = indx - (_indx << 24);	// find the remainder in the indx after substracting the _indx for the array.
	_indx += (128 - 11);  // bring _indx into range 128 - 255 where the audible frequencies lie. // change this for LFO?

	_freq0 = _expFrequency[_indx];
	_freq1 = _expFrequency[_indx + 1];
	_dfreq = _freq1 - _freq0;
	_ffrac = (_ifrac * _dfreq) >> 24;
	_freq0 += _ffrac;

	// _dPhase = (_freq0 / SAMPLE_RATE) * _dir;
	_dPhase = _freq0 * _dir;

}


void Oscillator::setExpFrequencyInt32(int indx) {	// takes an int between 0 and SIGNED_BIT_32_HIGH
	_dir = 1;
	if(indx < 0) {
		indx = -indx;
		_dir = -1;
	}
	if(indx > SIGNED_BIT_32_HIGH) indx = SIGNED_BIT_32_HIGH;

	_indx = indx >> 24;  // take it down to the range 0-127
	_ifrac = indx - (_indx << 24);	// find the remainder in the indx after substracting the _indx for the array.
	_indx += (128 - 11);  // bring _indx into range 128 - 255 where the audible frequencies lie. // change this for LFO?

	_freq0 = _expFrequency[_indx];
	_freq1 = _expFrequency[_indx + 1];
	_dfreq = _freq1 - _freq0;
	_ffrac = (_ifrac * _dfreq) >> 24;
	_freq0 += _ffrac;

	_dPhase = (_freq0 / SAMPLE_RATE) * _dir;

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
	_detune = detune * 0.05946;	// piecewise linear approximation of expential relationship from 0-100 cents, i.e. one semitone.
	// _detune = detune;
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
	_gain = convertFloatInput(gain);
	// if(gain < -1.0f) _gain = SIGNED_BIT_32_LOW;
	// else if(gain > 1.0f) _gain = SIGNED_BIT_32_HIGH;
	// else _gain = int(int64_t(gain * SIGNED_BIT_32_HIGH));
}


float Oscillator::getGain() {
	return float(_gain)/SIGNED_BIT_32_HIGH;
}        

