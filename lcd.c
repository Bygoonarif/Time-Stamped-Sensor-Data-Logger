#include<lpc21xx.h>
#include"lcd.h"
#include"defines.h"
#include"types.h"
#include"delay.h"
#define RW 16
#define RS 18
#define EN 17
void InitLCD(void)
{
        IODIR0=(0XFF<<8)|(1<<RS)|(1<<RW)|(1<<EN);

        delay_ms(20);
        CmdLCD(0x30);
        delay_ms(10);
        CmdLCD(0X30);
        delay_ms(1);
        CmdLCD(0X30);
        delay_ms(1);
        CmdLCD(0X38);
        CmdLCD(0X10);
        CmdLCD(0X01);
        CmdLCD(0x06);
        CmdLCD(0X0F);
}
void CmdLCD(u8 cmd)
{
        IOCLR0=1<<RS;
        DisplayLCD(cmd);
}
void CharLCD(u8 data)
{
        IOSET0=1<<RS;
        DisplayLCD(data);
}
void DisplayLCD(u8 data)
{
        IOCLR0=1<<RW;
        WRITEBYTE(IOPIN0,8,data);
        IOSET0=1<<EN;
        delay_ms(1);
        IOCLR0=1<<EN;
        delay_ms(1);
}
void IntLCD(s32 n)
{
        u8 ARR[10] ;
        s8 i=0;
                if(n==0)
                {
                        CharLCD('0');
                        //i++;
                }
        else
        {
        if(n<0)
        {
                n=-n;
                CharLCD('-');
        }

        for(;n;n/=10)
        {
                ARR[i++]=n%10+48;
        }
        for(--i;i>=0;i--)
        {
                CharLCD(ARR[i]) ;
        }
        }
}
void StrLCD(u8 *ptr)
{
        while(*ptr!='\0')

                CharLCD(*ptr++);
}
 void FloatLCD(f32 fnum)
{
        u32 num,i;
        if(fnum<0)
        {
                CharLCD('-');
                fnum=-fnum;
        }
        num=fnum;
        IntLCD(num);
        CharLCD('.');
        for(i=0;i<6;i++)
        {
                fnum=(fnum-num)*10;
                num=fnum;
                CharLCD(num+48);
        }
}
