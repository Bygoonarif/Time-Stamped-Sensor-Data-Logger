#include<lpc21xx.h>
#include"defines.h"
#include"UART.h"
#include"delay.h"
#include"types.h"
#include"pinconnect.h"
void InitUART()
{
         CfgPinFunc(0,0,1);     //TX
         CfgPinFunc(0,1,1);     //RX
         U0LCR=0X03; // SEL FOR 8-BIT LINES
         U0LCR|=1<<7;  // DLAB=1
         U0DLL=97;
         U0DLM=0;
         U0LCR&=~(1<<7);         //DLAB=0
}
void UARTTxChar(s8 ch)
{
        U0THR=ch;
        while(!(U0LSR>>6)&1);
}
s8 UARTRxChar(void)
{
        while(!((U0LSR>>0)&1));
        return (U0RBR);
}
void UARTTxStr(s8 *ptr)
{
        while(*ptr)
                UARTTxChar(*ptr++);
}
void UARTTxU32(u32 num)
{
        u8 a[10];
        s8 i=0;
//      if(!(num/10))
//      {
//              UARTTxChar('0');
//      }
        if(num==0)
        {
                UARTTxChar('0');

        }
        else
        {
                while(num>0)
                {
                        a[i++]=num%10+48;
                        num=num/10;
                }
                for(--i;i>=0;i--)
                {
                        UARTTxChar(a[i]);
                }
        }
}
void UARTTxF32(f32 fnum)
{
        u32 num,i;
        if(fnum<0)
        {
                UARTTxChar('-');
                fnum=-fnum;
        }
        num=fnum;
        UARTTxU32(num);
        UARTTxChar('.');
        for(i=0;i<6;i++)
        {
                fnum=(fnum-num)*10;
                num=fnum;
                UARTTxChar(num+48);
        }
}
