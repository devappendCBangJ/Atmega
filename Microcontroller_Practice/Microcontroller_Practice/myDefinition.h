#ifndef MYDEFINITION_H_
#define MYDEFINITION_H_

// 초기 설정
void initial();

// 디스플레이
void disp_digit(unsigned char, unsigned char);
void disp_FND(unsigned int val, unsigned int a);

// DC모터
void runMotor(char dir, uint8_t vel);
unsigned char vel;

// 타이머
volatile unsigned int count=0, prevCount=0, curCount=0;
volatile unsigned char i;

// 모드
enum {STOP, CW,STOP2, CCW} mode;

#endif /* MYDEFINITION_H_ */