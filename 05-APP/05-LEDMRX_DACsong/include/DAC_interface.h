/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V01								*/
/* Date      : 12 Sep 2020						*/
/************************************************/
#ifndef DAC_INTERFACE_H_
#define DAC_INTERFACE_H_


void HDAC_voidInit(void);
void HDAC_voidStart(u8 *Copy_u8Ptr, u16 Copy_u16Length);
void HDAC_voidStop(void);
void HDAC_voidChangeFrequency(u16 Copy_u16Ticks);


#endif
