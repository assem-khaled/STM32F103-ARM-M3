/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V01								*/
/* Date      : 22 Sep 2020						*/
/************************************************/
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H


void MDMA_voidChannelInit(void);
void MDMA_voidChannelStart(u32 *Copy_PTRu32SourceAddress, u32 *Copy_PTRu32DestinationAddress, u16 Copy_u16BlockLength);
void MDMA_voidSetCallBack(void (*Copy_ptr) (void));


#endif
