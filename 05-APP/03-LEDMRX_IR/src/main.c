/*
 * main.c
 *
 *  Created on: Sep 31, 2020
 *      Author: Assem
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "AFIO_interface.h"

#include "IR_interface.h"
#include "LEDMRX_interface.h"

u8 DataArray64[] = {60, 18, 18, 60, 0, 0, 46, 42, 58, 0, 0, 46, 42, 58, 0, 0, 62, 42, 42, 0, 0, 62, 4, 8, 4, 62, 0, 0, 0, 0, 62, 8, 20, 34, 0, 0, 62, 8, 8, 62, 0, 0, 60, 18, 18, 60, 0, 0, 62, 32, 0, 0, 62, 42, 42, 0, 0, 62, 34, 34, 28, 0, 255, 0};

void Speed_up(void)
{
	HLEDMRX_voidSpeedUp();
}

void Speed_down(void)
{
	HLEDMRX_voidSpeedDown();
}

void Pause(void)
{
	HLEDMRX_voidPause();
}

void Start(void)
{
	HLEDMRX_voidPlay();
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

	/* IR Initialization */
	HIR_voidInit(HIR_LEFT, Speed_down);
	HIR_voidInit(HIR_RIGHT, Speed_up);
	HIR_voidInit(HIR_PLAY, Start);
	HIR_voidInit(HIR_POWER, Pause);


	while(1)
	{
		HLEDMRX_voidShift(DataArray64, 64);
	}

}
