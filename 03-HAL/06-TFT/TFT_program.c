/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V03								*/
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

void HTFT_voidDisplayImage(const u16* Copy_u16Image)
{
	u16 Local_u16Counter;
	u16 Local_u16Size = (TFT_MAX_X- 1) * (TFT_MAX_Y - 1);

	/* Set Address */
	voidSetAddress(0, (TFT_MAX_X- 1), 0, (TFT_MAX_Y - 1));

	for(Local_u16Counter = 0; Local_u16Counter< Local_u16Size; Local_u16Counter++)
	{
		voidSetColour(Copy_u16Image[Local_u16Counter]);
	}
}

void HTFT_voidFillColor(u16 Copy_u16Color)
{
	u16 Local_u16Counter;

	/* Set Address */
	voidSetAddress(0, (TFT_MAX_X- 1), 0, (TFT_MAX_Y - 1));

	for(Local_u16Counter = 0; Local_u16Counter< 20480; Local_u16Counter++)
	{
		voidSetColour(Copy_u16Color);
	}
}

void HTFT_voidDrawRect(u8 Copy_u8x1, u8 Copy_u8w, u8 Copy_u8y1, u8 Copy_u8h, u16 Copy_u16Color)
{
	u16 Local_u16Counter;
	u8 Copy_u8x2 = Copy_u8x1 + Copy_u8w;
	u8 Copy_u8y2 = Copy_u8y1 + Copy_u8h;
	u16 Local_u16Size = (Copy_u8x2 - Copy_u8x1) * (Copy_u8y2 - Copy_u8y1);

	/* Set Address */
	voidSetAddress(Copy_u8x1, Copy_u8x2, Copy_u8y1, Copy_u8y2);

	for(Local_u16Counter = 0; Local_u16Counter< Local_u16Size; Local_u16Counter++)
	{
		voidSetColour(Copy_u16Color);
	}
}

void HTFT_voidDrawChar(u8 Copy_u8Char, u8 Copy_u8x1, u8 Copy_u8y1, f32 Copy_f32Size, u16 Copy_u16Color, u16 Copy_u16BackColor)
{
	/* Get array index */
	u8 local_u8CharIndex = 0 ;
	if (( Copy_u8Char >= ' ' ))
	{
		local_u8CharIndex = Copy_u8Char - 32 ;
	}

	// Draw the Background Color
	HTFT_voidDrawRect(Copy_u8x1-((TFT_CHAR_WIDTH-1)*Copy_f32Size), ((TFT_CHAR_WIDTH-1)*Copy_f32Size)+ Copy_f32Size, Copy_u8y1-((TFT_CHAR_HIGHT-1)*Copy_f32Size)+ Copy_f32Size, ((TFT_CHAR_HIGHT-1)*Copy_f32Size)+ Copy_f32Size, Copy_u16BackColor);

	for(u8 x = 0; x < TFT_CHAR_WIDTH; x++)
	{
		for(u8 y = 0; y < TFT_CHAR_HIGHT; y++)
		{
			if( (TFT_Font5x7[(local_u8CharIndex*5) + x]) & (1 << y))
			{
				HTFT_voidDrawRect(Copy_u8x1-(x*Copy_f32Size), (u8)Copy_f32Size, Copy_u8y1-(y*Copy_f32Size), (u8)Copy_f32Size, Copy_u16Color);
			}
		}
	}
}

void HTFT_voidDrawText(u8 *Copy_u8Text, s8 Copy_s8x1, u8 Copy_u8y1, f32 Copy_f32Size, u16 Copy_u16Color, u16 Copy_u16BackColor)
{
	s8 Local_s8x1 = Copy_s8x1;
	u8 Local_u8y1 = Copy_u8y1;

	Local_s8x1 -= Copy_f32Size;
	Local_u8y1 -= Copy_f32Size-1;

	while(*Copy_u8Text)
	{
		if (Local_s8x1 <= 0) // return to the next line
		{
			Local_s8x1 = Copy_s8x1;
			Local_u8y1 =  Copy_u8y1 - (TFT_CHAR_HIGHT * Copy_f32Size) - TFT_CHAR_SPACING;
		}

		HTFT_voidDrawChar(*Copy_u8Text, Local_s8x1, Local_u8y1, Copy_f32Size, Copy_u16Color, Copy_u16BackColor); // Draw char

		Copy_u8Text++; // Next char

		Local_s8x1 -= (TFT_CHAR_WIDTH * Copy_f32Size) + TFT_CHAR_SPACING; // Next Char Location in TFT
	}
}

void HTFT_voidDrawNum(u32 u32Num, u8 Copy_u8x1, u8 Copy_u8y1, f32 Copy_f32Size, u16 Copy_u16Color, u16 Copy_u16BackColor)
{
	u8  i , j , temp , num[10]={0} ;

	if (u32Num == 0)
	{
		HTFT_voidDrawChar('0', Copy_u8x1, Copy_u8y1, Copy_f32Size, Copy_u16Color, Copy_u16BackColor);
		return;
	}

	for(i=0;u32Num>0;i++)
		{
			num[i]=u32Num%10 + 0x30;
			u32Num=u32Num/10;
		}
	for(j=0,i--;j<i;j++,i--)
		{
			temp=num[i];
			num[i]=num[j];
			num[j]=temp;
		}
	HTFT_voidDrawText(num, Copy_u8x1, Copy_u8y1, Copy_f32Size, Copy_u16Color, Copy_u16BackColor);
}



/////////////////* Private Functions */////////////////

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

static void voidSetAddress(u8 Copy_u8x1, u8 Copy_u8x2, u8 Copy_u8y1, u8 Copy_u8y2)
{
	/* Set X Address */
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(Copy_u8x1);
	voidWriteData(0);
	voidWriteData(Copy_u8x2);

	/* Set Y Address */
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(Copy_u8y1);
	voidWriteData(0);
	voidWriteData(Copy_u8y2);

	/* RAM Write */
	voidWriteCommand(0x2C);
}

static void voidSetColour(u16 Copy_u16Color)
{
	/* Write the high byte */
	voidWriteData( (Copy_u16Color >> 8) );

	/* Write the low byte */
	voidWriteData((Copy_u16Color & 0x00ff));
}

