/*
 * GPIO_program.c
 *
 *  Created on: Aug 14, 2022
 *      Author: ELHOSSENI
 */



#include "../Inc/LIB/STD_TYPES.h"
#include "../Inc/LIB/BIT_MATH.h"

#include "../Inc/MCAL/GPIO/GPIO_interface.h"
#include "../Inc/MCAL/GPIO/GPIO_private.h"
#include "../Inc/MCAL/GPIO/GPIO_configuration.h"



void MGPIO_voidSetPinDirection(GPIO_PORT_t PortID, GPIO_PIN_t PinID, GPIO_DIRECTION_t Direction)
{
			/*range check*/
		if (PortID <= GPIO_U8_PORTC && PinID <= GPIO_U8_PIN15)
		{
		switch (PortID)
		{
		case GPIO_U8_PORTA:
		{
			if (PinID < 8)  /*CRL*/
			{
				PORTA->GPIOA_CRL &= ~((0b1111)   << (PinID * 4));
				PORTA->GPIOA_CRL |=  ((Direction)<< (PinID * 4));
			}
			else if (PinID <16 && PinID >7)/*CRH*/
			{
				PinID -= 8;
				PORTA->GPIOA_CRH &= ~((0b1111)   << (PinID * 4));
				PORTA->GPIOA_CRH |=  ((Direction)<< (PinID * 4));
			}
			else /*Error*/
			{}
			break;
		}
		case GPIO_U8_PORTB:
		{
			if (PinID < 8)  /*CRL*/
			{
				PORTB->GPIOB_CRL &= ~((0b1111)   << (PinID * 4));
				PORTB->GPIOB_CRL |=  ((Direction)<< (PinID * 4));
			}
			else if (PinID <16 && PinID >7)/*CRH*/
			{
				PinID -= 8;
				PORTB->GPIOB_CRH &= ~((0b1111)   << (PinID * 4));
				PORTB->GPIOB_CRH |=  ((Direction)<< (PinID * 4));
			}
			else /*Error*/
			{	}
			break;
		}
		case GPIO_U8_PORTC:
		{
			if (PinID < 8)  /*CRL*/
			{
			PORTC->GPIOC_CRL &= ~((0b1111)   << (PinID * 4));
			PORTC->GPIOC_CRL |=  ((Direction)<< (PinID * 4));
			}
			else if (PinID <16 && PinID >7)/*CRH*/
			{
				PinID -= 8;
				PORTC->GPIOC_CRH &= ~((0b1111)   << (PinID * 4));
				PORTC->GPIOC_CRH |=  ((Direction)<< (PinID * 4));
			}
			else /*Error*/
			{}
			break;
		}

		}/*switch*/
	}/*if check range*/
}
void MGPIO_voidSetPinValue(GPIO_PORT_t PortID, GPIO_PIN_t PinID, GPIO_VALUE_t Value)
{
	/*range check*/
		if (PortID <= GPIO_U8_PORTC && PinID <= GPIO_U8_PIN15)
		{
			if (Value == GPIO_HIGH)
			{
				switch (PortID)
				{


				case GPIO_U8_PORTA : SET_BIT(PORTA->GPIOA_ODR, PinID); break;
				case GPIO_U8_PORTB : SET_BIT(PORTB->GPIOB_ODR, PinID); break;
				case GPIO_U8_PORTC : SET_BIT(PORTC->GPIOC_ODR, PinID); break;
				/*
				case GPIO_U8_PORTA :	PORTA->GPIOA_BSRR = (1 << PinID); break;
				case GPIO_U8_PORTB : 	PORTB->GPIOB_BSRR = (1 << PinID); break;
				case GPIO_U8_PORTC : 	PORTC->GPIOC_BSRR = (1 << PinID); break;
*/
				}
			}
			else if (Value == GPIO_LOW)
			{
				switch (PortID)
				{

				case GPIO_U8_PORTA : CLR_BIT(PORTA->GPIOA_ODR, PinID); break;
				case GPIO_U8_PORTB : CLR_BIT(PORTB->GPIOB_ODR, PinID); break;
				case GPIO_U8_PORTC : CLR_BIT(PORTC->GPIOC_ODR, PinID); break;
				/*
				case GPIO_U8_PORTA :	PORTA->GPIOA_BRR = (1 << PinID); break;
				case GPIO_U8_PORTB : 	PORTB->GPIOB_BRR = (1 << PinID); break;
				case GPIO_U8_PORTC : 	PORTC->GPIOC_BRR = (1 << PinID); break;*/}
			}
		}
}
u8 MGPIO_u8GetPinValue(GPIO_PORT_t PortID, GPIO_PIN_t PinID)
{
u8 Local_u8Value = 0x55;
			/*range check*/
		if (PortID <= GPIO_U8_PORTC && PinID <= GPIO_U8_PIN15)
		{
			switch (PortID)
			{
			case GPIO_U8_PORTA : Local_u8Value = GET_BIT(PORTA->GPIOA_IDR, PinID); break;
			case GPIO_U8_PORTB : Local_u8Value = GET_BIT(PORTB->GPIOB_IDR, PinID); break;
			case GPIO_U8_PORTC : Local_u8Value = GET_BIT(PORTC->GPIOC_IDR, PinID); break;
			}
		}
		else
		{
		}

return Local_u8Value;
}

void MGPIO_voidSetPortDirection (GPIO_PORT_t portID, GPIO_DIRECTION_t Direction)
{
	if (portID <= GPIO_U8_PORTC)
	{
		int PinID = 0;
		switch(portID)
		{
		case GPIO_U8_PORTA:

			PORTA->GPIOA_CRL = 0x00000000;
			PORTA->GPIOA_CRH = 0x00000000;

			for (int PinID = 0 ; PinID <= 7 ; PinID++)
			{
			PORTA->GPIOA_CRL |=  ((Direction)<< (PinID * 4));
			PORTA->GPIOA_CRH |=  ((Direction)<< (PinID * 4));
			}
			break;

		case GPIO_U8_PORTB:

			PORTB->GPIOB_CRL = 0x00000000;
			PORTB->GPIOB_CRH = 0x00000000;

			for ( PinID = 0 ; PinID <= 7 ; PinID++)
			{
			PORTB->GPIOB_CRL |=  ((Direction)<< (PinID * 4));
			PORTB->GPIOB_CRH |=  ((Direction)<< (PinID * 4));
			}
			break;

		case GPIO_U8_PORTC:

			PORTC->GPIOC_CRL = 0x00000000;
			PORTC->GPIOC_CRH = 0x00000000;

			for ( PinID = 0 ; PinID <= 7 ; PinID++)
			{
			PORTC->GPIOC_CRL |=  ((Direction)<< (PinID * 4));
			PORTC->GPIOC_CRH |=  ((Direction)<< (PinID * 4));
			}
			break;
		}/*switch*/
	}/*if*/
}

void MGPIO_voidSetPortValue (GPIO_PORT_t portID, u8 value)
{
	if (portID <= GPIO_U8_PORTC)
	{
		switch(portID)
		{
		case GPIO_U8_PORTA : PORTA->GPIOA_ODR = value;  break;
		case GPIO_U8_PORTB : PORTB->GPIOB_ODR = value;  break;
		case GPIO_U8_PORTC : PORTC->GPIOC_ODR = value;  break;
		}/*switch*/
	}/*if*/
}
