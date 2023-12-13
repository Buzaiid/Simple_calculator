/*
 * LCD.h
 *
 * Created: 5/12/2023 8:54:55 PM
 *  Author: Mohamad osama
 */ 


#ifndef LCD_H_
#define LCD_H_



void LCD_SEND_DATA(char x);
void LCD_SEND_CMD (char x);
void LCD_Init ();
void LCD_SEND_STRING(char *ptr);
void LCD_GoTo (char x, char y);
void LCD_CLR_SCREEN(void);
void lcdgoto(unsigned char x, unsigned char y);


#endif /* LCD_H_ */