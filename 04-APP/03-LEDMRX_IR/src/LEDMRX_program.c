/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V03								*/
/* Date      : 31  Aug 2020						*/
/************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"
#include "DELAY_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"


static u8 *HLEDMRX_u8Frame;
static u8 HLEDMRX_u8CurrentIdx;
static u8 HLEDMRX_u8Speed = LEDMRX_SHIFT_SPEED;

void HLEDMRX_voidInit(void)
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


void HLEDMRX_voidDisplay(u8 *Copy_u8Data)
{
	/* Save the desired Frame */
	HLEDMRX_u8Frame = Copy_u8Data;

	/* Reset the frame Start */
	HLEDMRX_u8CurrentIdx = 0;

	/* Display The first Column */
	DisableAllCols(); /* Disable all columns */
	SetRowValues(HLEDMRX_u8Frame[HLEDMRX_u8CurrentIdx]); /* Set Row values */
	EnableAllCols(HLEDMRX_u8CurrentIdx); /* Enable the desired column */

#if LEDMRX_DISPLAY_DELAY == LEDMRX_PERIODIC
	/* Start timer */
	MSTK_voidSetIntervalPeriodic(2500, DisplayNextColumn);


#elif	LEDMRX_DISPLAY_DELAY == LEDMRX_BUSY_WAIT
	MSTK_voidSetBusyWait(2500);
	DisplayNextColumn();

#elif	LEDMRX_DISPLAY_DELAY == LEDMRX_NOP
	while(1)
	{
		// Delay
		DELAY_ms(2);
		DisplayNextColumn();
	}

#else
	#error("You Chose Wrong Delay type")
#endif
}


void HLEDMRX_voidShift(u8 *Copy_u8Data, u8 Copy_u8ColNum)
{
	u8 Local_u8TempArr[8];
	u8 Local_u8Counter = 0;

	for(u8 Local_u8Counter2 = 0; Local_u8Counter2 < Copy_u8ColNum; Local_u8Counter2++)
	{
		Local_u8Counter = 0;
		for(u8 Local_u8Index = Local_u8Counter2 ;Local_u8Index < (Local_u8Counter2 + 8); Local_u8Index++)
		{
			/* Save the data in the Array */
			if(Local_u8Index > Copy_u8ColNum-1)
			{
				Local_u8TempArr[Local_u8Counter] = Copy_u8Data[(Local_u8Index-Copy_u8ColNum)]; /* Concatenate the beginning and the end of the array */
			}
			else
			{
				Local_u8TempArr[Local_u8Counter] = Copy_u8Data[Local_u8Index];
			}

			Local_u8Counter++;
		}
		/* Display the current array for a given number of times (the bigger *Local_u8Counter3*, the slower the LED Matrix shifts) */
		for(u8 Local_u8Counter3 = 0; Local_u8Counter3 < HLEDMRX_u8Speed+1; Local_u8Counter3++)
		{
			Display(Local_u8TempArr);
		}
	}
}


void HLEDMRX_voidAnimation(u8 *Copy_u8Data, u8 Copy_u8ColNum)
{
	u8 Local_u8TempArr[8];
	u8 Local_u8Counter = 0;
	u8 Local_u8Index = 0;


	for(Local_u8Counter = 1; Local_u8Counter <= Copy_u8ColNum; Local_u8Counter++)
	{
		Local_u8TempArr[Local_u8Index] = Copy_u8Data[Local_u8Counter-1];
		Local_u8Index++;

		if( (Local_u8Counter % 8) == 0 )
		{
			Local_u8Index = 0;

			/* Display the current array for a given number of times (the bigger *Local_u8Counter3*, the slower the LED Matrix shifts) */
			for(u8 Local_u8Counter3 = 0; Local_u8Counter3 < HLEDMRX_u8Speed+1; Local_u8Counter3++)
			{
				Display(Local_u8TempArr);
			}
		}
	}
}

void HLEDMRX_voidSpeedUp(void)
{
	if (HLEDMRX_u8Speed > 2)
		HLEDMRX_u8Speed -= 2;
}

void HLEDMRX_voidSpeedDown(void)
{
	HLEDMRX_u8Speed += 2;
}

void HLEDMRX_voidPause(void)
{
	HLEDMRX_u8Speed = 255;
}

void HLEDMRX_voidPlay(void)
{
	HLEDMRX_u8Speed = HLEDMRX_SHIFT_SPEED_MEDIUM;
}

void Display(u8 *Copy_u8Data)
{
	/* Save the desired Frame */
	HLEDMRX_u8Frame = Copy_u8Data;

	/* Reset the frame Start */
	HLEDMRX_u8CurrentIdx = 0;

	/* Display The first Column */
	DisableAllCols(); /* Disable all columns */
	SetRowValues(HLEDMRX_u8Frame[HLEDMRX_u8CurrentIdx]); /* Set Row values */
	EnableAllCols(HLEDMRX_u8CurrentIdx); /* Enable the desired column */

	for(u8 i=0; i<8; i++)
	{
	#if	LEDMRX_SHIFT_ANIMATION_DELAY == LEDMRX_BUSY_WAIT

		MSTK_voidStopInterval();
		/* Start timer */
		MSTK_voidSetBusyWait(2500);
		DisplayNextColumn();

	#elif	LEDMRX_SHIFT_ANIMATION_DELAY == LEDMRX_NOP

		// Delay
		DELAY_ms(2);
		DisplayNextColumn();

	#else
		#error("You Chose Wrong Delay type")

	#endif
	}
}

void DisplayNextColumn(void)
{
	HLEDMRX_u8CurrentIdx++;
	if (HLEDMRX_u8CurrentIdx == 8)
	{
		HLEDMRX_u8CurrentIdx = 0;
	}

	/* Dislay The first Column */
	DisableAllCols(); /* Disable all columns */
	SetRowValues(HLEDMRX_u8Frame[HLEDMRX_u8CurrentIdx]); /* Set Row values */
	EnableAllCols(HLEDMRX_u8CurrentIdx); /* Enable the desired column */
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

static void EnableAllCols(u8 Copy_u8Col)
{
	/* Enable the desired pin only */
	switch (Copy_u8Col)
	{
		case 0: MGPIO_voidSetPinValue(LEDMRX_C0_PIN,GPIO_LOW); break;
		case 1: MGPIO_voidSetPinValue(LEDMRX_C1_PIN,GPIO_LOW); break;
		case 2: MGPIO_voidSetPinValue(LEDMRX_C2_PIN,GPIO_LOW); break;
		case 3: MGPIO_voidSetPinValue(LEDMRX_C3_PIN,GPIO_LOW); break;
		case 4: MGPIO_voidSetPinValue(LEDMRX_C4_PIN,GPIO_LOW); break;
		case 5: MGPIO_voidSetPinValue(LEDMRX_C5_PIN,GPIO_LOW); break;
		case 6: MGPIO_voidSetPinValue(LEDMRX_C6_PIN,GPIO_LOW); break;
		case 7: MGPIO_voidSetPinValue(LEDMRX_C7_PIN, GPIO_LOW); break;
	}
}

static void SetRowValues(u8 Copy_u8Value)
{
	u8 Local_u8Idx;
	u8 Local_u8Bit[8];
	for (Local_u8Idx =0; Local_u8Idx<8;Local_u8Idx++)
	{
		Local_u8Bit[Local_u8Idx] = GET_BIT(Copy_u8Value,Local_u8Idx);
	}

	MGPIO_voidSetPinValue(LEDMRX_R0_PIN, Local_u8Bit[0]);
	MGPIO_voidSetPinValue(LEDMRX_R1_PIN, Local_u8Bit[1]);
	MGPIO_voidSetPinValue(LEDMRX_R2_PIN, Local_u8Bit[2]);
	MGPIO_voidSetPinValue(LEDMRX_R3_PIN, Local_u8Bit[3]);
	MGPIO_voidSetPinValue(LEDMRX_R4_PIN, Local_u8Bit[4]);
	MGPIO_voidSetPinValue(LEDMRX_R5_PIN, Local_u8Bit[5]);
	MGPIO_voidSetPinValue(LEDMRX_R6_PIN, Local_u8Bit[6]);
	MGPIO_voidSetPinValue(LEDMRX_R7_PIN, Local_u8Bit[7]);

}


