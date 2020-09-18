/*************************************************/
/* Author    : Assem Khaled					*/
/* Version   : V01							*/
/* Date      : 15 Aug 2020						*/
/*************************************************/
#ifndef _SEVEN_SEG_INTERFACE_H
#define _SEVEN_SEG_INTERFACE_H

#define	SEVENSEG_ZERO    	0b00111111
#define SEVENSEG_ONE     	0b00000110
#define SEVENSEG_TWO     	0b01011011
#define SEVENSEG_THREE   	0b01001111
#define SEVENSEG_FOUR    	0b01100110
#define SEVENSEG_FIVE    	0b01101101
#define SEVENSEG_SIX     	0b01111101
#define SEVENSEG_SEVEN   	0b00000111
#define SEVENSEG_EIGHT   	0b01111111
#define SEVENSEG_NINE    	0b01101111
#define SEVENSEG_DOT     	0b10000000
#define SEVENSEG_TEST    	0b11111111


void SEVENSEG_voidInit();
void SEVENSEG_voidDisplay(u8 copy_u8Number);
void SEVENSEG_voidCount(u8 copy_u8Time);


#endif