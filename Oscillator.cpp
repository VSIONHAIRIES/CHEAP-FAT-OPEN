#include "Oscillator.h"

#define BIT_32 4294967296
#define PERIOD_MAX BIT_32 /// need to move this
#define SAMPLE_RATE 48000 /// need to move this

const float semiToneTable[] = {0.25,0.2648658,0.2806155,0.29730177,0.31498027,0.33370996,0.35355338,0.37457678,0.39685026,0.4204482,0.44544938,0.47193715,0.5,0.5297315,0.561231,0.59460354,0.62996054,0.6674199,0.70710677,0.74915355,0.7937005,0.8408964,0.8908987,0.9438743,1.0,1.0594631,1.122462,1.1892071,1.2599211,1.3348398,1.4142135,1.4983071,1.587401,1.6817929,1.7817974,1.8877486,2.0,2.1189263,2.244924,2.3784142,2.5198421,2.6696796,2.828427,2.9966142,3.174802,3.3635857,3.563595,3.7754972,4.0};
const extern uint32_t portamentoTimeTable[] = {1,5,9,13,17,21,26,30,35,39,44,49,54,59,64,69,74,79,85,90,96,101,107,113,119,125,132,138,144,151,158,165,172,179,187,194,202,210,218,226,234,243,252,261,270,279,289,299,309,320,330,341,353,364,376,388,401,414,427,440,455,469,484,500,516,532,549,566,584,602,622,642,663,684,706,729,753,778,804,831,859,888,919,951,984,1019,1056,1094,1134,1176,1221,1268,1317,1370,1425,1484,1547,1614,1684,1760,1841,1929,2023,2125,2234,2354,2484,2627,2785,2959,3152,3368,3611,3886,4201,4563,4987,5487,6087,6821,7739,8918,10491,12693,15996,21500,32509,65535};

Oscillator::Oscillator() {
	_period = 0;
	_phase = 0;
	_osc = 0;
	_accumulator = 0;
	_index = 0;
	_sample = 0;

	_freq = 110;
	_detune = 0;
	_semi = 0;
	_bend = 0;
	_portamento = 1;
	setFrequency();

	_gain = 65535;  // full gain is 0xFFFF

}


// FREQUENCY AND DETUNE FUNCTIONS
void Oscillator::setFrequency(float freq) {
	_freq = freq;
	setFrequency();
}


void inline Oscillator::setFrequency() {
	_period = int32_t(((_freq * _semi * (1 + _detune + _bend)) * PERIOD_MAX) / SAMPLE_RATE);
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
	if(gain < 0.0f) _gain = 0;
	else if(gain > 1.0f) _gain = 65535;
	else _gain = uint16_t(gain * 65535);
}


float Oscillator::getGain() {
	return float(_gain)/65535.0;
}        


