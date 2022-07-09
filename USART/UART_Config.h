/***************************************************************/
/*  Author 	     : Hashim Sobhi                               **/
/*  Date    	 : 6.6.2021                                 **/
/*  Description  : UART driver 	                	          **/
/*  Version 	 : 1.1                                        **/
/***************************************************************/
#ifndef _UART_CONFIG_H_
#define _UART_CONFIG_H_

/* clock */
#define F_CPU 8000000UL
/*  baud rate */
#define BAUD_RATE 9600

/*double speed enable
**options:
	1- ENABLE
	2- DISABLE
*/
#define DOUBLE_SPEED DISABLE

/*RX interrupt enable
**options:
	1- ENABLE
	2- DISABLE
*/
#define RX_INT DISABLE

/*TX interrupt enable
**options:
	1- ENABLE
	2- DISABLE
*/
#define TX_INT DISABLE





#endif