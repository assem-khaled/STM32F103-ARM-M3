/************************************************/
/* Author    : Assem Khaled					*/
/* Version   : V01							*/
/* Date      : 31  Aug 2020					*/
/************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"

void HLEDMAX_voidInit(void)
{
	/* Initialize Rows */
	MGPIO_voidSetPinDirection(LEDMRX_R0_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_R1_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_R2_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_R3_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_R4_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_R5_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_R6_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_R7_PIN, OUTPUT_SPEED_2MHZ_PP);
	
	/* Initialize Columns*/
	MGPIO_voidSetPinDirection(LEDMRX_C0_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_C1_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_C2_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_C3_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_C4_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_C5_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_C6_PIN, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_C7_PIN, OUTPUT_SPEED_2MHZ_PP);	
	
}

void HLEDMAX_voidDisplay(u8 *Copy_u8Data)
{
	while(1)
	{
		/* Column 0 */
		DisableAllCols();/* Disable all columns */
		SetRowValues(Copy_u8Data[0]); /* Set Row values */
		MGPIO_voidSetPinValue(LEDMRX_C0_PIN, GPIO_LOW);/* Enable Column 0 */
		MSTK_voidSetBusyWait(2500); /* Delay 2.5 M sec*/

		/* Column 1 */
		DisableAllCols();/* Disable all columns */
		SetRowValues(Copy_u8Data[1]); /* Set Row values */
		MGPIO_voidSetPinValue(LEDMRX_C1_PIN, GPIO_LOW);/* Enable Column */
		MSTK_voidSetBusyWait(2500); /* Delay 2.5 M sec*/
		
		/* Column 2 */
		DisableAllCols();/* Disable all columns */
		SetRowValues(Copy_u8Data[2]); /* Set Row values */
		MGPIO_voidSetPinValue(LEDMRX_C2_PIN, GPIO_LOW);/* Enable Column */
		MSTK_voidSetBusyWait(2500); /* Delay 2.5 M sec*/

		/* Column 3 */
		DisableAllCols();/* Disable all columns */
		SetRowValues(Copy_u8Data[3]); /* Set Row values */
		MGPIO_voidSetPinValue(LEDMRX_C3_PIN, GPIO_LOW);/* Enable Column */
		MSTK_voidSetBusyWait(2500); /* Delay 2.5 M sec*/

		/* Column 4 */
		DisableAllCols();/* Disable all columns */
		SetRowValues(Copy_u8Data[4]); /* Set Row values */
		MGPIO_voidSetPinValue(LEDMRX_C4_PIN, GPIO_LOW);/* Enable Column */
		MSTK_voidSetBusyWait(2500); /* Delay 2.5 M sec*/
		
		/* Column 5 */
		DisableAllCols();/* Disable all columns */
		SetRowValues(Copy_u8Data[5]); /* Set Row values */
		MGPIO_voidSetPinValue(LEDMRX_C5_PIN, GPIO_LOW);/* Enable Column */
		MSTK_voidSetBusyWait(2500); /* Delay 2.5 M sec*/

		/* Column 6 */
		DisableAllCols();/* Disable all columns */
		SetRowValues(Copy_u8Data[6]); /* Set Row values */
		MGPIO_voidSetPinValue(LEDMRX_C6_PIN, GPIO_LOW);/* Enable Column */
		MSTK_voidSetBusyWait(2500); /* Delay 2.5 M sec*/
		
		/* Column 7 */
		DisableAllCols();/* Disable all columns */
		SetRowValues(Copy_u8Data[7]); /* Set Row values */
		MGPIO_voidSetPinValue(LEDMRX_C7_PIN, GPIO_LOW);/* Enable Column */
		MSTK_voidSetBusyWait(2500); /* Delay 2.5 M sec*/
	}
}

static void DisableAllCols(void)
{
	/* Disable all columns */
	MGPIO_voidSetPinValue(LEDMRX_C0_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_C1_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_C2_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_C3_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_C4_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_C5_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_C6_PIN, GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMRX_C7_PIN, GPIO_HIGH);
}

static void SetRowValues(u8 Copy_u8Value)
{
	u8 Local_u8BIT = GET_BIT(Copy_u8Value, 0);
	MGPIO_voidSetPinValue(LEDMRX_R0_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value, 1);
	MGPIO_voidSetPinValue(LEDMRX_R1_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value, 2);
	MGPIO_voidSetPinValue(LEDMRX_R2_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value, 3);
	MGPIO_voidSetPinValue(LEDMRX_R3_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value, 4);
	MGPIO_voidSetPinValue(LEDMRX_R4_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value, 5);
	MGPIO_voidSetPinValue(LEDMRX_R5_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value, 6);
	MGPIO_voidSetPinValue(LEDMRX_R6_PIN, Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value, 7);
	MGPIO_voidSetPinValue(LEDMRX_R7_PIN, Local_u8BIT);
}

