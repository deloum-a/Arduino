#include <IRremote.h>

int RECV_PIN = 10;
int ARRAY_SIZE = 4;

long int btn_1 = 16724175;
long int btn_2 = 16718055;
long int btn_3 = 16743045;
long int btn_4 = 16716015;
long int btns[] = {btn_1, btn_2, btn_3, btn_4};

int led_1 = 4;
int led_2 = 5;
int led_3 = 6;
int led_4 = 7;
int leds[] = {led_1, led_2, led_3, led_4};

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  // Start the receiver
  irrecv.enableIRIn();
  // sets the digital pin as output
  for (int i = 0; i < ARRAY_SIZE; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  if (irrecv.decode(&results)) {
    long int decCode = results.value;
    Serial.println(decCode);
    if (decCode != -1) {
      for (int i = 0; i < ARRAY_SIZE; i++) {
        digitalWrite(leds[i], LOW);
      }
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
      if (decCode == btns[i]) {
        digitalWrite(leds[i], HIGH);
      }
    }

    irrecv.resume(); // Receive the next value
  }
}

