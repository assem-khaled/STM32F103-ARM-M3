/*
 * main.c
 *
 *  Created on: Aug 12, 2020
 *      Author: Assem
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SEVEN_SEG_interface.h"


int main()
{
	RCC_voidInitSysClock();
	/* Enable RCC for GPIOA */
	RCC_voidEnableClock(RCC_APB2, 2);
	/* Enable RCC for GPIOB */
	RCC_voidEnableClock(RCC_APB2, 3);
	/* Enable RCC for GPIOC */
	RCC_voidEnableClock(RCC_APB2, 4);


	SEVENSEG_voidInit();

	while(1)
	{
		SEVENSEG_voidCount(1000000); /* increment every 1 sec */
	}

	return 0;
}
