/************************************************/
/* Author    : Assem Khaled					*/
/* Version   : V02							*/
/* Date      : 22 Aug 2020						*/
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"


static void (*EXTI_CallBack[16]) (void)  ;

void MEXTI_voidInit(void)
{
	#if 	EXIT_SENSE_MODE == MEXTI_RISING
	SET_BIT(EXTI -> RTSR, EXTI_LINE);
	
	#elif 	EXIT_SENSE_MODE == MEXTI_FALLING
	SET_BIT(EXTI -> FTSR, EXTI_LINE);
	
	#elif 	EXIT_SENSE_MODE == MEXTI_ON_CHANGE
	SET_BIT(EXTI -> RTSR, EXTI_LINE);
	SET_BIT(EXTI -> FTSR, EXTI_LINE);
	
	#else	
	#error("Wrong Mode and Line Choice")

	#endif
	
	/* Disable interrupt */
	CLR_BIT(EXTI -> IMR, EXTI_LINE);
}

void MEXTI_voidSetSignalLatch(u8 Copy_u8EXTILine, u8 Copy_u8EXTISenseMode)
{
	switch(Copy_u8EXTISenseMode)
	{
		case MEXTI_RISING		:	SET_BIT(EXTI -> RTSR, Copy_u8EXTILine);
									break;
		
		case MEXTI_FALLING		:	SET_BIT(EXTI -> FTSR, Copy_u8EXTILine);
									break;
		
		case MEXTI_ON_CHANGE	:	SET_BIT(EXTI -> RTSR, Copy_u8EXTILine);
									SET_BIT(EXTI -> FTSR, Copy_u8EXTILine);
									break;
	}
}

void MEXTI_voidEnableEXTI(u8 Copy_u8EXTILine)
{
	SET_BIT(EXTI -> IMR, Copy_u8EXTILine);
}

void MEXTI_voidDisableEXTI(u8 Copy_u8EXTILine)
{
	CLR_BIT(EXTI -> IMR, Copy_u8EXTILine);
}

void MEXTI_voidSWTrigger(u8 Copy_u8EXTILine)
{
	SET_BIT(EXTI -> SWIER, Copy_u8EXTILine);
}

void MEXTI_voidSetCallBack(u8 Copy_u8EXTILine, void (*Copy_ptr) (void))
{
	EXTI_CallBack[Copy_u8EXTILine] = Copy_ptr;
}


/* Interrupt Request Handler */
void EXTI0_IRQHandler(void)
{
	EXTI_CallBack[0]();
	
	/* Clear Pending Bit */
	EXTI -> PR = 0b1;
}

void EXTI1_IRQHandler(void)
{
	EXTI_CallBack[1]();

	/* Clear Pending Bit */
	EXTI -> PR = 0b10;
}

void EXTI2_IRQHandler(void)
{
	EXTI_CallBack[2]();

	/* Clear Pending Bit */
	EXTI -> PR = 0b100;
}

void EXTI3_IRQHandler(void)
{
	EXTI_CallBack[3]();

	/* Clear Pending Bit */
	EXTI -> PR = 0b1000;
}

void EXTI4_IRQHandler(void)
{
	EXTI_CallBack[4]();

	/* Clear Pending Bit */
	EXTI -> PR = 0b10000;
}

void EXTI9_5_IRQHandler( void )
{
	/* Highest Priority:	LINE5
	 * Lowest Priority:		LINE9 	*/
	for( u8 exti = 5; exti <= 9; exti++ )
	    {
			if(GET_BIT(EXTI -> PR, exti) != 0)
			{
				EXTI_CallBack[exti]();

				/* Clear Pending Bit */
				EXTI -> PR = (1 << exti);
			}
	    }
}

void EXTI15_10_IRQHandler( void )
{
	/* Highest Priority:	LINE10
	 * Lowest Priority:		LINE15 	*/
	for( u8 exti = 10; exti <= 15; exti++ )
	    {
			if(GET_BIT(EXTI -> PR, exti) != 0)
			{
				EXTI_CallBack[exti]();

				/* Clear Pending Bit */
				EXTI -> PR = (1 << exti);
			}
	    }
}
