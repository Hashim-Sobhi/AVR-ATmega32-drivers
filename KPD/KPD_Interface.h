/***************************************************************/
/*  Author 	 : Hashim Sobhi                                 **/
/*  Date    	 : 29.4.2021                                     **/
/*  Description: keypad driver for 4x4                        **/
/*  Version 	 : 1.0                                          **/
/***************************************************************/
#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_


#define NOT_PRESSED 32
#define PORT_KPD PORT_A 



void KPD_VoidInit(void);
u8 KPD_U8GetKey(void);

#endif