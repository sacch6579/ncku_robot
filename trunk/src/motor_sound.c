#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <unistd.h>

#define TrigPin 27
#define EchoPin 28
void delayMSM(int x){
 usleep(x*1000);
}
float motor_sound(int y){
//wiringPiSetup();
pinMode(TrigPin, OUTPUT);
pinMode(EchoPin, INPUT);
while(y){
digitalWrite(TrigPin, LOW);
delayMSM(2);
digitalWrite(TrigPin, HIGH);
delayMSM(10);
digitalWrite(TrigPin, LOW);
float startime;
float traveltime;
float distance;
while(digitalRead(EchoPin) == LOW)
{startime = micros();}
while(digitalRead(EchoPin) == HIGH)
{traveltime = micros() - startime;}

distance = traveltime*17/1000;

printf("Value_cm=%f\n",distance);
delayMSM(10);
return distance;
}
}

