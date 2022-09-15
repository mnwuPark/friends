#include <mega128a.h> //ATmega128a 프로세서 헤더파일
#include <delay.h> //딜레이 헤더파일
#include <lcd.h> //LCD 제어 라이브러리 헤더파일

/*
asm : 어셈블리 언어 구간 시작
.equ __lcd_port 0x15; : 어셈블리 언어로 라이브러리 내 변수 변경
endasm : 어셈블리 언어 구간 끝
*/ 
#asm
    .equ __lcd_port = 0x15;
#endasm

bit sw_toggle = 0; //bit 크기로 데이터 제어 0,1

void Init(); //이니셜라이팅 함수 선언
void Control(); //컨트롤 함수 선언

void main(void) //메인 함수 시작
{
    Init(); //이니셜라이팅 함수 호출
    while(1) //무한 반복
    {
        Control(); //컨트롤 함수 호출      
    }
}

void Init() //이니셜라이팅 함수 시작
{
    DDRA = 0xff; //PORTA의 방향 설정 (출력)
    DDRC = 0xff; //PORTC의 방향 설정 (출력)
    DDRE = 0x00; //PORTE의 방향 설정 (입력)
    
    PORTA = 0x00; //PORTA의 출력 설정
    PORTC = 0xff; //PORTC의 출력 설정
    PORTE = 0x00; //PORTE의 출력 설정
    
    EIMSK = 0x80; //외부인터럽트마스크설정 0b10000000 INT7만 활성화
    EICRA = 0x00; //외부인터럽트레지스터A 0b00000000 
    EICRB = 0x80; //외부인터럽트레지스터B 0b10000000 외부인터럽트 트리거 설정 자세한 설명 https://wowon.tistory.com/7
    SREG = 0x80; //레지스터 상태 제어 변수 인터럽트 사용시 무조건 0x80
    
    lcd_init(16); //LCD 길이 설정
    lcd_gotoxy(0,0); //LCD의 0.0 번째 화소로 이동             
    lcd_putsf(" IEMHS - MDP_01 "); //LCD 표시
    lcd_gotoxy(0,1); //LCD의 0.1 번째 화소로 이동
    lcd_putsf(" TEAM : CURTAIN "); //LCD 표시 
    delay_ms(1000); //1sec delay         
}

void Control()//컨트롤 함수 시작
{
    if (sw_toggle == 0) //스위치 토글 확인
    {                                 
        PORTA = 0x01; //LED 점등
        lcd_gotoxy(0,0); //LCD의 0.0 번째 화소로 이동             
        lcd_putsf(" CURTAIN  STATE "); //LCD 표시
        lcd_gotoxy(0,1); //LCD의 0.1 번째 화소로 이동
        lcd_putsf("       OFF      "); //LCD 표시   
    }
    else
    {              
        PORTA = 0x02; //LED 점등
        lcd_gotoxy(0,0); //LCD의 0.0 번째 화소로 이동             
        lcd_putsf(" CURTAIN  STATE "); //LCD 표시
        lcd_gotoxy(0,1); //LCD의 0.1 번째 화소로 이동
        lcd_putsf("       ON       "); //LCD 표시
    }
}

interrupt [EXT_INT7] void external_int7 (void) //외부 인터럽트 함수
{
    sw_toggle = !sw_toggle; //sw_toggle 반전
}
