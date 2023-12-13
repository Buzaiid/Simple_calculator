/*
 * DIO_Module.c
 *
 * Created: 4/24/2023 4:59:44 PM
 *  Author: Mohammad Osama
 */ 
 

#include "DIO_Module.h"
#include "MACROS.h"
 
 void DIO_Set_Pin_Direction(u8 Port_ID , u8 Pin_ID , u8 Pin_Direction )
 
 {
	  switch (Port_ID)
	  {
		  case DIO_PORTA:
		  if(DIO_PIN_OUTPUT == Pin_Direction)
		  {
			  SET_BIT(DDRA,Pin_ID);
		  }
		  else
		  {
			  CLR_BIT(DDRA,Pin_ID);
		  }
		  break;
	  
	  
	  case DIO_PORTB:
		  if(DIO_PIN_OUTPUT == Pin_Direction)
		  {
			  SET_BIT(DDRB,Pin_ID);
		  }
		  else
		  {
			  CLR_BIT(DDRB,Pin_ID);
		  }
		  break;
		  
		  case DIO_PORTC:
		  if(DIO_PIN_OUTPUT == Pin_Direction)
		  {
			  SET_BIT(DDRC,Pin_ID);
		  }
		  else
		  {
			  CLR_BIT(DDRC,Pin_ID);
		  }
		  break;
		  
		  case DIO_PORTD:
		  if(DIO_PIN_OUTPUT == Pin_Direction)
		  {
			  SET_BIT(DDRD,Pin_ID);
		  }
		  else
		  {
			  CLR_BIT(DDRD,Pin_ID);
		  }
		  break;
		  
	  }	  
	  
 }
 
void DIO_Set_Pin_Value      (u8 Port_ID , u8 Pin_ID , u8 Pin_Value)
{
	switch (Port_ID)
	{
		case DIO_PORTA:
		if(DIO_PIN_HIGH==Pin_Value)
		{
			SET_BIT(PORTA,Pin_ID);
		}
		else
		{
			CLR_BIT(PORTA,Pin_ID);			
		}
		break;
	}
	
	
}
u8 DIO_Read_Pin_Value       (u8 Port_ID , u8 Pin_ID, u8 Pin_Value)
         {
		u8 result= DIO_PIN_LOW;
		switch (Port_ID)
		 {
		case DIO_PORTA:
			result = READ_BIT(PINA,Pin_ID);
		break;
		
		case DIO_PORTB:
			result = READ_BIT(PINB,Pin_ID)
			;
		break;
		
		case DIO_PORTC:
			result = READ_BIT(PINC,Pin_ID);
		break;
		
		case DIO_PORTD:
			result = READ_BIT(PIND,Pin_ID);
		break;
		
        }
	
	return result;
		}

void DIO_TGL_Pin_Value      (u8 Port_ID , u8 Pin_ID )
{
	switch (Port_ID)
	{
		case DIO_PORTA:
		TGL_BIT(PORTA,Pin_ID);
		break;
		
		case DIO_PORTB:
		TGL_BIT(PORTB,Pin_ID);
		break;
		
		case DIO_PORTC:
		TGL_BIT(PORTC,Pin_ID);
		break;
		
		case DIO_PORTD:
		TGL_BIT(PORTD,Pin_ID);
		break;
	}	
}

void DIO_Activate_PullUpRes(u8 Port_ID , u8 Pin_ID)
{
	switch (Port_ID)
	{
		case (DIO_PORTA):
		SET_BIT(PORTA,Pin_ID);
		break;
		
		case (DIO_PORTB):
		SET_BIT(PORTB,Pin_ID);
		break;
		
		case (DIO_PORTC):
		SET_BIT(PORTC,Pin_ID);
		break;
		
		case (DIO_PORTD):
		SET_BIT(PORTD,Pin_ID);
		break;
	}
}

void M_DIO_clearPort(u8 Port_ID)
{
	switch(Port_ID)
	{
		case DIO_PORTA:
			CLR_REG(PORTA);
		break;
		
		case DIO_PORTB:
			CLR_REG(PORTB);
		break;
		
		case DIO_PORTC:
			CLR_REG(PORTC);
		break;
		
		case DIO_PORTD:
			CLR_REG(PORTD);
		break;
		
	}
}

void M_DIO_setPortValue(u8 Port_ID, u8 Value)
{
	switch(Port_ID)
	{
		case DIO_PORTA:
			SET_REG_VAL(PORTA,Value);
		break;
		
		case DIO_PORTB:
			SET_REG_VAL(PORTB,Value);
		break;
		
		case DIO_PORTC:
			SET_REG_VAL(PORTC,Value);
		break;
		
		case DIO_PORTD:
			SET_REG_VAL(PORTD,Value);
		break;
		
	}
}

void M_DIO_setPortDirection(u8 Port_ID, u8 Mask) //0b00001111  15  0x0f
{
	switch(Port_ID)
	{
		case DIO_PORTA:
			SET_REG_VAL(DDRA,Mask);	//0b00001111
		break;
		
		case DIO_PORTB:
			SET_REG_VAL(DDRB,Mask);
		break;
		
		case DIO_PORTC:
			SET_REG_VAL(DDRC,Mask);
		break;
		
		case DIO_PORTD:
			SET_REG_VAL(DDRD,Mask);
		break;
		
	}
	
	
}

void M_DIO_setPortDirectionOutputMask(u8 Port_ID, u8 Mask) //0b00001111  15  0x0f
{
	switch(Port_ID)
	{
		case DIO_PORTA:
			SET_REG_MASK(DDRA,Mask);	//0b00001111
		break;
		
		case DIO_PORTB:
			SET_REG_MASK(DDRB,Mask);
		break;
		
		case DIO_PORTC:
			SET_REG_MASK(DDRC,Mask);
		break;
		
		case DIO_PORTD:
			SET_REG_MASK(DDRD,Mask);
		break;
		
	}
	
	
}

void M_DIO_setPortDirectionInputMask(u8 Port_ID, u8 Mask) //0b00001111  15  0x0f
{
	switch(Port_ID)
	{
		case DIO_PORTA:
			CLR_REG_MASK(DDRA,Mask);	//0b00001111
		break;
		
		case DIO_PORTB:
			CLR_REG_MASK(DDRB,Mask);
		break;
		
		case DIO_PORTC:
			CLR_REG_MASK(DDRC,Mask);
		break;
		
		case DIO_PORTD:
			CLR_REG_MASK(DDRD,Mask);
		break;
		
	}
	
	
}


void M_DIO_setPortValueHighMask(u8 Port_ID, u8 Mask)
{
	switch(Port_ID)
	{
		case DIO_PORTA:
			SET_REG_MASK(PORTA,Mask);
		break;
		
		case DIO_PORTB:
			SET_REG_MASK(PORTB,Mask);
		break;
		
		case DIO_PORTC:
			SET_REG_MASK(PORTC,Mask);
		break;
		
		case DIO_PORTD:
			SET_REG_MASK(PORTD,Mask);
		break;
		
	}
	
}

void M_DIO_setPortValueLowMask(u8 Port_ID, u8 Mask)
{
	switch(Port_ID)
	{
		case DIO_PORTA:
			CLR_REG_MASK(PORTA,Mask);
		break;
		
		case DIO_PORTB:
			CLR_REG_MASK(PORTB,Mask);
		break;
		
		case DIO_PORTC:
			CLR_REG_MASK(PORTC,Mask);
		break;
		
		case DIO_PORTD:
			CLR_REG_MASK(PORTD,Mask);
		break;
		
	}
}





