/*
 * Microcontroller_Practice.cpp
 *
 * Created: 2022-03-21 오후 10:52:25
 * Author : Hi
 */ 

// ● GPIO - LED
	// 2. LED 실습
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// LED 1개 켜기 + delay
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
// LED 4비트 켜기 - 1개씩
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
// LED 4비트 켜기 - level
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
// LED 모두 켜기 basic1 by Switch
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>

int main(){
	DDRA = 0x0F; // 4비트 출력모드
	DDRB = 0x00; // 4비트 입력모드
	while(1){
		if((PINB & 0x01) == 0x00) // 풀업모드임을 인지. 4비트만 확인. 5V를 연결하지 않은 경우 플로팅 현상으로 인해 스위치를 누르지 않아도 LED가 켜져 있는듯
			PORTA = 0x0F; // 4비트 출력 ON
		else
			PORTA = 0x00; // 4비트 출력 OFF
	}
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// LED 모두 켜기 basic2 by Switch
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
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
// LED 4비트 2진count by Switch
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
			delay(1); // delay(1)이 없다면 switch 읽을 때, 여러번 클릭되서 난리남 ♣
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
// LED 4비트 level변화 by Switch
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
// LED 4비트 2진count _delay_ms by Switch
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
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//● GPIO - Speaker
	//2. Speaker 실습
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 1kHz 소리내기 by 무조건
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define M1 1<<1 // 1번핀 마스크 ♣

int main(){
	DDRE |= M1; // 1번핀 마스크 ♣
	while(1){
		PORTE |= M1; // 1번핀 마스크 ♣q
		_delay_us(500);
		PORTE &= ~M1; // 1번핀 마스크 ♣
		_delay_us(500);
	}
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 1kHz 소리내기 by 스위치
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/* // E0핀에 회로 연결한 상태로 컴파일 시 오류 발생
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define M0 1<<PE0 // 0번핀 마스크 ♣
#define M1 1<<PE1 // 1번핀 마스크 ♣

int main(){
	DDRE |= M1;
	while(1){
		if((PINE & M0) == 0){ // 풀업모드이기 때문 ♣
			PORTE |= M1;
			_delay_us(500);
			PORTE &= ~M1;
			_delay_us(500);
		}
	}
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 20~500Hz 소리내기(320Hz 8번, 480Hz 12번)
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>
#define F_CPU 16000000UL
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>
#define M0 1 << 0
#define M1 1 << 1

void tone(int fr, int duration){
	int t_ms = (1/fr) * 1000/2; // 주기 = 2 * t_ms = (1 / f). 이건 초단위 이므로 ms에 맞게 * 1000 ♣
	for (int i = 0; i < duration; i++){ // 특정 주기 횟수 기준 반복o. 동일한 시간 기준 반복x  ♣
		PORTE |= M1;
		_delay_ms(t_ms);
		PORTE &= ~M1;
		_delay_ms(t_ms);
	}
}

int main(){
	DDRE = M1;
	while(1){
		if((PINE & M0) == 0){ // 풀업모드이기 때문 ♣
			for(int i = 0; i < 20; i ++){
				tone(320, 8);
				tone(480, 12);
			}
			_delay_ms(2000);
		}
	}
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 1~20KHz 소리내기
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>
#include <stdint.h> // 다양한 정수형 선언 가능. uint32_t 선언을 위함 ♣
#define F_CPU 16000000UL
#define __DELAY_BACKWARD_COMPATIBLE__ // 지연함수 _delay_ms, _delay_us 인수에 변수 사용 가능 ♣
#include <util/delay.h>
#define HALF_CYC 500000UL
#define M0 1 << 0
#define M1 1 << 1

void tone2(int fr, int duration){
	uint32_t t_tot = HALF_CYC/fr; // 주기 = 2 * t_ms = (1 / f). 이건 초단위 이므로 us에 맞게 * 1000000 ♣
	int t_ms = t_tot/1000;
	int t_us = t_tot % 1000;
	for (int i = 0; i < duration; i++){ // 특정 주기 횟수 기준 반복o. 동일한 시간 기준 반복x ♣
		PORTE |= M1;
		_delay_ms(t_ms);
		_delay_us(t_us);
		PORTE &= ~M1;
		_delay_ms(t_ms);
		_delay_us(t_us);
	}
}

int main(){
	DDRE = M1;
	while(1){
		if((PINE & M0) == 0){ // 풀업모드이기 때문 ♣
			tone2(784, 240);
			tone2(1047, 700);
			_delay_ms(50);
		}
	}
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 1~20KHz 소리내기 - 도레미파솔라시도
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>
#include <stdint.h> // 다양한 정수형 선언 가능. uint32_t 선언을 위함 ♣
#define F_CPU 16000000UL
#define __DELAY_BACKWARD_COMPATIBLE__ // 지연함수 _delay_ms, _delay_us 인수에 변수 사용 가능 ♣
#include <util/delay.h>
#define HALF_CYC 500000UL
#define M0 1 << 0
#define M1 1 << 1

void tone2(int fr, int duration){
	uint32_t t_tot = HALF_CYC/fr; // 주기 = 2 * t_ms = (1 / f). 이건 초단위 이므로 us에 맞게 * 1000000 ♣
	int t_ms = t_tot/1000;
	int t_us = t_tot % 1000;
	for (int i = 0; i < duration; i++){ // 특정 주기 횟수 기준 반복o. 동일한 시간 기준 반복x ♣
		PORTE |= M1;
		_delay_ms(t_ms);
		_delay_us(t_us);
		PORTE &= ~M1;
		_delay_ms(t_ms);
		_delay_us(t_us);
	}
}

int main(){
	DDRE |= M1;
	int freq[] = {523, 587, 659, 698, 784, 880, 988, 1047}; // 옥타브4 
	while(1){
		if((PINE & M0) == 0){ // 풀업모드이기 때문 ♣
			for(int i = 0; i < 8; i++){
				tone2(freq[i], 300);
				_delay_ms(50);
			}
		}
	}
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 1~20KHz 소리내기 - 도레미파솔라이도 음길이 일정
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>
#include <stdint.h> // 다양한 정수형 선언 가능. uint32_t 선언을 위함 ♣
#define F_CPU 16000000UL
#define __DELAY_BACKWARD_COMPATIBLE__ // 지연함수 _delay_ms, _delay_us 인수에 변수 사용 가능 ♣
#include <util/delay.h>
#define M0 1 << 0
#define M1 1 << 1

void tone3(uint16_t fr, uint16_t dur){
	uint16_t on_time = (1. / fr) * 500000.; // 주기 = 2 * on_time = (1 / f). 이건 초단위 이므로 us에 맞게 * 1000000 ♣
	uint16_t n = dur * 1000. / (2. * on_time); // 특정 주기 횟수 * 1000 / 주기. 한 주기가 짧은 것은 더 많은 주기 횟수 반복, 한 주기가 긴 것은 더 적은 주기 횟수 반복 ♣
	for (int i = 0; i < n; i++){ // 특정 주기 횟수 기준 반복x. 동일한 시간 기준 반복o ♣
		PORTE |= M1;
		_delay_us(on_time);
		PORTE &= ~M1;
		_delay_us(on_time);
	}
}

int main(){
	DDRE |= M1;
	int freq[] = {523, 587, 659, 698, 784, 880, 988, 1047}; // 옥타브4 
	while(1){
		if((PINE & M0) == 0){ // 풀업모드이기 때문 ♣
			for(int i = 0; i < 8; i++){
				tone3(freq[i], 300);
				_delay_ms(50);
			}
		}
	}
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 기말 대체 과제
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>
#include <stdio.h>
#include <stdint.h> // 다양한 정수형 선언 가능. uint32_t 선언을 위함 ♣
#define F_CPU 16000000UL
#define __DELAY_BACKWARD_COMPATIBLE__ // 지연함수 _delay_ms, _delay_us 인수에 변수 사용 가능 ♣
#include <util/delay.h>
#define M0 1 << 0
#define M1 1 << 1

#define DO 262
#define RE 294
#define MI 330
#define FA 349
#define FA_S 370
#define SOL 392
#define SOL_S 412
#define RA 440
#define SI 494
#define DO2 523
#define DO2_S 554
#define RE2 587
#define RE2_S 622
#define MI2 659
#define FA2 698
#define SOL2 784
#define RA2 880
#define SI2 988
#define DO3 1047

void tone3(uint16_t fr){
	uint16_t on_time = (1. / fr) * 500000.; // 주기 = 2 * on_time = (1 / f). 이건 초단위 이므로 us에 맞게 * 1000000 ♣
	PORTE |= M1;
	_delay_us(on_time);
	PORTE &= ~M1;
	_delay_us(on_time);
}

int main(){
	DDRE |= M1;
	DDRA |= 15; //
	unsigned int melody[] = {DO2, DO2, RA2, SOL2, MI2, MI2, SOL2, FA2, MI2, RE2, DO2, DO2, RA, DO2, MI2, MI2, MI2, SOL2, FA2, MI2, RE2, DO2, RA2,
		SOL2, RE2, MI2, MI2, SOL2, FA2, MI2, RE2, DO2, DO2, RA, DO2, MI2, DO2, RE2, DO2, FA, FA_S, SOL, DO2, RA2,
		SOL2, SOL2,  MI2, MI2, SOL2, FA2, MI2, RE2, DO2, DO2, RA, DO2, MI2, MI2, MI2, SOL2, FA2, MI2, RE2, DO2, RA2,
		SOL2, RE2, MI2, MI2, SOL2, FA2, MI2, RE2, DO2, DO2, RA, DO2, MI2, DO2, RE2, DO2, MI, FA, MI,
		MI2, RE2, MI2, MI2, RE2, DO2, DO2, DO2, DO2, RE2, MI2, SOL2, SOL2, MI2, MI2, RE2, DO2_S, RE2, MI2, RA, FA2,
		MI2, RE2, MI2, MI2, RE2, DO2, DO2, DO2, DO2, RE2, MI2, SOL2, SOL2, MI2, MI2, RE2, DO2_S, RE2, MI2, RA, FA2, RA,
		DO2, DO2, RA, DO2, DO2, RA, DO2, DO2, RA, DO2, RE2, MI2, RE2, DO2, RE2, DO2, DO2, RA, DO2, DO2, DO2, SOL2, SOL2, RA2, MI2, RE2, 
		DO2, RE2, DO2, DO2, RE2, DO2, MI2, MI2, MI2, MI2, RE2, DO2, RE2, MI2, RA2, MI2, RE2_S, RE2, SOL, SOL_S, RA, DO2, DO2, FA, FA_S, SOL, SOL}; // 옥타브4~5
	int melody_cnt = sizeof(melody) / sizeof(unsigned int);
	int cnt = 0;
	int flag = 1;
	while(cnt < melody_cnt){
		while((PINE & M0) == 0){
			tone3(melody[cnt]);
			PORTA |= 1; //
			PORTA &= ~2; //
			PORTA &= ~4; //
			
			if(flag == 1){
				cnt++;
				flag = 0;
			}
		}
		flag = 1;
		_delay_ms(50);
		PORTA |= 2; //
		PORTA &= ~1; //
		PORTA &= ~4; //
	}
	PORTA |= 4; //
	PORTA &= ~1; //
	PORTA &= ~2; //
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//● GPIO - FND
	//2. FND 실습
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 0~9 숫자 by 0.2초 간격 
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void){
	unsigned char digit[] = {0x88, 0xBE, 0xC4, 0xB2, 0xA1, 0x83, 0xBC, 0x80, 0xB0};
	unsigned int count = 0, num;
	DDRC = 0xff;
	PORTC = digit[0];
	
	while(1){
		count++;
		_delay_ms(200);
		num = count % 10;
		PORTC = digit[num];
	}
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 0~9 숫자 by 버튼
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void){
	unsigned char digit[] = {0x88, 0xBE, 0xC4, 0xB2, 0xA1, 0x83, 0xBC, 0x80, 0xB0};
	unsigned int count = 0, num;
	DDRB = 0x00; // 입력 모드 ♣
	PORTB |= 1 << PORTB0;
	DDRC = 0xff;
	PORTC = digit[0];
	
	while(1){
		if((PINB & 1 << PORTB0) == 0x00){ // 풀업모드이기 때문 ♣
			count++;
			_delay_ms(200);
		}
		num = count % 10;
		PORTC = digit[num];
	}
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 0~9 숫자 + PWM LED by 버튼
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/* // 아직 이해 못함 ♣♣♣
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define LONG_CYC 20

int main(void){
	uint8_t digit[] = {0x88, 0xBE, 0xC4, 0xA4, 0xB2, 0xA1, 0x83, 0xBC, 0x80, 0xB0};
	uint16_t count = 0;
	uint16_t scount = 0;
	uint16_t duty = 0;
	DDRA = 0x0f;
	DDRE = 0x00;
	PINE |= 1 << PINE0;
	DDRC = 0xff;
	PORTC = digit[0];
	
	while(1){
		if((PINE & 1 << PINE0) == 0x00){ // 풀업모드이기 때문 ♣
			duty++;
			if(duty == 10){
				duty = 0; // duty : 0~9 사이값
			}
			PORTC = digit[duty];
			_delay_ms(200);
		}
		
		// scount가 10~19인 경우 LED on ♣
		if((count % LONG_CYC) == 0){
			PORTA |= 0x0f;
			scount = 0; // scount : 0~19 사이값
		}
		
		// scount가 0~9인 경우 LED off ♣
		if(scount == duty){
			PORTA=(PORTA & 0xf0);
			_delay_ms(1);
			scount++;
			count++;
		}
	}
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 0~9 숫자 + PWM LED + Debouncing by 버튼
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define LONG_CYC 20

int main(void){
	uint8_t digit[] = {0x88, 0xBE, 0xC4, 0xA4, 0xB2, 0xA1, 0x83, 0xBC, 0x80, 0xB0};
	uint16_t count = 0;
	uint16_t scount = 0;
	uint16_t duty = 0;
	DDRA = 0x0f;
	DDRE = 0x00;
	PINE |= 1 << PINE0;
	DDRC = 0xff;
	PORTC = digit[0];
	
	while(1){
		if((PINE & 1 << PINE0) == 0x00){ // 풀업모드이기 때문 ♣
			duty++;
			if(duty == 10){
				duty = 0; // duty : 0~9 사이값
			}
			PORTC = digit[duty];
			_delay_ms(200);
		}
		
		// scount가 10~19인 경우 LED on ♣
		if((count % LONG_CYC) == 0){
			PORTA |= 0x0f;
			scount = 0; // scount : 0~19 사이값
		}
		
		// scount가 0~9인 경우 LED off ♣
		if(scount == duty){
			PORTA=(PORTA & 0xf0);
			_delay_ms(1);
			scount++;
			count++;
		}
	}
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//● GPIO - FND
//2. 4자리 FND 실습
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 0123 출력
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
uint8_t digit[10] = {0x88, 0xBE, 0xC4, 0xA4, 0xB2, 0xA1, 0x83, 0xBC, 0x80, 0xB0};
uint8_t digi_sel[4] = {0x01, 0x02, 0x04, 0x08};
	
int main(){
	int i = 0;
	DDRC = 0xff;
	DDRF = 0x0f;
	
	while(1){
		for(int i = 0; i < 4; i++){
			PORTC = digit[i];
			PORTF = digi_sel[i];
			_delay_ms(2);
		}
	}
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 1/100초 시계
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
uint8_t digit[10] = {0x88, 0xBE, 0xC4, 0xA4, 0xB2, 0xA1, 0x83, 0xBC, 0x80, 0xB0};
uint8_t digi_sel[4] = {0x01, 0x02, 0x04, 0x08};
uint8_t fnd[4];
	
int main(){
	uint16_t count = 0;
	DDRC = 0xff;
	DDRF = 0x0f;
	while(1){
		count++;
		if(count == 10000){
			count = 0;
		}
		
		fnd[0] = (count/1000)%10;
		fnd[1] = (count/100)%10;
		fnd[2] = (count/10)%10;
		fnd[3] = count%10;
		for(int i = 0; i < 4; i++){
			PORTC = digit[fnd[i]];
			PORTF = digi_sel[i];
			_delay_us(2500); // 2500us + 2500us + 2500us + 2500us = 총 10ms(160만분의 1초의 속도로 코드를 실행하는 시간은 무시한 것)
		}
	}
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//● GPIO - Interrupt
	//2. Interrupt 실습
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// button led 반전 - polling
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(){
	DDRA = 0x01; DDRD = 0x00; PORTD = 0x01;		// 풀업 선언 ♣♣♣
	while(1){
		do{
		}while((PIND & 0x01) != 0x00);
		PORTA = PORTA ^ 0x01;					// XOR 반전 ♣
		_delay_ms(50);
	}
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// button led 반전 - 외부 interrupt
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>						// interrupt 헤더파일 불러오기 ♣

ISR(INT0_vect){
	PORTA = PORTA ^ 0x01;
}

int main(){
	DDRA = 0x0f;
	DDRD = 0x00;
	EICRA |= (1<<ISC01);	// 하강 에지 ♣
	EIMSK |= (1<<INT0);		// 인터럽트 활성화 ♣
	sei();					// 전역 인터럽트 활성화 ♣
	while(1);
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// button 누를때만 led 켜지기 - 외부 interrupt
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*	// 이거 왜 안됨??? ♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣
#include <avr/io.h>
#include <avr/interrupt.h>
#define USE_IE0_INTERRUPT (EIMSK |= (1<<INT0))					// 이렇게 해도 된다 ♣♣
#define IE0_DETECT_FALLING (EICRA = (1<<ISC01))					// 10 : 하강에지 ♣
#define IE0_DETECT_RISING (EICRA = (1<<ISC01) | (1<<ISC00))		// 11 : 상승에지 ♣

ISR(INT0_vect){
	PORTA = PORTA ^ 0x01;
	if((EICRA & (1<<ISC00)) == 0){	// FALLING인 경우 RISING으로 바꿈. 누른 상태에서는 반전되서 켜짐 ♣
		IE0_DETECT_RISING;
	}
	else{							// RISING인 경우 FALLING으로 바꿈. 뗀 상태에서는 다시 반전되서 꺼짐 ♣
		IE0_DETECT_FALLING;	
	}
}

int main(){
	DDRA = 0x0f;
	DDRD = 0x00;
	IE0_DETECT_FALLING;		// 하강 에지
	USE_IE0_INTERRUPT;		// 인터럽트 활성화
	sei();					// 전역 인터럽트 활성화
	while(1);
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ


// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//● GPIO - PWM
	//2. PWM 실습
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 1/100초 타이머
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>
#include <avr/interrupt.h>
void disp_digit(unsigned char, unsigned char);
unsigned char digit[10] = {0x88, 0xBE, 0xC4, 0xA4, 0xB2, 0xA1, 0x83, 0xBC, 0x80, 0xB0};
volatile unsigned int count=0;
ISR(TIMER0_OVF_vect) {
	count++;
	TCNT0=6;
}

int main() {
	unsigned char num;
	DDRC = 0xff;
	DDRG = 0x0f;
	TCCR0 |= 1<<CS02;			// Prescale 64 -> 4us ♣
	TIMSK |= 1<<TOIE0;			// Count Overflow Interrupt Enable ♣
	TCNT0=6;					// 4us x (256 - 6) = 1ms ♣♣
	sei();
	
	while (1){
		if ((count % 10)==0){	//1자리
			num= (count/10)%10;
			disp_digit(num, 0);
		}
		if ((count % 10)==2){	//10자리
			num= (count/100)%10;
			disp_digit(num, 1);
		}
		if ((count % 10)==5){	//100자리
			num= (count/1000)%10;
			disp_digit(num, 2);
		}
		if ((count % 10)==8){ //1000자리
			num= (count/10000)%10;
			disp_digit(num, 3);
		}
	}
}

void disp_digit(unsigned char num, unsigned char d) {
	PORTC = digit[num];
	PORTG = 0x01<<d;
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// 타이머에 따른 LED PWM 조절
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define TC0_FAST_PWM (1<<WGM00 | 1<<WGM01)		// 웨이브 제너레이션 모드 : 고속 PWM 모드 ♣
#define TC0_NONIVERT_PWM (1<<COM01)				// 비교 출력 모드 of 고속 PWM 모드 : OC0핀을 BOTTOM에서 셋 / TCNT0 == OCR0면 클리어 ♣
#define TC0_PRESCALE_32 (1<<CS00 | 1<<CS01)		// pre-scale : 32비트 ♣

void disp_FND(unsigned char num);
void initialize(void);
void disp_digit(unsigned char num, unsigned char d);

unsigned char digit[10] = {0x88, 0XBE, 0xC4, 0xA4, 0xB2, 0xA1, 0x83, 0xBC, 0x80, 0xB0};
	
int main(void) {
	unsigned int count=0;
	unsigned char duty;
	initialize();
	while (1){
		duty=count % 256;
		OCR0=duty;
		count++;
		disp_FND(duty);
	}
}

void disp_FND(unsigned char num){
	unsigned char fnd[4];
	fnd[3] = (num/1000)%10;
	fnd[2] = (num/100)%10;
	fnd[1] = (num/10)%10;
	fnd[0] = num%10;
	for (int i=0; i<4; i++){
		disp_digit(fnd[i],i);
		_delay_ms(2);
		if(i%2) _delay_ms(1);
	}
}

void disp_digit(unsigned char num, unsigned char d){
	PORTC = digit[num];
	PORTF = 1<<d;
}
void initialize(){
	DDRB=0x10;	// DDRB |=1<<PORTB4
	DDRC=0xFF;
	DDRF=0x0F;
	TCCR0 |= TC0_FAST_PWM | TC0_NONIVERT_PWM | TC0_PRESCALE_32;
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// button 누를때 서보모터 움직임
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>
#define BOT (PIND & 0x01)
#define TC0_FAST_PWM (1<<WGM00 | 1<<WGM01) // 고속 PWM 모드
#define TC0_NONIVERT_PWM (1<<COM01) // 비교 출력 모드
#define TC0_PRESCALE_1024 (1<<CS00| 1<<CS01 | 1<<CS02) // 프리스케일 모드
unsigned int prev_BOT=1, count=0;
int main(void) {
	DDRB=0x10; // 서보모터
	DDRD=0x00; // 버튼
	PORTD |= 1<<PORTD0; // Pull up
	OCR0=23; count=23; // 서보모터
	TCCR0 |= TC0_FAST_PWM | TC0_NONIVERT_PWM | TC0_PRESCALE_1024; // 제어 레지스터
	
	while(1) {
		// 서보모터 제어
		if ((BOT==0) && (prev_BOT ==1)){
			count=count+2;
			count=(count<39) ? count: 9;
			OCR0=count;
		}
		prev_BOT=BOT;
	}
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// DC모터 움직임 - sin파
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <math.h>
#define IN1 PB7
// (IN1 IN2) = (H L)-->CW, (IN1 IN2)= (L H)--> CCW
#define IN2 PB4 //(IN1 IN2)= (H H) or (L L)--> STOP
#define TC0_PRESCALE_32 (1<<CS00 | 1<<CS01)
#define TC0_FAST_PWM (1<<WGM00| 1<<WGM01)
#define TC0_NONINVERT_PWM (1<<COM01)
void initial ();

int main(void) {
	int count=0;
	double speed, t;
	unsigned char vel;
	initial ();
	while(1){
		t=(double)count/180.*3.141592;
		speed=255*sin(t);
		vel=(unsigned int)fabs(speed);
		if (speed>=0){
			PORTB|=(1<<IN1);
			OCR0=255-vel;
		}
		else{
			PORTB &=~(1<<IN1);
			OCR0=vel;
		}
		count++;
		_delay_ms(20);
	}
}
void initial (){
	DDRB=0x90;
	TCCR0 |= TC0_FAST_PWM | TC0_NONINVERT_PWM
	| TC0_PRESCALE_32; //PRESCALE 32
}
*/
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
// DC모터 움직임 - 버튼에 따른 state 변화 // 이거 교수님도 안된대 ♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣♣
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
/*
#include <avr/io.h>
#include <avr/interrupt.h>
#define IN1 PB7
// (IN1 IN2) = (H L)-->CW, (IN1 IN2)= (L H)--> CCW
#define IN2 PB4 //(IN1 IN2)= (H H) or (L L)--> STOP
#define Use_IE0_Interrupt (EIMSK |= (1<<INT0))
#define IE0_Detect_Falling (EICRA = (1<<ISC01))
#define TC0_PRESCALE_32 (1<<CS00 | 1<<CS01)
#define TC0_FAST_PWM (1<<WGM00| 1<<WGM01)
#define TC0_NONINVERT_PWM (1<<COM01)
void initial ();
unsigned char vel;
enum {STOP, CW,STOP2, CCW} mode ;

ISR(INT0_vect) {
	if (mode==STOP) mode=CW;
	if (mode==CW) mode=STOP2;
	if (mode==STOP2) mode=CCW;
if (mode==CCW) mode=STOP;}
int main(void) {
	mode=STOP;
	initial ();
	vel=100;
	while(1){
		switch (mode){
			case STOP:
			case STOP2:
				PORTB &=~(1<<IN1);
				OCR0=0;
				break;
			case CW:
				PORTB|=(1<<IN1);
				vel=0.3*255; //70%
				OCR0=255-vel;
				break;
			case CCW:
				PORTB &=~(1<<IN1);
				vel=0.4*255; //40%
				OCR0=vel;
				break;
			}}}
			
void initial (){
	DDRB=0xff; DDRD=0x00; PORTD|=0x01;
	OCR0=0;
	TCCR0 |= TC0_FAST_PWM | TC0_NONINVERT_PWM
	| TC0_PRESCALE_32; //PRESCALE 32
	EICRA |= IE0_Detect_Falling; // Falling Edge
	EIMSK |= (1<<INT0); // Use Interrupt
	sei();
}
*/

