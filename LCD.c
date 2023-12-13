/*
 * LCD.c
 *
 * Created: 5/12/2023 8:55:10 PM
 *  Author: Mohamad oasma
 */ 
#include <avr/io.h>
#define  F_CPU 16000000ul
#include <util/delay.h>
#include "MACROS.h"



void LCD_SEND_DATA(char x)
{
	DDRB = 0xFF;
	PORTA = (x & 0xF0) | (PORTA &0X0F);
	SET_BIT (PORTB,1);   //set RS to send data
	CLR_BIT(PORTB,2);    // Clear RW to write
	SET_BIT (PORTB,3);   //Set Enable
	_delay_ms(1);
	CLR_BIT (PORTB,3);    //Clear Enable
	PORTA = (x<<4) | (PORTA & 0x0F);
	_delay_ms(1);
	SET_BIT (PORTB,3);    //Set Enable
	_delay_ms(1);
	CLR_BIT (PORTB,3);   //Clear Enable

}
void LCD_SEND_CMD (char x)
{
	PORTA = (x & 0xF0) | (PORTA &0X0F);
	
	/* Sending upper nibble */
	CLR_BIT (PORTB,1);   //set RS to send CMD
	CLR_BIT(PORTB,2);    // Clear RW to write
	SET_BIT (PORTB,3);   //Set Enable
	_delay_ms(1);
	CLR_BIT (PORTB,3);   //Clear Enable
	/* Sending Higher nibble */
	PORTA = (x<<4) | (PORTA & 0x0F);
	_delay_ms(1);
	SET_BIT (PORTB,3);   //Set Enable
	_delay_ms(1);
	CLR_BIT (PORTB,3);   //Clear Enable

}
void LCD_Init ()
{
	DDRA= 0xFF;
	SET_BIT(DDRB,1);		//Set RS
	SET_BIT(DDRB,2);		//Set RW
	SET_BIT(DDRB,3);		//Set enable
	
	LCD_SEND_CMD(0x02);		//return home
	LCD_SEND_CMD(0x28);		//2 line 4 BIT mode
	LCD_SEND_CMD(0x0C);		//display ON
	LCD_SEND_CMD(0x06);		//auto increment
	LCD_SEND_CMD(0x01);		//clear screen
	LCD_SEND_CMD(0b0000001111);
	LCD_SEND_CMD(0b0000011100);
	_delay_ms(20);
	
}
void LCD_SEND_STRING (unsigned char *str )
{	
	int i = 0;
	while(str[i]!=0)
	{
		LCD_SEND_DATA(str[i]);
		i++;
	}
}

 void lcdgoto(unsigned char x, unsigned char y){
	 unsigned char firstcharadr[] = {0x80, 0xC0, 0x94, 0xD4};
	 LCD_SEND_CMD(firstcharadr[y-1] + x-1);
	 _delay_us(1000);
 }

/*
void LCD_GoTo (char row, char pos)	/ * Send string to LCD with xy position * /
{
	if (row == 0 && pos<16)
	LCD_SEND_CMD((pos & 0x0F)|0x80);	/ * Command of first row and required position<16 * /
	else if (row == 1 && pos<16)
	LCD_SEND_CMD((pos & 0x0F)|0xC0);	/ * Command of first row and required position<16 * /
	
}
*/

void LCD_CLR_SCREEN() {
	LCD_SEND_CMD(0x01); // Send the Clear Display command (0x01)
	_delay_ms(2);     // Delay for 2 ms to allow the LCD to clear the display
}