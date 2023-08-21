/*
 * RCC_program.c
 *
 *  Created on: Aug 11, 2022
 *      Author: Elhosseni
 */


#include "../Inc/LIB/BIT_MATH.h"
#include "../Inc/LIB/STD_TYPES.h"


#include "../Inc/MCAL/RCC/RCC_interface.h"
#include "../Inc/MCAL/RCC/RCC_private.h"
#include "../Inc/MCAL/RCC/RCC_configuration.h"

void MRCC_voidInit (void)
{
#if CLK_SOURCE == HSI
	/*step (1): Turn on HSI*/
	MRCC_voidClkEnable(HSI);

	/*step (2): check HSI is ready*/
	while (MRCC_u8CheckClockReady(HSI) == NOT_READY);

	/*step (3): set buses prescaller*/
	MRCC_voidSetBusesPrescaler(AHB_PRESCALER, ABP1_PRESCALER, ABP2_PRESCALER);

	/*step (4): switch to HSI clock*/
	MRCC_voidSetClkSource(HSI);

	/*step (5): turn off HSE and PLL*/
	MRCC_voidClkDisable(HSE);
	MRCC_voidClkDisable(PLL);

#elif CLK_SOURCE == HSE
		/*step (1): Turn on HSE*/
		MRCC_voidClkEnable(HSE);

		/*step (2): check HSE is ready*/
		while (MRCC_u8CheckClockReady(HSE) == NOT_READY);

		/*step (3): set buses prescaller*/
		MRCC_voidSetBusesPrescaler(AHB_PRESCALER, ABP1_PRESCALER, ABP2_PRESCALER);

		/*step (4): switch to HSE clock*/
		MRCC_voidSetClkSource(HSE);

		/*step (5): turn off HSI and PLL*/
		MRCC_voidClkDisable(HSI);
		MRCC_voidClkDisable(PLL);

#elif CLK_SOURCE == PLL
	#if PLL_SOURCE == HSE
		/*step(1): set PLL source*/
		MRCC_voidSetPLLSource(PLL_SOURCE, PLL_HSE_FACTOR);
		/*step(2): turn on HSE*/
		MRCC_voidClkEnable(HSE);
		/*step(3): check HSE is ready*/
		while (MRCC_u8CheckClockReady(HSE) == NOT_READY);
		/*step(4): turn on HSI*/
		MRCC_voidClkEnable(HSI);
		/*step(5): check HSI is ready*/
		while (MRCC_u8CheckClockReady(HSI) == NOT_READY);
		/*step(6): switch to HSI clock*/
		MRCC_voidSetClkSource(HSI);
	#elif PLL_SOURCE == HSI
				/*step(1): set PLL source*/
				MRCC_voidSetPLLSource(PLL_SOURCE, PLL_HSE_FACTOR);
				/*step(2): turn on HSE*/
				MRCC_voidClkEnable(HSE);
				/*step(3): check HSE is ready*/
				while (MRCC_u8CheckClockReady(HSE) == NOT_READY);
				/*step(4): turn on HSI*/
				MRCC_voidClkEnable(HSI);
				/*step(5): check HSI is ready*/
				while (MRCC_u8CheckClockReady(HSI) == NOT_READY);
				/*step(6): switch to HSE clock*/
				MRCC_voidSetClkSource(HSE);
	#else
	#error Wrong PLL Configurations
	#endif /*PLL_SOURCE*/

		/*step(7):  set PLL multiplication factor*/
		MRCC_voidSetPLLMulFactor(PLL_MULTIPLICATION_FACTOR);

		/*step(8):  set buses prescaller*/
		MRCC_voidSetBusesPrescaler(AHB_PRESCALER, ABP1_PRESCALER, ABP2_PRESCALER);

		/*step(9):  turn on PLL*/
		MRCC_voidClkEnable(PLL);
		/*step(10): check PLL is ready*/
		while (MRCC_u8CheckClockReady(PLL) == NOT_READY);

		/*step(11): switch to HSI clock*/
		MRCC_voidSetClkSource(HSI);

#if PLL_SOURCE == HSE
		/*step(12): turn off HSI*/
		MRCC_voidClkDisable(HSI);
#elif PLL_SOURCE == HSI
		/*step(12): turn off HSI*/
		MRCC_voidClkDisable(HSE);
#endif

#else
#error Wrong PLL Configurations
#endif /*CLK_SOURCE*/
}
void MRCC_voidClkEnable (u8 A_u8ClkSource)
{
	switch (A_u8ClkSource)
	{
	case HSI: SET_BIT(RCC->CR, HSI_ON_BIT); break;
	case HSE: SET_BIT(RCC->CR, HSE_ON_BIT); break;
	case PLL: SET_BIT(RCC->CR, PLL_ON_BIT); break;
	}
}

void MRCC_voidClkDisable (u8 A_u8ClkSource)
{
		switch (A_u8ClkSource)
		{
		case HSI: CLR_BIT(RCC->CR, HSI_ON_BIT); break;
		case HSE: CLR_BIT(RCC->CR, HSE_ON_BIT); break;
		case PLL: CLR_BIT(RCC->CR, PLL_ON_BIT); break;
		}
}

u8 MRCC_u8CheckClockReady (u8 A_u8ClkSource)
{
	u8 local_u8ReadyFlag = 0;
	switch (A_u8ClkSource)
		{
		case HSI: local_u8ReadyFlag = GET_BIT(RCC->CR, HSI_RDY_BIT); break;
		case HSE: local_u8ReadyFlag = GET_BIT(RCC->CR, HSE_RDY_BIT); break;
		case PLL: local_u8ReadyFlag = GET_BIT(RCC->CR, PLL_RDY_BIT); break;
		}
	return local_u8ReadyFlag;
}

void MRCC_voidSetBusesPrescaler (u8 A_u8AHBPrescaler, u8 A_u8APB1Prescaler, u8 A_u8APB2Prescaler)
{
	/* BUSES_PRESCALER_RESET_MASK: is a mask to clear only bits used in prescaller set for AHB - APB1 - APB2 */
	RCC->CFGR &= ~(BUSES_PRESCALER_RESET_MASK);
	RCC->CFGR |=  (A_u8AHBPrescaler  << AHB_PRESCALER_FBIT);
	RCC->CFGR |=  (A_u8APB1Prescaler << APB1_PRESCALER_FBIT);
	RCC->CFGR |=  (A_u8APB2Prescaler << APB2_PRESCALER_FBIT);
}


void MRCC_voidSetClkSource(u8 A_u8ClkSource)
{
	switch (A_u8ClkSource)
	{
	case HSI: CLR_BIT(RCC->CFGR, SYSTEM_CLOCK_BIT0);
			  CLR_BIT(RCC->CFGR, SYSTEM_CLOCK_BIT1);break;

	case HSE: SET_BIT(RCC->CFGR, SYSTEM_CLOCK_BIT0);
	  	  	  CLR_BIT(RCC->CFGR, SYSTEM_CLOCK_BIT1);break;

	case PLL: CLR_BIT(RCC->CFGR, SYSTEM_CLOCK_BIT0);
	  	  	  SET_BIT(RCC->CFGR, SYSTEM_CLOCK_BIT1);break;
	}
}

void MRCC_voidSetPLLSource(u8 A_u8ClkSource, u8 A_u8Prescaler)
{
	switch(A_u8ClkSource)
	{
	case HSI:CLR_BIT(RCC->CFGR, PLLSRC_BIT); break;
	case HSE:SET_BIT(RCC->CFGR, PLLSRC_BIT);
		switch (A_u8Prescaler)
		{
		case HSE_NOT_DIVIDED: CLR_BIT(RCC->CFGR, PLLXTPRE_BIT); break;
		case HSE_DIVIDED:	  SET_BIT(RCC->CFGR, PLLXTPRE_BIT); break;
		}
	}
}

void MRCC_voidSetPLLMulFactor(u8 A_u8MulFactor)
{
	/*MULTIPLICATION_FACTOR_RESET_MASK: is a mask to clear 4 bit for multiplication factor at CFGR register started from bit 18*/
		RCC->CFGR &= ~(MULTIPLICATION_FACTOR_RESET_MASK);
		RCC->CFGR |= (A_u8MulFactor << PLL_MUL_FBIT);
}


void MRCC_voidPreipheralEnable (u8 A_u8BusID, u8 A_u8PrephieralID)
{
	if (A_u8PrephieralID < 31)
	{
			switch (A_u8BusID)
			{
			case AHB  : SET_BIT( RCC->AHBENR,  A_u8PrephieralID); break;
			case APB1 : SET_BIT( RCC->APB1ENR, A_u8PrephieralID); break;
			case APB2 : SET_BIT( RCC->APB2ENR, A_u8PrephieralID); break;
			}
	}
}


void MRCC_voidPreipheralDisable (u8 A_u8BusID, u8 A_u8PrephieralID)
{
	if (A_u8PrephieralID < 31)
	{
		switch (A_u8BusID)
		{
		case AHB  : CLR_BIT( RCC->AHBENR,  A_u8PrephieralID); break;
		case APB1 : CLR_BIT( RCC->APB1ENR, A_u8PrephieralID); break;
		case APB2 : CLR_BIT( RCC->APB2ENR, A_u8PrephieralID); break;
		}
	}
}
