#include <Wire.h>
#include <Servo.h>
#include <IRremote.h>

const int Entrance = 6;  // Entrance
const int Exit = 7;      // Exit
const int servoPin = 9;    // Servo motor
Servo myservo;

void setup() {
  pinMode(Entrance, INPUT);
  pinMode(Exit, INPUT);
  myservo.attach(servoPin);
  Serial.begin(9600);
  Serial.println("Car Parking System");
}

void loop() {
  if (digitalRead(Entrance) == HIGH) {
    Serial.println("Car detected at entrance");
    myservo.write(90);  // Open the gate
    delay(2000);        // 2 seconds
    while (digitalRead(Exit) == LOW) {
      Serial.println("Waiting for car to exit");
      delay(1000);
    }
    Serial.println("Car has exited");
    myservo.write(0);   // Close the gate
  }
}

