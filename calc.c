/*
 * calc.c
 *
 * Created: 12/8/2023 3:27:02 PM
 *  Author: Naa
 */ 

#define F_CPU 16000000ul
#include <util/delay.h>
#include <avr/io.h>



#include "STD_TYPES.h"
#include "Keypad.h"
#include "calc.h"
#include "LCD.h"





int Get_num(u8 chr){
	
	int num = 0;
	
	switch(chr)
	{
		case '0':
			num=0;
			break;
		case '1':
			num=1;
			break;
		case '2':
			num=2;
			break;
		case '3':
			num=3;
			break;
		case '4':
			num=4;
			break;
		case '5':
			num=5;
			break;
		case '6':
			num=6;
			break;
		case '7':
			num=7;
			break;
		case '8':
			num=8;
			break;
		case '9':
			num=9;
			break;
		case 'C':
			LCD_SEND_CMD(0x01);
			num=Error;
			break;	
	}
	return num;
}

unsigned char Get_Operand(u8 Operand){

	if ((Operand != '+') &&( Operand != '-' )&& (Operand != '/') && (Operand != 'x'))
	{
		DispError(0);
		return 'e';
	}
	else
	return Operand;
}

void DispError(int x){

	unsigned char msg1[] = {"Wrong Input"};
	unsigned char msg2[] = {"Wrong Function"};

	LCD_SEND_CMD(0x01);             
	switch(x)
	{
		case 0:
		LCD_SEND_STRING(msg1);
		break;
		case 1:
		LCD_SEND_STRING(msg2);
		break;
		default:
		LCD_SEND_STRING(msg1);
		break;
	}
	}


void disp_num(int numb){
	
		u8 Unit_Digit = 0;
		u8 Tenth_Digit = 0;
	
	if (numb < 0)
	{
		numb=-1*numb;
		LCD_SEND_DATA('-');
	}
	Tenth_Digit = (numb/10);          
	if( Tenth_Digit != 0)             
	LCD_SEND_DATA(Tenth_Digit+0x30);  
	Unit_Digit = numb - Tenth_Digit*10;
	LCD_SEND_DATA(Unit_Digit+0x30);   
}