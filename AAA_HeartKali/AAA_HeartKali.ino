/*Arduino program for HeartBeat and
 * Body temperature monitoring 
 *Two sensors have been used: 
 *HeartBeat Sensor 
 *LM35 : Temp Sensor
 *LCD Display, LED, PushButtons and other 
 *components have been used to enhance the effectiveness 
 *of the projects.
 *
 *Projects Designed and Implemented by 
 *: Beryl Chebet and Kithinji Muriungi
 *Courtesy of SEDMu
 *Presented : Moi University Expo 16/17 (Hosted by TSA)
 */


#include<LiquidCrystal.h>  // Including LCD Library
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int HeartBeatSensor = 9;

int ResetButton=7;
int StartButton=8;

int tempValue;
int tempPin = 0;

int whiteLed = 22;
int greenLed = 24;
int yellowLed = 26;
int redLed = 28;

int buzzerPin = 10;

int count=0,i=0,k=0,rate=0; // Initializing the Counters to Enable While Loop
unsigned long timeFinal,timeInitial; // Initializing Time variables 
unsigned long time; // Initializing time function

byte heart[8] = // Designing the HEART Symbol ( Initialize the Function)
{
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};


void setup()
{
  pinMode(HeartBeatSensor, INPUT);
  pinMode(StartButton, INPUT);
  pinMode(ResetButton, INPUT);
  pinMode(whiteLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  lcd.begin(16,2);
  lcd.createChar(1, heart); // Initializing the Symbol Creation Function in LCD
  
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.write(1);lcd.write(1);lcd.write(1);
  lcd.print(" System ");
  lcd.write(1);lcd.write(1);lcd.write(1);
  lcd.setCursor(2,1);
  lcd.write(1);lcd.write(1);
  lcd.print(" Ready ");
  lcd.write(1);lcd.write(1);
  
  digitalWrite(StartButton, HIGH);
  digitalWrite(ResetButton, HIGH);

  digitalWrite(whiteLed, HIGH);
  
  delay(1000);
}

void loop()
{
  tempValue = analogRead(tempPin);
  tempValue = tempValue * 0.48828125;
  
  if(!(digitalRead(ResetButton))) 
  {
    k=0;
    lcd.clear();
    lcd.print("   Please Wait ");
    heartBlink();
    while(k<5)
    {
     if(digitalRead(HeartBeatSensor))
     {
      if(k==0)
      timeInitial=millis();
      k++;
      while(digitalRead(HeartBeatSensor));
     }
    }
      timeFinal=millis();
      rate=timeFinal-timeInitial;
      rate=rate/5;
      rate=60000/rate;
      lcd.clear();
      lcd.print("H ");
      lcd.write(1);
      lcd.print(" B ");
      lcd.print("Rate = ");
      lcd.print(rate);
      lcd.setCursor(4,1);
      lcd.print("Temp = ");
      lcd.print(tempValue);
      ledLoop();
         
      k=0;
      rate=0;
    }
  if(!digitalRead(StartButton))
  {
    rate=0;
     lcd.clear();
     lcd.write(1);
      lcd.print(" Monitor Your ");
      lcd.write(1);
      lcd.setCursor(3,1);
      lcd.write(1);lcd.write(1);
      lcd.print("Body");
      lcd.write(1);lcd.write(1);
      k=0;
  }
}

void heartBlink() //Heart Symbol Blinking Function
  {
    lcd.setCursor(0, 1);
    lcd.write(1);
    delay(1000);
    lcd.setCursor(1, 1);
    lcd.write(1);
    delay(1000);
    lcd.setCursor(2, 1);
    lcd.write(1);
    delay(1000);
    lcd.setCursor(3, 1);
    lcd.write(1);
    delay(1000);
    lcd.setCursor(4, 1);
    lcd.write(1);
    delay(1000);
    lcd.setCursor(5, 1);
    lcd.write(1);
    delay(1000);
    lcd.setCursor(6, 1);
    lcd.write(1);
    delay(1000);
    lcd.setCursor(7, 1);
    lcd.write(1);
    delay(1000);
    lcd.setCursor(8, 1);
    lcd.write(1);
    delay(1000);
    lcd.setCursor(9, 1);
    lcd.write(1);
    delay(1000);
    lcd.setCursor(10, 1);
    lcd.write(1);
    delay(1000);
    lcd.setCursor(11, 1);
    lcd.write(1);
    delay(1000);
    lcd.setCursor(12, 1);
    lcd.write(1);
    delay(1000);
    lcd.setCursor(13, 1);
    lcd.write(1);
    delay(1000);
    lcd.setCursor(14, 1);
    lcd.write(1);
    delay(1000);
    lcd.setCursor(15, 1);
    lcd.write(1);
    delay(1000);
  }

void ledLoop(){
  if(tempValue > 15 && tempValue < 45 && rate > 60 && rate < 100){
     digitalWrite(greenLed, HIGH);
     digitalWrite(whiteLed, LOW);
     }
     else if(tempValue > 0 && tempValue < 15 && rate < 60){
      digitalWrite(yellowLed, HIGH);
      digitalWrite(whiteLed, LOW);
      }
      else if(tempValue > 45 && rate > 100){
        digitalWrite(redLed, HIGH);
        digitalWrite(whiteLed, LOW);
        digitalWrite(buzzerPin, HIGH);
        }
        else if(tempValue > 15 && tempValue < 45 || rate > 60 && rate < 100){
          digitalWrite(greenLed, HIGH);
          digitalWrite(whiteLed, HIGH);
          }
          else if(tempValue > 0 && tempValue < 15 || rate < 60){
            digitalWrite(yellowLed, HIGH);
            digitalWrite(whiteLed, HIGH);
            }
            else if(tempValue < 45 || rate < 60){
              digitalWrite(redLed, HIGH);
              digitalWrite(whiteLed, HIGH);
              digitalWrite(buzzerPin, HIGH);
              }
              else{
                digitalWrite(whiteLed, HIGH);
                }
  }
