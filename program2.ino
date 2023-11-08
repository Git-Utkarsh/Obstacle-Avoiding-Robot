#include <AFMotor.h>
#include <Wire.h>
#include <Servo.h>
const int trigPin = A2; 
const int echoPin = A3;
Servo servoMotor; 
int servoPin = 9; 
AF_DCMotor motorM1(1); // Motor M1
AF_DCMotor motorM2(2); // Motor M2
AF_DCMotor motorM3(3); // Motor M3
AF_DCMotor motorM4(4); // Motor M4
void setup() {
  Serial.begin(9600);
  servoMotor.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  float distance_cm = duration / 58.2;
  if (distance_cm<20){
    stop();
    distanceMeasure();
 
  }
  else{
    moveForward();
  }
  delay(100);
}

void moveForward() {
  motorM1.setSpeed(150);
  motorM2.setSpeed(150);
  motorM3.setSpeed(150);
  motorM4.setSpeed(150);
  motorM1.run(FORWARD);
  motorM2.run(FORWARD);
  motorM3.run(FORWARD);
  motorM4.run(FORWARD);
}

void moveBackward() {
  motorM1.setSpeed(150);
  motorM2.setSpeed(150);
  motorM3.setSpeed(150);
  motorM4.setSpeed(150);
  motorM1.run(BACKWARD);
  motorM2.run(BACKWARD);
  motorM3.run(BACKWARD);
  motorM4.run(BACKWARD);
}

void rightTurn() {
  motorM1.setSpeed(0);   // Left motors (M1 and M2) stop
  motorM2.setSpeed(0);
  motorM3.setSpeed(150); // Right motors (M3 and M4) turn forward
  motorM4.setSpeed(150);
  motorM1.run(RELEASE);  // Release the left motors
  motorM2.run(RELEASE);
  motorM3.run(FORWARD);  // Run the right motors forward
  motorM4.run(FORWARD);
}


void leftTurn() {
  motorM1.setSpeed(150);   // Left motors (M1 and M2) stop
  motorM2.setSpeed(150);
  motorM3.setSpeed(0); // Right motors (M3 and M4) turn forward
  motorM4.setSpeed(0);
  motorM1.run(FORWARD);  // Release the left motors
  motorM2.run(FORWARD);
  motorM3.run(RELEASE);  // Run the right motors forward
  motorM4.run(RELEASE);
}

void stop(){

  motorM1.setSpeed(0);
  motorM2.setSpeed(0);
  motorM3.setSpeed(0);
  motorM4.setSpeed(0);
  motorM1.run(RELEASE);
  motorM2.run(RELEASE);
  motorM3.run(RELEASE);
  motorM4.run(RELEASE);

}


void distanceMeasure() {
  int distanceAt0Degrees, distanceAt90Degrees, distanceAt180Degrees;
  // Measure distance at 90 degrees
  servoMotor.write(90);
  delay(1000);
  distanceAt90Degrees = measureDistance();

  // Measure distance at 0 degrees
  servoMotor.write(0);
  delay(1000);
  distanceAt0Degrees = measureDistance();



  // Measure distance at 180 degrees
  servoMotor.write(180);
  delay(1000);
  distanceAt180Degrees = measureDistance();

  // Measure distance at 0 degrees
  servoMotor.write(90);
  delay(1000);

  // Print the measured distances
  Serial.print("");
  Serial.print(distanceAt0Degrees);
  Serial.print(" cm, ");

  Serial.print(",");
  Serial.print(distanceAt90Degrees);
  Serial.print(" cm, ");

  Serial.print(",");
  Serial.print(distanceAt180Degrees);
  Serial.println(" cm");

  if (distanceAt90Degrees>distanceAt180Degrees){
    moveBackward();
    delay(500);
    rightTurn();
    delay(1500);
    leftTurn();
    delay(1500);
    moveForward();
    delay(700);
  }
  else {
    moveBackward();
    delay(500);
    leftTurn();
    delay(1500);
    rightTurn();
    delay(1500);
    moveForward();
    delay(700); 
  }
}

int measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  unsigned int duration = pulseIn(echoPin, HIGH);
  int distance = (duration / 2) / 29.1;  // Calculate distance in centimeters
  return distance;
}
