#include <AudioDestinationNode_T3DAC.h>
#include <OscillatorPWM.h>

AudioDestinationNode_T3DAC t3dac_destinationNode;
OscillatorPWM* pwm0 = new OscillatorPWM();

void setup() {
  // put your setup code here, to run once:
  cli();
  pwm0->connect(&t3dac_destinationNode);
  sei();  
}

void loop() {
  // put your main code here, to run repeatedly:
  pwm0->_pwm += 4096;
}
