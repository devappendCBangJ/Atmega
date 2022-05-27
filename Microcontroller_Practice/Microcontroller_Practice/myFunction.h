#ifndef MYFUNCTION_H_
#define MYFUNCTION_H_

#define IN1 PB7
#define IN2 PB4
#define Use_IE4_Interrupt (EIMSK |= (1<<INT4))
#define IE4_Detect_Falling (EICRA|= (1<<ISC41))
#define IE4_Detect_Rising (EICRA= (1<<ISC41)|(1<<ISC40))
#define TC0_FAST_PWM (1<<WGM00| 1<<WGM01)
#define TC0_NONINVERT_PWM (1<<COM01)
#define TC0_INVERT_PWM (1<<COM01)
#define TC0_PRESCALE_1024 (1<<CS00|1<<CS01|1<<CS02)
#define TC0_PRESCALE_128 (1<<CS00 | 1<<CS02)
#define TC0_PRESCALE_64 (1<<CS02)
#define TC0_PRESCALE_32 (1<<CS00|1<<CS01)
#define TC0_PRESCALE_8 (1<<CS01 )
#define TC0_PRESCALE_1 (1<<CS00 )
#define TC2_PRESCALE_64 (1<<CS21|1<<CS20)
#define TC2_PRESCALE_256 (1<<CS22)
#define TC2_OV_INT_ENABALE (1<<TOIE2)
#define TC2_COMP_INT_ENABALE (1<<OCIE2)
unsigned char digit[10] = {0x77, 0x41, 0x3B, 0x5B, 0x4D, 0x5e,
0x7c, 0x43, 0x7f, 0x4f};

#endif /* MYFUNCTION_H_ */