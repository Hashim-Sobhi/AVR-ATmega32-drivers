/***************************************************************/
/*  Author 	  : Hashim Sobhi                               **/
/*  Date    	  : 1.5.2021                                  **/
/*  Description  : General Interrupt Enable program           **/
/*  Version 	  : 1.1                                        **/
/***************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "GIE_Register.h"

void GIE_VoidSetEnable(void)
{
	SET_BIT(SREG,I);
}

void GIE_VoidSetDisable(void)
{
	CLR_BIT(SREG,I);
}