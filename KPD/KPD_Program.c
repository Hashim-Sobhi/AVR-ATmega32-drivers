/***************************************************************/
/*  Author 	 : Hashim Sobhi                                 **/
/*  Date    	 : 29.4.2021                                   **/
/*  Description: keypad driver for 4x4                        **/
/*  Version 	 : 1.0                                          **/
/***************************************************************/
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "avr/delay.h"

/*the key pad */
/* 0   1   2   3  */
/* 4   5   6   7  */
/* 8   9   10  11 */
/* 12  13  14  15 */


/* using port A and the first 4 pins are output for columns and last four are input for rows*/
void KPD_VoidInit(void)
{
	DIO_VoidSetPortDirection(PORT_KPD,0x0F);
	DIO_VoidSetPortValue(PORT_KPD,0xFF);
}

u8 KPD_U8GetKey(void)
{
	u8 loc_u8pressedkey = NOT_PRESSED;
	u8 loc_u8column = 0;
	u8 loc_u8row = 0;
	/* looping on columns of the keypad*/
	for (loc_u8column = 0;loc_u8column<4;loc_u8column++)
	{
		/*activate the column*/
		DIO_VoidSetPinValue(PORT_KPD,loc_u8column,LOW);
		/* looping on rows of the keypad*/
		for(loc_u8row = 4;loc_u8row<8;loc_u8row++)
		{
			/*check if the key is pressed*/
			if (!DIO_U8GetPinValue(PORT_KPD,loc_u8row))
			{
				/* get the value of the key*/
				loc_u8pressedkey = loc_u8column + (loc_u8row - 4)*4;
				/*wait till the key is released*/
				while (!DIO_U8GetPinValue(PORT_KPD,loc_u8row));
				/*to avoid bouncing*/
				_delay_ms(10);
			}
		}
		/*deactivate column*/
		DIO_VoidSetPinValue(PORT_KPD,loc_u8column,HIGH);
	}
	return loc_u8pressedkey;
}
























