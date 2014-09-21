#include <PS2Mouse.h>
#define MOUSE_DATA 5
#define MOUSE_CLOCK 6

#include "WProgram.h"
void setup();
void loop();
void forward(int del);
void backward(int del);
void left(int del);
void right(int del);
PS2Mouse mouse(MOUSE_CLOCK, MOUSE_DATA, STREAM);
int motor1Pin1 = 9; 
int motor1Pin2 = 10; 

int motor2Pin1 = 8; 
int motor2Pin2 = 7; 

int motorsPinEnable = 2;
char mx = 0;
char my = 0;
void setup()
{
  Serial.begin(38400);
  mouse.initialize();
  pinMode(motor1Pin1, OUTPUT); 
  pinMode(motor1Pin2, OUTPUT); 
  pinMode(motor2Pin1, OUTPUT); 
  pinMode(motor2Pin2, OUTPUT); 
  pinMode(motorsPinEnable, OUTPUT);

  digitalWrite(motorsPinEnable,HIGH); 

}

void loop()
{
  int data[2];
  mouse.report(data);
  mx = data[1];
  my = data[2];
  
   if(my < 0)
   backward(my);
 else if(my > 0)
   forward(my);
   
 if(mx < 0)
   right(mx);
 else if (mx > 0)
    left(mx);
}
void forward(int del){
   Serial.println("Begin");
    digitalWrite(motorsPinEnable,HIGH);
    digitalWrite(motor1Pin1, LOW); 
    digitalWrite(motor1Pin2, HIGH);
    
    digitalWrite(motor2Pin1, HIGH); 
    digitalWrite(motor2Pin2, LOW);
   
    delay(abs(del)*2); 
    digitalWrite(motorsPinEnable,LOW);
    Serial.println("Einde");
}

void backward(int del){
    digitalWrite(motorsPinEnable,HIGH);
    digitalWrite(motor1Pin1, HIGH); 
    digitalWrite(motor1Pin2, LOW); 
    
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    
    delay(abs(del)*2); 
    digitalWrite(motorsPinEnable,LOW);
}

void left(int del){
    digitalWrite(motorsPinEnable,HIGH);
    digitalWrite(motor1Pin1, LOW); 
    digitalWrite(motor1Pin2, HIGH);  
    
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    
    delay(abs(del)*2); 
    digitalWrite(motorsPinEnable,LOW);
}

void right(int del){
    digitalWrite(motorsPinEnable,HIGH);
    digitalWrite(motor1Pin1, HIGH); 
    digitalWrite(motor1Pin2, LOW);  
    
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    
    delay(abs(del)*2);  
    digitalWrite(motorsPinEnable,LOW);
}



int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

