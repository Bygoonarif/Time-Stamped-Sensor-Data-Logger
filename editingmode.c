#include"typedef.h"
#include"delay.h"
#include"ADC_MACRO.h"
#include"LM35.h"
#include"UART.h"
#include"RTC.h"
#include"LCD.h"
void editrtc(void);
s32 keyval(void);
u8 keypad(void);
void EDITMODE(void);
void setpoint(void);
s32 set,rev=0;
s32 hour,min,sec,date,month,year,day;
void EDITMODE()
{
                u8 ch;
                while(1)
                {               UARTTXstr("*** Time Editing Mode Activated ***");

                UARTTXstr("\r\n");
                                cmdLCD(0X01);
                        cmdLCD(0X80);
                                strLCD("1.EDIT RTC INFO");
                                UARTTXstr("1.EDIT RTC INFO");

                UARTTXstr("\r\n");
                                cmdLCD(0XC0);
                                strLCD("2.TEMP");
                                UARTTXstr("2.TEMP");
                                cmdLCD(0XC7);

                UARTTXstr("\r\n");
                                strLCD("3.EXIT");
                                UARTTXstr("3.EXIT");
                UARTTXstr("\r\n");
                        //      while(colstate());
                                delay_us(10);
                                ch=(keypad());
                        //      while(!colstate());
                                switch(ch)
                                {
                                        case 1: editrtc();
                                                        break;
                                        case 2: setpoint();
                                                        break;
                                        case 3: return;
                                }

                        }
}
void editrtc()
{
        u8 ch;
        while(1)
        {
                UARTTXstr("1.H 2.M 3.S 4.D");
                UARTTXstr("\n\r");
                UARTTXstr("5.M 6.Y 7.DAY 8.E");
                UARTTXstr("\n\r");
                cmdLCD(0X01);
                cmdLCD(0X80);
                strLCD("1.H 2.M 3.S 4.D");
                cmdLCD(0XC0);
                strLCD("5.M 6.Y 7.d 8.E");


        //      while(colstate());
                delay_us(10);
                ch=(keypad());
        //      while(!colstate());
                switch(ch)
                {
                        case 1:UARTTXstr("ENTER HOUR:");
                           cmdLCD(0X01);
                           cmdLCD(0X80);
                           strLCD("ENTER HOUR:");
                           delay_ms(100);
                           hour=keyval();
                                    SetRTCTimeInfo(hour,min,sec);          //Set the initial time (hours, minutes, seconds)
                                   break;
                //UARTTxU32(h);

        //      SetRTCTimeInfo(hour,04,00);

                 case 2:UARTTXstr("ENTER MINUTES:");
                        cmdLCD(0X01);
                        cmdLCD(0X80);
                        strLCD("ENTER MINUTES:");
                        min=keyval();
                                         SetRTCTimeInfo(hour,min,sec);     //Set the initial time (hours, minutes, seconds)
                                        break;



                 case 3:UARTTXstr("ENTER SECONDS:");
                        cmdLCD(0X01);
                        cmdLCD(0X80);
                        strLCD("ENTER SECONDS:");
                        sec=keyval();
                                         SetRTCTimeInfo(hour,min,sec);     //Set the initial time (hours, minutes, seconds)
                                        break;


                 case 4:UARTTXstr("ENTER DATE:");
                        cmdLCD(0X01);
                        cmdLCD(0X80);
                        strLCD("ENTER DATE:");
                        date=keyval();
                                         SetRTCDateInfo(date,month,year);
                                        break;


                 case 5:UARTTXstr("ENTER MONTH:");
                        cmdLCD(0X01);
                        cmdLCD(0X80);
                        strLCD("ENTER MONTH:");
                        month=keyval();
                                         SetRTCDateInfo(date,month,year);
                                        break;
                 case 6:UARTTXstr("ENTER YEAR:");
                        cmdLCD(0X01);
                        cmdLCD(0X80);
                        strLCD("ENTER YEAR:");
                        year=keyval();
                        SetRTCDateInfo(date,month,year);    //set the date (day, month, year)
                                        break;
                         case 7:UARTTXstr("ENTER DAY:");
                        cmdLCD(0X01);
                        cmdLCD(0X80);
                        strLCD("ENTER DAY:");
                        day=keyval();
                                         SetRTCDay(day);
                                        break;
                        case 8:return ;

                }
        }


}
s32 keyval()
{
        s32 stop;
        rev=0;
   while(1)
   {
                stop=keypad();

                if(stop==3)
                {
                        UARTTXu32(rev);
                        IntLCD(rev);
                        delay_s(5);
                        return rev;
                        //delay_s(5);
                }
                        rev=(rev*10)+stop;
        }
}
void setpoint()
{
        cmdLCD(0X01);
        UARTTXstr("ENTER SETPOINT:");
        strLCD("ENTER SP:");
        set= keyval();
        UARTTXu32(set);
        delay_ms(100);
}