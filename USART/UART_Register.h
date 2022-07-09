/***************************************************************/
/*  Author 	     : Hashim Sobhi                               **/
/*  Date    	 : 6.6.2021                                **/
/*  Description  : UART driver 	                	          **/
/*  Version 	 : 1.1                                        **/
/***************************************************************/
#ifndef _UART_REGISTER_H_
#define _UART_REGISTER_H_

//data register
#define UDR   *((volatile u8*)0x2C)
#define UCSRA *((volatile u8*)0x2B)
#define UCSRB *((volatile u8*)0x2A)
#define UCSRC *((volatile u8*)0x40)
#define UBRRL *((volatile u8*)0x29)
#define UBRRH *((volatile u8*)0x40)

// UCRSA Pins
#define RXC  7
#define TXC  6
#define UDRE 5
#define U2X  1
// UCSRB Pins
#define RXCIE 7
#define TXCIE 6
#define UDRIE 5
#define RXEN  4
#define TXEN  3
#define UCSZ2 2
// UCSRC Pins
#define URSEL 7
#define UCSZ1 2
#define UCSZ0 1

/*********************confic*******************/
#define ENABLE  1
#define DISABLE 0



#endif