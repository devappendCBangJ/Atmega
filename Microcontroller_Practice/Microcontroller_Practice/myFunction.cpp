#include <avr/io.h>
#include <avr/interrupt.h>
#include "myFunction.h"

// 초기 설정
void initial(){
	DDRD=0xff;						// FND data
	DDRG|=0x0f;						// digit transistors
	DDRB|=_BV(IN1)|_BV(IN2);		// motor IN1 & IN2
	DDRE=0x00;						// button
	DDRA|=_BV(PA0);					// LED
	PORTE|=_BV(PE4);				// internal pull-up
	OCR0=0;
	TCCR0 |= TC0_FAST_PWM | TC0_NONINVERT_PWM |
	TC0_PRESCALE_32;				//PRESCALE
	TCCR2 |= TC2_PRESCALE_64;		// 64 --> 4us*250count =1ms
	OCR2=250;						//4us x 250 count =1ms
	TIMSK |= TC2_COMP_INT_ENABALE;	// compare interrupt
	TCNT2=0;						// 16us x (256-191)= 1ms
	IE4_Detect_Falling;				// Falling Edge
	Use_IE4_Interrupt;				// Use Interrupt
	sei(); 
}

void disp_digit(unsigned char num, unsigned char d){
	PORTD = ~digit[num]; // anode type
	PORTG = 1<<d;
}

void disp_FND(unsigned int val,unsigned int a){
	unsigned char num;
	if ((a % 10)==0){
		num = (val) % 10;
	disp_digit(num, 0); }
	if ((a % 10)==2){
		num = (val/10) % 10;
	disp_digit(num, 1); }
	if ((a % 10)==4){
		num = (val/100) % 10;
	disp_digit(num, 2); }
	if ((a % 10)==6){
		num = (val/1000) % 10;
	disp_digit(num, 3); }
}

void runMotor(char dir, uint8_t vel){
	if (dir==1){
		PORTB|=_BV(IN1);
		OCR0=255-vel;
	}
	else{
		PORTB &=~_BV(IN1);
		OCR0=vel;
	}
}