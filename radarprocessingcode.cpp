// without lcd,oled and dht11 sensor
#include <Servo.h>
//#include <LiquidCrystal.h>

// Defines Trigger and Echo pins of the Ultrasonic Sensor
const int trigPin = 8;
const int echoPin = 9;
//LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Variables for duration, distance, and angle
long duration;
int distance;
Servo myServo; // Servo object for controlling the servo motor

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  myServo.attach(10); // Servo motor attached to pin 10

  pinMode(11, OUTPUT); // LED pins
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // Rotates the servo motor from 15 to 165 degrees
  for (int i = 15; i <= 165; i++) {  
    myServo.write(i);
    delay(120);
    distance = calculateDistance(); // Calls function to calculate distance

    Serial.print(i); // Current angle in Serial Port
    Serial.print(",");
    Serial.print(distance); // Distance value in Serial Port
    Serial.print(".");
    if (distance > 40) {
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
    } else if (distance >= 0 && distance <= 40) {
      digitalWrite(13, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(11, HIGH);
    }
  }

  // Repeats the previous lines from 165 to 15 degrees
  for (int i = 165; i > 15; i--) {  
    myServo.write(i);
    delay(120);
    distance = calculateDistance();

    Serial.print(i); // Current angle in Serial Port
    Serial.print(",");
    Serial.print(distance); // Distance value in Serial Port
    Serial.print(".");

    if (distance > 40) {
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
    } else if (distance >= 0 && distance <= 40) {
      digitalWrite(13, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(11, HIGH);
    }
  }
}

// Function to calculate distance measured by the Ultrasonic sensor
int calculateDistance() { 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}
