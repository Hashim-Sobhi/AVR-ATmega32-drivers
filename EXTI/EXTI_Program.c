/***************************************************************/
/*  Author 	  : Hashim Sobhi                               **/
/*  Date    	  : 1.5.2021                                 **/
/*  Description  : External Interrupt program                 **/
/*  Version 	  : 1.1                                        **/
/***************************************************************/
#include "stdio.h"
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "EXTI_Register.h"
#include "EXTI_Config.h"

void EXIT_VoidInit(void)
{
	/*INT0*/
	#if INT0_ENABLE == ENABLE
	/* enable INT0 */
	SET_BIT(GICR,INT0);
	/*choose mode of INT0*/
	#if INT0_MODE == LOW_LEVEL
	CLR_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
	#elif INT0_MODE == OCH
	SET_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
	#elif INT0_MODE == FALLING_EDGE
	CLR_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
	#elif INT0_MODE == RISING_EDGE
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
	#endif
	#endif
	
	/*INT1*/
	#if INT1_ENABLE == ENABLE
	/* enable INT1 */
	SET_BIT(GICR,INT1);
	/*choose mode of INT1*/
	#if INT1_MODE == LOW_LEVEL
	CLR_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
	#elif INT1_MODE == OCH
	SET_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
	#elif INT1_MODE == FALLING_EDGE
	CLR_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
	#elif INT1_MODE == RISING_EDGE
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
	#endif
	#endif
	
	/*INT2*/
	#if INT2_ENABLE == ENABLE
	/* enable INT2 */
	SET_BIT(GICR,INT2);
	/*choose mode of INT2*/
	#if INT2_MODE == FALLING_EDGE
	CLR_BIT(MCUCSR,ISC2);
	#elif INT2_MODE == RISING_EDGE
	SET_BIT(MCUCSR,ISC2);
	#endif
	#endif
}

void EXTI0_VoidSetCallBackFun (void (*ptofun)(void))
{
	EXTI0_CallBackFun = ptofun;
}
void EXTI1_VoidSetCallBackFun (void (*ptofun)(void))
{
	EXTI1_CallBackFun = ptofun;
}
void EXTI2_VoidSetCallBackFun (void (*ptofun)(void))
{
	EXTI2_CallBackFun = ptofun;
}
/*ISR for INT0*/
void __vector_1(void)
{
	//body
	EXTI0_CallBackFun ();
}
/*ISR for INT1*/
void __vector_2(void)
{
	//body
	EXTI1_CallBackFun ();
}
/*ISR for INT2*/
void __vector_3(void)
{
	//body
	EXTI2_CallBackFun ();
}