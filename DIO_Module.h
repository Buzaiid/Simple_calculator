/*
 * DIO_Module.h
 *
 * Created: 4/24/2023 4:56:30 PM
 *  Author: Mohammad Osama
 */ 


#ifndef DIO_MODULE_H_
#define DIO_MODULE_H_
#include <avr/io.h>
#include "MACROS.h"
#include "STD_TYPES.h"
                        /* MACROS FOR Port_ID*/
#define DIO_PORTA   0
#define DIO_PORTB   1
#define DIO_PORTC   2
#define DIO_PORTD   3
                        /* MACROS FOR Pin_Direction*/

#define DIO_PIN_INPUT     0
#define DIO_PIN_OUTPUT    1
                        /* MACROS FOR Pin_Value*/
#define DIO_PIN0         0
#define DIO_PIN1         1
#define DIO_PIN2         2
#define DIO_PIN3         3
#define DIO_PIN4         4
#define DIO_PIN5         5
#define DIO_PIN6         6
#define DIO_PIN7         7     
                        /* MACROS FOR PIN_STATE*/

#define DIO_PIN_LOW       0
#define DIO_PIN_HIGH      1

       
void DIO_Set_Pin_Direction  (u8 Port_ID , u8 Pin_ID , u8 Pin_Direction );
void DIO_Set_Pin_Value      (u8 Port_ID , u8 Pin_ID , u8 Pin_Value);
u8 DIO_Read_Pin_Value       (u8 Port_ID , u8 Pin_ID, u8 Pin_Value);
void DIO_TGL_Pin_Value      (u8 Port_ID , u8 Pin_ID );
void DIO_Activate_PullUpRes (u8 Port_ID , u8 Pin_ID);


void M_DIO_clearPort(u8 Port_ID);
void M_DIO_setPortValue(u8 Port_ID, u8 Value);
void M_DIO_setPortValueLowMask(u8 Port_ID, u8 Mask);
void M_DIO_setPortValueHighMask(u8 Port_ID, u8 Mask);
void M_DIO_setPortDirection(u8 Port_ID, u8 Mask);
void M_DIO_setPortDirectionOutputMask(u8 Port_ID ,u8 Mask);
void M_DIO_setPortDirectionInputMask(u8 Port_ID, u8 Mask);

#endif /* DIO_MODULE_H_ */