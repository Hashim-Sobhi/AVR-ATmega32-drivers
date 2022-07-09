/*  Author 	      : Hashim Sobhi                              **/
/*  Date    	  : 28.5.2021                                 **/
/*  Description   : TIMER Driver                              **/
/*  Version 	  : 1.1                                       **/
/***************************************************************/

#ifndef _TIMER_REGISTER_H_
#define _TIMER_REGISTER_H_

/***************************Timer0******************************/
/*Timer Control Register*/
#define TCCR0  *((u8*)0x53)
/*Timner Register*/
#define TCNT0  *((u8*)0x52)
/*Output Compare Register*/
#define OCR0   *((u8*)0x5C)
/*Timer0/1 Interrupt Mask Register*/
#define TIMSK  *((u8*)0x59)
/*Timer0/1 Interrupt Flaf Register*/
#define TIFR   *((u8*)0x58)

/*TCCR0 PINS*/
/*Waveform Generation Mode*/
#define WGM00 6
#define WGM01 3
/*Compare Match Output Mode*/
#define COM01 5
#define COM00 4
/*Clock Select*/ /* timer0 & timer1 share the same prescaler*/
#define CS02 2
#define CS01 1
#define CS00 0

/*TIMSK PINS*/
/* Output Compare Match Interrupt Enable */
#define OCIE0 1
/* Overflow Interrupt Enable */
#define TOIE0 0

/*TIFR PINS*/
/* Output Compare Flag */
#define OCF0 1
/* Overflow Flag */
#define TOV0 0
// timer0 max
#define TIMER0_MAX 256
/***************************************************************/

/***************************Timer1******************************/
/*registers*/
/*Timer Control Register A*/
#define TCCR1A  *((u8*)0x4F)

#define TCCR1B  *((u8*)0x4E)

#define TCNT1H  *((u8*)0x4D)
#define TCNT1L  *((u8*)0x4C)
#define TCNT1   *((u16*)0x4C)

#define OCR1AH  *((u8*)0x4B)
#define OCR1AL  *((u8*)0x4A)
#define OCR1A   *((u16*)0x4A)

#define OCR1BH  *((u8*)0x49)
#define OCR1BL  *((u8*)0x48)
#define OCR1B   *((u16*)0x48)

#define ICR1H   *((u8*)0x47)
#define ICR1L   *((u8*)0x46)
#define ICR1    *((u16*)0x46)

/*TCCR1A Pins*/
/* Compare Output Mode for Channel A pins*/
#define COM1A0 6
#define COM1A1 7
/* Compare Output Mode for Channel B pins*/
#define COM1B0 4
#define COM1B1 5
/* Waveform Generation Mode pins*/
#define WGM10 0
#define WGM11 1

/*TCCR1B Pins*/
/*Input Capture Noise Canceler*/
#define ICNC1 7
/* Input Capture Edge Select*/
#define ICES1 6
/* Waveform Generation Mode pins*/
#define WGM12 3
#define WGM13 4
/*Clock Select pins*/
#define CS10 0
#define CS11 1
#define CS12 2

/*TIMSK Pins*/
/* Input Capture Interrupt Enable*/
#define TICIE1 5
/*  Output Compare A Match Interrupt Enable*/
#define OCIE1A 4 
/* Output Compare B Match Interrupt Enable*/
#define OCIE1B 3 
/* Overflow Interrupt Enable*/
#define TOIE1  2 

/*TIFR Pins*/
/*input Capture Flag*/
#define ICF1  5
/*Output Compare A Match Flag*/
#define OCF1A 4
/*Output Compare B Match Flag*/
#define OCF1B 3
/*Overflow Flag*/
#define TOV1  2
/************************************************************/

void (*TIMER0_CallBackFunCom) (void) = NULL;
void (*TIMER0_CallBackFunOF) (void) = NULL;
void (*TIMER1_CallBackFunOF) (void) = NULL;
void (*TIMER1_CallBackFunICU) (void) = NULL;

void __vector_9(void) __attribute__ ((signal));
void __vector_10(void) __attribute__ ((signal));
void __vector_11(void) __attribute__ ((signal));
void __vector_6(void)  __attribute__ ((signal));

#endif
