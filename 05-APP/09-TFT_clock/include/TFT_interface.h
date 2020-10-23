/************************************************/
/* Author    : Assem Khaled						*/
/* Version   : V03								*/
/* Date      : 21 Sep 2020						*/
/************************************************/
#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H


// Color definitions
#define HTFT_COLOR_BLACK 		0x0000
#define HTFT_COLOR_NAVY 		0x000F
#define HTFT_COLOR_DARKGREEN 	0x03E0
#define HTFT_COLOR_DARKCYAN		0x03EF
#define HTFT_COLOR_MAROON		0x7800
#define HTFT_COLOR_PURPLE		0x780F
#define HTFT_COLOR_OLIVE		0x7BE0
#define HTFT_COLOR_LIGHTGREY	0xC618
#define HTFT_COLOR_DARKGREY		0x7BEF
#define HTFT_COLOR_BLUE			0x001F
#define HTFT_COLOR_GREEN		0x07E0
#define HTFT_COLOR_CYAN			0x07FF
#define HTFT_COLOR_RED			0xF800
#define HTFT_COLOR_MAGENTA		0xF81F
#define HTFT_COLOR_YELLOW		0xFFE0
#define HTFT_COLOR_WHITE		0xFFFF
#define HTFT_COLOR_GREY  		0x8410
#define HTFT_COLOR_ORANGE		0xE880
#define HTFT_COLOR_GREENYELLOW	0xAFE5
#define HTFT_COLOR_PINK			0xF81F


void HTFT_voidInitialize(void);
void HTFT_voidDisplayImage(const u16* Copy_u16Image);
void HTFT_voidFillColor(u16 Copy_u16Image);
void HTFT_voidDrawRect(u8 Copy_u8x1, u8 Copy_u8w, u8 Copy_u8y1, u8 Copy_u8h, u16 Copy_u16Color);
void HTFT_voidDrawChar(u8 Copy_u8Char, u8 Copy_u8x1, u8 Copy_u8y1, f32 Copy_f32Size, u16 Copy_u16Color, u16 Copy_u16BackColor);
void HTFT_voidDrawText(u8 *Copy_u8Text, s8 Copy_s8x1, u8 Copy_u8y1, f32 Copy_f32Size, u16 Copy_u16Color, u16 Copy_u16BackColor);
void HTFT_voidDrawNum(u32 u32Num, u8 Copy_u8x1, u8 Copy_u8y1, f32 Copy_f32Size, u16 Copy_u16Color, u16 Copy_u16BackColor); // Takes Number as a parameter

#endif
