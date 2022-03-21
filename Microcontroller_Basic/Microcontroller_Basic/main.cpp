/*
1. 개발 환경 구축
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
		1] 프로젝트 생성 : 상단 File >> New Project >> C/C++ GCC C Executable project >> 파일명 입력 >> Device Selection >> MCU : ATmega128 선택
		3] 코드 작성
		4] 솔루션 빌드 : F7
		5] target 설정 : 상단 Tools >> Add Target >> Tool : STK500, Serial Port : 해당COM
		6] Device Programming : 상단 Tools >> Device Programming >> SKT500, ATmega128, ISP >> Apply 클릭
			>> Memories >> Flash 설정 >> Program 클릭

1. LED
	1) 회로
		(1) I/O 포트가 Source
			MCU : High >> Port >> LED >> Register >> Ext : GND
		(2) I/O 포트가 Sink
			Ext : 5V >> Regiester >> LED >> Port >> MCU : Low
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
		
*/