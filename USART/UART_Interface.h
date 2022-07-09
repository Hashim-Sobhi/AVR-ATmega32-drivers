/***************************************************************/
/*  Author 	     : Hashim Sobhi                               **/
/*  Date    	 : 6.6.2021                                 **/
/*  Description  : UART driver 	                	          **/
/*  Version 	 : 1.1                                        **/
/***************************************************************/

#ifndef _UART_INTERFACE_H_
#define _UART_INTERFACE_H_

void UART_VoidInit(void);
void UART_VoidSendData(u8 copy_u8Char);
u8 UART_U8ReceiveData(void);
void UART_VoidSendString(u8* copy_u8str);
void UART_VoidSendNum(u32 copy_u32num);
#endif