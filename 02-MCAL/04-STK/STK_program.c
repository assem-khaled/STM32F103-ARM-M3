/*************************************************/
/* Author    : Assem Khaled					*/
/* Version   : V01							*/
/* Date      : 26  Aug 2020					*/
/*************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"


/* Define Callback Global Variable */
static void (*MSTK_CallBack) (void);
/* Define Variable for interval mode */
static u8 MSTK_u8ModeOfInterval;

void MSTK_voidInit(void)
{
	#if MSTK_CLKSOURCE == MSTK_AHB
		MSTK->CTRL = 0x00000004;/* Set clock source AHB */
		
	#elif MSTK_CLKSOURCE == MSTK_AHB_8
		MSTK->CTRL = 0;/* Set clock source AHB/8 */
		
	#else
		#error("You Chose Wrong Clock type")
	
	#endif
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	/* Load ticks to load register */
	MSTK->LOAD = Copy_u32Ticks;
	/* Start Timer */
	SET_BIT(MSTK->CTRL, 0);
	
	while(!GET_BIT(MSTK->CTRL, 16))
		asm("NOP");
	
	/* Stop Timer */
	CLR_BIT(MSTK->CTRL, 0);
	MSTK->LOAD = 0;
	MSTK->VAL = 0;
}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* Load ticks to load register */
	MSTK->LOAD = Copy_u32Ticks;
	/* SysTick exception request enable */
	SET_BIT(MSTK->CTRL, 1);
	/* Start Timer */
	SET_BIT(MSTK->CTRL, 0);
	/* Save CallBack */
	MSTK_CallBack = Copy_ptr;
	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;
}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* Load ticks to load register */
	MSTK->LOAD = Copy_u32Ticks;
	/* SysTick exception request enable */
	SET_BIT(MSTK->CTRL, 1);
	/* Start Timer */
	SET_BIT(MSTK->CTRL, 0);
	/* Save CallBack */
	MSTK_CallBack = Copy_ptr;
	/* Set Mode to Periodic */
	MSTK_u8ModeOfInterval = MSTK_PERIOD_INTERVAL;
}

void MSTK_voidStopInterval(void)
{
	/* Disable SysTick Interrupt */
	CLR_BIT(MSTK->CTRL, 1);
	/* Stop Timer */
	CLR_BIT(MSTK->CTRL, 0);
	MSTK->LOAD = 0;
	MSTK->VAL = 0;
}

u32  MSTK_u32GetElapsedTime(void)
{
	return (MSTK->LOAD - MSTK->VAL);
}

u32  MSTK_u32GetRemainingTime(void)
{
	return (MSTK->VAL);
}


void SysTick_Handler(void)
{
	u8 Local_u8Temporary;
	if(MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
		/* Disable SysTick Interrupt */
		CLR_BIT(MSTK->CTRL, 1);
		/* Stop Timer */
		CLR_BIT(MSTK->CTRL, 0);
		MSTK->LOAD = 0;
		MSTK->VAL = 0;
	}
	
	MSTK_CallBack();
	
	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(MSTK->CTRL,16);
}



