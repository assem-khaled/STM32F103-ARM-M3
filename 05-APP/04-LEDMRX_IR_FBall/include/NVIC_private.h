/*************************************************/
/* Author    : Assem Khaled					*/
/* Version   : V01							*/
/* Date      : 19 Aug 2020						*/
/*************************************************/
#ifndef _NVIC_PRIVATE_H
#define _NVIC_PRIVATE_H


#define NVIC_ISER0 		*((volatile u32*)0xE000E100) // Enable External interrupts from 0 to 31
#define NVIC_ISER1 		*((volatile u32*)0xE000E104) // Enable External interrupts from 32 to 63

#define NVIC_ICER0		*((volatile u32*)0xE000E180) // Disable External interrupts from 0 to 31
#define NVIC_ICER1 		*((volatile u32*)0xE000E184) // Disable External interrupts from 32 to 63

#define NVIC_ISPR0		*((volatile u32*)0xE000E200) // Changes interrupt state to pending from 0 to 31
#define NVIC_ISPR1 		*((volatile u32*)0xE000E204) // Changes interrupt state to pending from 32 to 63

#define NVIC_ICPR0		*((volatile u32*)0xE000E280) // Removes the pending state of an interrupt from 0 to 31
#define NVIC_ICPR1 		*((volatile u32*)0xE000E284) // Removes the pending state of an interrupt from 32 to 63

#define NVIC_IABR0 		*((volatile u32*)0xE000E300) // corresponding interrupt is active or active and pending => 1, Interrupt not active => 0
#define NVIC_IABR1 		*((volatile u32*)0xE000E304) // corresponding interrupt is active or active and pending => 1, Interrupt not active => 0

#define NVIC_IPR		((volatile u8*)0xE000E400)


/* in (SCB => AIRCR) 4 bits for group and 0 sub => 4bits in (IPR) to determine group number	*/
#define		NVIC_GROUP4_SUB0		0x05FA0300
/* in (SCB => AIRCR) 3 bits for Group and 1 bit for sub										*/
#define		NVIC_GROUP3_SUB1		0x05FA0400
/* in (SCB => AIRCR) 2 bits for Group and 2 bit for sub										*/
#define		NVIC_GROUP2_SUB2		0x05FA0500
/* in (SCB => AIRCR) 1 bits for Group and 3 bit for sub										*/
#define		NVIC_GROUP1_SUB3		0x05FA0600
/* in (SCB => AIRCR) 0 group for 4 bits for sub											*/
#define		NVIC_GROUP0_SUB4		0x05FA0700

#endif
