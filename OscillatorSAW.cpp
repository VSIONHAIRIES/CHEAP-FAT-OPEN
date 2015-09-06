#include "OscillatorSAW.h"
#include <Arduino.h>


OscillatorSAW::OscillatorSAW(): Oscillator() {
	AudioOut = new AudioNodeOutput(this, &_osc);
}

void OscillatorSAW::process() {
//	Serial.println("OscillatorSAW process() running");
	accumulator();
	_osc = _accumulator;
}//	_osc = int((int64_t(_accumulator) * int64_t(_gain)) >> 32);


