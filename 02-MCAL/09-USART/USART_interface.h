/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V01								*/
/* Date      : 16 Sep 2020						*/
/************************************************/
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H


void MUSART1_voidInit(void);
void MUSART1_voidTransmit(u8 *Copy_u8Ptr);
u8 MUSART1_u8Receive(void);


#endif
