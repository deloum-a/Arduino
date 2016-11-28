/*
 # Product: Flame sensor  
 # SKU    : DFR0076 
 # Description:     
 # When flame sensor detected flame, the data will be read by the serial.
*/

void setup() {
  //Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
}
