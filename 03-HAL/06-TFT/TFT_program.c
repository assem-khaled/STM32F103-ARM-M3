/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V01								*/
/* Date      : 21 Sep 2020						*/
/************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"


void HTFT_voidInitialize(void)
{
	/* Initialize GPIO PINS */
	MGPIO_voidSetPinDirection(TFT_RST_PIN, OUTPUT_SPEED_2MHZ_PP);	/* RST */
	MGPIO_voidSetPinDirection(TFT_A0_PIN, OUTPUT_SPEED_2MHZ_PP);	/* A0 */

	/* Reset Pulse */
	MGPIO_voidSetPinValue(TFT_RST_PIN, GPIO_HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_HIGH);
	MSTK_voidSetBusyWait(120000);
	
	/* Sleep Out Command */
	voidWriteCommand(0x11);
	
	/* Wait 150 ms */
	MSTK_voidSetBusyWait(150000);
	
	/* Color Mode Command */
	voidWriteCommand(0x3A);
	voidWriteData	(0x05);
	
	/* Display On Command */
	voidWriteCommand(0x29);
}

void HTFT_voidDisplayImage(const u16* Copy_Image)
{
	u16 Local_counter;

	/* Set X Address */
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127);
	
	/* Set Y Address */
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);

	/* RAM Write */
	voidWriteCommand(0x2C);

	for(Local_counter = 0; Local_counter< 20480; Local_counter++)
	{
		/* Write the high byte */
		voidWriteData( (Copy_Image[Local_counter] >> 8) );

		/* Write the low byte */
		voidWriteData((Copy_Image[Local_counter] & 0x00ff));
	}
}



static void voidWriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8Temp;
	
	/* Set A0 Pin to Low */
	MGPIO_voidSetPinValue(TFT_A0_PIN, GPIO_LOW);
	
	/* Send Command over SPI */
	MSPI_voidSendReceiveSynch(Copy_u8Command, &Local_u8Temp);
}

static void voidWriteData(u8 Copy_u8Data)
{
	u8 Local_u8Temp;
	
	/* Set A0 Pin to High */
	MGPIO_voidSetPinValue(TFT_A0_PIN, GPIO_HIGH);
	
	/* Send data over SPI */
	MSPI_voidSendReceiveSynch(Copy_u8Data, &Local_u8Temp);
}
