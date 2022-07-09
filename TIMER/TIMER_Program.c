/*  Author 	      : Hashim Sobhi                              **/
/*  Date    	  : 28.5.2021                                 **/
/*  Description   : TIMER Driver                              **/
/*  Version 	  : 1.1                                       **/
/***************************************************************/
#include <stdio.h>
#include "STD_TYPES.h"
#include "BIT_MATHS.h" 
#include "TIMER_Register.h"
#include "TIMER_Config.h"



// enable TIMER0
#if TIMER0_ENABLE == ENABLE
void TIMER0_VoidInit(void)
{
	// select timer0 mode 
	#if TIMER0_MODE == OF_MODE
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	#elif TIMER0_MODE == FAST_PWM_MODE
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	#elif TIMER0_MODE == CTC_MODE
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	#endif
	// select timer0 compare match  output mode 
	#if TIMER0_COMP_MODE == OC0_DISC
	CLR_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);
	#elif TIMER0_COMP_MODE == TOGGLE_OC0
	SET_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);
	#elif TIMER0_COMP_MODE == CLEAR_OC0
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	#elif TIMER0_COMP_MODE == SET_OC0
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	#endif
	// select prescaler from config file 
	TCCR0 |= TIMER0_PRESCALER;
	// enable Output Compare Match Interrupt Enable
	#if TIMER0_INT_COMP == ENABLE 
	SET_BIT(TIMSK,OCIE0);
	#else
	CLR_BIT(TIMSK,OCIE0);
	#endif
	// enable Overflow Interrupt Enable
	#if TIMER0_INT_OF == ENABLE 
	SET_BIT(TIMSK,TOIE0);
	#else
	CLR_BIT(TIMSK,TOIE0);
	#endif
}
#endif

#if TIMER1_ENABLE == ENABLE
void TIMER1_VoidInit(void)
{
	// select timer1 mode 
	#if TIMER1_MODE == OF_MODE
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
	#elif TIMER1_MODE == FAST_PWM_MODE_TOP_OCR1A
	SET_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	#elif TIMER1_MODE == CTC_MODE
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
	#elif TIMER1_MODE == FAST_PWM_MODE_TOP_ICR1
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	#endif
	// select timer1 compare match  output mode for cannel A
	#if TIMER1_COMPA_MODE == OC1_DISC
	CLR_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);
	#elif TIMER1_COMPA_MODE == TOGGLE_OC1
	SET_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);
	#elif TIMER1_COMPA_MODE == CLEAR_OC1
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	#elif TIMER1_COMPA_MODE == SET_OC1
	SET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
	#endif
	// select timer1 compare match  output mode for cannel B
	#if TIMER1_COMPB_MODE == OC1_DISC
	CLR_BIT(TCCR1A,COM1B0);
	CLR_BIT(TCCR1A,COM1B1);
	#elif TIMER1_COMPB_MODE == TOGGLE_OC1
	SET_BIT(TCCR1A,COM1B0);
	CLR_BIT(TCCR1A,COM1B1);
	#elif TIMER1_COMPB_MODE == CLEAR_OC1
	CLR_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
	#elif TIMER1_COMPB_MODE == SET_OC1
	SET_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
	#endif
	//enable Input Capture Noise Canceler 
	#if NOISE_CANCELLER == ENABLE
	SET_BIT(TCCR1B,ICNC1);
	#elif NOISE_CANCELLER == DISABLE
	CLR_BIT(TCCR1B,ICNC1);
	#endif
	// select prescaler from config file 
	TCCR1B |= TIMER1_PRESCALER;
	// Input Capture Interrupt Enable
	#if TIMER1_INT_CIE == ENABLE
	SET_BIT(TIMSK,TICIE1);
	#else
	CLR_BIT(TIMSK,TICIE1);	
	#endif
	// enable Output Compare A Match Interrupt Enable
	#if TIMER1_INTA_COMP == ENABLE 
	SET_BIT(TIMSK,OCIE1A);
	#else
	CLR_BIT(TIMSK,OCIE1A);
	#endif
	// enable Output Compare B Match Interrupt Enable
	#if TIMER1_INTB_COMP == ENABLE 
	SET_BIT(TIMSK,OCIE1B);
	#else
	CLR_BIT(TIMSK,OCIE1B);
	#endif
	// enable Overflow Interrupt Enable
	#if TIMER1_INT_OF == ENABLE 
	SET_BIT(TIMSK,TOIE1);
	#else
	CLR_BIT(TIMSK,TOIE1);
	#endif
}
#endif

/********* timer0 ***********/
void TIMER0_VoidSetTimer(u8 copy_u8Timer)
{
	TCNT0 = copy_u8Timer;
}

void TIMER0_VoidSetCTCRegister(u8 copy_u8Value)
{
	OCR0 = copy_u8Value;
}


//overflow
void TIMER0_VoidSetCallBackFunOF(void (*ptofun)(void))
{
	TIMER0_CallBackFunOF = ptofun;
}

//compare match
void TIMER0_VoidSetCallBackFunCom(void (*ptofun)(void))
{
	TIMER0_CallBackFunCom = ptofun;
}


//compare match ISR for timer0
void __vector_10(void)
{
	TIMER0_CallBackFunCom();
}
//overflow ISR for timer0
void __vector_11(void)
{
	TIMER0_CallBackFunOF();
}

/**************timer1**********/

void TIMER1_VoidSetTimer(u16 copy_u16Timer)
{
	TCNT1 = copy_u16Timer;
}

void TIMER1_VoidSetCHACTCValue(u16 copy_u16Value)
{
	OCR1A = copy_u16Value;
}

void TIMER1_VoidSetICR1Value(u16 copy_u16Value)
{
	ICR1 = copy_u16Value;
}

u16 TIMER1_U16GetICR1Value(void)
{
	return ICR1;
}

u16 TIMER1_U16GetTIMERValue(void)
{
	return TCNT1;
}

void TIMER1_VoidSetRisingEdgeForICU(void)
{
	// Rising Edge for ICU
	SET_BIT(TCCR1B, ICES1);
}
void TIMER1_VoidSetFallingEdgeForICU(void)
{
	// Falling Edge for ICU
	CLR_BIT(TCCR1B, ICES1);
}
void TIMER1_VoidSetCallBackFunOF (void (*ptofun)(void))
{
	TIMER1_CallBackFunOF = ptofun;
}

void TIMER1_VoidSetCallBackFunICU(void (*ptofun)(void))
{
	TIMER1_CallBackFunICU = ptofun;
}
//overflow ISR for timer1 
void __vector_9 (void)
{
	TIMER1_CallBackFunOF();
}

//ICU ISR TIMER1
void __vector_6 (void)
{
	TIMER1_CallBackFunICU();
}
