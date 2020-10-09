/*************************************************/
/* Author    : Assem Khaled					*/
/* Version   : V01							*/
/* Date      : 19 Aug 2020						*/
/*************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		NVIC_ISER0 = (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISER1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		/* Return Error */
	}
}

void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		NVIC_ICER0 = (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICER1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		/* Return Error */
	}
}


void MNVIC_voidSetPendingFlag (u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		NVIC_ISPR0 = (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISPR1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		/* Return Error */
	}
}

void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		NVIC_ICPR0 = (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICPR1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		/* Return Error */
	}
}


u8 MNVIC_u8GetActiveFlag (u8 Copy_u8IntNumber)
{
	u8 Local_u8Result;
	
	if (Copy_u8IntNumber <= 31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0, Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		Local_u8Result = GET_BIT(NVIC_IABR1, Copy_u8IntNumber);
	}
	else
	{
		/* Return Error */
	}
	return Local_u8Result;
}


void MNVIC_voidSetPriority (s8 Copy_s8IntID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority)
{						/* Ex : 0x05FA0400 3 Group & 1 sub priority */
	u8 Local_u8Priority = Copy_u8SubPriority|(Copy_u8GroupPriority<<((NVIC_GROUP_SUB_DISTRIBUTION - 0x05FA0300)/256));
	/* Core Peripheral */
	if(Copy_s8IntID < 0)
	{

	}
	/* External Peripheral */ /*EXTI0 = 6*/
	if(Copy_s8IntID >= 0)
	{
		NVIC_IPR[Copy_s8IntID] = Local_u8Priority << 4;
	}
	#define SCB_AIRCR		*((u32 *)0xE000ED0C)
	SCB_AIRCR = NVIC_GROUP_SUB_DISTRIBUTION;
}

/* delete later */
void MNVIC_voidInit(void)
{
	#define SCB_AIRCR		*((u32 *)0xE000ED0C)

	SCB_AIRCR = NVIC_GROUP_SUB_DISTRIBUTION ;
}
void MNVIC_voidSetPriority2(u8 Copy_PeripheralIdx, u8 Copy_u8Priority)
{
	NVIC_IPR[Copy_PeripheralIdx] = Copy_u8Priority;
}

/**/
