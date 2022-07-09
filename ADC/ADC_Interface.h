/*  Author 	      : Hashim Sobhi                              **/
/*  Date    	  : 10.5.2021                                **/
/*  Description   : Analog To Digital Interface               **/
/*  Version 	  : 1.1                                       **/
/***************************************************************/
#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_ 

/*channels of ADC: bits MUX4:MUX0 in ADMUX register*/
#define CH_0   0
#define CH_1   1
#define CH_2   2
#define CH_3   3
#define CH_4   4
#define CH_5   5
#define CH_6   6
#define CH_7   7



void ADC_VoidInit(void);
u16 ADC_U16ReadValue(u8 ADC_CH);
void ADC_VoidSetCallBackFun(void (*ptofun)(void));


#endif
