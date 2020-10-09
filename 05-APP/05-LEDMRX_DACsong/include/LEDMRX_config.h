/************************************************/
/* Author    : Assem Khaled					*/
/* Version   : V02							*/
/* Date      : 31  Aug 2020					*/
/************************************************/
#ifndef LEDMRX_CONFIG_H
#define LEDMRX_CONFIG_H


/* Please write pin pair PORT,PIN */
#define	LEDMRX_R0_PIN	GPIOA,PIN0
#define	LEDMRX_R1_PIN	GPIOA,PIN1
#define	LEDMRX_R2_PIN	GPIOA,PIN2
#define	LEDMRX_R3_PIN	GPIOA,PIN3
#define	LEDMRX_R4_PIN	GPIOA,PIN4
#define	LEDMRX_R5_PIN	GPIOA,PIN5
#define	LEDMRX_R6_PIN	GPIOA,PIN6
#define	LEDMRX_R7_PIN	GPIOA,PIN7

/* Please write pin pair PORT,PIN */
#define	LEDMRX_C0_PIN	GPIOB,PIN15
#define	LEDMRX_C1_PIN	GPIOB,PIN14
#define	LEDMRX_C2_PIN	GPIOB,PIN13
#define	LEDMRX_C3_PIN	GPIOB,PIN12
#define	LEDMRX_C4_PIN	GPIOB,PIN11
#define	LEDMRX_C5_PIN	GPIOB,PIN10
#define	LEDMRX_C6_PIN	GPIOB,PIN9
#define	LEDMRX_C7_PIN	GPIOA,PIN8


/* Options:	LEDMRX_PERIODIC
			LEDMRX_BUSY_WAIT
			LEDMRX_NOP			*/
#define LEDMRX_DISPLAY_DELAY			LEDMRX_NOP

/* Options:	LEDMRX_BUSY_WAIT
			LEDMRX_NOP			*/
#define LEDMRX_SHIFT_ANIMATION_DELAY	LEDMRX_NOP

/* Options:	HLEDMRX_SHIFT_SPEED_LOW
 *			HLEDMRX_SHIFT_SPEED_MEDIUM
 *			HLEDMRX_SHIFT_SPEED_HIGH		*/
#define LEDMRX_SHIFT_SPEED				6


#endif
