/*
 * main.c
 *
 *  Created on: Oct 20, 2020
 *      Author: Assem
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"

#include "TFT_interface.h"

#define size 2
u8 Local_u8TFT_sec = 46, Local_u8TFT_min = 53, Local_u8TFT_hr = 10, Local_u8TFT_AM = 0, Local_u8TFT_day = 13, Local_u8TFT_month = 7;
u16 Local_u16TFT_year = 2020 ;
u8 *week_days[7] = {"Friday" , "Saturday" , "Sunday" , "Monday" , "Tuesday" , "Wednesday" , "Thursday" };
u8 *year_month[12] = {"Jan", "Feb", "Mar", "Apr", "May",  "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

void voidIncCounter(void)
{
	Local_u8TFT_sec++;

	voidUpdateDate();
}

void voidUpdateDate(void)
{
	if(Local_u8TFT_sec >= 60)
	{
		Local_u8TFT_sec = Local_u8TFT_sec - 60;
		Local_u8TFT_min++;
	}
	else
	{
		// Time
		voidPrintTime();
		return;
	}

	if(Local_u8TFT_min >= 60)
	{
		Local_u8TFT_min = Local_u8TFT_min - 60;
		Local_u8TFT_hr++;
	}
	else
	{
		// Time
		voidPrintTime();
		return;
	}

	if(Local_u8TFT_hr >= 12)
	{
		Local_u8TFT_hr = Local_u8TFT_hr - 12;

		if(Local_u8TFT_AM == 0) // PM
		{
			Local_u8TFT_AM = 1; // Return to AM
			Local_u8TFT_day++; // increase the day
		}
		else	// AM
		{
			Local_u8TFT_AM = 0; // PM
		}
	}
	else
	{
		// Time
		voidPrintTime();
		return;
	}

	if(Local_u8TFT_day >= 29)
	{
		Local_u8TFT_day = Local_u8TFT_day - 28;	// Assume all months 28 days
		Local_u8TFT_month++;
	}
	else
	{
		// Time
		voidPrintTime();
		// Date
		voidPrintDate();
		voidPrintWeekDay();
		return;
	}

	if(Local_u8TFT_month >= 12)
	{
		Local_u8TFT_month = Local_u8TFT_month - 12;
		Local_u16TFT_year++;
	}
	// Time
	voidPrintTime();
	// Date
	voidPrintDate();
	voidPrintWeekDay();
}

void voidPrintTime(void)
{
	HTFT_voidDrawRect(0, 127, 90, 20, HTFT_COLOR_BLACK);	// Clear Old Time

	/* Print Hours */
	if (Local_u8TFT_hr<10)
	{
		HTFT_voidDrawChar('0', 120, 105, size, HTFT_COLOR_GREEN, HTFT_COLOR_BLACK);
		HTFT_voidDrawNum(Local_u8TFT_hr, 108, 105, size, HTFT_COLOR_GREEN, HTFT_COLOR_BLACK);
	}
	else
	{
		HTFT_voidDrawNum(Local_u8TFT_hr, 120, 105, size, HTFT_COLOR_GREEN, HTFT_COLOR_BLACK);
	}

	HTFT_voidDrawChar(':', 95, 105, size, HTFT_COLOR_GREEN, HTFT_COLOR_BLACK); // Print ":"

	/* Print Minutes */
	if (Local_u8TFT_min<10)
	{
		HTFT_voidDrawChar('0', 86, 105, size, HTFT_COLOR_GREEN, HTFT_COLOR_BLACK);
		HTFT_voidDrawNum(Local_u8TFT_min, 74, 105, size, HTFT_COLOR_GREEN, HTFT_COLOR_BLACK);
	}
	else
	{
		HTFT_voidDrawNum(Local_u8TFT_min, 86, 105, size, HTFT_COLOR_GREEN, HTFT_COLOR_BLACK);
	}

	HTFT_voidDrawChar(':', 62, 105, size, HTFT_COLOR_GREEN, HTFT_COLOR_BLACK); // Print ":"

	/* Print Seconds */
	if (Local_u8TFT_sec<10)
	{
		HTFT_voidDrawChar('0', 52, 105, size, HTFT_COLOR_GREEN, HTFT_COLOR_BLACK);
		HTFT_voidDrawNum(Local_u8TFT_sec, 40, 105, size, HTFT_COLOR_GREEN, HTFT_COLOR_BLACK);
	}
	else
	{
		HTFT_voidDrawNum(Local_u8TFT_sec, 52, 105, size, HTFT_COLOR_GREEN, HTFT_COLOR_BLACK);
	}

	/* Print AM / PM */
	if (Local_u8TFT_AM == 1)
	{
		HTFT_voidDrawText("AM", 25, 105, size, HTFT_COLOR_GREEN, HTFT_COLOR_BLACK);
	}
	else
	{
		HTFT_voidDrawText("PM", 25, 105, size, HTFT_COLOR_GREEN, HTFT_COLOR_BLACK);
	}
}

void voidPrintDate(void)
{
	HTFT_voidDrawRect(0, 127, 55, 20, HTFT_COLOR_BLACK); // Clear Old Date

	/* Print Day */
	if (Local_u8TFT_day<10)
	{
		HTFT_voidDrawChar('0', 124, 70, size, HTFT_COLOR_YELLOW, HTFT_COLOR_BLACK);
		HTFT_voidDrawNum(Local_u8TFT_day, 112, 70, size, HTFT_COLOR_YELLOW, HTFT_COLOR_BLACK);
	}
	else
	{
		HTFT_voidDrawNum(Local_u8TFT_day, 124, 70, size, HTFT_COLOR_YELLOW, HTFT_COLOR_BLACK);
	}

	/* Print Month */
	HTFT_voidDrawText(year_month[Local_u8TFT_month], 93, 70, size, HTFT_COLOR_YELLOW, HTFT_COLOR_BLACK);

	/* Print Year */
	HTFT_voidDrawNum(Local_u16TFT_year, 50, 70, size, HTFT_COLOR_YELLOW, HTFT_COLOR_BLACK);
}

void voidPrintWeekDay(void) // Not Very Accurate
{
	HTFT_voidDrawRect(0, 127, 20, 20, HTFT_COLOR_BLACK); // Clear Old Date

	HTFT_voidDrawText(week_days[Local_u8TFT_day%7], 112, 35, size, HTFT_COLOR_CYAN, HTFT_COLOR_BLACK);
}


void main()
{
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(MRCC_APB2, MRCC_APB2_PORTA);
	MRCC_voidEnableClock(MRCC_APB2, MRCC_APB2_SPI1);

	/* Pins Init */
	MGPIO_voidSetPinDirection(GPIOA, PIN5, OUTPUT_SPEED_10MHZ_AFPP);	/* CLK */
	MGPIO_voidSetPinDirection(GPIOA, PIN7, OUTPUT_SPEED_10MHZ_AFPP);	/* MOSI */

	/* STK Init */
	MSTK_voidInit();

	/* SPI Init */
	MSPI_voidInit();

	/* TFT Init */
	HTFT_voidInitialize();

	/* Background */
	HTFT_voidFillColor(HTFT_COLOR_BLACK);

	HTFT_voidDrawText("Digital Clock", 110, 140, 1, HTFT_COLOR_PURPLE, HTFT_COLOR_BLACK);

	// Print Time
	voidPrintTime();

	// Print Date
	voidPrintDate();
	voidPrintWeekDay();

	// Start Timer
	MSTK_voidSetIntervalPeriodic(1000000, voidIncCounter);

	while(1)
		;
}

