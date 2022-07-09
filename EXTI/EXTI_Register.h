/***************************************************************/
/*  Author 	  : Hashim Sobhi                               **/
/*  Date    	  : 1.5.2021                                  **/
/*  Description  : External Interrupt Registers               **/
/*  Version 	  : 1.1                                        **/
/***************************************************************/

#ifndef _EXTI_REGISTER_H_
#define _EXTI_REGISTER_H_

/* mcu control register for INT0&INT1*/
#define MCUCR  *((u8*)0x55)
/*mcu contrl register  for INT2*/
#define MCUCSR *((u8*)0x54)
/*General Interrupt Control Register*/
#define GICR   *((u8*)0x5B)
/*General Interrupt Flag Register*/
#define GIFR   *((u8*)0x5A)

/*MCUCR PINS*/
/*ISR00 & ISC01  for INT0*/
/*ISR10 & ISC11  for INT1*/
/* 00 ==> sense low level     */
/* 01 ==> sense on change     */
/* 10 ==> sense falling edge  */
/* 11 ==> sense rising edge   */
#define ISC00  0
#define ISC01  1
#define ISC10  2
#define ISC11  3

/*MCUCSR PINS*/
/*if ISC2 set to 1 ==> sense rising edge */
/*if ISC2 set to 0 ==> sense fallin edge */
#define ISC2   6

/*GICR PINS*/
/* when set to 1 ==> enable interrupt*/
#define INT2  5
#define INT0  6
#define INT1  7

void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));
void (*EXTI0_CallBackFun) (void) = NULL;
void (*EXTI1_CallBackFun) (void) = NULL;
void (*EXTI2_CallBackFun) (void) = NULL;

#endif 
