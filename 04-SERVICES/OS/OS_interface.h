/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V01								*/
/* Date      : 6 Sep 2020						*/
/************************************************/
#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H


void SOS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u16Periodicity, void (*Copy_ptr) (void), u16 Copy_u16FirstDelay);
void SOS_voidStart(void);
void SOS_voidSuspend(u8 Copy_u8ID);
void SOS_voidResume(u8 Copy_u8ID);
void SOS_voidDelete(u8 Copy_u8ID);



#endif
