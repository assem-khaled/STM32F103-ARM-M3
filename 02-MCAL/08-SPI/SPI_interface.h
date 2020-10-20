/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V01								*/
/* Date      : 16 Sep 2020						*/
/************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H


void MSPI_voidInit(void);
void MSPI_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceive);
void MSPI_voidSendReceiveAsynch(u8 Copy_u8DataToTransmit, void (*Copy_CallBack)(u8));


#endif
