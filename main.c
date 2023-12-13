/*
 * GccApplication1.c
 *
 * Created: 12/7/2023 11:33:34 PM
 * Author : Mohammad Osama
 */ 

#include <avr/io.h>
#include <stdio.h>
#define F_CPU 16000000ul
#include <util/delay.h>
#include "LCD.h"
#include "Keypad.h"
#include "STD_TYPES.h"
#include "DIO_Module.h"
#include "calc.h"


int main(void)
{

	Keypad_init();
	LCD_Init();
	u8 key_press;
	u8 x = 0;
	u8 y = 0;
	char operand;



	LCD_SEND_STRING("Hello There! ");
	_delay_ms(200);
	LCD_CLR_SCREEN();
	lcdgoto(5,1);
	LCD_SEND_STRING("Welcome to ");
	lcdgoto(4,2);
	LCD_SEND_STRING("Calculator");
	_delay_ms(200);
	LCD_CLR_SCREEN();

    while (1) 
    {
		LCD_CLR_SCREEN();
		key_press=Keypad_read();
		x = Get_num(key_press);
		LCD_SEND_DATA(key_press);
		if ((x != Error))
		{
			key_press=Keypad_read();
			LCD_SEND_DATA(key_press);
			operand=Get_Operand(key_press);
			if (operand != 'e')
			{
				key_press = Keypad_read();
				LCD_SEND_DATA(key_press);
				y = Get_num(key_press);
			}
			if (y != Error)
			{
				 key_press = Keypad_read();	    	//get equal sign
				 LCD_SEND_DATA(key_press);			//print the key pressed to LCD
				 if(key_press == '=')				//if = is pressed then proceed
				 {
					 switch(operand)				//switch on Operand
					 {
						 case '+':
						 disp_num(x+y);
						 break;
						 case '-':
						 disp_num(x-y);
						 break;
						 case 'x':
						 disp_num(x*y);
						 break;
						 case '/':
						 disp_num(x/y);
						 break;
					 }
					 _delay_ms(50);
			}
			else {
				if(key_press == 'C')
				{LCD_CLR_SCREEN();}
					else 
					DispError('1');
			}
			}
			}
		}
	return 0;
}
