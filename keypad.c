#include<lpc21xx.h>
#include"defines.h"
#include"delay.h"
#include"types.h"
#include"lcd.h"
u8 keypad(void);
#define OUT 0XFF
#define R0 16
#define R1 17
#define R2 18
#define R3 19
#define C0 20
#define C1 21
#define C2 22
#define C3 23
u8 LUT[][4]={1,2,3,4,
                        4,5,6,'B',
                        7,8,9,'C',
                        '*','0','#','D'};
u8 keypad()
{
        u32 row=0,col=0;
        IODIR0|=OUT;
        IODIR1=((1<<R0)|(1<<R1)|(1<<R2)|(1<<R3));
//      InitLCD();
//      CmdLCD(0X80);

        while(1)
        {
                IOCLR1=((1<<R0)|(1<<R1)|(1<<R2)|(1<<R3));
                while(((IOPIN1>>C0)&0X0F)==0X0F);
                delay_ms(50);
                IOCLR1=1<<R0;
                IOSET1=((1<<R1)|(1<<R2)|(1<<R3));
                if(((IOPIN1>>C0)&0X0F)!=0X0F)
                {
                        row=0;
                        goto colcheck;
                }
                IOCLR1=1<<R1;
                IOSET1=((1<<R0)|(1<<R2)|(1<<R3));
                if(((IOPIN1>>C0)&0X0F)!=0X0F)
                {
                        row=1;
                        goto colcheck;
                }
                IOCLR1=1<<R2;
                IOSET1=((1<<R0)|(1<<R1)|(1<<R3));
                if(((IOPIN1>>C0)&0X0F)!=0X0F)
                {
                        row=2;
                        goto colcheck;
                }
                IOCLR1=1<<R3;
                IOSET1=((1<<R0)|(1<<R1)|(1<<R2));
                if(((IOPIN1>>C0)&0X0F)!=0X0F)
                {
                        row=3;
                        goto colcheck;
                }


                colcheck:
                if(((IOPIN1>>C0)&1)==0)
                {
                        col=0;
                }
                else if(((IOPIN1>>C1)&1)==0)
                {
                        col=1;
                }
                else if(((IOPIN1>>C2)&1)==0)
                {
                        col=2;
                }
                else if(((IOPIN1>>C3)&1)==0)
                {
                        col=3;
                }
                                while(((IOPIN1>>C0)&0X0F)!=0X0F);

                return LUT[row][col];
                         //WRITEBYTE(IOPIN0,0,LUT[row][col]);
                         //CharLCD(LUT[row][col]);

        }

}
