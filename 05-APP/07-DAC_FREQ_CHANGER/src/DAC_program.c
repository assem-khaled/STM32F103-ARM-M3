/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V01								*/
/* Date      : 12 Sep 2020						*/
/************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "DAC_interface.h"
#include "DAC_private.h"
#include "DAC_config.h"


#define NULL (void*)0

static u8 *HDAC_u8Ptr = NULL;
static volatile u16 HDAC_u16Counter = 0;
static volatile u16 HDAC_u16Length = 0;
static volatile u16 HDAC_u16Ticks = DAC_Ticks;


void HDAC_voidInit(void)
{
	/* GPIO Initialization */
	MGPIO_voidSetPinDirection(DAC_PIN0, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(DAC_PIN1, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(DAC_PIN2, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(DAC_PIN3, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(DAC_PIN4, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(DAC_PIN5, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(DAC_PIN6, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(DAC_PIN7, OUTPUT_SPEED_2MHZ_PP);
}

void HDAC_voidStart(u8 *Copy_u8Ptr, u16 Copy_u16Length)
{
	HDAC_u8Ptr = Copy_u8Ptr;
	HDAC_u16Length = Copy_u16Length;

	/* Start SysTick */
	MSTK_voidSetIntervalPeriodic(HDAC_u16Ticks, voidSetDAC);
}

void HDAC_voidStop(void)
{
	MSTK_voidStopInterval();
}

void HDAC_voidChangeFrequency(u16 Copy_u16Ticks)
{
	HDAC_u16Ticks = Copy_u16Ticks;
}


void voidSetDAC(void)
{
	MGPIO_voidSetPinValue(DAC_PIN0, GET_BIT(HDAC_u8Ptr[HDAC_u16Counter], 0));
	MGPIO_voidSetPinValue(DAC_PIN1, GET_BIT(HDAC_u8Ptr[HDAC_u16Counter], 1));
	MGPIO_voidSetPinValue(DAC_PIN2, GET_BIT(HDAC_u8Ptr[HDAC_u16Counter], 2));
	MGPIO_voidSetPinValue(DAC_PIN3, GET_BIT(HDAC_u8Ptr[HDAC_u16Counter], 3));
	MGPIO_voidSetPinValue(DAC_PIN4, GET_BIT(HDAC_u8Ptr[HDAC_u16Counter], 4));
	MGPIO_voidSetPinValue(DAC_PIN5, GET_BIT(HDAC_u8Ptr[HDAC_u16Counter], 5));
	MGPIO_voidSetPinValue(DAC_PIN6, GET_BIT(HDAC_u8Ptr[HDAC_u16Counter], 6));
	MGPIO_voidSetPinValue(DAC_PIN7, GET_BIT(HDAC_u8Ptr[HDAC_u16Counter], 7));

	HDAC_u16Counter++;

	if(HDAC_u16Counter==HDAC_u16Length)
	{
		HDAC_u16Counter=0;

#if DAC_MODE == DAC_MODE_ONE_TIME
		/* Stop DAC */
		HDAC_voidStop();
#endif
	}
}
