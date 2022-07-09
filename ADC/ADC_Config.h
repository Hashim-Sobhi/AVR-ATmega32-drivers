/*  Author 	     : Hashim Sobhi                               **/
/*  Date    	 : 10.5.2021                                 **/
/*  Description  : Analog To Digital Configrations            **/
/*  Version 	 : 1.1                                        **/
/***************************************************************/
#ifndef _ADC_CONFIG_H_
#define _ADC_CONFIG_H_

/*****************select Vref*********************/
#define REF_VOLTAGE   AVCC
/*ref voltage options*/
#define AREF            0
#define AVCC            1
#define INTERNAL_2260mV 2
/**************select left\right result **********/
#define ADC_RESULT  RIGHT
/*options*/
#define LEFT  0
#define RIGHT 1
/******************enable ADC*********************/
#define ADC_ENABLE ENABLE
/*options*/
#define ENABLE  1
#define DISABLE 0
/******************select mode********************/
#define ADC_MODE FREE_RUNNING
/*optins*/
#define SINGLE_CONV  0
#define FREE_RUNNING 1
/***************interrupt enable******************/
#define ADCI_ENABLE  ENABLE
/*options: 1-ENABLE
		   2-DISABLE
*/
/****************ADC prescalar********************/
#define ADC_PRESCALAR ADPS_128
/*options*/
/*ADPS_presecalar*/
#define ADPS_2   1
#define ADPS_4   2
#define ADPS_8   3
#define ADPS_16  4
#define ADPS_32  5
#define ADPS_64  6
#define ADPS_128 7
/*************************************************/

#endif
