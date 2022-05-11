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
			- 저항 재료 : 금속선 or 탄소 피막 (칼라 코드 표시 for 직관성, 식별성) ♣♣
			  검 갈 빨 주 노 초 파 보 회 흰
			  0 1 2 3 4 5 6 7 8 9
			- 건전지 +에서 나오고, -로 들어가지 않으면 저항 무한대 ♣♣
		4] 커패시터 : 전하 모음 V = (1/C)*integral(qdt) ♣♣
		  [1] 특징
			- 용량 C : 전하 모을 수 있는 양
			- 유량 intgral(qdt) : 전압 형성
			- 단위 : 패러드(F)
		4] 컨덴서 : 커패시터를 제품화한 것 ♣♣
		  [1] 전해 커패시터 : 극성 있는 커패시터
			내전압 : V표시
			용량 : uF, nF, pF 등 표시
			오차
		  [2] 세라믹, 마일러, 탄탈 커패시터 : 극성 없는 커패시터
			- 세라믹 커패시터
			  내전압 : 표 참조
			  용량 : pF단위, 유효숫자 2자리, 지수 1자리 표시
			  오차 : 표 참조
		  [3] 커패시터 응용
			- LowPassFilter : RC(dV_0/dt)+V_0 = V_i
		5] 브레드 보드 : 납땜x 전자 부품 리드 꼽아서 쓸 수 있는 기판
		  [1] 구조
			- 좌우 파워라인
			- 5개 구멍 짝
		6] 점퍼선
		7] 발광 다이오드(LED = Light Emitting Diode)
		  [1] 특징
			- 다이오드 : 전기를 +(애노드)에서 -(캐소드)로 순방향으로만 흘리는 소자 ♣♣
			- 발광 다이오드 : 빛 발생 다이오드
			- 장점 : 높은 효율, 긴 수명으로 미래 조명으로 각광
			- 예시 : 지시등, 숫자 표시기, 전광판, TV 백라이트
			- 정격 전류 : 대부분 대략 10mA. 300옴 저항 직렬 필수 사용 ♣♣
			- 정격 전압 : 대부분 대략 2.0V. 300옴 저항 직렬 필수 사용 ♣♣
			  V_1 - V_2 = IR
			  >> 5.0 - 2.0 = (0.01)R
			  >> R = 300
			- 구조 : 긴 단자가 +, 짧은 리드가 -

		0] 물탱크 비유 ♣♣
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
	

● Interrupt & Polling ♣♣
	1) 개념 : 외부 장치 상태 변화 감지 in 프로그램
	2) 방법
		(1) Polling : 각 장치의 상태 체크 by 주기적
			1] 상태 감지 방법
				[1] 레벨 감지 : High/Low 감지
				[2] 에지 감지
					[[1]] 상승 에지 : 0 -> 1
					[[2]] 하강 에지 : 1 -> 0
			2] 상태 감지 코드
				[1] 레벨 감지
					while(!(장치값 == 지정값))						// 장치값과 지정값이 다르면 계속 탐색
				[2] 에지 감지
					1]] 상승 에지
						Do {
							prev = now;
						} while(!((now == 1) && (prev == 0)));		// prev = 0, now = 1이 아니면 계속 탐색
					2]] 하강 에지
						Do {
							prev = now;
						} while(!((now == 0) && (prev == 1)));		// prev = 1, now = 0이 아니면 계속 탐색
		(2) Interrupt : 시점을 알 수 없는 상태 변화 체크 by 하드웨어적
			1] Atmega128 Interrupt Pin ♣
				- 총 : 35개
				- 외부 장치 : 8개
				- 타이머 : 14개
				- 통신 : 8개
			2] Interrupt 처리 순서 ♣
				[0-1] 장치 활성화 by 레지스터
				[0-2] 개별 장치 인터럽트 설정 by 레지스터
				[0-3] 전역 인터럽트 활성화 by 레지스터
				[1] 이벤트 발생 : main 코드 중단, ISR 실행
				[2] ISR 실행 완료 : main 코드 이어서 실행
			3] Interrupt 활성화
				[1] 장치 활성화 by 레지스터
				[2] 개별 장치 인터럽트 설정 by 레지스터
				[3] 전역 인터럽트 활성화 by 레지스터
			4] 구현 by ISR(Interrupt Service Routine) ♣
				- Interrupt 발생 시 처리해야할 코드 정의하는 함수
				
				void ISR(인터럽트_벡터명){
					~~~
				}
			5] 외부 Interrupt Pin ♣
				- 8개 외부 Interrupt 사용 가능
				
				[1] I/O Pin 레지스터
					1]] INT0 ~ INT3 : PORTD0~3
					2]] INT4 ~ INT7 : PORTE4~7
				[2] 제어 레지스터
					1]] EICRA : 7 = ISC31, 6 = ISC30, 5 = ISC21, 4 = ISC20, 3 = ISC11, 2 = ISC10, 1 = ISC01, 0 = ISC00
					2]] EICRB : 7 = ISC71, 6 = ISC70, 5 = ISC61, 4 = ISC60, 3 = ISC51, 2 = ISC50, 1 = ISC41, 0 = ISC40
					
					- 00 : 레벨
					- 10 : 하강 에지
					- 11 : 상승 에지
					ex. ISC01 ISC00 : 하강 에지
				[3] 마스크 레지스터
					EIMSK : 7 = INT7, 6 = INT6, 5 = INT5, 4 = INT4, 3 = INT3, 2 = INT2, 1 = INT1, 0 = INT0
					- 0 ~ 7비트
					- 1 : 활성화
					- 0 : 비활성화
				[4] 전역 Interrupt 활성화
					1]] 함수 호출 way : sei();
					2]] 레지스터 way : SREG |= I<<1; 
				[5] Interrupt 벡터
					ISR(INTn_vect){
						~~~
					}
				
					- n : 0 ~ 7
					
● Timer & Counter ♣♣
	1) Timer / Counter 개수 ♣
		- 총 : 4개
		- 8비트 : 2개 T/C0, T/C2
			BOTTOM ~ TOP : 0 ~ 255
		- 16비트 : 2개 T/C1, T/C3
			BOTTOM ~ TOP : 0 ~ 65535
	2) 동작 방식 ♣♣
		(1) 동기식 : 내부클럭 -> pre-scaler -> 업카운트 -> [CVF : 타이머값 overflow] or [Comp : 타이머값 OCR(Output Compare Register) 도달] 
		(2) 비동기식 : 외부클럭 -> 업카운트 -> [CVF : 타이머값 overflow] or [Comp : 타이머값 OCR(Output Compare Register) 도달] 
	3) Timer / Counter 모드 ♣♣
		(1) 일반 모드
			- 주기 : 외부 펄스 입력 -> BOTTOM ~ MAX 주기 단순 업카운트
			- 리셋 : 중간에서 자동리셋x
		(2) 위상정정 PWM 모드
			- 단점 : 고속 PWM보다 느림
			- 장점 : 업다운 카운터 동작 -> 분해능 2배. 위상 유지 good
			- 변화 : 중간에서 TCNTn == OCRn되면 OCn 출력 변화
		(3) CTC(Clear Time on Compare Match) 모드
			- 주기 : OCR 이용하여 원하는 주기 interrupt 발생
			- 리셋 : 중간에서 TCNT0 == OCR0되면 0으로 clear. OCn 출력도 가능
		(4) 고속 PWM 모드
			- 고속 PWM 파형 발생
			- 주기 : BOTTOM ~ MAX로 count 진행
			- 변화 : 중간에서 TCNT0 == OCR0되면 OCn 출력 변화

	4) Counter Pin ♣♣
		(1) I/O Pin 레지스터
			OC0 = PORTB4
		(2) 제어 레지스터
			TCCR0 : 7 = FOC0, 6 = WGM00, 5 = COM01, 4 = COM00, 3 = WGM01, 2 = CS02, 1 = CS01, 0 = CS00
			1] pre-scale : 16MHz가 너무 빨라서 느리게 만듦
				CS02 CS01 CS00 : 001 = 1, 010 = 8, 011 = 32, 100 = 64, 101 = 128, 110 = 256, 111 = 1024
				
				[1] pre-scaler 사용x
					- 짧은 주기
					- 세부 control 가능 but 전자기파 증가
				[2] pre-scaler 사용o
					- 긴 주기
					- 세부 control 불가능 but 전자기파 감소
			2] 웨이브 제너레이션 모드
				WGM01 WGM00 : 00 = 일반 모드, 01 = 위상정정 PWM 모드, 10 = CTC 모드, 11 = 고속 PWM 모드
			3] 비교출력 모드
				COM01 COM00 : 00 = 사용 안함, 01 = 반전, 10 = 클리어, 11 = 셋
				
				[2] 위상정정 PWM
					COM01 COM00 : 00 = 사용 안함, 01 = 예약, 
									10 = 카운트 업 중에 TCNT0 == OCR0면 OC0핀 클리어 / 카운트 다운 중에 TCNT0 == OCR0면 CO0핀 셋
									11 = 카운트 업 중에 TCNT0 == OCR0면 OC0핀 셋 / 카운트 다운 중에 TCNT0 == OCR면 OC0핀 셋(이게 맞나??? 클리어 아닌가???)
				[4] 고속 PWM
					COM01 COM00 : 00 = 사용 안함, 01 = 예약, 
									10 = OC0핀을 BOTTOM에서 셋 / TCNT0 == OCR0면 OC0핀 클리어
									11 = OC0핀을 BOTTOM에서 클리어 / TCNT0 == OCR0면 OC0핀 셋
									
			ex. 64 pre-scale의 주기
				1/16M x 64 = 4 x 10^-6 = 4us
		(3) Interrupt 마스크 레지스터
			TIMSK : 7 = OCIE2, 6 = TOIE2, 5 = TOCIE1, 4 = OCIE1A, 3 = OCIE1B, 2 = TOIE1, 1 = OCIE0, 0 = TOIE0
			
			- TOIE0 : 카운트 Overflow Interrupt 활성화
			- OCIE0 : 출력 Compare Interrupt 활성화
		(4) 전역 Interrupt 활성화
			1] 함수 호출 way : sei();
			2] 레지스터 way : SREG |= I<<1;
		(5) Interrupt 벡터
			1] Overflow Vector
				ISR(TIMER0_OVF_vect){
					~~~
				}
			
			2] Compare Vector
				ISR(TIMER0_COMP_vect){
					~~~
				}
		// 뒷부분은 대면 강의시간에 안함. 뒷부분도 해야되나? ♣♣♣
	+a)
		1) 상태도
			(1) 개념
				- 시스템 상태 표현 by 유한개 상태 + 상태 천이
			(2) 구조
				- 강의자료 참조
			(3) 예시
				1] 닭의 일생
				2] 세탁기
				3] 유료 입장 게이트
				4] 엘레베이터
			

● Practice Basic
	1. LED
		1) 회로 ♣
			(1) I/O 포트가 Source
				MCU : Port에서 5V가 High 출력 >> LED >> 저항 >> Ext : GND
			(2) I/O 포트가 Sink
				Ext : 5V >> 저항 >> LED >> Port에서 GND가 Low 받음
		2) 레지스터 : MCU 입출력 기능 사용
			(1) AVR 레지스터 상수, 이름 정의 헤더파일 불러오기
				#include <avr/io.h>
			(2) 주요 GPIO 설정 레지스터
				1] DDRx : set the mode
					ex. DDRA = 0x01
					- x : ABCDEFG 포트 중 하나
					- 0 : 입력
					- 1 : 출력
					- 16진수로 제어
				2] PORTx : write state
					ex. PORTA = 0x01
					- x : ABCDEFG 포트 중 하나
					- 0 : low
					- 1 : high
					- 16진수로 제어
				3] PINx : read state
					- x : ABCDEFG 포트 중 하나
					- 0 : low
					- 1 : high
					- 16진수로 제어
	2. Switch
		1) 회로
			(1) 외부 회로 ♣
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
				- 설정 방법 ♣
					PullUp : 해당 핀을 input 설정 + high 출력
					PullDown : 해당 핀을 input 설정 + low 출력
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
			(1) 연결 구조 ♣
				1] default : 왼팔 - 왼다리 연결
				1] default : 오른팔 - 오른다리 연결
				2] switch 클릭 : 왼팔 - 오른다리 연결
				2] switch 클릭 : 오른팔 - 왼다리 연결
	3. 스피커
		1) 음 전달 원리
			- 전기 신호 >> 스피커 전자석이 진동판 울림 >> 공기를 따라 종파의 형태로 방출 >> 귀
			(1) 주파수
				- 개념 : 초당 발생된 정현파(sine) 주기 수
				- 단위 : Hz
				- 높은 주파수 : 고음
				- 낮은 주파수 : 저음
			(2) 주파수 구현
				1] DAC : 정현파(sine)를 아날로그적 구현
				2] 사각파 근사 : 정현파(sine)를 사각파로 디지털적 구현
					- ex. 주파수 : 1kHz >> 주기 : 1 / 주파수 = 1ms = 500us On + 500us Off
		2) 회로 구성
			(0) 스피커 : + / - 존재
			(1) 작은 스피커 : 직접 연결
			(2) 조금 큰 스피커 : 100Ω 저항 or 10uF 전해 커패시터 연결
				- 포트 보호를 위한 전류 제한
			(3) 큰 스피커 : 트랜지스터 연결
				1] 정논리 회로
					5V >> 스피커 >> npn TR >> GND
					포트 >> 1kΩ >>
				2] 부논리 회로
					5V >> pnp TR >> 스피커 >> GND
					포트 >> 1kΩ >>
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
					FND 데이터핀 >> 200Ω >> npn TR >> GND
					포트 >> 1kΩ >> npn TR
				2] 공통 애노드(양극 공통)
					5V >> npn TR >> 200Ω >> FND 데이터핀
					포트 >> 1kΩ >> npn TR
		3) 사용
			- FND의 datasheet 확인
			- FND에 캐소드, 애노드 타입 적혀있음
	+a)
		1) 정밀 지연함수 ♣
			(1) AVR CPU 클럭 속도 선언 : #define F_CPU 16000000UL // CPU 속도에 따라 지연시간 변화. unsigned long형
				- 지연시간 변화 by CPU Clock 속도
			(2) 라이브러리 불러오기 : #include <util/delay.h>
			(2) delay 함수 인수에 변수 사용 가능 : #define __DELAY_BACKWARD_COMPATIBLE__ ♣
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
	5. DC모터
		1) DC모터
			(1) 종류
				1] DC모터
					- 저렴
					- 수명 문제
					- 완구, 저가 기기
				2] RC서보
					- 제어 easy
					- 수명 문제
					- 무선조종장치, 취미로봇, 간이장치
				3] Step모터
					- 속도, 위치제어 easy
					- 긴 수명
					- Holding 토크 큼. 탈조 문제
					- 사무정보기기, 산업용 장비
				4] AC모터
					- 간단, 튼튼
					- 속도 제어 hard
				5] 서보모터
					- 고가
					- 초정밀
					- 산업용 장비, 로봇
			(2) 원리
				1] DC모터
					영구자석, 회전자의 코일에 의한 인력, 반발력 -> 회전
					회전자의 코일에 브러쉬, 정류자에 의해 서로 다른 극성 전기 공급
				3] step모터
					회전자 : 이가 나있는 금속휠 or 영구자석
					고정자 : 여러 조의 코일
					자기력선이 가장 잘 통과하기 위해 회전자 회전
				6] 모터 드라이버
					[1] H-bridge
						모터 속도, 회전방향 제어를 위해 4개 스위치로 구성
						스위치 대신 반도체인 트랜지스터 or MOSFET 4개로 구성
			(3) 실습용 모터드라이버
				1] H-bridge 칩 - LB1630
					- DC모터 1개 제어
					- H-bridge 1개 내장
					- 8핀 DIP 패키지
					- 2.5~6V 범위 모터 전원
					
		아직 덜함
						
				
*/