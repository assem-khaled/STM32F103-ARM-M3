/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V01								*/
/* Date      : 12 Sep 2020						*/
/************************************************/
#ifndef DAC_CONFIG_H_
#define DAC_CONFIG_H_


/* Please write pin pair PORT,PIN */
#define	DAC_PIN0	GPIOB,PIN0
#define	DAC_PIN1	GPIOB,PIN1
#define	DAC_PIN2	GPIOB,PIN2
#define	DAC_PIN3	GPIOB,PIN3
#define	DAC_PIN4	GPIOB,PIN4
#define	DAC_PIN5	GPIOB,PIN5
#define	DAC_PIN6	GPIOB,PIN6
#define	DAC_PIN7	GPIOB,PIN7


/* SysTick Ticks */
#define DAC_Ticks	125

/* Options:	DAC_MODE_CONTINUOUS
 *			DAC_MODE_ONE_TIME		*/
#define DAC_MODE	DAC_MODE_ONE_TIME


#endif
