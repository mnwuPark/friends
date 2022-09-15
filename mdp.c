#include <mega128a.h> //ATmega128a ÇÁ·Î¼¼¼­ Çì´õÆÄÀÏ
#include <delay.h> //µô·¹ÀÌ Çì´õÆÄÀÏ
#include <lcd.h> //LCD Á¦¾î ¶óÀÌºê·¯¸® Çì´õÆÄÀÏ

/*
asm : ¾î¼Àºí¸® ¾ð¾î ±¸°£ ½ÃÀÛ
.equ __lcd_port 0x15; : ¾î¼Àºí¸® ¾ð¾î·Î ¶óÀÌºê·¯¸® ³» º¯¼ö º¯°æ
endasm : ¾î¼Àºí¸® ¾ð¾î ±¸°£ ³¡
*/ 
#asm
    .equ __lcd_port = 0x15;
#endasm

bit sw_toggle = 0; //bit Å©±â·Î µ¥ÀÌÅÍ Á¦¾î 0,1

void Init(); //ÀÌ´Ï¼È¶óÀÌÆÃ ÇÔ¼ö ¼±¾ð
void Control(); //ÄÁÆ®·Ñ ÇÔ¼ö ¼±¾ð

void main(void) //¸ÞÀÎ ÇÔ¼ö ½ÃÀÛ
{
    Init(); //ÀÌ´Ï¼È¶óÀÌÆÃ ÇÔ¼ö È£Ãâ
    while(1) //¹«ÇÑ ¹Ýº¹
    {
        Control(); //ÄÁÆ®·Ñ ÇÔ¼ö È£Ãâ      
    }
}

void Init() //ÀÌ´Ï¼È¶óÀÌÆÃ ÇÔ¼ö ½ÃÀÛ
{
    DDRA = 0xff; //PORTAÀÇ ¹æÇâ ¼³Á¤ (Ãâ·Â)
    DDRC = 0xff; //PORTCÀÇ ¹æÇâ ¼³Á¤ (Ãâ·Â)
    DDRE = 0x00; //PORTEÀÇ ¹æÇâ ¼³Á¤ (ÀÔ·Â)
    
    PORTA = 0x00; //PORTAÀÇ Ãâ·Â ¼³Á¤
    PORTC = 0xff; //PORTCÀÇ Ãâ·Â ¼³Á¤
    PORTE = 0x00; //PORTEÀÇ Ãâ·Â ¼³Á¤¤
    
    EIMSK = 0x80; //¿ÜºÎÀÎÅÍ·´Æ®¸¶½ºÅ©¼³Á¤ 0b10000000 INT7¸¸ È°¼ºÈ­
    EICRA = 0x00; //¿ÜºÎÀÎÅÍ·´Æ®·¹Áö½ºÅÍA 0b00000000 
    EICRB = 0x80; //¿ÜºÎÀÎÅÍ·´Æ®·¹Áö½ºÅÍB 0b10000000 ¿ÜºÎÀÎÅÍ·´Æ® Æ®¸®°Å ¼³Á¤ ÀÚ¼¼ÇÑ ¼³¸í https://wowon.tistory.com/7
    SREG = 0x80; //·¹Áö½ºÅÍ »óÅÂ Á¦¾î º¯¼ö ÀÎÅÍ·´Æ® »ç¿ë½Ã ¹«Á¶°Ç 0x80
    
    lcd_init(16); //LCD ±æÀÌ ¼³Á¤
    lcd_gotoxy(0,0); //LCDÀÇ 0.0 ¹øÂ° È­¼Ò·Î ÀÌµ¿             
    lcd_putsf(" IEMHS - MDP_01 "); //LCD Ç¥½Ã
    lcd_gotoxy(0,1); //LCDÀÇ 0.1 ¹øÂ° È­¼Ò·Î ÀÌµ¿
    lcd_putsf(" TEAM : CURTAIN "); //LCD Ç¥½Ã 
    delay_ms(1000); //1sec delay         
}

void Control()//ÄÁÆ®·Ñ ÇÔ¼ö ½ÃÀÛ
{
    if (sw_toggle == 0) //½ºÀ§Ä¡ Åä±Û È®ÀÎâ
    {                                 
        PORTA = 0x01; //LED Á¡µî
        lcd_gotoxy(0,0); //LCDÀÇ 0.0 ¹øÂ° È­¼Ò·Î ÀÌµ¿             
        lcd_putsf(" CURTAIN  STATE "); //LCD Ç¥½Ã
        lcd_gotoxy(0,1); //LCDÀÇ 0.1 ¹øÂ° È­¼Ò·Î ÀÌµ¿
        lcd_putsf("       OFF      "); //LCD Ç¥½Ã   
    }
    else
    {              
        PORTA = 0x02; //LED Á¡µî
        lcd_gotoxy(0,0); //LCDÀÇ 0.0 ¹øÂ° È­¼Ò·Î ÀÌµ¿             
        lcd_putsf(" CURTAIN  STATE "); //LCD Ç¥½Ã
        lcd_gotoxy(0,1); //LCDÀÇ 0.1 ¹øÂ° È­¼Ò·Î ÀÌµ¿
        lcd_putsf("       ON       "); //LCD Ç¥½Ã
    }
}

interrupt [EXT_INT7] void external_int7 (void) //¿ÜºÎ ÀÎÅÍ·´Æ® ÇÔ¼ö
{
    sw_toggle = !sw_toggle; //sw_toggle ¹ÝÀü
}