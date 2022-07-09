/***************************************************************/
/*  Author 	  : Hashim Sobhi                               **/
/*  Date    	  : 1.5.2021                                  **/
/*  Description  : General Interrupt Enable Register          **/
/*  Version 	  : 1.1                                        **/
/***************************************************************/

#ifndef _GIE_REGISTER_H_
#define _GIE_REGISTER_H_

#define SREG *((u8*)0x5F)

/*SREG PINS*/
/*if I set to one ==> enable interrupts*/
#define I  7



#endif