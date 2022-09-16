#include <stdio.h>
#include <conio.h>
#include <windows.h>

// HDMI SWITCH B.1.0

/*
조건
1. 연결된 순서 기억
2. 현재 채널의 연결이 끊기면 마지막 연결(가장 큰 순서의 연결 번호)로 재연결, 아무 연결이 없으면 1번으로
3. 입력은 8개 출력은 1개
*/

void Init(); //초기설정
void Starting_Logo_Disp(); //시작화면
void Disp_State(unsigned char Connect_nums); //화면 출력
unsigned char Connect_State(); //연결 인식

//unsigned char nums [8]; 

int main(void) {
    Init();
    Starting_Logo_Disp();
    system("cls");
    while (1) {
        //Disp_State(Connect_State());
    }
    return 0;
}

void Init() {

}

void Disp_State(unsigned char Connect_nums) {

}

unsigned char Connect_State() {
     
    return 0x00;
}

void Starting_Logo_Disp() {
    int Press_Enter = 0;
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("■                                                                   ■\n");
    printf("■ ■   ■ ■■■   ■   ■ ■■■■■        ■■■  ■ ■ ■ ■■■■■ ■■■■■  ■■■  ■   ■ ■\n");
    printf("■ ■   ■ ■  ■  ■■ ■■   ■         ■   ■ ■ ■ ■   ■     ■   ■   ■ ■   ■ ■\n");
    printf("■ ■   ■ ■   ■ ■ ■ ■   ■         ■     ■ ■ ■   ■     ■   ■     ■   ■ ■\n");
    printf("■ ■■■■■ ■   ■ ■   ■   ■          ■■■  ■ ■ ■   ■     ■   ■     ■■■■■ ■\n");
    printf("■ ■   ■ ■   ■ ■   ■   ■             ■ ■ ■ ■   ■     ■   ■     ■   ■ ■\n");
    printf("■ ■   ■ ■  ■  ■   ■   ■         ■   ■ ■ ■ ■   ■     ■   ■   ■ ■   ■ ■\n");
    printf("■ ■   ■ ■■■   ■   ■ ■■■■■        ■■■   ■ ■  ■■■■■   ■    ■■■  ■   ■ ■\n");
    printf("■                                                                   ■\n");
    printf("■ Press Enter...                                        Ver : B.1.0 ■\n");
    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    while (Press_Enter == 0) {
        char c = _getch();
        if (c == 13) {
            break;
        }
    }
}