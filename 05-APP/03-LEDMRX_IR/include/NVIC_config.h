/*************************************************/
/* Author    : Assem Khaled					*/
/* Version   : V01							*/
/* Date      : 19 Aug 2020						*/
/*************************************************/
#ifndef _NVIC_CONFIG_H
#define _NVIC_CONFIG_H


/* Options:	NVIC_GROUP4_SUB0	>>	in (SCB => AIRCR) 4 bits for group and 0 sub => 4bits in (IPR) to determine group number
			NVIC_GROUP3_SUB1	>>	in (SCB => AIRCR) 3 bits for Group and 1 bit for sub
			NVIC_GROUP2_SUB2	>>	in (SCB => AIRCR) 2 bits for Group and 2 bit for sub
			NVIC_GROUP1_SUB3	>>	in (SCB => AIRCR) 1 bits for Group and 3 bit for sub
			NVIC_GROUP0_SUB4	>>	in (SCB => AIRCR) 0 group and 4 bits for sub			*/
			
#define	NVIC_GROUP_SUB_DISTRIBUTION		NVIC_GROUP2_SUB2

#endif
