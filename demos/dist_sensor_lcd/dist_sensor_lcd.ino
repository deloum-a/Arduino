#include <LiquidCrystal.h>

#define dist_echo 8 // Echo Pin
#define dist_trig 9 // Trigger Pin
LiquidCrystal lcd(11, 10, 5, 4, 3, 2);


int maximumRange = 200;
int minimumRange = 0;
long duration, distance;

void setup() {
   pinMode(dist_trig, OUTPUT);
   pinMode(dist_echo, INPUT);

  lcd.begin(16, 2);
}

void loop() {
  lcd.clear();
  lcd.print("Distance:");
  lcd.setCursor(0, 1);

  digitalWrite(dist_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(dist_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(dist_trig, LOW);

  duration = pulseIn(dist_echo, HIGH);
  distance = duration / 58.2;
 
  if (distance >= maximumRange || distance <= minimumRange) {
    lcd.print("-1");
  } else {
    lcd.print(distance);
  }

  delay(250);
}
