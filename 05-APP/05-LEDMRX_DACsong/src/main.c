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
#include "LEDMRX_interface.h"

#include "song.h"

u8 animation[]= {16, 203, 63, 203, 16, 0, 0, 0,
		0, 132, 75, 63, 75, 132, 0, 0,
		0, 132, 75, 63, 75, 132, 0, 0,
		0, 0, 16, 203, 63, 203, 16, 0,
		0, 0, 0, 132, 75, 63, 75, 132,
		0, 0, 16, 203, 63, 203, 16, 0,
		0, 132, 75, 63, 75, 132, 0, 0,
		0, 132, 75, 63, 75, 132, 0, 0
};

void main(void)
{
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(MRCC_APB2, MRCC_PORTA);
	MRCC_voidEnableClock(MRCC_APB2, MRCC_PORTB);

	MSTK_voidInit();

	HDAC_voidInit();
	HLEDMRX_voidInit();

	HDAC_voidStart(Amaren_raw, 39660);


	while(1)
	{
		HLEDMRX_voidAnimation(animation, 64);
	}

}
