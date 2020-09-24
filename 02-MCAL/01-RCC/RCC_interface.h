/************************************************/
/* Author    : Assem Khaled					*/
/* Version   : V01							*/
/* Date      : 8 Aug 2020						*/
/*************************************************/
#ifndef _RCC_INTERFACE_H
#define _RCC_INTERFACE_H

#define MRCC_AHB	0
#define	MRCC_APB1	1
#define	MRCC_APB2	2

/* PORTS */
#define MRCC_AFIO	0
#define MRCC_PORTA	2
#define MRCC_PORTB	3
#define MRCC_PORTC	4

void MRCC_voidInitSysClock(void);
void MRCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void MRCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);


#endif
