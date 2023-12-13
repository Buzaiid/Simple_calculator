/*
 * Keypad.h
 *
 * Created: 5/13/2023 6:58:04 PM
 *  Author: Mohamed osama
 */ 




#ifndef KEYPAD_H_
#define KEYPAD_H_



#ifndef _sbit_h_
#define _sbit_h_

struct bits {
	uint8_t b0:1;
	uint8_t b1:1;
	uint8_t b2:1;
	uint8_t b3:1;
	uint8_t b4:1;
	uint8_t b5:1;
	uint8_t b6:1;
	uint8_t b7:1;
} __attribute__((__packed__));


#define SBIT(port,pin) ((*(volatile struct bits*)&port).b##pin)

#endif



void Keypad_init();
unsigned char Keypad_read();





#endif /* KEYPAD_H_ */