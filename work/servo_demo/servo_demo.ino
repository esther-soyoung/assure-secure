#include <Servo.h>
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(2);
  myServo.write(0);

}

void loop() {
  // put your main code here, to run repeatedly:
  myServo.writeMicroseconds(2300);

//  myServo.write(90);
//  delay(500);
//  myServo.write(30);
//  delay(1000);
  myServo.write(0);
}
