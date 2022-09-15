#include <mega128a.h> //ATmega128a ���μ��� �������
#include <delay.h> //������ �������
#include <lcd.h> //LCD ���� ���̺귯�� �������

/*
asm : ����� ��� ���� ����
.equ __lcd_port 0x15; : ����� ���� ���̺귯�� �� ���� ����
endasm : ����� ��� ���� ��
*/ 
#asm
    .equ __lcd_port = 0x15;
#endasm

bit sw_toggle = 0; //bit ũ��� ������ ���� 0,1

void Init(); //�̴ϼȶ����� �Լ� ����
void Control(); //��Ʈ�� �Լ� ����

void main(void) //���� �Լ� ����
{
    Init(); //�̴ϼȶ����� �Լ� ȣ��
    while(1) //���� �ݺ�
    {
        Control(); //��Ʈ�� �Լ� ȣ��      
    }
}

void Init() //�̴ϼȶ����� �Լ� ����
{
    DDRA = 0xff; //PORTA�� ���� ���� (���)
    DDRC = 0xff; //PORTC�� ���� ���� (���)
    DDRE = 0x00; //PORTE�� ���� ���� (�Է�)
    
    PORTA = 0x00; //PORTA�� ��� ����
    PORTC = 0xff; //PORTC�� ��� ����
    PORTE = 0x00; //PORTE�� ��� �����
    
    EIMSK = 0x80; //�ܺ����ͷ�Ʈ����ũ���� 0b10000000 INT7�� Ȱ��ȭ
    EICRA = 0x00; //�ܺ����ͷ�Ʈ��������A 0b00000000 
    EICRB = 0x80; //�ܺ����ͷ�Ʈ��������B 0b10000000 �ܺ����ͷ�Ʈ Ʈ���� ���� �ڼ��� ���� https://wowon.tistory.com/7
    SREG = 0x80; //�������� ���� ���� ���� ���ͷ�Ʈ ���� ������ 0x80
    
    lcd_init(16); //LCD ���� ����
    lcd_gotoxy(0,0); //LCD�� 0.0 ��° ȭ�ҷ� �̵�             
    lcd_putsf(" IEMHS - MDP_01 "); //LCD ǥ��
    lcd_gotoxy(0,1); //LCD�� 0.1 ��° ȭ�ҷ� �̵�
    lcd_putsf(" TEAM : CURTAIN "); //LCD ǥ�� 
    delay_ms(1000); //1sec delay         
}

void Control()//��Ʈ�� �Լ� ����
{
    if (sw_toggle == 0) //����ġ ��� Ȯ���
    {                                 
        PORTA = 0x01; //LED ����
        lcd_gotoxy(0,0); //LCD�� 0.0 ��° ȭ�ҷ� �̵�             
        lcd_putsf(" CURTAIN  STATE "); //LCD ǥ��
        lcd_gotoxy(0,1); //LCD�� 0.1 ��° ȭ�ҷ� �̵�
        lcd_putsf("       OFF      "); //LCD ǥ��   
    }
    else
    {              
        PORTA = 0x02; //LED ����
        lcd_gotoxy(0,0); //LCD�� 0.0 ��° ȭ�ҷ� �̵�             
        lcd_putsf(" CURTAIN  STATE "); //LCD ǥ��
        lcd_gotoxy(0,1); //LCD�� 0.1 ��° ȭ�ҷ� �̵�
        lcd_putsf("       ON       "); //LCD ǥ��
    }
}

interrupt [EXT_INT7] void external_int7 (void) //�ܺ� ���ͷ�Ʈ �Լ�
{
    sw_toggle = !sw_toggle; //sw_toggle ����
}