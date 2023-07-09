#include <Arduino.h>

// Replace these definitions with the GPIO pins you use
#define MOTEN 5
#define MOTO1 4
#define MOTO2 3
#define LDR1 A0
#define LDR2 A1

void StopMotor();
void MoveMotor(int speed);

void setup() {
  Serial.begin(9600);
  
  pinMode(MOTEN, OUTPUT);
  pinMode(MOTO1, OUTPUT);
  pinMode(MOTO2, OUTPUT);
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);

  MoveMotor(100);
  delay(250);
  MoveMotor(-100);
  delay(250);
  StopMotor();
}

void loop() {

}

void MoveMotor(int speed) {
  if (speed > 100) speed = 100;
  if (speed < -100) speed = -100;

  analogWrite(MOTEN, int(abs(speed)*2.55));

  if (speed > 0) {
    digitalWrite(MOTO1, HIGH);
    digitalWrite(MOTO2, LOW);
  } else {
    digitalWrite(MOTO1, LOW);
    digitalWrite(MOTO2, HIGH);
  }
}

void StopMotor() {
  digitalWrite(MOTO1, LOW);
  digitalWrite(MOTO2, LOW);
}

void HoldMotor() {
  
}