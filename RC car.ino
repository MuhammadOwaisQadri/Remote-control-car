#include <AFMotor.h>
 
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

char command;

void forward();
void backward();
void left();
void right();
void Stop();

void setup() {
  Serial.begin(9600);
}
 
void loop() {
  if(Serial.available()>0){
    command=Serial.read();
    Stop();
  }

  switch(command){
    case 'F':
    forward();
    break;
    case 'B':
    backward();
    break;
    case 'L':
    left();
    break;
    case 'R':
    right();
    break;
  }
}

void forward(){
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor4.setSpeed(200);
  motor3.setSpeed(200);
 
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor4.run(FORWARD);
  motor3.run(FORWARD);
}

void backward(){
  motor1.setSpeed(100);
  motor2.setSpeed(100);
  motor4.setSpeed(100);
  motor3.setSpeed(100);

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor4.run(BACKWARD);
  motor3.run(BACKWARD);
}

void left(){
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor4.setSpeed(200);
  motor3.setSpeed(200);
 
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor4.run(FORWARD);
  motor3.run(FORWARD);
}

void right(){
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor4.setSpeed(200);
  motor3.setSpeed(200);
 
  motor4.run(BACKWARD);
  motor3.run(BACKWARD);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void Stop(){
  motor4.run(RELEASE);
  motor3.run(RELEASE);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
