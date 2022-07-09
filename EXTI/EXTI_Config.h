/***************************************************************/
/*  Author 	  : Hashim Sobhi                               **/
/*  Date    	  : 1.5.2021                                  **/
/*  Description  : External Interrupt configration            **/
/*  Version 	  : 1.1                                        **/
/***************************************************************/


#ifndef _EXTI_CONFIG_H_
#define _EXTI_CONFIG_H_

/*enable ints*/
#define INT0_ENABLE  ENABLE
#define INT1_ENABLE  ENABLE
#define INT2_ENABLE  DISABLE

/*modes*/
#define LOW_LEVEL     0
#define OCH           1
#define FALLING_EDGE  2
#define RISING_EDGE   3

/*choose INT0 & INT 1 mode */
#define INT0_MODE  LOW_LEVEL
#define INT1_MODE  OCH
/*choose INT2 mode */
#define INT2_MODE  FALLING_EDGE



#define ENABLE  1
#define DISABLE 0





#endif
