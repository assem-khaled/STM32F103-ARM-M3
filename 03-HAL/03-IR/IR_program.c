/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V01								*/
/* Date      : 9 Sep 2020						*/
/************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "AFIO_interface.h"

#include "IR_interface.h"
#include "IR_private.h"
#include "IR_config.h"


volatile u8 u8StartFlag = 0;
volatile u32 u32FrameData[50] = {0};
volatile u8 u8EdgeCounter = 0;
volatile u8 u8Data = 0;


static void (*HIR_CallBack[21]) (void)  ;


void HIR_voidInit(u8 Copy_u8Button, void (*Copy_ptr) (void))
{
	/* IO Pin Initialization */
	MGPIO_voidSetPinDirection(IR_PORT, IR_PIN, INPUT_FLOATING);  // By Default INPUT_FLOATING
	
	/* EXTI Initialization */
	MEXTI_voidSetCallBack(IR_PIN, voidGetFrame);
	MEXTI_voidSetSignalLatch(IR_PIN, MEXTI_FALLING);
	MEXTI_voidEnableEXTI(IR_PIN);
	
	/* AFIO Initialization */
	MAFIO_voidSetEXTIConfig(IR_PIN, IR_PORT);
	
	/* NVIC Initialization */
	switch(IR_PIN)
	{
	case PIN0:	MNVIC_voidEnableInterrupt(MNVIC_INT_EXTI0);		break;
	case PIN1:	MNVIC_voidEnableInterrupt(MNVIC_INT_EXTI1);		break;
	case PIN2:	MNVIC_voidEnableInterrupt(MNVIC_INT_EXTI2);		break;
	case PIN3:	MNVIC_voidEnableInterrupt(MNVIC_INT_EXTI3);		break;
	case PIN4:	MNVIC_voidEnableInterrupt(MNVIC_INT_EXTI4);		break;
	default:
		if(IR_PIN <10 )
			MNVIC_voidEnableInterrupt(MNVIC_INT_EXTI9_5);
		else if(IR_PIN <16)
			MNVIC_voidEnableInterrupt(MNVIC_INT_EXTI15_10);
	}
	
	/* Initialize Callback functions */
	switch(Copy_u8Button)
	{
		case HIR_POWER:		HIR_CallBack[0] = Copy_ptr;		break;
		case HIR_MODE:		HIR_CallBack[1] = Copy_ptr;		break;
		case HIR_MUTE:		HIR_CallBack[2] = Copy_ptr;		break;
		case HIR_PLAY:		HIR_CallBack[3] = Copy_ptr;		break;
		case HIR_LEFT:		HIR_CallBack[4] = Copy_ptr;		break;
		case HIR_RIGHT:		HIR_CallBack[5] = Copy_ptr;		break;
		case HIR_EQ:		HIR_CallBack[6] = Copy_ptr;		break;
		case HIR_VOL_DOWN:	HIR_CallBack[7] = Copy_ptr;		break;
		case HIR_VOL_UP:	HIR_CallBack[8] = Copy_ptr;		break;
		case HIR_ZERO:		HIR_CallBack[9] = Copy_ptr;		break;
		case HIR_RPT:		HIR_CallBack[10] = Copy_ptr;	break;
		case HIR_U_SD:		HIR_CallBack[11] = Copy_ptr;	break;
		case HIR_ONE:		HIR_CallBack[12] = Copy_ptr;	break;
		case HIR_TWO:		HIR_CallBack[13] = Copy_ptr;	break;
		case HIR_THREE:		HIR_CallBack[14] = Copy_ptr;	break;
		case HIR_FOUR:		HIR_CallBack[15] = Copy_ptr;	break;
		case HIR_FIVE:		HIR_CallBack[16] = Copy_ptr;	break;
		case HIR_SIX:		HIR_CallBack[17] = Copy_ptr;	break;
		case HIR_SEVEN:		HIR_CallBack[18] = Copy_ptr;	break;
		case HIR_EIGHT:		HIR_CallBack[19] = Copy_ptr;	break;
		case HIR_NINE:		HIR_CallBack[20] = Copy_ptr; 	break;
	}
}

void voidGetFrame(void)
{
	if(u8StartFlag == 0)
	{
		/* Start Time */
		MSTK_voidSetIntervalSingle(WAIT_TIME, voidTakeAction);
		u8StartFlag = 1;
	}
	else
	{
		u32FrameData[u8EdgeCounter] = MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(WAIT_TIME, voidTakeAction);
		u8EdgeCounter++;
	}
}

void voidTakeAction(void)
{
	u8 i;
	u8Data = 0;

	for(i=0; i<8; i++)
	{
		if( (u32FrameData[17+i] >= 2000) && (u32FrameData[17+i] <= 2300) )
		{
			SET_BIT(u8Data, i);
		}
		else
		{
			CLR_BIT(u8Data, i);
		}
	}

	voidPlay();

	u8StartFlag = 0;
	u32FrameData[0] = 0;
	u8EdgeCounter = 0;
}

void voidPlay(void)
{
	// Only execute if the callback function is initialized for the button
	switch(u8Data)
	{
		case HIR_POWER:		if(HIR_CallBack[0])		HIR_CallBack[0]();		break;
		case HIR_MODE:		if(HIR_CallBack[1])		HIR_CallBack[1]();		break;
		case HIR_MUTE:		if(HIR_CallBack[2])		HIR_CallBack[2]();		break;
		case HIR_PLAY:		if(HIR_CallBack[3])		HIR_CallBack[3]();		break;
		case HIR_LEFT:		if(HIR_CallBack[4])		HIR_CallBack[4]();		break;
		case HIR_RIGHT:		if(HIR_CallBack[5])		HIR_CallBack[5]();		break;
		case HIR_EQ:		if(HIR_CallBack[6])		HIR_CallBack[6]();		break;
		case HIR_VOL_DOWN:	if(HIR_CallBack[7])		HIR_CallBack[7]();		break;
		case HIR_VOL_UP:	if(HIR_CallBack[8])		HIR_CallBack[8]();		break;
		case HIR_ZERO:		if(HIR_CallBack[9])		HIR_CallBack[9]();		break;
		case HIR_RPT:		if(HIR_CallBack[10])	HIR_CallBack[10]();		break;
		case HIR_U_SD:		if(HIR_CallBack[11])	HIR_CallBack[11]();		break;
		case HIR_ONE:		if(HIR_CallBack[12])	HIR_CallBack[12]();		break;
		case HIR_TWO:		if(HIR_CallBack[13])	HIR_CallBack[13]();		break;
		case HIR_THREE:		if(HIR_CallBack[14])	HIR_CallBack[14]();		break;
		case HIR_FOUR:		if(HIR_CallBack[15])	HIR_CallBack[15]();		break;
		case HIR_FIVE:		if(HIR_CallBack[16])	HIR_CallBack[16]();		break;
		case HIR_SIX:		if(HIR_CallBack[17])	HIR_CallBack[17]();		break;
		case HIR_SEVEN:		if(HIR_CallBack[18])	HIR_CallBack[18]();		break;
		case HIR_EIGHT:		if(HIR_CallBack[19])	HIR_CallBack[19]();		break;
		case HIR_NINE:		if(HIR_CallBack[20])	HIR_CallBack[20]();		break;
	}
}
