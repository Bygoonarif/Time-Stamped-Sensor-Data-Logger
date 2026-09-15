#include<lpc21xx.h>
#include"typedef.h"
#include"delay.h"
#include"ADC_MACRO.h"
#include"LM35.h"
#include"UART.h"
#include"RTC.h"
#include"LCD.h"
u8 keypad(void);
void EDITMODE(void);
volatile s32 set;
s32 hour,min,sec,date,month,year,day;
volatile s32 temp;
int main()
{       set=45;
        initUART();     //initilization  UART

        RTC_Init();     //initilization RTC
        SetRTCTimeInfo(12,10,00);//SET RTC TIME (HOUR,MINUTE,SEC)
        SetRTCDateInfo(30,12,2025);//SET RTC DATE(DAY,MONTH,YEAR)
        SetRTCDay(4);//SET DAY

    int_ADC(CH1);//ADC initilization channel 1 (p0.28)
        int_ADC(CH2);//ADC initilization channel 2      (p0.29)

        initLCD();//LCD initilization
        IODIR0 |=3<<5;

    while (1)
        {
        // Get and display the current time, date, day on LCD

                GetRTCTimeInfo(&hour,&min,&sec);

                DisplayRTCTime(hour,min,sec);

                GetRTCDateInfo(&date,&month,&year);

                DisplayRTCDate(date,month,year);

                GetRTCDay(&day);

                DisplayRTCDay(day);

            cmdLCD(0X89);

                UARTTXstr("T:");
                strLCD("T:");
                temp=(int)(READ_LM35('C'));^M
                UARTTXu32(temp);
                IntLCD(temp);
                UARTTXchar(176);
                UARTTXchar('C');
                CharLCD(223);
                CharLCD('C');
                UARTTXstr("\n\r");
                delay_s(1);
                if(set<temp)
                {
                        IOSET0=1<<5;
                        IOSET0=1<<6;

                while(set<temp)
                {
                        temp=(int)(READ_LM35('C'));
                        //IOSET0=1<<5;
                        //IOSET0=1<<6;
                        UARTTXstr("OVER TEMP");
                        strLCD("OVER TEMP");
                }
                IOCLR0=1<<5;
                IOCLR0=1<<6;
                }
            if(((IOPIN1>>26)&1)==0)
                {

                        while(((IOPIN1>>26)&1)==0);
                                delay_ms(10);
                                EDITMODE();
                }
        }
}