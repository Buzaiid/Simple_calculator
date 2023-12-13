/*
 * calc.h
 *
 * Created: 12/8/2023 3:26:49 PM
 *  Author: Naa
 */ 


#ifndef CALC_H_
#define CALC_H_

#include <avr/io.h>


#define Error   0

#define WRONGINPUT   1
#define WRONGOPERAND 0

int Get_num(unsigned char);
unsigned char Get_Operand(unsigned char);
void DispError(int);
void disp_num(int);



#endif /* CALC_H_ */