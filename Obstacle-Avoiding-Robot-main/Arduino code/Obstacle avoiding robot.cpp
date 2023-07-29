#include <NewPing.h> 
const int LeftMotorForward = 6;
const int LeftMotorBackward = 3;
const int RightMotorForward = 5;
const int RightMotorBackward = 9;
const int ENB=11;
const int ENA=10;

//int buzz = 12;
#define trig_pin A1
#define echo_pin A2
#define maximum_distance 200
int distance=100;
boolean goesForward = false;
NewPing sonar(trig_pin, echo_pin, maximum_distance);
void setup() {
  // put your setup code here, to run once:
//  pinMode(trigPin, OUTPUT);
//  pinMode(echoPin, INPUT);
  //pinMode(buzz, OUTPUT);
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(ENA, OUTPUT);
  //Serial.begin(9600);


  //Serial.begin(9600);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(50);
  analogWrite(ENB, 60);
  analogWrite(ENA, 60);

  if (distance <= 20){
    moveStop();
    delay(300);
    turnRight();
    //moveStop();
  }
  else{
    moveForward();
  }
  distance = readPing();
  
}
int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
//  Serial.print("horha");
//  Serial.println(cm);
  return cm;
}
void moveStop(){
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}


void moveForward(){
  if(!goesForward){
    //goesForward=true;

    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW);
  }
}
void turnRight(){

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);

  delay(500);

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}