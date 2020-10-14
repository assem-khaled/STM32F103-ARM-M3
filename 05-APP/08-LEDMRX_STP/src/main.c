/*
 * main.c
 *
 *  Created on: Oct 14, 2020
 *      Author: Assem
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"
#include "DELAY_interface.h"


u8 hamada[]= {0, 144, 75, 63, 75, 144, 0, 0};
u8 DataArray67[] = {0, 60, 18, 18, 60, 0, 0, 46, 42, 58, 0, 0, 46, 42, 58, 0, 0, 62, 42, 42, 0, 0, 62, 4, 8, 4, 62, 0, 0, 0, 0, 62, 8, 20, 34, 0, 0, 62, 8, 8, 62, 0, 0, 60, 18, 18, 60, 0, 0, 62, 32, 0, 0, 62, 42, 42, 0, 0, 62, 34, 34, 28, 0, 0, 0, 0, 0};

u8 *HLEDMRX_u8Frame;
u8 HLEDMRX_u8CurrentIdx;
u8 HLEDMRX_u8Speed = 5;


// same as HLEDMRX_voidShift
void shift(u8 *Copy_u8Data, u8 Copy_u8ColNum)
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
			shift_display(Local_u8TempArr);
		}
	}
}

// same as Display(Local_u8TempArr)
void shift_display(u8 *Copy_u8Data)
{
	HLEDMRX_u8Frame = Copy_u8Data;

	/* Reset the frame Start */
	HLEDMRX_u8CurrentIdx = 0;

	//set row values
	u8 STP_u8rows = HLEDMRX_u8Frame[HLEDMRX_u8CurrentIdx];

	//enable all cols
	u8 STP_u8cols = 0xff;	// 0b 1111 1111
	CLR_BIT(STP_u8cols,HLEDMRX_u8CurrentIdx);	// 0b 1111 11(0)1 change the selected() column to 0

	u16 STP_u16RowsCols;
	STP_u16RowsCols = STP_u8rows*0x100;		// Change 0b 1100 0011 To >> 0b 1100 0011 0000 0000
	STP_u16RowsCols += STP_u8cols;			// Add the columns so 0b 1100 0011 0000 0000 To >> 0b 1100 0011 1111 1101

	HSTP_voidSendSynchronous(STP_u16RowsCols, 16);

	for(u8 i=0; i<8; i++)
	{
		DELAY_ms(2);
		DisplayNextColumn();
	}
}

// same as DisplayNextColumn
void DisplayNextColumn(void)
{
	HLEDMRX_u8CurrentIdx++;
	if (HLEDMRX_u8CurrentIdx == 8)
	{
		HLEDMRX_u8CurrentIdx = 0;
	}

	//set row values
	u8 STP_u8rows = HLEDMRX_u8Frame[HLEDMRX_u8CurrentIdx];

	//enable all cols
	u8 STP_u8cols = 0xff;	// 0b 1111 1111
	CLR_BIT(STP_u8cols,HLEDMRX_u8CurrentIdx);	// 0b 1111 11(0)1 change the selected() column to 0

	u16 STP_u16RowsCols;
	STP_u16RowsCols = STP_u8rows*0x100;		// Change 0b 1100 0011 To >> 0b 1100 0011 0000 0000
	STP_u16RowsCols += STP_u8cols;			// Add the columns so 0b 1100 0011 0000 0000 To >> 0b 1100 0011 1111 1101

	HSTP_voidSendSynchronous(STP_u16RowsCols, 16);
}



// same as HLEDMRX_voidDisplay
void LEDMRX_display(u8 *Copy_u8Data)
{
	HLEDMRX_u8Frame = Copy_u8Data;

	/* Reset the frame Start */
	HLEDMRX_u8CurrentIdx = 0;

	//set row values
	u8 STP_u8rows = HLEDMRX_u8Frame[HLEDMRX_u8CurrentIdx];

	//enable all cols
	u8 STP_u8cols = 0xff;
	CLR_BIT(STP_u8cols,HLEDMRX_u8CurrentIdx);
	u16 STP_u16RowsCols;
	STP_u16RowsCols = STP_u8rows*0x100;
	STP_u16RowsCols += STP_u8cols;
	HSTP_voidSendSynchronous(STP_u16RowsCols, 16);


	while(1)
	{
		DELAY_ms(2);

		// same as DisplayNextColumn
		HLEDMRX_u8CurrentIdx++;
		if (HLEDMRX_u8CurrentIdx == 8)
		{
			HLEDMRX_u8CurrentIdx = 0;
		}

		//set row values
		u8 STP_u8rows = HLEDMRX_u8Frame[HLEDMRX_u8CurrentIdx];

		//enable all cols
		u8 STP_u8cols = 0xff;	// 0b 1111 1111
		CLR_BIT(STP_u8cols,HLEDMRX_u8CurrentIdx);	// 0b 1111 11(0)1 change the selected() column to 0

		u16 STP_u16RowsCols;
		STP_u16RowsCols = STP_u8rows*0x100;		// Change 0b 1100 0011 To >> 0b 1100 0011 0000 0000
		STP_u16RowsCols += STP_u8cols;			// Add the columns so 0b 1100 0011 0000 0000 To >> 0b 1100 0011 1111 1101

		HSTP_voidSendSynchronous(STP_u16RowsCols, 16);
	}
}



void main()
{
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(MRCC_APB2, MRCC_APB2_PORTA);

	MSTK_voidInit();

	HSTP_voidInit();

	//LEDMRX_display(hamada);
	while(1)
	{
		shift(DataArray67, 67);
	}

}
