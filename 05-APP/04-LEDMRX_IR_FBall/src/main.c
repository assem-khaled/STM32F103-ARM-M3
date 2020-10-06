/*
 * main.c
 *
 *  Created on: Sep 30, 2020
 *      Author: Assem
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"

#include "IR_interface.h"
#include "LEDMRX_interface.h"


u8 state1[]= {0, 152, 75, 63, 75, 144, 128, 0};
u8 state2[]= {0, 152, 75, 63, 75, 80, 64, 0, 0, 152, 75, 63, 75, 144, 32, 0, 0, 152, 75, 63, 75, 144, 16, 0, 0, 152, 75, 63, 75, 144, 8, 0, 0, 152, 75, 63, 75, 144, 4, 0, 0, 152, 75, 63, 75, 144, 2, 0, 0, 152, 75, 63, 75, 144, 2, 0, 0, 152, 75, 63, 75, 144, 4, 0, 0, 152, 75, 63, 75, 144, 8, 0, 0, 152, 75, 63, 75, 144, 16, 0, 0, 152, 75, 63, 75, 144, 32, 0, 0, 152, 75, 63, 75, 144, 64, 0, 0, 152, 75, 63, 75, 144, 128, 0};

void football(void)
{
	HLEDMRX_voidAnimation(state2, 104);
}


void main()
{
	/* Initialize RCC */
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(MRCC_APB2, MRCC_PORTA);
	MRCC_voidEnableClock(MRCC_APB2, MRCC_PORTB);
	MRCC_voidEnableClock(MRCC_APB2, MRCC_AFIO);

	/* SysTick Initialization */
	MSTK_voidInit();

	/* LED Matrix Initialization */
	HLEDMRX_voidInit();

	HIR_voidInit(HIR_POWER, football);

	while(1)
	{
		HLEDMRX_voidDisplay(state1);
	}

}
