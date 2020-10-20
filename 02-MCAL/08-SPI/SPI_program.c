/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V01								*/
/* Date      : 16 Sep 2020						*/
/************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"


static void (*Local_CallBack)(u8);

void MSPI_voidInit(void)
{
	/* Bidirectional data mode enable */
	ASSIGN_BIT((SPI1->CR1), 15, MSPI_BIDIMODE);

	/* Output enable in bidirectional mode */
	ASSIGN_BIT((SPI1->CR1), 14, MSPI_BIDIOE);

	/* Hardware CRC calculation enable */
	ASSIGN_BIT((SPI1->CR1), 13, MSPI_CRCEN);

	/* CRC transfer next */
	ASSIGN_BIT((SPI1->CR1), 12, MSPI_CRCNEXT);

	/* Data frame format */
	ASSIGN_BIT((SPI1->CR1), 11, MSPI_DFF);

	/* Receive only */
	ASSIGN_BIT((SPI1->CR1), 10, MSPI_RXONLY);

#if MSPI_SSM == 1
	SET_BIT((SPI1->CR1), 9);	/* Software slave management */
	ASSIGN_BIT((SPI1->CR1), 8, MSPI_SSI);	/* Internal slave select */

#else
	CLR_BIT((SPI1->CR1), 9);
	CLR_BIT(SPI1->CR1), 8);

#endif

	/* Frame format */
	ASSIGN_BIT((SPI1->CR1), 7, MSPI_LSBFIRST);

	/* Baud rate */
	ASSIGN_BIT((SPI1->CR1), 5, GET_BIT(MSPI_BR,2));
	ASSIGN_BIT((SPI1->CR1), 4, GET_BIT(MSPI_BR,1));
	ASSIGN_BIT((SPI1->CR1), 3, GET_BIT(MSPI_BR,0));

	/* Master selection */
	ASSIGN_BIT((SPI1->CR1), 2, MSPI_MSTR);

	/* Clock polarity */
	ASSIGN_BIT((SPI1->CR1), 1, MSPI_CPOL);

	/* Clock phase */
	ASSIGN_BIT((SPI1->CR1), 0, MSPI_CPHA);

	/* Tx buffer empty interrupt enable */
	ASSIGN_BIT((SPI1->CR2), 7, MSPI_TXEIE);

	/* RX buffer not empty interrupt enable */
	ASSIGN_BIT((SPI1->CR2), 6, MSPI_RXNEIE);

	/* RX buffer not empty interrupt enable */
	ASSIGN_BIT((SPI1->CR2), 5, MSPI_ERRIE);

	/* RX buffer not empty interrupt enable */
	ASSIGN_BIT((SPI1->CR2), 2, MSPI_SSOE);

	/* SPI enable */
	SET_BIT((SPI1->CR1), 6);
}

void MSPI_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceive)
{
	/* Clear For Slave Select Pin */
	MGPIO_voidSetPinValue(MSPI_SLAVE_PIN, GPIO_LOW);
	
	/* Send Data */
	SPI1 -> DR = Copy_u8DataToTransmit;
	
	/* Wait Busy Flag to finish */
	while (GET_BIT(SPI1 -> SR, 7) == 1);

 	/* Return to the received data */
	*Copy_DataToReceive = SPI1 -> DR;
	
	/* Set Salve Select Pin */
	MGPIO_voidSetPinValue(MSPI_SLAVE_PIN, GPIO_HIGH);
}

void MSPI_voidSendReceiveAsynch(u8 Copy_u8DataToTransmit, void (*Copy_CallBack)(u8))
{
	/* Clear For Slave Select Pin */
	MGPIO_voidSetPinValue(MSPI_SLAVE_PIN, GPIO_LOW);
	
	/* Assign call back function */
	Local_CallBack = Copy_CallBack;
	
	/* Send Data */
	SPI1 -> DR = Copy_u8DataToTransmit;
}


void SPI1_IRQHandler(void)
{
	/* Call Back Function */
	Local_CallBack(SPI1 -> DR);
}
