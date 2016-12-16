
#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define CLOCKWISE 1
#define COUNTER_CLOCKWISE 2
void delayMS(int x);
void rotate(int* pins, int direction);
void rotate1(int* pins1, int direction);
int main(void) {
/* number of the pins which connected to the stepper motor driver board */
int pinA = 0;
int pinB = 2;
int pinC = 3;
int pinD = 7;
int pinE = 22;
int pinF = 24;
int pinG = 23;
int pinH = 25;
int pins[4] = {pinA, pinB, pinC, pinD};
int pins1[4]= {pinE, pinF, pinG, pinH};
if (-1 == wiringPiSetup()) {
printf("Setup wiringPi failed!");
return 1;
}
/* set mode to output */
pinMode(pinA, OUTPUT);
pinMode(pinB, OUTPUT);
pinMode(pinC, OUTPUT);
pinMode(pinD, OUTPUT);
pinMode(pinE, OUTPUT);
pinMode(pinF, OUTPUT);
pinMode(pinG, OUTPUT);
pinMode(pinH, OUTPUT);
int i;
delayMS(50);    // wait for a stable status 
for (i = 0; i < 500; i++) {
rotate(pins, COUNTER_CLOCKWISE);

rotate1(pins1, CLOCKWISE);
}
return 0;
}
/* Suspend execution for x milliseconds intervals.
* @param ms Milliseconds to sleep.
*/
void delayMS(int x) {
usleep(x * 1000);
}
/* Rotate the motor.
* @param pins     A pointer which points to the pins number array.
*  @param direction CLOCKWISE for clockwise rotation, COUNTER_CLOCKWISE for counter clockwise rotation.
*/
void rotate(int* pins, int direction) {
int i,j;
for (i = 0; i < 4; i++) {
if (CLOCKWISE == direction) {
for (j = 0; j < 4; j++) {
if (j == i) {
digitalWrite(pins[3 - j], 1); // output a high level 
} else {
digitalWrite(pins[3 - j], 0); // output a low level 
}
}
} else if (COUNTER_CLOCKWISE == direction) {
for (j = 0; j < 4; j++) {
if (j == i) {
digitalWrite(pins[j], 1); // output a high level 
} else {
digitalWrite(pins[j], 0); // output a low level 
}
}
}
delayMS(4);
}
}
void rotate1(int* pins1, int direction) {
int i,j;
for (i = 0; i < 4; i++) {
if (CLOCKWISE == direction) {
for (j = 0; j < 4; j++) {
if (j == i) {
digitalWrite(pins1[3 - j], 1); // output a high level 
} else {
digitalWrite(pins1[3 - j], 0); // output a low level 
}
}
} else if (COUNTER_CLOCKWISE == direction) {
for (j = 0; j < 4; j++) {
if (j == i) {
digitalWrite(pins1[j], 1); // output a high level 
} else {
digitalWrite(pins1[j], 0); // output a low level 
}
}
}
delayMS(2);
}
}
