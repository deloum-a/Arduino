/*  Infrared Remote Controller & IR Receiver demo program
  copy right John Yu
  connect VS1838B to  D10 see http://osoyoo.com/?p=144
*/
#include <IRremote.h>
int input_pin = 11; //set D10 as input signal pin
IRrecv irrecv(input_pin);
decode_results signals;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // enable input from IR receiver
}
void loop() {
if (irrecv.decode(&signals)) {
    Serial.println(signals.value);
    irrecv.resume(); // get the next signal
  }
}
