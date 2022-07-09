/*  Author 	      : Hashim Sobhi                              **/
/*  Date    	  : 28.5.2021                                 **/
/*  Description   : TIMER Driver                              **/
/*  Version 	  : 1.1                                       **/
/***************************************************************/

#ifndef _TIMER_INTERFACE_H_
#define _TIMER_INTERFACE_H_

void TIMER0_VoidInit(void);
void TIMER0_VoidSetCTCRegister(u8 copy_u8Value);
void TIMER0_VoidSetTimer(u8 copy_u8Timer);

void TIMER1_VoidInit(void);
void TIMER1_VoidSetTimer(u16 copy_u16Timer);
void TIMER1_VoidSetICR1Value(u16 copy_u16Value);
void TIMER1_VoidSetCHACTCValue(u16 copy_u16Value);
u16 TIMER1_U16GetICR1Value(void);
u16 TIMER1_U16GetTIMERValue(void);
void TIMER1_VoidSetFallingEdgeForICU(void);
void TIMER1_VoidSetRisingEdgeForICU(void);

void TIMER0_VoidSetCallBackFunCom(void (*ptofun)(void));
void TIMER0_VoidSetCallBackFunOF(void (*ptofun)(void));

void TIMER1_VoidSetCallBackFunOF(void (*ptofun)(void));
void TIMER1_VoidSetCallBackFunICU(void (*ptofun)(void));





#endif
