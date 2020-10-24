/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V01								*/
/* Date      : 16 Sep 2020						*/
/************************************************/
#ifndef USART_CONFIG_H
#define USART_CONFIG_H


/* Options:	Baud Rate For 8MHz:-
 					9600 	-> 	0
 					115200 	-> 	1	*/
#define MUSART_BAUD_RATE		0


/* Options:	Word Length
					8 Bit 	->	0
 					9 Bit 	->	1	*/
#define MUSART_U8_BIT_WORD		0


/* Options:	Parity Control Enable
					Parity control disabled ->	0
 					Parity control enabled 	->	1	*/
#define MUSART_PARITY_Enable		0


/* Options:	Parity Selection
					Even parity ->	0
 					Odd parity 	->	1	*/
#define MUSART_PARITY_SELECTION		0


/* Options:	Transmitter Enable
					disable Transmitter ->	0
 					Enable Transmitter 	->	1	*/
#define MUSART_TX_ENABLE			1


/* Options:	Receiver Enable
					disable Receiver 	->	0
 					Enable Receiver 	->	1	*/
#define MUSART_RX_ENABLE			1


#endif
