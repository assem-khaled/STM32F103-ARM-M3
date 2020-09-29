/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V02								*/
/* Date      : 31  Aug 2020						*/
/************************************************/
#ifndef LEDMRX_PRIVATE_H
#define LEDMRX_PRIVATE_H

void Display(u8 *Copy_u8Data);
void DisplayNextColumn(void);
static void DisableAllCols(void);
static void EnableAllCols(u8 Copy_u8Col);
static void SetRowValues(u8 Copy_u8Value);

#endif
