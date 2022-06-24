/************************************************************/
/*  Author  : Hashim Sobhi                                 **/
/*  Date    : 13.3.2021                                    **/
/*  Version : 1.0                                          **/
/************************************************************/

#ifndef DIO_REGISTER_H
#define DIO_REGISTER_H

/*ENABLE PORTS*/
#define DDRA *((u8*)0x3A)
#define DDRB *((u8*)0x37)
#define DDRC *((u8*)0x34)
#define DDRD *((u8*)0x31)

/*OUTPUT REGISTERS */
#define PORTA *((u8*)0x3B)
#define PORTB *((u8*)0x38)
#define PORTC *((u8*)0x35)
#define PORTD *((u8*)0x32)

/*INPUT REGITERS*/
#define PINA *((u8*)0x39)
#define PINB *((u8*)0x36)
#define PINC *((u8*)0x33)
#define PIND *((u8*)0x30)



#endif