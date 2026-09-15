#include<lpc21xx.h>
#include"adc_defines.h"
#include"adc.h"
#include"delay.h"
#include"pinconnect.h"
#include"types.h"
#include"uart.h"
#include"lm35.h"
u32 adcChSel[4]={AIN0_PIN_0_27,AIN1_PIN_0_28,AIN2_PIN_0_29,AIN3_PIN_0_30} ;

void Init_adc(u32 CHNO)
{
        //clear prev
        PINSEL1&=~(adcChSel[CHNO]);
        //cfg reg p0.27
        PINSEL1|=adcChSel[CHNO];
        ADCR|=(1<<PDN_BIT)|(CLKDIV<<CLKDIV_BITS);
}
//f32 Read_LM35_NP(u8 tType)
//{
//      u32 adcDVal1,adcDVal2;
//      f32 eAR1,eAR2,tDeg;
////    Read_ADC(CH0,&eAR1,&adcDVal1);
////    Read_ADC(CH1,&eAR2,&adcDVal2);
//      tDeg=(eAR1-eAR2)*100;
//      if(tType=='C');
//      else if(tType=='F')
//      {
//              tDeg=((tDeg*(9/5))+32);
//      }
//      return tDeg;
//}
f32 Read_LM35(u8 tType)
{
        u32 adcDVal;
        f32 eAR,tDeg;
        Read_ADC(CH1,&eAR,&adcDVal);
//      UARTTxU32(eAR);
        tDeg=(eAR)*100;
        if(tType=='C');
        else if(tType=='F')
        {
                tDeg=((tDeg*(9/5))+32);
        }
        return tDeg;
}
