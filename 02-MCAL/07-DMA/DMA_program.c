/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V01								*/
/* Date      : 22 Sep 2020						*/
/************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_config.h"
#include "DMA_private.h"

#define NULL (void*)0
/* Define Callback Global Variable */
static void (*DMA_CallBack[7]) (void) = {0} ;


void MDMA_voidChannelInit(void)
{
	ASSIGN_BIT((DMA -> CHANNEL[DMA_CHANNEL_ID-1].CCR), 0, 0);
	ASSIGN_BIT((DMA -> CHANNEL[DMA_CHANNEL_ID-1].CCR), 1, DMA_TCIE);
	ASSIGN_BIT((DMA -> CHANNEL[DMA_CHANNEL_ID-1].CCR), 2, DMA_HTIE);
	ASSIGN_BIT((DMA -> CHANNEL[DMA_CHANNEL_ID-1].CCR), 3, DMA_TEIE);
	ASSIGN_BIT((DMA -> CHANNEL[DMA_CHANNEL_ID-1].CCR), 4, DMA_DIR);
	ASSIGN_BIT((DMA -> CHANNEL[DMA_CHANNEL_ID-1].CCR), 5, DMA_CIRC);
	ASSIGN_BIT((DMA -> CHANNEL[DMA_CHANNEL_ID-1].CCR), 6, DMA_PINC);
	ASSIGN_BIT((DMA -> CHANNEL[DMA_CHANNEL_ID-1].CCR), 7, DMA_MINC);
	ASSIGN_BIT((DMA -> CHANNEL[DMA_CHANNEL_ID-1].CCR), 8, GET_BIT(DMA_PERIPHERAL_SIZE,0));
	ASSIGN_BIT((DMA -> CHANNEL[DMA_CHANNEL_ID-1].CCR), 9, GET_BIT(DMA_PERIPHERAL_SIZE,1));
	ASSIGN_BIT((DMA -> CHANNEL[DMA_CHANNEL_ID-1].CCR), 10, GET_BIT(DMA_MEMORY_SIZE,0));
	ASSIGN_BIT((DMA -> CHANNEL[DMA_CHANNEL_ID-1].CCR), 11, GET_BIT(DMA_MEMORY_SIZE,1));
	ASSIGN_BIT((DMA -> CHANNEL[DMA_CHANNEL_ID-1].CCR), 12, GET_BIT(DMA_PRIORITY_LEVEL,0));
	ASSIGN_BIT((DMA -> CHANNEL[DMA_CHANNEL_ID-1].CCR), 13, GET_BIT(DMA_PRIORITY_LEVEL,1));
	ASSIGN_BIT((DMA -> CHANNEL[DMA_CHANNEL_ID-1].CCR), 14, DMA_MEM2MEM);
}

void MDMA_voidSetCallBack(void (*Copy_ptr) (void))
{
	DMA_CallBack[DMA_CHANNEL_ID-1] = Copy_ptr;
}

void MDMA_voidChannelStart(u32 *Copy_PTRu32SourceAddress, u32 *Copy_PTRu32DestinationAddress, u16 Copy_u16BlockLength)
{
	/* Disable the channel first */
	CLR_BIT(DMA -> CHANNEL[DMA_CHANNEL_ID-1].CCR, 0);
	
	/* Set Source and Destination Addresses */
	DMA -> CHANNEL[DMA_CHANNEL_ID-1].CPAR = Copy_PTRu32SourceAddress;
	DMA -> CHANNEL[DMA_CHANNEL_ID-1].CMAR = Copy_PTRu32DestinationAddress;
	
	/* Block Length */
	DMA -> CHANNEL[DMA_CHANNEL_ID-1].CNDTR = Copy_u16BlockLength;
	
	/* Enable the channel */
	SET_BIT(DMA -> CHANNEL[DMA_CHANNEL_ID-1].CCR, 0);
}


void DMA1_Channel1_IRQHandler(void)
{
	/* clear flags */
	DMA -> IFCR = 1<<0; 		//Clear the GIF, TEIF, HTIF and TCIF flags in the DMA_ISR register
	//DMA -> IFCR = 1<<1;		//Clear the corresponding TCIF flag in the DMA_ISR register
	//DMA -> IFCR = 1<<2;		//Clear the corresponding HTIF flag in the DMA_ISR register
	//DMA -> IFCR = 1<<3;		//Clear the corresponding TEIF flag in the DMA_ISR register

	// Execute CallBack function
	if(DMA_CallBack[0] != NULL)
		DMA_CallBack[0]();
}

void DMA1_Channel2_IRQHandler(void)
{
	/* clear flags */
	DMA -> IFCR = 1<<4;			//Clear the GIF, TEIF, HTIF and TCIF flags in the DMA_ISR register
	//DMA -> IFCR = 1<<5;		//Clear the corresponding TCIF flag in the DMA_ISR register
	//DMA -> IFCR = 1<<6;		//Clear the corresponding HTIF flag in the DMA_ISR register
	//DMA -> IFCR = 1<<7;		//Clear the corresponding TEIF flag in the DMA_ISR register

	// Execute CallBack function
	if(DMA_CallBack[1] != NULL)
		DMA_CallBack[1]();
}

void DMA1_Channel3_IRQHandler(void)
{
	/* clear flags */
	DMA -> IFCR = 1<<8;			//Clear the GIF, TEIF, HTIF and TCIF flags in the DMA_ISR register
	//DMA -> IFCR = 1<<9;		//Clear the corresponding TCIF flag in the DMA_ISR register
	//DMA -> IFCR = 1<<10;		//Clear the corresponding HTIF flag in the DMA_ISR register
	//DMA -> IFCR = 1<<11;		//Clear the corresponding TEIF flag in the DMA_ISR register

	// Execute CallBack function
	if(DMA_CallBack[2] != NULL)
		DMA_CallBack[2]();
}

void DMA1_Channel4_IRQHandler(void)
{
	/* clear flags */
	DMA -> IFCR = 1<<12;		//Clear the GIF, TEIF, HTIF and TCIF flags in the DMA_ISR register
	//DMA -> IFCR = 1<<13;		//Clear the corresponding TCIF flag in the DMA_ISR register
	//DMA -> IFCR = 1<<14;		//Clear the corresponding HTIF flag in the DMA_ISR register
	//DMA -> IFCR = 1<<15;		//Clear the corresponding TEIF flag in the DMA_ISR register

	// Execute CallBack function
	if(DMA_CallBack[3] != NULL)
		DMA_CallBack[3]();
}

void DMA1_Channel5_IRQHandler(void)
{
	/* clear flags */
	DMA -> IFCR = 1<<16;		//Clear the GIF, TEIF, HTIF and TCIF flags in the DMA_ISR register
	//DMA -> IFCR = 1<<17;		//Clear the corresponding TCIF flag in the DMA_ISR register
	//DMA -> IFCR = 1<<18;		//Clear the corresponding HTIF flag in the DMA_ISR register
	//DMA -> IFCR = 1<<19;		//Clear the corresponding TEIF flag in the DMA_ISR register

	// Execute CallBack function
	if(DMA_CallBack[4] != NULL)
		DMA_CallBack[4]();
}

void DMA1_Channel6_IRQHandler(void)
{
	/* clear flags */
	DMA -> IFCR = 1<<20;		//Clear the GIF, TEIF, HTIF and TCIF flags in the DMA_ISR register
	//DMA -> IFCR = 1<<21;		//Clear the corresponding TCIF flag in the DMA_ISR register
	//DMA -> IFCR = 1<<22;		//Clear the corresponding HTIF flag in the DMA_ISR register
	//DMA -> IFCR = 1<<23;		//Clear the corresponding TEIF flag in the DMA_ISR register

	// Execute CallBack function
	if(DMA_CallBack[5] != NULL)
		DMA_CallBack[5]();

}

void DMA1_Channel7_IRQHandler(void)
{
	/* clear flags */
	DMA -> IFCR = 1<<24;		//Clear the GIF, TEIF, HTIF and TCIF flags in the DMA_ISR register
	//DMA -> IFCR = 1<<25;		//Clear the corresponding TCIF flag in the DMA_ISR register
	//DMA -> IFCR = 1<<26;		//Clear the corresponding HTIF flag in the DMA_ISR register
	//DMA -> IFCR = 1<<27;		//Clear the corresponding TEIF flag in the DMA_ISR register

	// Execute CallBack function
	if(DMA_CallBack[6] != NULL)
		DMA_CallBack[6]();
}
