/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V02								*/
/* Date      : 31  Aug 2020						*/
/************************************************/
#ifndef LEDMRX_INTERFACE_H
#define LEDMRX_INTERFACE_H


void HLEDMRX_voidInit(void);
void HLEDMRX_voidDisplay(u8 *Copy_u8Data);
void HLEDMRX_voidShift(u8 *Copy_u8Data, u8 Copy_u8ColNum);

#endif
