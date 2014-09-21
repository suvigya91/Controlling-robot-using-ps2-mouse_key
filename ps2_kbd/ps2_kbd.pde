
#include <ps2.h>

PS2 kbd(6, 5);
int motor1Pin1 = 8; 
int motor1Pin2 = 9; 

int motor2Pin1 = 10; 
int motor2Pin2 = 11; 

int motorsPinEnable = 12;

void kbd_init()
{
  char ack;

  kbd.write(0xff);  
  ack = kbd.read(); 
  ack = kbd.read(); 
}

void setup()
{
  Serial.begin(9600);
  kbd_init();
  pinMode(motor1Pin1, OUTPUT); 
  pinMode(motor1Pin2, OUTPUT); 
  pinMode(motor2Pin1, OUTPUT); 
  pinMode(motor2Pin2, OUTPUT); 
  pinMode(motorsPinEnable, OUTPUT);

  digitalWrite(motorsPinEnable,HIGH); 
}

void loop()
{
  unsigned char code;
  
  for (;;) 
  { 
    code = kbd.read();
      switch (code)
	{ 
	case 0x75:
	{
	forward();
	break;
	}
	case 0x72:	
	{
	backward();
	break;
	}
	case 0x6B:	
	{
	right();
        break;
	}
	case 0x74:	
	{
	left();
	break;
	}
}
} 
}

 void forward()
{

    digitalWrite(motorsPinEnable,HIGH);
    digitalWrite(motor1Pin1, LOW); 
    digitalWrite(motor1Pin2, HIGH);
    
    digitalWrite(motor2Pin1, HIGH); 
    digitalWrite(motor2Pin2, LOW);
    delay(100);
    digitalWrite(motorsPinEnable,LOW);
   }

void backward()
{
    digitalWrite(motorsPinEnable,HIGH);
    digitalWrite(motor1Pin1, HIGH); 
    digitalWrite(motor1Pin2, LOW); 
    
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    delay(100);
    digitalWrite(motorsPinEnable,LOW);
    
   }

void left()
{
    digitalWrite(motorsPinEnable,HIGH);
    digitalWrite(motor1Pin1, LOW); 
    digitalWrite(motor1Pin2, HIGH);  
    
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    delay(100);
    digitalWrite(motorsPinEnable,LOW);
    
   }

void right()
{
    digitalWrite(motorsPinEnable,HIGH);
    digitalWrite(motor1Pin1, HIGH); 
    digitalWrite(motor1Pin2, LOW);  
    
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    delay(100);
    digitalWrite(motorsPinEnable,LOW);
    
 }
