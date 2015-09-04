#include <AudioDestinationNode_T3DAC.h>
#include <OscillatorSAW.h>

AudioDestinationNode_T3DAC t3dac_destinationNode;
OscillatorSAW* saw0 = new OscillatorSAW();
OscillatorSAW* saw1 = new OscillatorSAW();
OscillatorSAW* saw2 = new OscillatorSAW();
OscillatorSAW* saw3 = new OscillatorSAW();
OscillatorSAW* saw4 = new OscillatorSAW();

void setup() {
  saw0->setDetune(0.017);
  saw1->setDetune(0.009);
  saw2->setDetune(0.003);
  saw3->setDetune(-0.007);
  saw4->setDetune(-0.013);
  saw0->setGain(0.20);
  saw1->setGain(0.20);
  saw2->setGain(0.20);
  saw3->setGain(0.20);
  saw4->setGain(0.20);
  cli();
  saw0->connect(&t3dac_destinationNode);
  saw1->connect(&t3dac_destinationNode);
  saw2->connect(&t3dac_destinationNode);
  saw3->connect(&t3dac_destinationNode);
  saw4->connect(&t3dac_destinationNode);
  sei();  
}

void loop() {
  // put your main code here, to run repeatedly:
}
