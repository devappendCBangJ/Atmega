/*
● 사이트
  AVR 제조사 사이트 : atmel.com
  128실습키트 제조사 사이트 : jcnet.co.kr
  아두이노 사이트 : arduino.cc
  회로도 그리기 프로그램 사이트 : fritzing.org/home/

● 학습 목표
  1. 마이크로컨트롤러 동작원리, 회로, 프로그래밍 학습
  2. ATMEGA128, Arduino 학습
  3. 팀프로젝트

● Basic
	1. 임베디드 시스템
		1) 정의 : 특정 목적 위해 하드웨어 + 소프트웨어 결합 in 임베디드 시스템
		2) 목적 : 인간의 뇌 창조(비유). 특정 목적을 위한 최적화 설계
			- 특화된 기능 수행
			- 독립된 시스템 or 보다 큰 시스템의 일부로 동작
			ex. 가전제품 : 휴대폰, 디지털 TV 등
			ex. 산업용, 큰 시스템 : 로봇, 군사 항공 우주 장비, 자동차, 계측기 등
		3) 특징
			(1) 소형화, 경량화, 저전력
				ex. 휴대폰, mp3, 가전제품
			(2) 저가, 대량생산
				ex. 휴대폰, mp3, 가전제품
			(3) 실시간(RealTime) 처리
				ex. 차량용, 산업용, 군사용
			(4) 신뢰성 in 열악한 환경
				ex. 차량용, 산업용, 군사용
			(5) 멀티미디어, 네트워크 지원 ♣♣♣
				ex. 세탑박스
		4) 구성
			(1) 임베디드 하드웨어
				1] 프로세서/컨트롤러
				2] 메모리
				3] I/O 장치
				4] 네트워크 장치
				5] 센서
				6] 작동기
			(2) 임베디드 소프트웨어
				- 하드웨어 <-> 시스템 소프트웨어 <-> 응용 소프트웨어 <-> 사용자
				1] 시스템 소프트웨어(System Software)
					[1] 정의 : 시스템 하드웨어 관리, 응용프로그램에게 효율적이고 안전한 interface 제공 ♣♣♣
					[2] 종류 ♣♣♣
						1]] 운영체제(OS) ♣♣♣
							[[1]] 특징 ♣♣♣
								1 큰 임베디드시스템 처리
									- 순차적 처리 < 동시 처리
								2 다양한 인터페이스
									ex. Wifi, Bluetooth, USB, SD Card
								3 멀티미디어 지원
									ex. GUI, Audio, Video, Camera, Game
								4 실시간 처리
									ex. Linux, Android, IOS, Windows CE, Windows Phone 등
									- Linux ♣♣♣
									장점
										기능성, 확장성 우수
										다양한 CPU Platform 지원 : PowerPC, ARM, MIPS...
										가격경쟁력 우수(로열티가 없기 때문)
										넓은 사용자 층 >> 오류수정 쉬움, 안정성 우수
										데스크탑 개발 환경과 동일
									단점
										개발환경 Text >> 개발 어려움
										Real-Time 지원x(범용 OS로 설계하기 때문)
										표준화 어려움(많은 개발자들이 독자적으로 개발하기 때문)
						2]] 미들웨어 ♣♣♣
						3]] 디바이스 드라이버 ♣♣♣
				2] 응용 소프트웨어(Application Software) = App
					[1] 정의 : 사용자 특정 용도에 맞는 기능 수행

	2. 프로세서
		(0) 개별 논리소자
			- 디지털 논리회로 구성 by 개별 논리소자
			ex. TTL, CMOS ♣♣♣
			1] 특징
				[0] fixed logic
				[1] 디지털 논리회로 수정 : 수정 hard
		(1) 마이크로 프로세서(MPU = MicroProcessor Unit)
			- 프로그래밍을 통한 수정
			1] 특징
				[0] programmable logic
				[1] 프로그램 수정 : 수정 easy
				[2] 유지보수 / 업그레이드 용이
				[3] 소형화 / 소비전력 작음
				[4] 회로 단순화 : 신뢰성 향상 ♣♣♣
				[5] 작은 CPU 역할 : 프로그래머가 작성한 프로그램(Firmware)대로 동작 ♣♣♣
				[6] 주변장치와 Interface : memory, I/O port, ADC, DAC, communications chip 등 주변장치와 interface by 외부장치와 정보교환 가능한 BUS ♣♣♣
			2] 구조
				// 강의자료 참조
		(2) 마이크로 컨트롤러(MCU = MicroController Unit) = One-chip = 마이콤 = SOC(System On Chip)
			1] 특징
				[0] 개념 : 단일 IC 집적 = MPU + Memory + GPIO + Timer/Counter + Communications
				[1] 하나의 작은 컴퓨터
				[2] 저전력 / 빠른 개발 
				[3] MPU에 비해 소형화 / 저렴한 시스템 구성 ♣♣♣
				[4] 활용 : 간단한 장치 or 제어기 구축 ♣♣♣
			2] 구조
				// 강의자료 참조
		(3) DSP = Digital Signal Processor ♣♣♣
			1] 특징
				[1] 개념 : 특수 MPU = MPU + 디지털 신호처리에 적합한 연산기능
				[2] 활용 : Audio, Video 등 처리

	3. ATmega128
		1) 특징 ♣♣♣
			(1) 8bit
			(1) RISC(Reduced Instruction Set Computer), 하버드 구조 ♣♣♣
				- 명령어 수를 줄임. 1clock = 1instruction
			(2) Oscillator : 16MHz ♣♣♣
			(3) CPU ♣♣♣
				1] 최대 클럭 : 16MHz(저전력 버전 ATmega128L : 8MHz)
					- 초당 1600만번
				2] 처리속도 : 16MIPS(Million Instructions Per Second)
				3] Interrupt/WDT
			(4) Memory
				1] 프로그램 메모리 : Flash 128KB
					- RAM : 전원 꺼지면 증발
				2] RAM : 4KB
				3] EEPROM : 4KB
					- ROM : 전원 꺼져도 저장
				4] SFC(Special Function Register) : 8bit 전용 레지스터 x 32개 ♣♣♣
					- 레지스터 : CPU 내에 존재
			(4) External Memory : 1개
				- 외부로 나가는 버스 이용해서 외부 memory 사용 가능
			(5) I/O
				1] GPIO(General Purpose Input/Output) : 53개 = 6(A, B, C, D, E, F) x 8개 + 1(G) x 5개
				2] 특수기능 IO : Timer/Counter, ADC, Communication 등 용도
				3] Interrupt IO : Interrupt 벡터 x 34개(외부 Interrupt x 8개 포함) ♣♣♣
				- 핀 기능 중첩 : GPIO & 특수기능 IO핀 기능이 중첩 for pin수 절약
			(6) 프로그래밍 ♣♣♣
				1] 16bit, 133종 명령어 set
					- 1개 명령어 당, 2byte 차지
					- ATmega Flash memory가 128KB니까 64KB의 명령어 수행 가능
				2] ISP(In System Programming) : 시스템 동작 중에 프로그래밍 가능
				3] JTAG(Joint Test Action Group, IEEE1449.1) port 지원
			(7) 동작전원 : 4.5V - 5.5V(저전력 버전 ATmega128L : 2.7V - 5.5V)
			(7) Reset / Sleep
		2) 패키지 ♣♣♣
			(1) 종류
				1] TQFP(Thin profile Quad Flat Package)
				2] MLF(Micro Lead Frame) : compact화를 위해 핀이 안쪽으로 들어가있음
			(2) 칩의 Package 호칭
				1] DIP(Dual Inline Package)
				2] SOP(Small Outline Package)
				3] SOIC(Small Outline Intergrated Circuit)
				4] QFP(Quad Flat Package)
				5] QFN(Quad Flat Non-Leaded Package)
				6] MLF(Micro Lead Frame)
				7] BGA(Ball Grid Array)
			(3) 칩의 실장 방법
				1] DIP : 핀 뾰족 - 수작업
				2] SMD : 핀 넓적 - 현대식 자동화
		3) 주요 기능
			(1) ADC(Analog to Digital Converter) : 8채널, 10bit ♣♣♣
			(1) Analog Comparator : 외부 아날로그 전압 비교기 ♣♣♣
			(2) Timer/Counter
				1] Timer/Counter : 4개(8bit 2개, 16bit 2개) ♣♣♣
				2] PWM(Pulse Width Modulation) : 8개(8bit 2개, 16bit 6개) ♣♣♣
				3] Real Time Counter by 별도 Oscillator
				4] Programmable Watchdog Timer = Programmable WDT
			
				1] ADC : 센서 Analog 전압 -> n비트 Digital 근사화
					- 10bit, 5V AVR : 0 ~ 5V Analog -> 0 ~ 1023 Digital 근사화
				1] Timer : 시간 간격 일정한 pulse count ♣♣♣
					- Overflow : 설정한 시간에 다다름
				1] Counter : 이벤트 횟수 count ♣♣♣
					ex. 인코더 속도 측정, 유량계 등
				2] PWM : On Off Duty비 조정 -> 아날로그 근사화 to 디지털 출력
					- On duty : 일정 주기 내에서 켜지는 기간
					ex. 조명제어, 모터제어 등
				3] WDT : MCU의 비정상동작 방지
					- Watchdog Timer : 시한폭탄 역할. clock count하다가 timeout 발생시 MCU reset 시킴
					- MCU : 시한폭탄 reset 역할. 주기적으로 watchdog timer reset 시켜줌
			(3) Communications
				1] Serial UART : 2개
				2] TWI(Two Wire Interface) = I2C(Inter Intergrated Circuit) : 1개
				3] SPI Serial(Serial Peripheral Interface) : 1개
			
				1] Serial UART : 정보교환 with 다른장치(MCU, PC) by MCU
					- 산업용 UART : RS-232이기 때문에 신호 변환 필요(0~5V -> -10V~10V) ♣♣♣
				2] TWI = I2C : 주변 IC 제어 by MCU ♣♣♣
					- Master/Slave 방식
					- 선 2개 : SDA/SCL
				3] SPI : 주변 IC 제어 by MCU ♣♣♣
					- Master/Slave 방식
					- 선 4개 : SCLK/MOSI/SS/MISO
						SCLK
							의미 : Serial Clock / 방향 : from master
						MOSI
							의미 : Master Output, Slave Input / 방향 : from master
						SS
							의미 : Slave Selection / 방향 : from master
						MISO
							의미 : Master Input, Slave Output / 방향 : from slave

		3) 실습용 보드 : JMOD-128 ♣♣♣
			(1) CPU : ATmega128
			(2) Clock : 16MHz
			(3) I/O
			(4) USB 포트
				1] 프로그램 다운로더(ISP)
				2] 전원 공급
				3] RS-232 통신
			(5) reset 스위치
			(6) 전원 모드 : mbed와 유사한 방식
				- 왼쪽 + 가운데 : 외부 전원
				- 가운데 + 오른쪽 : USB 전원
			(7) 프로그램/통신 모드
				- 왼쪽 : 프로그램 모드
				- 오른쪽 : 통신 모드
			

● Basic++
	1. 프로그래밍 기초
	  1) C언어 실행환경
		(1) 프로그래밍 과정
		  1] 코딩 : 소스 코드 작성(*.c, *.h)
		  2] 컴파일 : Compiler 이용, 기계어로 Object 파일 생성(*.o) ♣♣
		  3] 링크 : 관련 파일 하나로 결합, 실행 파일 생성(*.exe, *.bin, *.hex ♣♣
		  - 각 메이커의 MCU마다 기계어 다름 >> 컴파일러 다름
		(2) 통합 개발환경
		  1] Ateml Studio 7.X ♣♣
			- Editor
			- Assembler
			- Debugger
			- Linker
			- WINAVR
			- Loader
	  2) 데이터 표현 ★★ 시험 출제
		(1) 진수 : 어떤 수에 도달하면 자리를 올리는 수 표기법
		  1] 2진수
			- 디지털 하드웨어 상태 0, 1 표시 편리
		  2] 10진수
		  3] 16진수
			- 2진수 표시 편리
        
		  1] 2진수 -> 10진수 : 2가중치 후 더하기 (2^n 가중치 곱하기 >> 더하기)
		  1] 2진수 -> 16진수 : 4자리씩 묶어 계산
		  2] 10진수 -> 2진수 : 2로 나누기 반복 (2로 나누기 반복 >> 나머지와 몫 역순으로 나열)
		  2] 10진수 -> 16진수 : 16으로 나누기 반복 (16으로 나누기 반복 >> 나머지와 몫 역순으로 나열)
		  3] 16진수 -> 10진수 : 16가중치 후 더하기 (16^n 가중치 곱하기 >> 더하기)
		  3] 16진수 -> 2진수 : 4자리씩 묶어 계산
	  3) 자료형 ♣♣
		(1) 정수
		  1] char : 1byte(-128~127)
		  2] int : 2byte
		  3] short : 2byte
		  4] long : 4byte
		  5] long long : 8byte(-21억~21억)
		(2) 실수
		  1] float : 4byte
		  2] double : 4byte
		(3) 플랫폼간 자료형 보존
		  1] int8_t : char
		  2] uint16_t : unsigned char
		  3] uint32_t : unsigned long
		  4] int64_t : long long
		(4) 자료형 선언 - 지시어
		  1] volatile : 컴파일 시 자동 최적화x
			- 개발자가 의도적으로 만든 비효율적 코드가 컴파일에 의해 왜곡되지 않도록 최적화 제외
			volatile int count = 0;
		  2] static : 함수 종료되어도 변수값 유지
			static float velocity;
		  3] const : 값 변경 불가 변수 선언
			const int size_of_data = 121;
	  4) 연산자 (C언어 참조)
		(1) 주요 연산자
		  1] 산술 연산자 : + - * / %
		  2] 증감 연산자 : ++ --
		  3] 관계 연산자 : < > == != <= >=
			a < b
			a > b
			a <= b
			a >= b
			a == b
			a != b
		  4] 조건 연산자 : ?:
		  5] 논리 연산자 : && || !
		  6] 비트 단위 연산자 : << >> & | ^ ~
			a << b : 좌측 시프트
			  - 2^b 곱하기 = 왼쪽으로 b비트 밀기 
			a >> b : 우측 시프트
			  - 2^b 나누기 = 오른쪽으로 b비트 밀기
			a & b : 논리곱
			a | b : 논리합
			a ^ b : 배타적 논리합
			  - 다르면 1, 같으면 0
			~a : 반전
		  7] 대입 연산자
		  8] 복합 연산자 : = += -= *= /= %= &= |= ^= <<= >>=
			a += b
			a -= b
			a *= b
			a /= b
			a %= b
			a <<= b
			a >>= b
	  5) 비트단위 연산 응용 ♣♣ ★★ 시험 출제
		(1) 선택적 세트 : 일부 비트 1로 만들기
		  1] 원본 보존 : 0 마스크로 or
		  2] 1로 변환 : 1 마스크로 or
		(2) 선택적 클리어 : 일부 비트 0으로 만들기
		  1] 원본 보존 : 1 마스크로 and
		  2] 0으로 변환 : 0 마스크로 and
		(3) 선택적 반전 : 일부 비트 반전
		  1] 원본 보존 : 0 마스크로 xor
		  2] 반전 : 1 마스크로 xor
		(4) 선택적 교체 : 일부 비트 원하는 비트로 교체
		  1] 변경 희망 비트 : 0으로 선택적 클리어
		  2] 변경 희망 비트 : 1로 선택적 세트
	  6) 제어문 (C언어 참조)

	2. 전기 기초
	  1) 옴의 법칙 : V = IR, (V_1 - V_2) = IR
		1] 전류 : 단위 시간당 흐르는 전하량
		2] 전압 : 전류가 흐르는 원동력
		3] 저항 : 전기 흐름 방해
		  [1] 특징
			- 저항 크기 : 가늘고 길다 > 굵고 짧다
			- 저항 원리 : 전자 >> 도체 지나감 >> 자유 전자의 방해 >> 도체 통과하는 전자 수 감소 >> 열 발생 >> 에너지 손실
			- 저항 재료 : 금속선 or 탄소 피막 (칼라 코드 표시 for 직관성, 식별성)
			  검 갈 빨 주 노 초 파 보 회 흰
			  0 1 2 3 4 5 6 7 8 9
			- 건전지 +에서 나오고, -로 들어가지 않으면 저항 무한대
		4] 커패시터 : 전하 모음 V = (1/C)*integral(qdt)
		  [1] 특징
			- 용량 C : 전하 모을 수 있는 양
			- 유량 intgral(qdt) : 전압 형성
			- 단위 : 패러드(F)
		4] 컨덴서 : 커패시터를 제품화한 것
		  [1] 전해 커패시터 : 극성 있는 커패시터
			내전압 : V표시
			용량 : uF, nF, pF 등 표시
			오차
		  [2] 세라믹, 마일러, 탄탈 커패시터 : 극성 없는 커패시터
			- 세라믹 커패시터
			  내전압 : 표 참조
			  용량 : pF단위, 유효숫자 2자리, 지수 1자리 표시
			  오차 : 표 참조
		  2 커패시터 응용
			- LowPassFilter : RC(dV_0/dt)+V_0 = V_i
		5] 브레드 보드 : 납땜x 전자 부품 리드 꼽아서 쓸 수 있는 기판
		  [1] 구조
			- 좌우 파워라인
			- 5개 구멍 짝
		6] 점퍼선
		7] 발광 다이오드(LED = Light Emitting Diode)
		  [1] 특징
			- 다이오드 : 전기를 +(애노드)에서 -(캐소드)로 순방향으로만 흘리는 소자
			- 발광 다이오드 : 빛 발생 다이오드
			- 장점 : 높은 효율, 긴 수명으로 미래 조명으로 각광
			- 예시 : 지시등, 숫자 표시기, 전광판, TV 백라이트
			- 정격 전류 : 대부분 대략 10mA. 300옴 저항 직렬 필수 사용
			- 정격 전압 : 대부분 대략 2.0V. 300옴 저항 직렬 필수 사용
			  V_1 - V_2 = IR
			  >> 5.0 - 2.0 = (0.01)R
			  >> R = 300
			- 구조 : 긴 단자가 +, 짧은 리드가 -

		0] 물탱크 비유
		  - 전위 : 수위 in 물탱크
		  - 전압 : 파이프 출구 물 압력 in 물탱크
		  - 전류 : 단위 시간당 분출되는 물의 양 in 물탱크
		  - 커패시터 : 단면적 in 물탱크
		  - integral(qdt) : 물 부피 in 물탱크
      

	3. 개발 환경 구축
		1) Atmel Studio : Atmel사 통합 개발 환경(GNU tool chain 포함)
			(1) 특징
				- 코드작성
				- 컴파일
				- 다운로드
			
		2) USB to Serial Driver : SILABS사 USB 이용하여 target 보드와 접속
			(1) 특징
				- USB-to-Serial 변환 칩(CP2102)용 USB 드라이버
	
		1) USB to Serial Driver 설치 : http://silabs.com >> CP210x VCP Windows 검색 >> 다운
		2) 디바이스 연결 확인 : 장치 관리자 >> COM 포트
		3) Ateml Studio 사용
			1] 프로젝트 생성 : 상단 File >> New Project >> C/C++ GCC C Executable project >> 파일명 입력 >> Device Selection >> MCU : ATmega128A 선택
			3] 코드 작성
			4] 솔루션 빌드 : F7
			5] target 설정 : 상단 Tools >> Add Target >> Tool : STK500, Serial Port : 해당COM
			6] Device Programming : 상단 Tools >> Device Programming >> SKT500, ATmega128A, ISP >> Apply 클릭
				>> Memories >> Flash 설정 >> Program 클릭

● Practice Basic
	1. LED
		1) 회로
			(1) I/O 포트가 Source
				MCU : High >> Port >> LED >> 저항 >> Ext : GND
			(2) I/O 포트가 Sink
				Ext : 5V >> 저항 >> LED >> Port >> MCU : Low
		2) 레지스터 : MCU 입출력 기능 사용
			(1) AVR 레지스터 상수, 이름 정의 헤더파일 불러오기
				#include <avr/io.h>
			(2) 주요 GPIO 설정 레지스터
				- x : ABCDEFG 포트 중 하나
				- 16진수로 제어
				1] DDRx : set the mode
					ex. DDRA = 0x01
					- 0 : 입력
					- 1 : 출력
				2] PORTx : write state
					ex. PORTA = 0x01
				3] PINx : read state

	2. Switch
		1) 회로
			(1) 외부 회로
				1] PullUp
					- default : 5V >> 저항 >> AVR pin
					- 연결 시 : 5V >> 저항 >> AVR pin
										  >> switch >> GND
					- 기본 입력 : 1
				2] PullDown
					- default : AVR pin >> 저항 >> GND
					- 연결 시 : 5V >> switch >> AVR pin
											 >> 저항 >> GND
					- 기본 입력 : 0
			(2) AVR 내부 회로
				- AVR칩 내부 제공 PullUp/PullDown 회로
				- 설정 방법 ♣♣♣
					해당 핀을 input으로 지정
					해당 핀이 input이지만 high를 출력
					low로 하면 풀다운이 됨
				1] PullUp
					- default : 5V >> 저항 >> AVR pin
					- 연결 시 : 5V >> 저항 >> AVR pin
										  >> switch >> GND
					- 기본 입력 : 1
				2] PullDown
					- default : AVR pin >> 저항 >> GND
					- 연결 시 : 5V >> switch >> AVR pin
											 >> 저항 >> GND
					- 기본 입력 : 0
		2) 구조
			(1) 연결 구조 ♣♣♣
				1] default : 왼팔 - 왼다리 연결
				1] default : 오른팔 - 오른다리 연결
				2] switch 클릭 : 왼팔 - 오른다리 연결
				2] switch 클릭 : 오른팔 - 왼다리 연결
	3. 스피커
		1) 음 전달 원리
			- 전기 신호 -> 스피커 전자석이 진동판 울림 -> 공기를 따라 종파의 형태로 방출 -> 귀
			(1) 주파수
				- 개념 : 초당 발생된 정현파(sine) 주기 수
				- 단위 : Hz
				- 높은 주파수 : 고음
				- 낮은 주파수 : 저음
			(2) 주파수 구현
				1] DAC : 정현파(sine)를 아날로그적 구현
				2] 사각파 근사 : 정현파(sine)를 사각파로 디지털적 구현
					- ex. 주파수 : 1kHz -> 주기 : 1 / 주파수 = 1ms = 500us On + 500us Off
		2) 회로 구성
			(0) 스피커 : + / - 존재
			(1) 작은 스피커 : 직접 연결
			(2) 조금 큰 스피커 : 100Ω 저항 or 10uF 전해 커패시터 연결
				- 포트 보호를 위한 전류 제한
			(3) 큰 스피커 : 트랜지스터 연결
				1] 정논리 회로
					5V -> 스피커 -> npn TR -> GND
					포트 -> 1kΩ ->
				2] 부논리 회로
					5V -> pnp TR -> 스피커 -> GND
					포트 -> 1kΩ ->
		3) 사용
			- 음계의 주파수 확인
	4. FND 디스플레이(7segment)
		1) 특징
			(1) 타입
				1] 공통 캐소드(음극 공통)
				2] 공통 애노드(양극 공통)
			(2) PIN : LED 8핀, CO 2핀
		2) 회로 구성
			(1) 각각 200~330Ω 저항 연결
		3) 사용
			- FND의 datasheet 확인
			- FND에 캐소드, 애노드 타입 적혀있음
	5. 4자리 FND 디스플레이
		1) 특징
			(1) 타입
				1] 공통 캐소드(음극 공통)
					- 제품명 : YDSR-4036KM
				2] 공통 애노드(양극 공통)
					- 제품명 : YDSR-4036AM
			(2) PIN : 데이터 8핀, 자리수 선택 4핀
				- 데이터를 동시에 쓸 수 없음. 잔상효과로 인해 동시에 쓰는 것처럼 보임
		2) 회로 구성
			(1) 자리수선택 4핀 : NPN 트랜지스터 연결
				1] 공통 캐소드(음극 공통)
					FND 데이터핀 -> 200Ω -> npn TR -> GND
					포트 -> 1kΩ -> npn TR
				2] 공통 애노드(양극 공통)
					5V -> npn TR -> 200Ω -> FND 데이터핀
					포트 -> 1kΩ -> npn TR
		3) 사용
			- FND의 datasheet 확인
			- FND에 캐소드, 애노드 타입 적혀있음
	+a)
		1) 정밀 지연함수 ♣♣♣
			(1) AVR CPU 클럭 속도 선언 : #define F_CPU 16000000UL
				- 지연시간 변화 by CPU Clock 속도
			(2) 라이브러리 불러오기 : #include <util/delay.h>
			(2) delay 함수 인수에 변수 사용 가능 : #define __DELAY_BACKWARD_COMPATIBLE__
			(3) 지연
				1] ms 지연 : _delay_ms(ms) // void
					- ms : 밀리초 // double
				2] us 지연 : _delay_us(us) // void
					- us : 마이크로초 // double
		2) 핀 마스크 생성
			(1) 마스크 생성
				#define 변수명 1<<x
					- x : 원하는 핀 번째수
				#define 변수명 1<<PAx
					- PA : 가독성 향상을 위해 지원(PA, PB, PC, PD, PE, PF 뭘하든 똑같은 의미)
					- x : 원하는 핀 번째수
				#define 변수명 1<<PORTAx
					- PORTA : 가독성 향상을 위해 지원(PORTA, PORTB, PORTC, PORTD, PORTE, PORTF 뭘하든 똑같은 의미)
					- x : 원하는 핀 번째수
				
			(2) 마스크 이용
		3) 다양한 정수형 선언 : #include <stdin.h>
			- uint32_t 등 사용 가능
*/