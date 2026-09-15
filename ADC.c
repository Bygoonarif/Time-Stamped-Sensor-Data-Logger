#include<lpc21xx.h>
#include"adc_defines.h"
#include"adc.h"
#include"delay.h"
#include"pinconnect.h"
#include"types.h"
//void Init_ADC()
//{
//      //clear all prev pin confg
//      PINSEL1&=~(255<<22);
//      PINSEL1|=AIN0_PIN_0_27;
//      //cfg ADCR
//      ADCR|=(1<<PDN_BIT)|(CLKDIV<<CLKDIV_BITS);
//}
void Read_ADC(u32 CHN0,f32 *eAR,u32 *adcDVal)
{
        //clear any previous channel selection
        ADCR&=0XFFFFFF00;
        //update require channel no     and set start adc bit
        ADCR|=((1<<ADC_CONV_START_BIT)|(1<<CHN0)) ;
        //wait for convertion time
        delay_us(300);
        //check if conv completed successfully
        while(((ADDR>>DONE_BIT)&1)==0);
        //stop ADC conversion
        ADCR&=~(1<<ADC_CONV_START_BIT);
        //read digital data
        *adcDVal=((ADDR>>DIGITAL_DATA_BITS)&1023);
        *eAR=(*adcDVal)*(3.3/1024);
}
