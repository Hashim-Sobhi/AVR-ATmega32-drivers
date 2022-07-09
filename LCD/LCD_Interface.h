/***************************************************************/
/*  Author 	 : Hashim Sobhi                                 **/
/*  Date    	 : 17.4.2021                                    **/
/*  Description: LCD driver 	(interface file)		          **/
/*  Version 	 : 1.0                                          **/
/***************************************************************/

#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_

/*data port*/
#define DATA_PORT PORT_C
/*control port*/
#define CONTROL_PORT PORT_D
/*contrl pins*/
#define RS PIN_2
#define RW PIN_1
#define E  PIN_0

/*lcd rows*/
#define ROW_0  0
#define ROW_1  1

/*shift the display lcd*/
#define SHIFT_LEFT  0
#define SHIFT_RIGHT 1

/*commands*/
#define LCD_FunctionSet8Bit 0x30
#define LCD_DISPALYOFF      0x08
#define LCD_DISPALYON       0x0C
#define LCD_CLEAR           0x01
#define LCD_ENTRYMODE       0x06
#define LCD_INCREMENT       0x06
#define LCD_DECREMENT       0x04
#define LCD_RETURNHOME      0x02
#define LCD_SHIFTLEFTDISPLAY  0x18
#define LCD_SHIFTRIGHTDISPLAY 0x1C
/*function set*/
#define N  3
#define F  2
/*display control*/
#define C  1
#define B  0





void LCD_VoidInit(void);
void LCD_VoidSendCommand(u8 copy_u8command);
void LCD_VoidSendData(u8 copy_u8data);
void LCD_VoidSendString(u8* copy_u8str);
void LCD_VoidSendNum(u32 copy_u32num);
void LCD_VoidSetPosition(u8 copy_u8row, u8 copy_u8col);
void LCD_VoidShiftDisplay(u8 copy_u8dir, u8 copy_u8steps);
void LCD_VoidSetCGRAMAddress(u8 copy_u8location);
#endif