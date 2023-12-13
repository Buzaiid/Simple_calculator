/*
 * Keypad.c
 *
 * Created: 5/13/2023 6:57:52 PM
 *  Author: Mohamad osama
 */


#define F_CPU 16000000ul
#include <util/delay.h>
#include <avr/io.h>
#include "Keypad.h"
#include "MACROS.h"

#define R1 SBIT(PORTC, 0)
#define R2 SBIT(PORTC, 1)
#define R3 SBIT(PORTC, 2)
#define R4 SBIT(PORTC, 3)
#define c1 SBIT(PINC, 4)
#define c2 SBIT(PINC, 5)
#define c3 SBIT(PINC, 6)
#define c4 SBIT(PINC, 7)




void Keypad_init()
{
    DDRC = 0x0f; //00001111
    PORTC = 0xff;
}

/*
char Keypad_read()
{
    char key = 0;
    CLR_BIT (PORTC,0);
    if (READ_BIT (PINC,4)==0)
    {
        key = '7';
        while (READ_BIT (PINC,4)==0);
    }
    else if (READ_BIT (PINC,5)==0)
    {
        key = '8';
        while (READ_BIT (PINC,5)==0);
    }
    else if (READ_BIT (PINC,6)==0)
    {
        key = '9';
        while (READ_BIT (PINC,6)==0);
    }

    else if (READ_BIT (PINC,7)==0)
    {
        key = '/';
        while (READ_BIT (PINC,7)==0);
    }
    _delay_ms(1);

    SET_BIT(PORTC,0);
    CLR_BIT(PORTC,1);

    if (READ_BIT (PINC,4)==0)
    {
        key = '4';
        while (READ_BIT (PINC,4)==0);
    }
    else if (READ_BIT (PINC,5)==0)
    {
        key = '5';
        while (READ_BIT (PINC,5)==0);
    }
    else if (READ_BIT (PINC,6)==0)
    {
        key = '6';
        while (READ_BIT (PINC,6)==0);
    }

    else if (READ_BIT (PINC,7)==0)
    {
        key = '*';
        while (READ_BIT (PINC,7)==0);
    }
	_delay_ms(1);

    SET_BIT(PORTC,1);
    CLR_BIT(PORTC,2);


    if (READ_BIT (PINC,4)==0)
    {
        key = '1';
        while (READ_BIT (PINC,4)==0);
    }
    else if (READ_BIT (PINC,5)==0)
    {
        key = '2';
        while (READ_BIT (PINC,5)==0);
    }
    else if (READ_BIT (PINC,6)==0)
    {
        key = '3';
        while (READ_BIT (PINC,6)==0);
    }

    else if (READ_BIT (PINC,7)==0)
    {
        key = '-';
        while (READ_BIT (PINC,7)==0);
    }
	_delay_ms(1);



    SET_BIT(PORTC,2);
    CLR_BIT(PORTC,3);


    if (READ_BIT (PINC,4)==0)
    {
        key = 'C';
        while (READ_BIT (PINC,4)==0);
    }
    else if (READ_BIT (PINC,5)==0)
    {
        key = '0';
        while (READ_BIT (PINC,5)==0);
    }
    else if (READ_BIT (PINC,6)==0)
    {
        key = '=';
        while (READ_BIT (PINC,6)==0);
    }

    else if (READ_BIT (PINC,7)==0)
    {
        key = '+';
        while (READ_BIT (PINC,7)==0);
    }
    _delay_ms(1);
    SET_BIT(PORTC,3);

    return key;
}
*/



unsigned char Keypad_read(void)
{
	
	DDRC=0b00001111;
	PORTC=0b11110000;

	while (1)
	{
		R1=0;     R2=1;     R3=1;     R4=1;
		_delay_us(50);
		if (c1==0){while (c1==0);return ('7');}
		if(c2==0){while (c2==0); return ('8');}
		if (c3==0){while (c3==0); return ('9');}
		if(c4==0){while (c4==0);return ('/');}
		
		R1=1;     R2=0;     R3=1;     R4=1;
		_delay_us(50);
		if (c1==0){while (c1==0); return ('4');}
		if(c2==0){while (c2==0); return ('5');}
		if(c3==0){while (c3==0); return ('6');}
		if(c4==0){while (c4==0); return ('x');}
		
		R1=1;     R2=1;     R3=0;     R4=1;
		_delay_us(50);
		if (c1==0){while (c1==0); return ('1');}
		if (c2==0){while (c2==0); return ('2');}
		if (c3==0){while (c3==0); return ('3');}
		if (c4==0){while (c4==0); return ('-');}
		
		R1=1;     R2=1;     R3=1;     R4=0;
		_delay_us(50);
		if (c1==0){while (c1==0); return ('C');}
		if (c2==0){while (c2==0); return ('0');}
		if (c3==0){while (c3==0); return ('=');}
		if (c4==0){while (c4==0); return ('+');}
	}

}




