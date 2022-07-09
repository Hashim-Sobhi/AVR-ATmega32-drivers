/*  Author 	      : Hashim Sobhi                                  **/
/*  Date    	  : 29.4.2021                                   **/
/*  Description   : Servo Motor Driver using timer1 and pin OC1A  **/
/*  Version 	  : 1.1                                           **/
/*******************************************************************/


#include "STD_TYPES.h"
#include "TIMER_Interface.h"




void SRVMOTOR_VoidSetAngle(u8 copy_u8angle)
{
	//fast pwm mode and its top -> ICR1 (mode 14)
	//non inverted mode 
	//prescaler = 8
	TIMER1_VoidInit();
	//for 50Hz
	TIMER1_VoidSetICR1Value(19999);
	//set angle
	// CHACTC = 500 ==> angle =0 
	// CHACTC = 2480 ==> angle =180 
	u16 local_u8value = 500 + copy_u8angle*11;
	TIMER1_VoidSetCHACTCValue(local_u8value);
}
