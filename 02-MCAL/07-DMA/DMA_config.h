/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V01								*/
/* Date      : 22 Sep 2020						*/
/************************************************/
#ifndef DMA_CONFIG_H
#define DMA_CONFIG_H


/* Options:	1 >> 7		*/
#define DMA_CHANNEL_ID		2

/* Options:	0: Memory to memory mode disabled
			1: Memory to memory mode enabled		*/
#define DMA_MEM2MEM			1

/* Options:	0: Low
			1: Medium
			2: High
			3: Very high		*/
#define DMA_PRIORITY_LEVEL	3

/* Options:	0: 8-bits
			1: 16-bits
			2: 32-bits		*/
#define DMA_MEMORY_SIZE		2

/* Options:	0: 8-bits
			1: 16-bits
			2: 32-bits		*/
#define DMA_PERIPHERAL_SIZE		2

/* Options:	0: Memory increment mode disabled
			1: Memory increment mode enabled		*/
#define DMA_MINC		1

/* Options:	0: Peripheral increment mode disabled
			1: Peripheral increment mode enabled		*/
#define DMA_PINC		1

/* Options:	0: Circular mode disabled
			1: Circular mode enabled	*/
#define DMA_CIRC		0

/* Options:	0: Read from peripheral
			1: Read from memory			*/
#define DMA_DIR			0

/* Options:	0: Transfer error interrupt disabled
			1: Transfer error interrupt enabled		*/
#define DMA_TEIE		0

/* Options:	0: Half transfer interrupt disabled
			1: Half transfer interrupt enabled		*/
#define DMA_HTIE		0

/* Options:	0: Transfer complete interrupt disabled
			1: Transfer complete interrupt enabled	*/
#define DMA_TCIE		1



#endif
