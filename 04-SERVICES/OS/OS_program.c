/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V01								*/
/* Date      : 6 Sep 2020						*/
/************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

#define NULL (void*)0

/* Array of Tasks structure */
static Task OS_Tasks[NUMBER_OF_TASKS];


void SOS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u16Periodicity, void (*Copy_ptr) (void), u16 Copy_u16FirstDelay)
{
	OS_Tasks[Copy_u8ID].periodicity = Copy_u16Periodicity;
	OS_Tasks[Copy_u8ID].ptr = Copy_ptr;
	OS_Tasks[Copy_u8ID].FirstDelay = Copy_u16FirstDelay;
	OS_Tasks[Copy_u8ID].State = TASK_READY;
}

void SOS_voidStart(void)
{
	/* Initialization */
	MSTK_voidInit();
	/* Tick >> 1 mSec */
	/* HSE 8 MHz / 8 ==> 1000 uSec >> 1 mSec */
	MSTK_voidSetIntervalPeriodic(1000, Scheduler );
}

void SOS_voidSuspend(u8 Copy_u8ID)
{
	OS_Tasks[Copy_u8ID].State = TASK_SUSPEND;
}

void SOS_voidResume(u8 Copy_u8ID)
{
	OS_Tasks[Copy_u8ID].State = TASK_READY;
}

void SOS_voidDelete(u8 Copy_u8ID)
{
	OS_Tasks[Copy_u8ID].ptr = NULL;
}



void Scheduler(void)
{
	for(u8 i=0; i < NUMBER_OF_TASKS; i++)
	{
		if((OS_Tasks[i].ptr != NULL) && (OS_Tasks[i].State) == TASK_READY)
		{
			if(OS_Tasks[i].FirstDelay == 0)
			{
				OS_Tasks[i].FirstDelay = OS_Tasks[i].periodicity-1;
				OS_Tasks[i].ptr();
			}
			else
			{
				OS_Tasks[i].FirstDelay--;
			}
		}
	}
}
