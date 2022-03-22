/*
 * Microcontroller_Practice.cpp
 *
 * Created: 2022-03-21 오후 10:52:25
 * Author : Hi
 */ 

// ● GPIO - LED
	// 2. LED 실습
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>
void delay(int sec);

int main(){
	DDRA = 0x01; // 몇 진수든 사용 가능
	while(1){
		PORTA = 0x01;
		delay(1);
		PORTA = 0x00;
		delay(1);
	}
}

void delay(int sec){
	volatile int i, j, k;
	for (i = 0; i < sec; i++){
		for (j = 0; j < 1000; j++){
			for (k = 0; k < 1000; k++);
		}
	}
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>
void delay(int sec);

int main(){
	DDRA = 0x0f; // 몇 진수든 사용 가능
	while(1){
		PORTA = 0b0001;delay(1);
		PORTA = 0b0010; delay(1);
		PORTA = 0b0100; delay(1);
		PORTA = 0b1000; delay(1);
		PORTA = 0b0100; delay(1);
		PORTA = 0b0010; delay(1);
	}
}

void delay(int sec){
	volatile int i, j, k;
	for (i = 0; i < sec; i++){
		for (j = 0; j < 1000; j++){
			for (k = 0; k < 1000; k++);
		}
	}
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>
void delay(int sec);

int main(){
	DDRA = 0x0f; // 몇 진수든 사용 가능
	while(1){
		PORTA = 0b0001; delay(1);
		PORTA = 0b0011; delay(1);
		PORTA = 0b0111; delay(1);
		PORTA = 0b1111; delay(1);
		PORTA = 0b0111; delay(1);
		PORTA = 0b0011; delay(1);
	}
}

void delay(int sec){
	volatile int i, j, k;
	for (i = 0; i < sec; i++){
		for (j = 0; j < 1000; j++){
			for (k = 0; k < 1000; k++);
		}
	}
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ


// ● GPIO - Switch
	// 2. Switch 실습
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>

int main(){
	DDRA = 0x0F; // 4비트 출력모드
	DDRB = 0x00; // 0비트 입력모드 ♣♣♣
	while(1){
		if((PINB & 0x01) == 0x00) // 풀업모드임을 인지. 4비트만 확인. 5V를 연결하지 않은 경우 플로팅 현상으로 인해 스위치를 누르지 않아도 LED가 켜져 있는듯
			PORTA = 0x0F; // 4비트 출력 ON
		else
			PORTA = 0x00; // 4비트 출력 OFF
	}
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/* // ♣♣♣
#include <avr/io.h>

int main(){
	DDRA |= 0x0F; // 4비트 출력모드 + 나머지 기존 비트 유지
	DDRB &= 0xFE; // 4비트 중 0번만 입력모드 + 나머지 기존 비트 유지
	PORTA |= 0x01;
	while(1){
		if((PINB & 0x01) == 0x00) // 풀업모드임을 인지. 4비트만 확인. 5V를 연결하지 않은 경우 플로팅 현상으로 인해 스위치를 누르지 않아도 LED가 켜져 있는듯
			PORTA |= 0x0F; // 4비트 출력 ON + 나머지 기존 비트 유지
		else
			PORTA &= 0xF0; // 4비트 출력 OFF + 나머지 기존 비트 유지
	}
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>
void delay(int sec);

int main(){
	unsigned char count = 0;
	DDRA = 0x0F;
	DDRB = 0x00;
	while(1){
		if((PINB & 0x01) == 0x00){ // 풀업모드임을 인지. 4비트만 확인. 5V를 연결하지 않은 경우 플로팅 현상으로 인해 스위치를 누르지 않아도 LED가 켜져 있는듯
			count++;
			delay(1);
		}
		PORTA = count & 0x0F; // 4비트 출력 지정 + 나머지 기존 비트 유지
	}
}

void delay(int sec){
	volatile int i, j, k;
	for (i = 0; i < sec; i++){
		for (j = 0; j < 1000; j++){
			for (k = 0; k < 1000; k++);
		}
	}
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>
void delay(int sec);

int main(){
	unsigned char count = 0;
	DDRA = 0x0F;
	DDRB = 0x00;
	while(1){
		if((PINB & 0x01) == 0x00){ // 풀업모드임을 인지. 4비트만 확인. 5V를 연결하지 않은 경우 플로팅 현상으로 인해 스위치를 누르지 않아도 LED가 켜져 있는듯
			count++;
			delay(1);
		}
		if (count == 5)
			count = 0;
		switch(count & 0x0F){
			case 0:
				PORTA = 0b0000; break;
			case 1:
				PORTA = 0b0001; break;
			case 2:
				PORTA = 0b0011; break;
			case 3:
				PORTA = 0b0111; break;
			default:
				PORTA = 0b1111; break;
		}
	}
}

void delay(int sec){
	volatile int i, j, k;
	for (i = 0; i < sec; i++){
		for (j = 0; j < 1000; j++){
			for (k = 0; k < 1000; k++);
		}
	}
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>
#define F_CPU 16000000UL // ♣♣♣
#include <util/delay.h> // ♣♣♣

int main(){
	unsigned char count = 0;
	DDRA = 0x0F;
	DDRB = 0X00;
	while(1){
		if ((PINB & 0x01) == 0x00){ // 풀업모드임을 인지. 4비트만 확인. 5V를 연결하지 않은 경우 플로팅 현상으로 인해 스위치를 누르지 않아도 LED가 켜져 있는듯
			count++;
			_delay_ms(50);
		}
		PORTA = count & 0x0F;
	}
}
*/