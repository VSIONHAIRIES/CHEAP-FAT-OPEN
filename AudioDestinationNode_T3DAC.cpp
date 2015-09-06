#include <AudioDestinationNode_T3DAC.h>

#include <Arduino.h>

#define SAMPLE_RATE 48000
#define CPU_FREQ 96 // in MHz

IntervalTimer synthTimer;

void synth_isr();

AudioDestinationNode_T3DAC::AudioDestinationNode_T3DAC() 
	: AudioNode(), AudioDestinationNode(){

	_outputSample = 0;

	analogWriteResolution(12);

	cli();
	synthTimer.begin(synth_isr, 1000000.0 / SAMPLE_RATE);
	sei();

}

void AudioDestinationNode_T3DAC::isr(void) {	

	// Serial.println("enter isr");

	_outputSample += SIGNED_BIT_32_HIGH; // upper limit of signed 32bit integer to bring it into unsigned int space.
	analogWrite(A14, _outputSample>>20);
	_outputSample = 0;
	_clock++;

	// http://fastcpp.blogspot.nl/2011/03/fast-iteration-over-stl-vector-elements.html
	const int n = _node_inputs.size();
	if(n == 0) return;
	AudioNode** ptr = &_node_inputs.front();
	for(int i = 0; i < n; i++) {
		ptr[i]->process(_accum);
		_outputSample += _accum;
	}
}

int AudioDestinationNode_T3DAC::sample_rate() {
	return SAMPLE_RATE;
}

uint64_t AudioDestinationNode_T3DAC::sample_clock() {
	return _clock;
}

void synth_isr() {	
	t3dac_destinationNode.isr();
}

