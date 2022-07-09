/***************************************************************/
/*  Author 	 : Hashim Sobhi                                 **/
/*  Date    	 : 17.4.2021                                   **/
/*  Description: LCD driver 	(program file)                    **/
/*  Version 	 : 1.0                                          **/
/***************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "LCD_Config.h"
#include <avr/delay.h>
void LCD_VoidInit(void)
{
	/*power on*/
	/*enable port C for data*/
	DIO_VoidSetPortDirection(DATA_PORT,OUTPUT_PORT);
	/*enable RS pin*/ 
	DIO_VoidSetPinDirection(CONTROL_PORT,RS,OUTPUT_PIN);
	/*enable RW pin*/ 
	DIO_VoidSetPinDirection(CONTROL_PORT,RW,OUTPUT_PIN);
	/*enable E pin*/ 
	DIO_VoidSetPinDirection(CONTROL_PORT,E,OUTPUT_PIN);
	
	/*wait for more than 30 ms after Vdd rises to 4.5V*/
	_delay_ms(40);
	
	/*functiom set*/
	/*set data length*/
	#if LCD_8bit == ON
	u8 local_u8funset = LCD_FunctionSet8Bit;
	/*set number of display lines*/
	#if LCD_2lines == ON
	SET_BIT(local_u8funset,N);
	#elif LCD_1lines == ON
	CLR_BIT(local_u8funset,N);
	#endif
	/*set character font*/
	#if LCD_5x10 == ON
	SET_BIT(local_u8funset,F);
	#elif LCD_5x8 == ON
	CLR_BIT(local_u8funset,F);
	#endif
	/*send function set commmand*/
	LCD_VoidSendCommand(local_u8funset);
	#endif
	
	/*wait for more than 39us*/
	_delay_us(100);
	
	/*display control*/
	u8 local_u8dis = LCD_DISPALYON;
	#if CURSOR_DISPLAY == ON
	SET_BIT(local_u8dis,C);
	#endif
	#if CURSOR_BLINK == ON
	SET_BIT(local_u8dis,B);
	#endif
	/*send display control command*/
	LCD_VoidSendCommand(local_u8dis);
	
	/*wait for more than 39us*/
	_delay_us(100);
	
	/*display clear*/
	LCD_VoidSendCommand(LCD_CLEAR);
	
	/*wait for more than 39us*/
	_delay_ms(2);
	
	/*entry mode set*/
	#if CURSOR_INCREMENT == ON
	LCD_VoidSendCommand(LCD_INCREMENT);
	#elif CURSOR_DECREMENT == ON
	LCD_VoidSendCommand(LCD_DECREMENT);
	#endif	
	
	/*wait for more than 39us*/
	_delay_us(100);
}

void LCD_VoidSendCommand(u8 copy_u8command)
{
	/*clear RS to write command*/
	DIO_VoidSetPinValue(CONTROL_PORT,RS,LOW);
	/*clear R\w to write*/
	DIO_VoidSetPinValue(CONTROL_PORT,RW,LOW);
	/*send command*/
	DIO_VoidSetPortValue(DATA_PORT,copy_u8command);
	//Enable sequence
	DIO_VoidSetPinValue(CONTROL_PORT,E,HIGH);
	_delay_ms(1);
	DIO_VoidSetPinValue(CONTROL_PORT,E,LOW);
	_delay_ms(2);
}

void LCD_VoidSendData(u8 copy_u8data)
{
	/*set RS to write command*/
	DIO_VoidSetPinValue(CONTROL_PORT,RS,HIGH);
	/*clear R\w to write*/
	DIO_VoidSetPinValue(CONTROL_PORT,RW,LOW);
	/*send data*/
	DIO_VoidSetPortValue(DATA_PORT,copy_u8data);
	//Enable sequence
	DIO_VoidSetPinValue(CONTROL_PORT,E,HIGH);
	_delay_ms(1);
	DIO_VoidSetPinValue(CONTROL_PORT,E,LOW);
	_delay_ms(2);
}

void LCD_VoidSendString(u8* copy_u8str)
{
	u8 local_u8counter = 0;
	while( copy_u8str[local_u8counter] != '\0')
	{
		LCD_VoidSendData(copy_u8str[local_u8counter]);
		local_u8counter++;
	}
}

void LCD_VoidSendNum(u32 copy_u32num)
{
	if (copy_u32num == 0)
	{
		LCD_VoidSendData('0');
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
			LCD_VoidSendData(local_u8num+48);
		} 	
	}	
}

void LCD_VoidSetPosition(u8 copy_u8row, u8 copy_u8col)
{
	if (copy_u8row == ROW_0)
	{
		LCD_VoidSendCommand(128+copy_u8col);		/*first location in DDRAM is 128*/
	}
	else if(copy_u8row == ROW_1)
	{
		LCD_VoidSendCommand(128+64+copy_u8col);     /*first location in DDRAM in row 1 is (128+64)*/
	}
}

void LCD_VoidShiftDisplay(u8 copy_u8dir, u8 copy_u8steps)
{
	if (copy_u8dir == SHIFT_LEFT)
	{
		while(copy_u8steps!=0)
		{
			LCD_VoidSendCommand(LCD_SHIFTLEFTDISPLAY);
			copy_u8steps--;
		}
	}
	if (copy_u8dir == SHIFT_RIGHT)
	{
		while(copy_u8steps!=0)
		{
			LCD_VoidSendCommand(LCD_SHIFTRIGHTDISPLAY);
			copy_u8steps--;
		}
	}
}
void LCD_VoidSetCGRAMAddress(u8 copy_u8location)
{
	/*no of lactions in CGRAM are 64*/
	LCD_VoidSendCommand(64+copy_u8location);
}







