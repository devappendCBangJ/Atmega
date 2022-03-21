/*
 * Microcontroller_Practice.cpp
 *
 * Created: 2022-03-21 오후 10:52:25
 * Author : Hi
 */ 

#include <avr/io.h>
void delay(int sec);

int main(){
	DDRA = 0x01;
	while(1){
		PORTA = 0x01;
		delay(1);
		PORTA = 0x00;
		delay(1);
	}
}

void delay(int sec){
	volatile int i, j, k;
	for (i = 0; i < sec; i++)
	for (j = 0; j < 1000; j++)
	for (k = 0; k < 1000; k++);
}

