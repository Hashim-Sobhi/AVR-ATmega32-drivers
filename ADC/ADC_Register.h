/*  Author 	    : Hashim Sobhi                               **/
/*  Date    	: 10.5.2021                                 **/
/*  Description : Analog To Digital Registers                **/
/*  Version     : 1.1                                        **/
/***************************************************************/

#ifndef _ADC_REGISTER_H_
#define _ADC_REGISTER_H_

/*ADC Multiplexer Selection Register*/
#define ADMUX  *((u8*)0x27) 
/*ADC Control and Status Register A*/
#define ADCSRA *((u8*)0x26)
/*data registers*/
#define ADCL   *((u8*)0x24)
#define ADCH   *((u8*)0x25)
#define ADC_D  *((u16*)0x24)
/*only use in free running mode and its default for free running mode no need to write any thing */ 
#define SFIOR  *((u8*)0x50)

/*ADMUX PINS*/
/*REFS1&REFS0 reference selection bits*/
/*REFS1&REFS0:00 ==> AREF, Internal Vref turned off*/
/*REFS1&REFS0:01 ==> AVCC with external capacitor at AREF pin*/
/*REFS1&REFS0:10 ==> Reserved*/
/*REFS1&REFS0:11 ==> Internal 2.56V Voltage Reference with external capacitor at AREF pin*/
#define REFS1 7
#define REFS0 6
/*ADC Left Adjust Result*/
/*ADLAR :0 ==>the result is right adjust*/
/*ADLAR :1 ==>the result is left adjust */
#define ADLAR 5

/*ADCSRA PINS*/
/*ADC bit enable*/
#define ADEN 7
/*ADC start conversion bit*/
#define ADSC 6
/*ADC auto trigger*/
/*ADATE: 0==> single conversion */
/*ADATE: 1==> free running mode */
#define ADATE 5
/*ADC Interrupt Flag bit is set to 1 when conv completed*/
#define ADIF  4
/*ADC Interrupt Enable*/
/*ADIE: 0==> disable */
/*ADIE: 1==> enable */
#define ADIE 3




void (*ADC_CallBackFun)(void) = NULL;
void __vector_16(void) __attribute__ ((signal));


#endif