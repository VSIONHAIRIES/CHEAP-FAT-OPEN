#include "FilterLP6.h"
#include <Arduino.h>

const int64_t filterCoefficient[] = {
	#include <filterCoefficients_1poleLP.inc>
};


FilterLP6::FilterLP6() : Filter() {
	AudioIn = new AudioNodeInput();
	CutoffIn = new AudioNodeInput();
	AudioOut = new AudioNodeOutput(this, &_audioOut);

	_a0 = 0;
	_a1 = 0;
	_b0 = 0;
	_b1 = 0;
	_x0 = 0;
	_x1 = 0;
	_y0 = 0;
	_y1 = 0;

	_cutoffModSource = 0;
	_cutoffModAmount = 0;
}

void FilterLP6::process() {
	// Serial.println("FilterLP6 process() running");

	AudioIn->process(_audioIn);
	_x0 = _audioIn;
	// CutoffIn->process(_cutoffIn);
	// _cutoff = _cutoffIn;
	// CutoffModAmount.process(_cutoffModAmount);
	// CutoffModSource.process(_cutoffModSource);

	// int64_t mod = (int64_t(_cutoffModAmount) * (int64_t(_cutoffModSource)))>>16;
	// int64_t c = (mod + int64_t(_cutoff));
	// if(c > 65535) c = 65535;
	// else if(c < 0) c = 0;
//	c = ((((c * 32768) >> 15) + 65536) >> 1);


    // _b1 = filterCoefficient[c>>8];
    // _a0 = BIT_32 - _b1;
    
    // _sample = (_a0 * _x0 + _b1 * _y1) >> 32;
    // _y1 = _sample;

	_audioOut = _x0;

}
