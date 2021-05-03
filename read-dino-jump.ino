#include <Servo.h>

#define pinRead A2
#define pinServo 9

Servo myservo;
int timeServo = 200;
int initServo = 170;
int endServo = 130;
int valueToJump = 60;

void setup() {
  myservo.attach(pinServo);
  
  pinMode(pinRead, INPUT);

  Serial.begin(9600);

  myservo.write(initServo);
}

void loop() {
  if(analogRead(pinRead) < valueToJump){
    Serial.println("PULA");

    delay(100);

    jump();  
  }
}

void jump(){
  myservo.write(initServo);
  delay(timeServo);

  myservo.write(endServo);
  delay(timeServo);

  myservo.write(initServo);
}