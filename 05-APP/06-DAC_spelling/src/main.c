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

#include "hello.h"
#include "help.h"
#include "hungry.h"
#include "water.h"


void voidHello(void)
{
	MSTK_voidStopInterval();
	HDAC_voidStart(Hello_raw, 5426);
}

void voidHelp(void)
{
	MSTK_voidStopInterval();
	HDAC_voidStart(Help_raw, 4671);
}

void voidHungry(void)
{
	MSTK_voidStopInterval();
	HDAC_voidStart(Hungry_raw, 5707);
}

void voidWater(void)
{
	MSTK_voidStopInterval();
	HDAC_voidStart(Water_raw, 4479);
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
	HIR_voidInit(HIR_ONE, voidHello);
	HIR_voidInit(HIR_TWO, voidHelp);
	HIR_voidInit(HIR_THREE, voidHungry);
	HIR_voidInit(HIR_FOUR, voidWater);

	while(1)
	{


	}

}
