/***************************************************************/
/*  Author 	     : Hashim Sobhi                               **/
/*  Date    	 : 6.6.2021                                 **/
/*  Description  : UART driver 	                	          **/
/*  Version 	 : 1.1                                        **/
/***************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "UART_Register.h"
#include "UART_Config.h"


void UART_VoidInit(void)
{	
	u8 UCSRC_temp = 0;
	u16 BAUD_PRESCALE = 0;
	
	// Double the USART Transmission Speed enable
	#if DOUBLE_SPEED == ENABLE
	SET_BIT(UCSRA,U2X);
	BAUD_PRESCALE = (((F_CPU / (BAUD_RATE * 8UL))) - 1);
	#elif DOUBLE_SPEED == DISABLE
	CLR_BIT(UCSRA,U2X);
	BAUD_PRESCALE = (((F_CPU / (BAUD_RATE * 16UL))) - 1);
	#endif
	
	// rx interrupt enable 
	#if RX_INT == ENABLE 
	SET_BIT(UCSRB,RXCIE);
	#elif RX_INT == DISABLE
	CLR_BIT(UCSRB,RXCIE);
	#endif
	
	// tx interrupt enable 
	#if TX_INT == ENABLE 
	SET_BIT(UCSRB,TXCIE);
	#elif TX_INT == DISABLE
	CLR_BIT(UCSRB,TXCIE);
	#endif
	
	// rx and tx enable 
	SET_BIT(UCSRB,RXEN); 
	SET_BIT(UCSRB,TXEN);
	
	// set baud rate
	UBRRL = BAUD_PRESCALE; // load lower 8-bits
	UBRRH = BAUD_PRESCALE >> 8; // load upper 8-bits
	
	// set URSEL to write UCSRC
	SET_BIT(UCSRC_temp,URSEL);
	// select 8-bits data and one stop bit
	SET_BIT(UCSRC_temp,UCSZ0);
	SET_BIT(UCSRC_temp,UCSZ1);
	//set UCSRC register
	UCSRC = UCSRC_temp;
	
}


void UART_VoidSendData(u8 copy_u8Char)
{
	while (!GET_BIT(UCSRA,UDRE)); // wait until UDR be empty
	UDR = copy_u8Char; // send data
}


u8 UART_U8GetData(void)
{
	while (!GET_BIT(UCSRA,RXC)); // wait until receiver be filled
	return UDR; //receive data
}

void UART_VoidSendString(u8* copy_u8str)
{
	u16 loc_u8counter = 0;
	while (copy_u8str[loc_u8counter]!='\0')
	{
		UART_VoidSendData(copy_u8str[loc_u8counter]);
		loc_u8counter++;
	}
}
void UART_VoidSendNum(u32 copy_u32num)
{
	if (copy_u32num == 0)
	{
		UART_VoidSendData('0');
	}
	else
	{
		u8 local_u8num = 0;
		u32 local_u32rev = 1;
		while (copy_u32num != 0)
		{
			local_u32rev = (local_u32rev*10)+(copy_u32num%10);
			copy_u32num /= 10;
		}
		while (local_u32rev != 1)
		{
			local_u8num = local_u32rev%10;
			local_u32rev /= 10;
			UART_VoidSendData(local_u8num+48);
		} 	
	}	
}