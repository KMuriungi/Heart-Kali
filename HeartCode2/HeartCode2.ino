#include<LiquidCrystal.h>                                            // including the lcd library
#define TempPin A0

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);                             // declaring pins for lcd

int heartSensor = 8;                                                      // declaring pin 8 for sensor output
 int ResetButton=4;                                                   // declaring pin 6 for push button
 int StartButton=3;                                             // declaring pin 7 for other push button

 
int TempValue;
 int green=14;
 int white=13;
 int red=12;
 int yellow=11;
 
 int count=0,i=0,k=0,rate=0;                                         // initializing other variables

unsigned long time2,time1;
 unsigned long time;

byte heart[8] = 
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

void setup ( )
 {
  buttonstate= analog read
  Serial.begin(9600);
  
  
   lcd.createChar(1, heart);                            
   lcd.begin(16,2);                                               // StartButtoning the lcd

   lcd,clear();
   lcd.setCursor(0, 0);
   lcd.print("Heart Beat ");                              // printing heart beat on the display
   lcd.write(1);
   lcd.setCursor(0,1);                                         // setting the cursor from StartButton
   lcd.print("READY");                              // printing monitoring on the display
 // initializing the pins as input pins 

pinMode(heartSensor, INPUT);
   pinMode(ResetButton, INPUT);
   pinMode(StartButton, INPUT);
   pinMode(green,OUTPUT);
   pinMode(white,OUTPUT);
   pinMode(red,OUTPUT);
   pinMode(yellow,OUTPUT);

// setting the push buttons state as high
   digitalWrite(ResetButton, HIGH);
   digitalWrite(StartButton, HIGH);
   delay(1000);                                     // giving a delay
 }
     // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    lcd.print("READY");
  }
void loop()
 {

   TempValue = analogRead(TempPin); // Getting LM35 value and saving it in variable
  float TempCel = ( TempValue/1024.0)*500; // Getting the celsius value from 10 bit analog value
  float TempFarh = (TempCel*9)/5 + 32; // Converting Celsius into Fahrenhiet
      
   
       lcd.clear();                                       // clearing the lcd
       lcd.setCursor(0,0);
       lcd.print("TEMP in *C =");                    // printing temprature on display
       lcd.print(TempCel);                            
       lcd.print(" ");
       lcd.write(1); 
       
  digitalWrite(red,HIGH);
    delay(100);
    digitalWrite(red,LOW);

        lcd.clear();                                       // clearing the lcd
       lcd.print("TEMP in F* =");                    // printing temprature on display
       lcd.print(TempFarh);                            
       lcd.print(" ");
       lcd.write(1); 

  digitalWrite(white,HIGH);
    delay(100);
    digitalWrite(white,LOW);

  
  delay(1000);

  
   if(startbutton= 1,0))                       // checking if the StartButton button is pressed or not

     {
    
    
     k=0;
     lcd.clear();
     lcd.print("Please wait...");    // displaying the please wait on the lcd
   
    digitalWrite(yellow,HIGH);
    delay(1000);
    digitalWrite(yellow,LOW);
      digitalWrite(yellow,HIGH);
      delay(1000);
      digitalWrite(yellow,LOW);
    
     while(k<5)                                     // applying another condition
     
      if(digitalRead(heartSensor))                         // reading from the sensor
      {
       if(k==0)
       time1=millis();
       k++;
       while(digitalRead(heartSensor));
      }
     }
       // applying the formula for calculating the heart beat

      time2=millis();
       rate=time2-time1;
       rate=rate/5;
       rate=60000/rate;
       lcd.clear();                                       // clearing the lcd
       lcd.print("Heart Beat Rate:");                    // printing heart beat rate on display
       lcd.setCursor(0,1);                            // setting the cursor at StartButton
       lcd.print(rate);                            // printing the heart beat on the display
       lcd.print(" ");
       lcd.write(1); 

    digitalWrite(green,HIGH);
    delay(1000);
    digitalWrite(green,LOW);  
      digitalWrite(green,HIGH);
      delay(1000);
      digitalWrite(green,LOW);      
         k=0;
       rate=0;
     }
   if(!digitalRead(ResetButton))                         // checking if ResetButton button is pressed or not
         {
           rate=0;
            lcd.clear();                              // clearing the lcd
             lcd.print("Heart Beat Rate:");          // printing heart beat rate on display
             lcd.setCursor(0,1);                    // setting the cursor at StartButton
             lcd.write(1);
             lcd.print(rate);                       // printing the heart beat on the display
             k=0;

             
         }
 }
 
