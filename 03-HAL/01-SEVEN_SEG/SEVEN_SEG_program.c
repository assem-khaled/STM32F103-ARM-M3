/*************************************************/
/* Author    : Assem Khaled					*/
/* Version   : V02							*/
/* Date      : 15 Aug 2020						*/
/*************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"
#include "SEVEN_SEG_interface.h"


static u8 Numbers[10]={SEVENSEG_ZERO,SEVENSEG_ONE,SEVENSEG_TWO,SEVENSEG_THREE,SEVENSEG_FOUR,SEVENSEG_FIVE,SEVENSEG_SIX,SEVENSEG_SEVEN,SEVENSEG_EIGHT,SEVENSEG_NINE};

void SEVENSEG_voidInit()
{
		/* PINA0~7 output push pull 10 MHZ */
	MGPIO_voidSetPinDirection(GPIOA, PIN0, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN1, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN2, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN3, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN4, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN5, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN6, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA, PIN7, OUTPUT_SPEED_10MHZ_PP);

}

void SEVENSEG_voidDisplay(u8 copy_u8Number)
{
		/* Display the number */
	MGPIO_voidSetPinValue(GPIOA, PIN0, GET_BIT(copy_u8Number,0));
	MGPIO_voidSetPinValue(GPIOA, PIN1, GET_BIT(copy_u8Number,1));
	MGPIO_voidSetPinValue(GPIOA, PIN2, GET_BIT(copy_u8Number,2));
	MGPIO_voidSetPinValue(GPIOA, PIN3, GET_BIT(copy_u8Number,3));
	MGPIO_voidSetPinValue(GPIOA, PIN4, GET_BIT(copy_u8Number,4));
	MGPIO_voidSetPinValue(GPIOA, PIN5, GET_BIT(copy_u8Number,5));
	MGPIO_voidSetPinValue(GPIOA, PIN6, GET_BIT(copy_u8Number,6));
	MGPIO_voidSetPinValue(GPIOA, PIN7, GET_BIT(copy_u8Number,7));
}

void SEVENSEG_voidCount(u32 copy_u32Time)
{
	u8 i ;
	
	void SEVENSEG_voidInit();
	
	for (i=0;i<10;i++)
	{
		SEVENSEG_voidDisplay(Numbers[i]);
		/* Delay */
		
		/* SysTick Initialization */
		MSTK_voidInit();
		MSTK_voidSetBusyWait(copy_u32Time); /* BusyWait */
	}
	
}
