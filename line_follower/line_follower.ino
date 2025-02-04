
#include <AFMotor.h>

#define lefts A4 
#define rights A5 

AF_DCMotor motor1(4, MOTOR12_8KHZ); 
AF_DCMotor motor2(3, MOTOR12_8KHZ);


void setup() {

  motor1.setSpeed(200);
  motor2.setSpeed(200);

  pinMode(lefts,INPUT);
  pinMode(rights,INPUT);
  
}

void loop(){
 
  if(analogRead(lefts)<=400 && analogRead(rights)<=400){
    
    motor1.run(RELEASE);
    motor2.run(RELEASE);
  }
  
  else if(analogRead(lefts)<=400 && !analogRead(rights)<=400){

    motor1.run(BACKWARD);
    motor2.run(FORWARD);
   
  }

  else if(!analogRead(lefts)<=400 && analogRead(rights)<=400){

    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    
  }

  else if(!analogRead(lefts)<=400 && !analogRead(rights)<=400){

    motor1.run(FORWARD);
    motor2.run(FORWARD);
   
  }
  
}
