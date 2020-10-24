/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V01								*/
/* Date      : 16 Sep 2020						*/
/************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"


void MUSART1_voidInit(void)
{
	/* Baud rate to be implemented
		For 8MHz:-

		9600-> 52.083 :-
		F=1
		M=34

		115200-> 4.34 :-
		F=5
		M=4
	*/
#if MUSART_BAUD_RATE == 0
	/* baud rate = 9600 */
	USART1 -> BRR = 0x341;
#elif MUSART_BAUD_RATE == 1
	/* baud rate = 115200 */
	USART1 -> BRR = 0x45;
#endif

#if MUSART_PARITY_Enable == 1
	/* Enable Parity */
	SET_BIT((USART1-> CR[0]), 10);
	/* Parity Selection : Even or Odd */
	ASSIGN_BIT((USART1-> CR[0]), 9, MUSART_PARITY_SELECTION);
#endif

	/* Word Length */
	ASSIGN_BIT((USART1-> CR[0]), 12, MUSART_U8_BIT_WORD);

	/* Transmitter Enable */
	ASSIGN_BIT((USART1-> CR[0]), 3, MUSART_TX_ENABLE);

	/* Receiver Enable */
	ASSIGN_BIT((USART1-> CR[0]), 2, MUSART_RX_ENABLE);

	/* Enabling USART */
	SET_BIT((USART1-> CR[0]), 13);
	
	/* Clearing status register */
	USART1 -> SR = 0;
}

void MUSART1_voidTransmit(u8 *Copy_u8Ptr)
{
	u8 Local_u8Counter = 0;
	while(Copy_u8Ptr[Local_u8Counter] != '\0')
	{
		(USART1 -> DR) = Copy_u8Ptr[Local_u8Counter];
		while((GET_BIT((USART1 -> SR), 6)) == 0) /* Check for TC (Transmission complete) */
			;
		Local_u8Counter++;
	}
}

u8 MUSART1_u8Receive(void)
{
	u8 Local_u8Receive = 0;
	while((GET_BIT((USART1 -> SR), 5)) == 0) /* Check for RXNE (Read data register not empty) */
		;
	Local_u8Receive = (USART1 -> DR);
	return (Local_u8Receive);
}
