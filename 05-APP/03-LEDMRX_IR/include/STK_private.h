/*************************************************/
/* Author    : Assem Khaled					*/
/* Version   : V01							*/
/* Date      : 26 Aug 2020						*/
/*************************************************/
#ifndef _STK_PRIVATE_H
#define _STK_PRIVATE_H


typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
}MSTK_t;

#define MSTK	((volatile MSTK_t*)0xE000E010)

/* SysTick Clock source selection */
#define MSTK_AHB	1
#define MSTK_AHB_8	0

#define	MSTK_SINGLE_INTERVAL    0
#define	MSTK_PERIOD_INTERVAL    1

#endif
