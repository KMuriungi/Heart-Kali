#define TempPin A0

int TempValue;

 int green=14;
 int blue=13;
 int red=12;
 int yellow=11;

void setup()
{
  Serial.begin(9600); // Initializing Serial Port
}

void loop()
{
  TempValue = analogRead(TempPin); // Getting LM35 value and saving it in variable
  float TempCel = ( TempValue/1024.0)*500; // Getting the celsius value from 10 bit analog value
  float TempFarh = (TempCel*9)/5 + 32; // Converting Celsius into Fahrenhiet

  Serial.print("TEMPRATURE in Celsius = "); //Displaying temperature in Celsius
  Serial.print(TempCel);
  Serial.print("*C");
  Serial.print("    |    ");
    digitalWrite(red,HIGH);
    delay(100);
    digitalWrite(red,LOW);

  Serial.print("TEMPRATURE = "); // Displaying Temperature in Fahrenheit
  Serial.print(TempFarh);
  Serial.print("*F");
  Serial.println();
  
  digitalWrite(blue,HIGH);
    delay(100);
    digitalWrite(blue,LOW);

  
  delay(1000);

}
