/*
 * main.c
 *
 *  Created on: Sep 20, 2020
 *      Author: Assem
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"


int main()
{
	RCC_voidInitSysClock();
	/* Enable RCC for GPIOA */
	RCC_voidEnableClock(RCC_APB2, RCC_PORTA);

	/* Pin Modes */
	MGPIO_voidSetPinDirection(GPIOA, PIN0, OUTPUT_SPEED_2MHZ_PP); /* A0 Output PP 2MHz */
	MGPIO_voidSetPinDirection(GPIOA, PIN1, OUTPUT_SPEED_2MHZ_PP); /* A1 Output PP 2MHz */
	MGPIO_voidSetPinDirection(GPIOA, PIN2, OUTPUT_SPEED_2MHZ_PP); /* A2 Output PP 2MHz */
	MGPIO_voidSetPinDirection(GPIOA, PIN3, OUTPUT_SPEED_2MHZ_PP); /* A3 Output PP 2MHz */
	MGPIO_voidSetPinDirection(GPIOA, PIN4, OUTPUT_SPEED_2MHZ_PP); /* A4 Output PP 2MHz */
	MGPIO_voidSetPinDirection(GPIOA, PIN5, OUTPUT_SPEED_2MHZ_PP); /* A5 Output PP 2MHz */
	MGPIO_voidSetPinDirection(GPIOA, PIN6, OUTPUT_SPEED_2MHZ_PP); /* A6 Output PP 2MHz */
	MGPIO_voidSetPinDirection(GPIOA, PIN7, OUTPUT_SPEED_2MHZ_PP); /* A7 Output PP 2MHz */

	/* SysTick Initialization */
	MSTK_voidInit();


	while(1)
		{
			/* First Animation: Ping Pong*/
			for(u8 i = 0; i<4; i++)
			{
				for(u8 PIN = 0; PIN<8; PIN++)
				{
					MGPIO_voidSetPinValue(GPIOA, PIN, GPIO_HIGH);
					MSTK_voidSetBusyWait(200000); /* BusyWait */
					MGPIO_voidSetPinValue(GPIOA, PIN, GPIO_LOW);
				}
				for(u8 PIN = 6; PIN>=1; PIN--)
				{
					MGPIO_voidSetPinValue(GPIOA, PIN, GPIO_HIGH);
					MSTK_voidSetBusyWait(200000); /* BusyWait */
					MGPIO_voidSetPinValue(GPIOA, PIN, GPIO_LOW);
				}
			}
			MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_HIGH);
			MSTK_voidSetBusyWait(200000); /* BusyWait */
			MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_LOW);
			MSTK_voidSetBusyWait(200000); /* BusyWait */

			/* Second Animation: Fata7y ya warda xD */
			for(u8 i = 0; i<4; i++)
			{
				for(u8 PIN = 4; PIN<8; PIN++)
				{
					MGPIO_voidSetPinValue(GPIOA, PIN, GPIO_HIGH);
					MGPIO_voidSetPinValue(GPIOA, 7-PIN, GPIO_HIGH);
					MSTK_voidSetBusyWait(200000); /* BusyWait */
				}
				for(u8 PIN = 7; PIN>=1; PIN--)
				{
					MGPIO_voidSetPinValue(GPIOA, PIN, GPIO_LOW);
					MGPIO_voidSetPinValue(GPIOA, 7-PIN, GPIO_LOW);
					MSTK_voidSetBusyWait(200000); /* BusyWait */
				}
			}

			/* Third Animation: Flashing */
			for(u8 i = 0; i<8; i++)
			{
				MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN2, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN3, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN4, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN5, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN6, GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIOA, PIN7, GPIO_HIGH);
				MSTK_voidSetBusyWait(500000); /* BusyWait */
				MGPIO_voidSetPinValue(GPIOA, PIN0, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN1, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN2, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN3, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN4, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN5, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN6, GPIO_LOW);
				MGPIO_voidSetPinValue(GPIOA, PIN7, GPIO_LOW);
				MSTK_voidSetBusyWait(500000); /* BusyWait */
			}
		}

}
