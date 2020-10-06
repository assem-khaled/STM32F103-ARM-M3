/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V01								*/
/* Date      : 31  Aug 2020						*/
/************************************************/
#include "STD_TYPES.h"

#include "DELAY_interface.h"
#include "DELAY_config.h"

void DELAY_ms(u32 Copy_u32Time_ms)
{
	u32 i;

	for(i = 0; i < (SYSTEMCORECLOCK/(12000)) * Copy_u32Time_ms; i++)
	{
		asm("NOP");
	}

}
