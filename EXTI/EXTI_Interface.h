/***************************************************************/
/*  Author 	  : Hashim Sobhi                               **/
/*  Date    	  : 1.5.2021                                  **/
/*  Description  : External Interrupt Interface               **/
/*  Version 	  : 1.1                                        **/
/***************************************************************/



#ifndef _EXIT_INTERFACE_H_
#define _EXIT_INTERFACE_H_


void EXIT_VoidInit(void);
void EXTI0_VoidSetCallBackFun (void (*ptofun)(void));
void EXTI1_VoidSetCallBackFun (void (*ptofun)(void));
void EXTI2_VoidSetCallBackFun (void (*ptofun)(void));

#endif