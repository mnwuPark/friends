#include <stdio.h>
#include <conio.h>
#include <windows.h>

// HDMI SWITCH B.1.0

/*
����
1. ����� ���� ���
2. ���� ä���� ������ ����� ������ ����(���� ū ������ ���� ��ȣ)�� �翬��, �ƹ� ������ ������ 1������
3. �Է��� 8�� ����� 1��
*/

void Init(); //�ʱ⼳��
void Starting_Logo_Disp(); //����ȭ��
void Disp_State(unsigned char Connect_nums); //ȭ�� ���
unsigned char Connect_State(); //���� �ν�

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
    printf("����������������������������������������������������������������������\n");
    printf("��                                                                   ��\n");
    printf("�� ��   �� ����   ��   �� ������        ����  �� �� �� ������ ������  ����  ��   �� ��\n");
    printf("�� ��   �� ��  ��  ��� ���   ��         ��   �� �� �� ��   ��     ��   ��   �� ��   �� ��\n");
    printf("�� ��   �� ��   �� �� �� ��   ��         ��     �� �� ��   ��     ��   ��     ��   �� ��\n");
    printf("�� ������ ��   �� ��   ��   ��          ����  �� �� ��   ��     ��   ��     ������ ��\n");
    printf("�� ��   �� ��   �� ��   ��   ��             �� �� �� ��   ��     ��   ��     ��   �� ��\n");
    printf("�� ��   �� ��  ��  ��   ��   ��         ��   �� �� �� ��   ��     ��   ��   �� ��   �� ��\n");
    printf("�� ��   �� ����   ��   �� ������        ����   �� ��  ������   ��    ����  ��   �� ��\n");
    printf("��                                                                   ��\n");
    printf("�� Press Enter...                                        Ver : B.1.0 ��\n");
    printf("����������������������������������������������������������������������\n");
    while (Press_Enter == 0) {
        char c = _getch();
        if (c == 13) {
            break;
        }
    }
}