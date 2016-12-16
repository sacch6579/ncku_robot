/**
Author:
Date:
Description:
This file demonstrates how to control a step motor using C code.
**/


#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
#define PWMpin1 7
#define PWMpin2 0
#define PWMpin3 2
#define PWMpin4 3
void delayMS(int);
int motor_angle(int);
int main(void)
{
	/*if( -1 == wiringPiSetup())
	{
	printf("Setup wiringPi failed");
	}*/
	wiringPiSetup();
	softPwmCreate(PWMpin1,0,100); 
	softPwmCreate(PWMpin2,0,100);
	softPwmCreate(PWMpin3,0,100);
	softPwmCreate(PWMpin4,0,100);
	pinMode(PWMpin1,PWM_OUTPUT); 
	pinMode(PWMpin2,PWM_OUTPUT); 
	pinMode(PWMpin3,PWM_OUTPUT);   
	pinMode(PWMpin4,PWM_OUTPUT);
	int select;
	printf("select begin is 1 select stop is 0\n");
	scanf("%d",&select);
	if(select == 1)        
	while(1)
	{
	          
		motor_angle(0);
		delayMS(100);
		motor_angle(60);
		delayMS(100);
		motor_angle(90);
		delayMS(100);
		motor_angle(120);
		delayMS(100);	
	}
	else if(select == 0)
	{
		return ;
	}
}
void delayMS(int x)
{
	usleep(x*1000);
}
int motor_angle(int angle)
{
		int i,pulsewidth=0,counter_angle=0;
		for(i=1;i<10;i++)
		{	
			pulsewidth=(int)((angle*11)+500); 
			digitalWrite(PWMpin1,HIGH); 
			delayMicroseconds(pulsewidth);	 
			digitalWrite(PWMpin1,LOW);	 
			delayMS(20-pulsewidth/1000);
			digitalWrite(PWMpin4,HIGH);
			delayMicroseconds(pulsewidth);
			digitalWrite(PWMpin4,LOW);
			delayMS(20-pulsewidth/1000);
			counter_angle = (90-angle)+90;	 			
			pulsewidth=(int)((counter_angle*11)+500); 
			digitalWrite(PWMpin2,HIGH); 
			delayMicroseconds(pulsewidth);	 
			digitalWrite(PWMpin2,LOW);	 
			delayMS(20-pulsewidth/1000);	 			
			digitalWrite(PWMpin3,HIGH);
			delayMicroseconds(pulsewidth);
			digitalWrite(PWMpin3,LOW);
			delayMS(20-pulsewidth/1000);
		}
		return ;
}















