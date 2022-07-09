/*  Author 	      : Hashim Sobhi                              **/
/*  Date    	  : 28.5.2021                                **/
/*  Description   : TIMER Driver                              **/
/*  Version 	  : 1.1                                       **/
/***************************************************************/
#ifndef _TIMER_CONFIG_H_
#define _TIMER_CONFIG_H_

/******************select TIMER********************/
#define TIMER0_ENABLE ENABLE
#define TIMER1_ENABLE ENABLE
#define TIMER2_ENABLE DISABLE
/*options*/
#define ENABLE  1
#define DISABLE 0
/**************************************************/

/********************TIMER0************************/
/****************select TIMER0 MODE****************/
#define TIMER0_MODE FAST_PWM_MODE
/*options*/
#define OF_MODE       0
#define CTC_MODE      1
#define FAST_PWM_MODE 2

/************ select campare match output mode*****/
#define TIMER0_COMP_MODE CLEAR_OC0
/*options*/
// normal mode OC0 is disconnected
#define OC0_DISC    0
//non-PWM mode toggle OC0 on compare match
//PWM mode the bits COM00/01 are reserved   
#define TOGGLE_OC0  1
//non-PWM mode clear OC0 on compare match
//PWM mode clear OC0 on compare match, set OC0 at top 
#define CLEAR_OC0   2
//non-PWM mode set OC0 on compare match
//PWM mode set OC0 on compare match, clear OC0 at top 
#define SET_OC0     3
/****************select TIMER0 prescaler**********/
#define TIMER0_PRESCALER PRESCALER_256
/*options*/
#define PRESCALER_0    1
#define PRESCALER_8    2
#define PRESCALER_64   3
#define PRESCALER_256  4
#define PRESCALER_1024 5
/*************select interrupt ******************/
/*output compare match interrupt enable*/
#define TIMER0_INT_COMP DISABLE
/*OVERFLOW interrupt enable*/
#define TIMER0_INT_OF   DISABLE
/*options
	1- ENABLE
	2- DISABLE
*/
/**************************************************/

/********************TIMER1************************/
/****************select TIMER0 MODE****************/
#define TIMER1_MODE OF_MODE
/*options
	1- OF_MODE
	2- CTC_MODE
	2- FAST_PWM_MODE
*/
#define FAST_PWM_MODE_TOP_ICR1  3
/************ select campare match output mode*****/
#define TIMER1_COMPA_MODE OC1_DISC // for channel A
#define TIMER1_COMPB_MODE OC1_DISC // for channel B
/*options*/
// normal mode OC1A/B is disconnected
#define OC1_DISC    0
//non-PWM mode toggle OC1A/B on compare match  
#define TOGGLE_OC1  1
//non-PWM mode clear OC1A/B on compare match
//PWM mode clear OC1A/B on compare match, set OC1A/B at top 
#define CLEAR_OC1   2
//non-PWM mode set OC1A/B on compare match
//PWM mode set OC1A/B on compare match, clear OC1A/B at top 
#define SET_OC1     3
/*******enable Input Capture Noise Canceler*******/
#define NOISE_CANCELLER DISABLE 
/*options
	1- ENABLE
	2- DISABLE
*/
/****************select TIMER1 prescaler**********/
#define TIMER1_PRESCALER PRESCALER_256
/*options
	1- PRESCALER_0
	2- PRESCALER_8
	3- PRESCALER_64
	4- PRESCALER_256
	5- PRESCALER_1024
*/
/*************select interrupt ******************/
/* Input Capture Interrupt Enable*/
#define TIMER1_INT_CIE   ENABLE
/*output compare A match interrupt enable*/
#define TIMER1_INTA_COMP DISABLE
/*output compare B match interrupt enable*/
#define TIMER1_INTB_COMP DISABLE
/*OVERFLOW interrupt enable*/
#define TIMER1_INT_OF    ENABLE
/*options
	1- ENABLE
	2- DISABLE
*/
/*************************************************/
 







#endif
