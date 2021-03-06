/************************************************/
/* Author    : Assem Khaled					*/
/* Version   : V01							*/
/* Date      : 8 Aug 2020						*/
/*************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void MRCC_voidInitSysClock(void)
{
	#if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
		RCC_CR	= 0x00010000; /* Enable HSEON -> HSE with no bypass */
		RCC_CFGR= 0x00000001;
	
	#elif RCC_CLOCK_TYPE == RCC_HSE_RC
		RCC_CR	= 0x00050000; /* Enable HSEON and HSEBYP -> HSE with no bypass */
		RCC_CFGR= 0x00000001;
	
	#elif RCC_CLOCK_TYPE == RCC_HSI
		RCC_CR 	= 0x00000081; /* Enable HSION + Triming = 0 */
		RCC_CFGR= 0x00000000;
	
	#elif RCC_CLOCK_TYPE == RCC_PLL
		#if RCC_PLL_INPUT = RCC_PLL_IN_HSI_DIV_2
		
		#elif RCC_PLL_INPUT = RCC_PLL_IN_HSE_DIV_2
		
		#elif RCC_PLL_INPUT = RCC_PLL_IN_HSE
		
		#endif
	
	#else
		#error("You Chose Wrong Clock type")
	#endif
}


void MRCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case MRCC_AHB	: SET_BIT(RCC_AHBENR, Copy_u8PerId);		break;
			case MRCC_APB1	: SET_BIT(RCC_APB1ENR, Copy_u8PerId);	break;
			case MRCC_APB2	: SET_BIT(RCC_APB2ENR, Copy_u8PerId);	break;
			//default			: /* Return Error */ 						break;
		}
	}
	else
	{
		/* Return Error */
	}
}

void MRCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if (Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
			case MRCC_AHB	: CLR_BIT(RCC_AHBENR, Copy_u8PerId);		break;
			case MRCC_APB1	: CLR_BIT(RCC_APB1ENR, Copy_u8PerId);	break;
			case MRCC_APB2	: CLR_BIT(RCC_APB2ENR, Copy_u8PerId);	break;
			//default			: /* Return Error */ 						break;
		}
	}
	else
	{
		/* Return Error */
	}
}
