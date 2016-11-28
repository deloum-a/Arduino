#include <IRremote.h>
#include <LiquidCrystal.h>

int receiver = 12; // Signal Pin of IR receiver to Arduino Digital Pin 11
IRrecv irrecv(receiver); // create instance of 'irrecv'
decode_results results; // create instance of 'decode_results'
LiquidCrystal lcd(11, 10, 5, 4, 3, 2);

long int btn_0 = 16738455;

long int btn_1 = 16724175;
long int btn_2 = 16718055;
long int btn_3 = 16743045;

long int btn_4 = 16716015;
long int btn_5 = 16726215;
long int btn_6 = 16734885;

long int btn_7 = 16728765;
long int btn_8 = 16730805;
long int btn_9 = 16732845;


void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  Serial.println("IR Receiver Button Decode");
  lcd.print("hello, world!");
//  irrecv.enableIRIn(); // Start the receiver
}


void loop()
{
//  if (irrecv.decode(&results)) // have we received an IR signal?
//  {
//    translateIR(); 
//    irrecv.resume(); // receive the next value
//  }

  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}


void translateIR() // takes action based on IR code received

// describing Remote IR codes

{
  switch(results.value) {
    case 16724175: //change zero to your IR remote 1 button number
    lcd.clear();
    lcd.print(" 1"); 
    Serial.println("1");
    break;
  
  case 16718055: //change zero to your IR remote 2 button number
  lcd.clear();
  lcd.print(" 2");  
  Serial.println("2");
  break;
  
//  case btn_3: //change zero to your IR remote 3 button number
//  lcd.clear(); 
//  lcd.print(" 3");  
//  break;
//  
//  case btn_4: //change zero to your IR remote 4 button number
//  lcd.clear();
//  lcd.print(" 4");  
//  break;
//  
//  case btn_5: //change zero to your IR remote 5 button number
//  lcd.clear();
//  lcd.print(" 5"); 
//  break;
//  
//  case btn_6: //change zero to your IR remote 6 button number
//  lcd.clear();
//  lcd.print(" 6");
//  break;
//  
//  case btn_7: //change zero to your IR remote 7 button number
//  lcd.clear(); 
//  lcd.print(" 7"); 
//  break;
//  
//  case btn_8: //change zero to your IR remote 8 button number
//  lcd.clear();
//  lcd.print(" 8");  
//  break;
//  
//  case btn_9: //change zero to your IR remote 9 button number
//  lcd.clear();
//  lcd.print(" 9");  
//  break;
  
//  case btn_0: //change zero to your IR remote 0 button number
//  lcd.clear();
//  lcd.print(" 0");  
//  break;
  
  default: 
  lcd.clear();
  lcd.print(" other button   ");

  }

  delay(500); // Do not get immediate repeat


} 



