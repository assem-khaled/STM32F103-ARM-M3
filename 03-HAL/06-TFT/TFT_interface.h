/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V02								*/
/* Date      : 21 Sep 2020						*/
/************************************************/
#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H


void HTFT_voidInitialize(void);
void HTFT_voidDisplayImage(const u16* Copy_u16Image);
void HTFT_voidFillColor(u16 Copy_u16Image);
void HTFT_voidDrawRect(u8 Copy_u8x1, u8 Copy_u8x2, u8 Copy_u8y1, u8 Copy_u8y2, u16 Copy_u16Color);


#endif
