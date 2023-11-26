#include <Servo.h> //including the library of Servo Motor
Servo sg90;
int initial_position = 90;
int LDR1 = A0;		//Connect the ldr on A0
int LDR2 = A1;		//Connect the ldr on A1
int error = 5;
int servopin = 9;	//you can change servo just make sure its

void setup(){
  sg90.attach(servopin);
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);
  sg90.write(initial_position);
  delay(500);
}


void loop(){
  int R1 = analogRead(LDR1);
  int R2 = analogRead(LDR2);
  int diff1 = abs(R1 - R2);
  int diff2 = abs(R2 - R1);
  
  if((diff1 <= error) || (diff2 <= error)){
  }else{
    if(R1>R2){
      initial_position = --initial_position;
    }
    if(R1<R2){
      initial_position = ++initial_position;
    }
  }
  sg90.write(initial_position);
  delay(200);
}


