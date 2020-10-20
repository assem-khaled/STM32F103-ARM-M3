/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V01								*/
/* Date      : 16 Sep 2020						*/
/************************************************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H


/* Write in a pair port,pin */
#define MSPI_SLAVE_PIN   	GPIOA,0


/* Options:	Bidirectional data mode enable
 					2-line unidirectional data mode selected 	-> 	0
 					1-line bidirectional data mode selected 	-> 	1	*/
#define MSPI_BIDIMODE		0


/* Options:	Output enable in bidirectional mode
					Output disabled (receive-only mode) 		->	0
 					Output enabled (transmit-only mode)		 	->	1	*/
#define MSPI_BIDIOE			0


/* Options:	Hardware CRC calculation enable
 					CRC calculation disabled 	-> 	0
 					calculation enabled		 	-> 	1	*/
#define MSPI_CRCEN			0


/* Options:	CRC transfer next
					Data phase (no CRC phase) 					->	0
 					Next transfer is CRC (CRC phase)		 	->	1	*/
#define MSPI_CRCNEXT		0


/* Options:	Data frame format
			8-bit data frame format is selected for transmission/reception 		->	0
 			16-bit data frame format is selected for transmission/reception		->	1	*/
#define MSPI_DFF			0


/* Options:	Receive only
					Full duplex (Transmit and receive) 			->	0
 					Output disabled (Receive-only mode)		 	->	1	*/
#define MSPI_RXONLY			0


/* Options:	Software slave management
					Software slave management disabled 			->	0
 					Software slave management enabled		 	->	1	*/
#define MSPI_SSM			1


/* Options:	Internal slave select
					XXXX 			->	0
 					XXXX		 	->	1	*/
#define MSPI_SSI			1


/* Options:	Frame format
					MSB transmitted first 			->	0
 					LSB transmitted first		 	->	1	*/
#define MSPI_LSBFIRST		0


/* Options:	Baud rate control
					fPCLK/2			->	000
					fPCLK/4			->	001
					fPCLK/8			->	010
					fPCLK/16		->	011
					fPCLK/32		->	100
					fPCLK/64		->	101
					fPCLK/128		->	110
					fPCLK/256		->	111		*/
#define MSPI_BR				000


/* Options:	Master selection
					Slave configuration 			->	0
 					Master configuration		 	->	1	*/
#define MSPI_MSTR			1


/* Options:	Clock polarity
					CK to 0 when idle 			->	0
 					CK to 1 when idle		 	->	1	*/
#define MSPI_CPOL			1


/* Options:	Clock phase
					The first clock transition is the first data capture edge 			->	0
 					The second clock transition is the first data capture edge		 	->	1	*/
#define MSPI_CPHA			1


/* Options:	Tx buffer empty interrupt enable
					TXE interrupt masked 			->	0
 					TXE interrupt not masked 	 	->	1
 	(Used to generate an interrupt request when the TXE flag is set)	*/
#define MSPI_TXEIE			0


/* Options:	RX buffer not empty interrupt enable
					RXNE interrupt masked 			->	0
 					RXNE interrupt not masked 	 	->	1
 	(Used to generate an interrupt request when the RXNE flag is set)	*/
#define MSPI_RXNEIE			0


/* Options:	Error interrupt enable
					Error interrupt is masked		->	0
 					Error interrupt is enabled 	 	->	1
 	(This bit controls the generation of an interrupt when an error condition occurs)	*/
#define MSPI_ERRIE			0


/* Options:	SS output enable
		SS output is disabled in master mode and the cell can work in multimaster configuration		->	0
 		SS output is enabled in master mode													 	 	->	1
 	(When the cell is enabled The cell cannot work in a multimaster environment)	*/
#define MSPI_SSOE			0


#endif
