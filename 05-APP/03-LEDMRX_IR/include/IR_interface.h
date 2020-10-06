/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V01								*/
/* Date      : 9 Sep 2020						*/
/************************************************/
#ifndef IR_INTERFACE_H
#define IR_INTERFACE_H


#define HIR_POWER		69
#define HIR_MODE		70
#define HIR_MUTE		71
#define HIR_PLAY		68
#define HIR_LEFT		64
#define HIR_RIGHT		67
#define HIR_EQ			7
#define HIR_VOL_DOWN	21
#define HIR_VOL_UP		9
#define HIR_ZERO		22
#define HIR_RPT			25
#define HIR_U_SD		13
#define HIR_ONE			12
#define HIR_TWO			24
#define HIR_THREE		94
#define HIR_FOUR		8
#define HIR_FIVE		28
#define HIR_SIX			90
#define HIR_SEVEN		66
#define HIR_EIGHT		82
#define HIR_NINE		74


void HIR_voidInit(u8 Copy_u8Button, void (*Copy_ptr) (void));


#endif
