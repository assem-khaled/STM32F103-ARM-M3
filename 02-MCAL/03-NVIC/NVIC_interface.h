/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V02								*/
/* Date      : 19 Aug 2020						*/
/************************************************/
#ifndef _NVIC_INTERFACE_H
#define _NVIC_INTERFACE_H


void MNVIC_voidEnableInterrupt 	(u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag 	(u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber);
u8 MNVIC_u8GetActiveFlag 		(u8 Copy_u8IntNumber);
void MNVIC_voidSetPriority 		(s8 Copy_s8IntID, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority);

void MNVIC_voidSetPriority2(u8 Copy_PeripheralIdx, u8 Copy_u8Priority);
void MNVIC_voidInit(void);


/* Interrupt Vector table */
#define MNVIC_INT_EXTI0			6
#define MNVIC_INT_EXTI1			7
#define MNVIC_INT_EXTI2			8
#define MNVIC_INT_EXTI3			9
#define MNVIC_INT_EXTI4			10
#define MNVIC_INT_EXTI9_5		23
#define MNVIC_INT_EXTI15_10		40


#endif
