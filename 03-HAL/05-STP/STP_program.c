/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V01								*/
/* Date      : 14 Sep 2020						*/
/************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"


void HSTP_voidInit(void)
{
	/* GPIO Initialization */
	MGPIO_voidSetPinDirection(HSTP_SERIAL_DATA, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(HSTP_SHIFT_CLOCK, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(HSTP_STORE_CLOCK, OUTPUT_SPEED_2MHZ_PP);
}

void HSTP_voidSendSynchronous(u16 Copy_u16DataToSend, u16 Copy_u16bitNo)
{
	s8 Local_s8Counter;
	u8 Local_u8Counter;
	for(Local_s8Counter = Copy_u16bitNo-1; Local_s8Counter >=0; Local_s8Counter--)
	{
		/* Send bit by bit starting from Most-Significant bit */
		Local_u8Counter = GET_BIT(Copy_u16DataToSend, Local_s8Counter);

		MGPIO_voidSetPinValue(HSTP_SERIAL_DATA,Local_u8Counter);

		/* Send Pulse to Shift clock */
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK, GPIO_HIGH);
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK, GPIO_LOW);
		MSTK_voidSetBusyWait(1);
	}
	/* Send Pulse to Store clock */
	MGPIO_voidSetPinValue(HSTP_STORE_CLOCK, GPIO_HIGH);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(HSTP_STORE_CLOCK, GPIO_LOW);
	MSTK_voidSetBusyWait(1);
}
