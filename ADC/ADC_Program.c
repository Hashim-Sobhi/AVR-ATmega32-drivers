/*  Author 	      : Hashim Sobhi                              **/
/*  Date    	  : 10.5.2021                                **/
/*  Description   : Analog To Digital program                 **/
/*  Version 	  : 1.1                                       **/
/***************************************************************/
#include <stdio.h>
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "ADC_Register.h"
#include "ADC_CONFIG.h"

/*in free running mode take this var to main */
u16 ADC_value;

void ADC_VoidInit(void)
{
	//select rev voltage 
	#if REF_VOLTAGE == AREF
	CLR_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);
	#elif REF_VOLTAGE == AVCC
	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);
	#elif REF_VOLTAGE == INTERNAL_2260mV
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	#endif
	//select right\left adjusted 	
	#if ADC_RESULT == RIGHT
	CLR_BIT(ADMUX,ADLAR);
	#elif ADC_RESULT == LEFT
	SET_BIT(ADMUX,ADLAR);	
	#endif
	//enable ADC
	#if ADC_ENABLE == ENABLE
	SET_BIT(ADCSRA,ADEN);
	#elif ADC_ENABLE == DISABLE
	CLR_BIT(ADCSRA,ADEN);	
	#endif
	//select mode 
	#if ADC_MODE == SINGLE_CONV
	CLR_BIT(ADCSRA,ADATE);
	#elif ADC_MODE == FREE_RUNNING
	SET_BIT(ADCSRA,ADATE);
	#endif
	//Interrupt enable
	#if ADCI_ENABLE == ENABLE
	SET_BIT(ADCSRA,ADIE);
	#elif ADCI_ENABLE == DISABLE
	CLR_BIT(ADCSRA,ADIE);
	#endif
	//select prescalar
	#if ADC_PRESCALAR == ADPS_2
	ADCSRA |= ADPS_2;
	#elif ADC_PRESCALAR == ADPS_4
	ADCSRA |= ADPS_4;
	#elif ADC_PRESCALAR == ADPS_8
	ADCSRA |= ADPS_8;
	#elif ADC_PRESCALAR == ADPS_16
	ADCSRA |= ADPS_16;
	#elif ADC_PRESCALAR == ADPS_32
	ADCSRA |= ADPS_32;
	#elif ADC_PRESCALAR == ADPS_64
	ADCSRA |= ADPS_64;
	#elif ADC_PRESCALAR == ADPS_128
	ADCSRA |= ADPS_128;
	#endif
}

u16 ADC_U16ReadValue(u8 ADC_CH)
{
	//remove last chn
	ADMUX &= 0b11100000;
	//select channel
	ADMUX |= ADC_CH;
	//start conversion
	SET_BIT(ADCSRA,ADSC);
	// if single conversion mode selected
	#if ADC_MODE == SINGLE_CONV
	//wait until conv completed 
	while (!GET_BIT(ADCSRA,ADIF));
	//clear flag
	CLR_BIT(ADCSRA,ADIF);
	//return value
	return ADC_D;
	// if free running mode selected and reading in ISR
	#elif ADC_MODE == FREE_RUNNING
	 return 0;
	#endif
}

void ADC_VoidSetCallBackFun(void (*ptofun)(void))
{
	ADC_CallBackFun = ptofun;
}

// ISR of ADC conversion complete
void __vector_16(void)
{
	ADC_value = ADC_D;
	ADC_CallBackFun();
}
