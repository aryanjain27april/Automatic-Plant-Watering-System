int m=2,soil=3,swt=6;
boolean soil_state,swt_state;
String s;
#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12, 11, 10, 9, 8);  /* For 4-bit mode */
                    //RS  EN   D4  D5  D6  D7
void setup() {
  pinMode(m,OUTPUT);
  pinMode(swt,INPUT);
  pinMode(soil,INPUT);
  Serial.begin(9600);// put your setup code here, to run once:
  digitalWrite(m,LOW);
  lcd.begin(16,2);  /* Initialize 16x2 LCD */
  lcd.clear();               /* Clear the LCD */
  lcd.setCursor(0,0); /* Set cursor to column 0 row 0 */
  lcd.print("WELCOME"); /* Print data on display */
  lcd.setCursor(0,1); /* Set cursor to column 0 row 0 */
  lcd.print("ABHINAV SIR"); /* Print data on display */
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("WELCOME");
  lcd.setCursor(0,1);
  lcd.print("&");
  delay(500);
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("WELCOME");
  lcd.setCursor(0,1);
  lcd.print("VAIBHAV SIR");
  delay(2000);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("MC PROJECT"); 
  
  while(Serial.available()){
    delay(10);
    char c=Serial.read();
    s+=c;
  }
      
  soil_state=digitalRead(soil);
  swt_state=digitalRead(swt);
  if (swt_state==HIGH){
    lcd.setCursor(0,1);
    lcd.print("BT Control");
    delay(1000);
  if(s.length()>0){
    Serial.println(s);
        if (s=="ON"){
           digitalWrite(m,HIGH);
           lcd.clear();
           lcd.setCursor(0,0);
           lcd.print("MC PROJECT");
           lcd.setCursor(0,1); 
           lcd.print("Manually Watering");
           delay(1000);
    }
   else if (s=="OFF"){
      digitalWrite(m,LOW);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("MC PROJECT");
      lcd.setCursor(0,1); 
      lcd.print("Manually Stoped");
      delay(1000);
    }
  }
  }
 
if (swt_state==LOW){

    lcd.clear();
    lcd.setCursor(0,0); 
    lcd.print("MC PROJECT");
    lcd.setCursor(0,1); 
    lcd.print("AUTO CONTROL");
    delay(1000);
// Sensor Control
  if (soil_state==HIGH){
    digitalWrite(m,LOW);
    lcd.setCursor(0,1); 
    lcd.print("No Water Needed");
    delay(1000);

  }
  
  if (soil_state==LOW){
    digitalWrite(m,HIGH);
    lcd.setCursor(0,1); 
    lcd.print("NOT ENOUGH WATER");
    delay(700);
    lcd.clear();
    lcd.setCursor(0,0); 
    lcd.print("MC PROJECT");
    lcd.setCursor(0,1); 
    lcd.print("WATERING AUTO");
    delay(700);
  }
}

  s="";// put your main code here, to run repeatedly:

}
