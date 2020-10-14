/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V02								*/
/* Date      : 8 Aug 2020						*/
/************************************************/
#ifndef _RCC_INTERFACE_H
#define _RCC_INTERFACE_H


#define MRCC_AHB	0
#define	MRCC_APB1	1
#define	MRCC_APB2	2

/* APB2 Clock Enable */
#define MRCC_APB2_AFIO		0
#define MRCC_APB2_PORTA		2
#define MRCC_APB2_PORTB		3
#define MRCC_APB2_PORTC		4
/* AHB Clock Enable */
#define MRCC_AHB_DMA1		0


void MRCC_voidInitSysClock(void);
void MRCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void MRCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);


#endif
