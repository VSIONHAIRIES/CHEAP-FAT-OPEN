#include <AudioDestinationNode_T3DAC.h>
#include <OscillatorWAVE.h>

AudioDestinationNode_T3DAC t3dac_destinationNode;
OscillatorWAVE* wave0 = new OscillatorWAVE();

uint16_t cnt = 1;
uint8_t wf = 0;

void setup() {
  // put your setup code here, to run once:
  cli();
  wave0->connect(&t3dac_destinationNode);
  sei();  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!cnt++) wave0->setWaveForm(wf++);
  if(wf==16) wf = 0;
}
