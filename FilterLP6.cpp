#include "FilterLP6.h"
#include <Arduino.h>

const int64_t filterCoefficient[] = {
	#include <filterCoefficients_1poleLP.inc>
};


FilterLP6::FilterLP6() : Filter() {
	// AudioIn = new AudioNodeInput();
	// CutoffIn = new AudioNodeInput();
	// CutoffModSourceIn = new AudioNodeInput();
	// CutoffModAmountIn = new AudioNodeInput();

	// AudioOut = new AudioNodeOutput(this, &_audioOut);

	_a0 = 0;
	_a1 = 0;
	_b0 = 0;
	_b1 = 0;
	_x0 = 0;
	_x1 = 0;
	_y0 = 0;
	_y1 = 0;

	// _cutoffModSource = 0;
	// _cutoffModAmount = 0;
}

void FilterLP6::process() {
	// Serial.println("FilterLP6 process() running");

	AudioIn->process(_audioIn);
	_x0 = _audioIn;
	CutoffIn->process(_cutoff);
	CutoffModAmountIn->process(_cutoffModAmount);  // need to check if input is connected!!!!!
	CutoffModSourceIn->process(_cutoffModSource);  // need to check if input is connected!!!!!

	int64_t mod = (int64_t(_cutoffModAmount) * (int64_t(_cutoffModSource)))>>32;
	int64_t c = (mod + int64_t(_cutoff));
	if(c > SIGNED_BIT_32_HIGH) c = SIGNED_BIT_32_HIGH;
	else if(c < SIGNED_BIT_32_LOW) c = SIGNED_BIT_32_LOW;
	c += SIGNED_BIT_32_HIGH;
	// c = ((((c * 32768) >> 15) + 65536) >> 1);


    _b1 = filterCoefficient[c>>24]; // we're only taking c back 23, as there is 
    _a0 = BIT_32 - _b1;
    
    _y0 = (_a0 * _x0 + _b1 * _y1) >> 32;
    _y1 = _y0;

	_audioOut = _y0;

}
