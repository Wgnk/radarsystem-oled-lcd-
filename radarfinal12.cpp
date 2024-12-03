#include <SPI.h>
 #include<LiquidCrystal.h>
 #include <Wire.h>
 #include <Adafruit_GFX.h>
 #include <Adafruit_SSD1306.h>
 #include <Servo.h>
 #define Trig 8
 #define Echo 9
 Adafruit_SSD1306 display(-1);
 Servo Servo1;
 LiquidCrystal lcd(7,6,5,4,3,2);
 void setup()
 {
   lcd.begin(16,2);
   lcd.setCursor(0,0);
   lcd.print("Radar datas.....");
   lcd.setCursor(4,1);
   lcd.print("Screen 1");
   delay(5000);
   lcd.clear();
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
   pinMode(Trig, OUTPUT);
   pinMode(Echo, INPUT);
   Serial.begin(9600);
   Servo1.attach(11);
   delay(1000);
   Servo1.write(40);
   display.clearDisplay();
   display.setTextSize(1);
   display.setTextColor(WHITE);
   display.setCursor(40, 10);
   display.println("RADAR GUI");
    display.setTextSize(1);
   display.setTextColor(WHITE);
   display.setCursor(40, 20);
   display.println("Screen 2");
   display.display();
   delay(2000);
   pinMode(13,OUTPUT);
   pinMode(12,OUTPUT);
   pinMode(10,OUTPUT);
 }
 long distance, duration, Distance;
  int currentAngle = 0;
 void loop() {
 int i, j, k, l, m, n;  
 for (i = 10; i >= 0; i -= 2)
   {
     int servomap = map(i, 0, 10, 60, 40);
     Distance = Distance_value();
Serial.print(servomap); 
    currentAngle = servomap; 
    lcd.setCursor(0, 0);
    lcd.print("Range: ");
    lcd.print(Distance);
    lcd.print(" cm   "); 
    lcd.setCursor(0, 1);
    lcd.print("Angle: ");
    lcd.print(currentAngle);
    lcd.print(" deg   "); 
    Serial.println(servomap);
    Serial.println(",");
    Serial.println(Distance);
    Serial.println("."); 
if(distance >40){   
display.clearDisplay();   
Servo1.write(servomap);   
display.drawLine(64, 32, 0, i, WHITE );
digitalWrite(13,HIGH);
digitalWrite(12,LOW);
digitalWrite(10,LOW);   
delay(100); 
} 
else if (Distance >= 0 && Distance <= 40)
{  
 int xmap1 = map(Distance, 0, 40, 64, 0); 
int ymap1 = map(Distance, 0, 40, 32, i);   
display.clearDisplay();   
Servo1.write(servomap);   
display.drawLine(64, 32, 0, i, WHITE ); 
display.fillCircle(10, 30, 1, WHITE);
display.display();   
delay(100); 
digitalWrite(13,LOW);
digitalWrite(12,HIGH);
digitalWrite(10,HIGH);  
}
 }
   for (j = 0; j <= 128; j += 4) 
   {
     int servomap = map(j, 0, 128, 61, 120);
     Distance = Distance_value();
Serial.print(servomap);  
currentAngle = servomap;
    lcd.setCursor(0, 0);
    lcd.print("Range: ");
    lcd.print(Distance);
    lcd.print(" cm   "); 
    lcd.setCursor(0, 1);
    lcd.print("Angle: ");
    lcd.print(currentAngle);
    lcd.print(" deg   ");
    Serial.println(servomap);
    Serial.println(",");
    Serial.println(Distance);
    Serial.println("."); 
if (Distance > 40 ) 
{   
display.clearDisplay();   
Servo1.write(servomap);   
display.drawLine(64, 32, j, 0, WHITE );   
display.display();   
delay(100); 
digitalWrite(13,HIGH);
digitalWrite(12,LOW);
digitalWrite(10,LOW);  
} 
else if (Distance >= 0 && Distance <= 40) 
{   
int xmap2 = map(Distance, 0, 40, 64, j);   
int ymap2 = map(Distance, 0, 40, 32, 0);   
display.clearDisplay();   
Servo1.write(servomap);   
display.drawLine(64, 32, j, 0, WHITE );   
display.drawCircle(xmap2, ymap2, 3, WHITE);   
display.fillCircle(10, 30, 1, WHITE);   
display.fillRoundRect(10, 20, 2, 8, 2, WHITE);   
display.display();   
delay(100);
digitalWrite(13,LOW);
digitalWrite(12,HIGH);
digitalWrite(10,HIGH);   
}
 }
   for (k = 0; k <= 10 ; k += 2)
   {
     int servomap = map(k, 0, 10, 121, 140);
     Distance = Distance_value();
Serial.print(servomap);
    currentAngle = servomap;
    lcd.setCursor(0, 0);
    lcd.print("Range: ");
    lcd.print(Distance);
    lcd.print(" cm   ");
    lcd.setCursor(0, 1);
    lcd.print("Angle: ");
    lcd.print(currentAngle);
    lcd.print(" deg   ");
    Serial.println(servomap);
    Serial.println(",");
    Serial.println(Distance);
    Serial.println("."); 
if (Distance > 40 ) {   
display.clearDisplay();   
Servo1.write(servomap);   
display.drawLine(64, 32, 128, k, WHITE );   
display.display();   
delay(100); 
digitalWrite(13,HIGH);
digitalWrite(12,LOW);
digitalWrite(10,LOW);  
} 
else if (Distance >= 0 && Distance <= 40) 
{   
int xmap3 = map(Distance, 0, 40, 64, 128);   
int ymap3 = map(Distance, 0, 40, 32, k);  
 display.clearDisplay();   
Servo1.write(servomap);   
display.drawLine(64, 32, 128, k, WHITE );   
display.drawCircle(xmap3, ymap3, 3, WHITE);   
display.fillCircle(10, 30, 1, WHITE);   
display.fillRoundRect(10, 20, 2, 8, 2, WHITE);   
display.display();   
delay(100);
digitalWrite(13,LOW);
digitalWrite(12,HIGH);
digitalWrite(10,HIGH);
}
 }
   for (l = 10; l >= 0 ; l -= 2)
   {
     int servomap = map(l, 10, 0, 140, 120);
     Distance = Distance_value();
Serial.print(servomap); 
    currentAngle = servomap; 
    lcd.setCursor(0, 0);
    lcd.print("Range: ");
    lcd.print(Distance);
    lcd.print(" cm   "); 
    lcd.setCursor(0, 1);
    lcd.print("Angle: ");
    lcd.print(currentAngle);
    lcd.print(" deg   ");
    Serial.println(servomap);
    Serial.println(",");
    Serial.println(Distance);
    Serial.println("."); 
if (Distance > 40 ) {   
display.clearDisplay();   
Servo1.write(servomap);   
display.drawLine(64, 32, 128, l, WHITE );   
display.display();   
delay(100); 
digitalWrite(13,HIGH);
digitalWrite(12,LOW);
digitalWrite(10,LOW); 
} 
else if (Distance >= 0 && Distance <= 40) 
{   
int xmap3 = map(Distance, 0, 40, 64, 128);  
 int ymap3 = map(Distance, 0, 40, 32, l);   
display.clearDisplay();   
Servo1.write(servomap);   
display.drawLine(64, 32, 128, l, WHITE );  
 display.drawCircle(xmap3, ymap3, 3, WHITE);   
display.fillCircle(10, 30, 1, WHITE);   
display.fillRoundRect(10, 20, 2, 8, 2, WHITE);   
display.display();   
delay(100); 
digitalWrite(13,LOW);
digitalWrite(12,HIGH);
digitalWrite(10,HIGH);  
}
 }
   for (m = 128; m >= 0; m -= 4)
   {
     int servomap = map(m, 128, 0, 121, 60);
     Distance = Distance_value();
Serial.print(servomap); 
    currentAngle = servomap; 
    lcd.setCursor(0, 0);
    lcd.print("Range: ");
    lcd.print(Distance);
    lcd.print(" cm   "); 
    lcd.setCursor(0, 1);
    lcd.print("Angle: ");
    lcd.print(currentAngle);
    lcd.print(" deg   ");
    Serial.println(servomap);
    Serial.println(",");
    Serial.println(Distance);
    Serial.println("."); 
if (Distance > 40 ) {   
display.clearDisplay();   
Servo1.write(servomap);   
display.drawLine(64, 32, m, 0, WHITE );   
display.display();   
delay(100); 
digitalWrite(13,HIGH);
digitalWrite(12,LOW);
digitalWrite(10,LOW); 
} 
else if (Distance >= 0 && Distance <= 40) 
{   
int xmap2 = map(Distance, 0, 40, 64, m);   
int ymap2 = map(Distance, 0, 40, 32, 0);   
display.clearDisplay();   
Servo1.write(servomap);   
display.drawLine(64, 32, m, 0, WHITE );   
display.drawCircle(xmap2, ymap2, 3, WHITE);   
display.fillCircle(10, 30, 1, WHITE);   
display.fillRoundRect(10, 20, 2, 8, 2, WHITE);  
 display.display();   
 delay(100); 
 digitalWrite(13,LOW);
digitalWrite(12,HIGH);
digitalWrite(10,HIGH); 
 }
 }
   for (n = 0; n <= 10; n += 2)
   {
     int servomap = map(n, 0, 10, 61, 40);
     Distance = Distance_value();
Serial.print(servomap);  
currentAngle = servomap;  
    lcd.setCursor(0, 0);
    lcd.print("Range: ");
    lcd.print(Distance);
    lcd.print(" cm   "); 
    lcd.setCursor(0, 1);
    lcd.print("Angle: ");
    lcd.print(currentAngle);
    lcd.print(" deg   ");
    Serial.println(servomap);
    Serial.println(",");
    Serial.println(Distance);
    Serial.println("."); 
if (Distance > 40 ) 
{   
display.clearDisplay();   
Servo1.write(servomap);   
display.drawLine(64, 32, 0, n, WHITE );   
display.display();   
delay(100);
digitalWrite(13,HIGH);
digitalWrite(12,LOW);
digitalWrite(10,LOW);  
} 
else if (Distance >= 0 && Distance <= 40)
 {   
int xmap1 = map(Distance, 0, 40, 64, 0);   
int ymap1 = map(Distance, 0, 40, 32, n);   
display.clearDisplay();   
Servo1.write(servomap);   
display.drawLine(64, 32, 0, n, WHITE );   
display.drawCircle(xmap1, ymap1, 3, WHITE);   
display.fillCircle(10, 30, 1, WHITE);   
display.fillRoundRect(10, 20, 2, 8, 2, WHITE);   
display.display();   
delay(100);
digitalWrite(13,LOW);
digitalWrite(12,HIGH);
digitalWrite(10,HIGH);  
 }
 }
 }
 int Distance_value()
 {
   digitalWrite(Trig, LOW);
   delayMicroseconds(2);
   digitalWrite(Trig, HIGH);
   delayMicroseconds(10);
   digitalWrite(Trig, LOW);
   duration = pulseIn(Echo, HIGH);
   distance = (duration / 2) / 29.1;
   return distance;
 }
