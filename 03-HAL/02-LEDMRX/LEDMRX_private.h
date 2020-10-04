/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V03								*/
/* Date      : 31  Aug 2020						*/
/************************************************/
#ifndef LEDMRX_PRIVATE_H
#define LEDMRX_PRIVATE_H

void Display(u8 *Copy_u8Data);
void DisplayNextColumn(void);
static void DisableAllCols(void);
static void EnableAllCols(u8 Copy_u8Col);
static void SetRowValues(u8 Copy_u8Value);

/* Delay Types */
#define LEDMRX_PERIODIC			0
#define LEDMRX_BUSY_WAIT		3
#define LEDMRX_NOP				5

/* Shift Speed */
#define HLEDMRX_SHIFT_SPEED_HIGH			1
#define HLEDMRX_SHIFT_SPEED_MEDIUM			5
#define HLEDMRX_SHIFT_SPEED_LOW				11

#endif
