/*
 * main.c
 *
 *  Created on: Oct 8, 2020
 *      Author: Assem
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"

#include "DELAY_interface.h"
#include "DAC_interface.h"
#include "IR_interface.h"

#include "song.h"



void voidFreq1(void)
{
	MSTK_voidStopInterval();

	HDAC_voidChangeFrequency(80);
}

void voidFreq2(void)
{
	MSTK_voidStopInterval();

	HDAC_voidChangeFrequency(100);
}

void voidFreq3(void)
{
	MSTK_voidStopInterval();

	HDAC_voidChangeFrequency(120);
}

void voidFreq4(void)
{
	MSTK_voidStopInterval();

	HDAC_voidChangeFrequency(150);
}


void main(void)
{
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(MRCC_APB2, MRCC_PORTA);
	MRCC_voidEnableClock(MRCC_APB2, MRCC_PORTB);
	MRCC_voidEnableClock(MRCC_APB2, MRCC_AFIO);

	MSTK_voidInit();

	HDAC_voidInit();

	/* IR Initialization */
	HIR_voidInit(HIR_ONE, voidFreq1);
	HIR_voidInit(HIR_TWO, voidFreq2);
	HIR_voidInit(HIR_THREE, voidFreq3);
	HIR_voidInit(HIR_FOUR, voidFreq4);


	while(1)
	{
		HDAC_voidStart(Amaren_raw, 39660);
		DELAY_ms(1000);
	}

}
