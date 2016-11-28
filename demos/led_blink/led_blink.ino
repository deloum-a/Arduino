#include <IRremote.h>
#include <IRremoteInt.h>

//LED Blink

int ledPin = 9;//the Arduino pin that is connected to the LED

void setup() {                
  pinMode(ledPin, OUTPUT);// initialize the pin as an output
}

void loop() {
  digitalWrite(ledPin, HIGH);//turn LED on
  delay(1000);// wait for 1000 milliseconds (one second)
  digitalWrite(ledPin, LOW);//turn LED off
  delay(1000);//wait one second
}
