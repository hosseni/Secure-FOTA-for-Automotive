/*
 * NVIC_program.c
 *
 *  Created on: ١٧‏/٠٨‏/٢٠٢٢
 *      Author: ELHOSSENI
 */

#include "../Inc/LIB/BIT_MATH.h"
#include "../Inc/LIB/STD_TYPES.h"
#include "../Inc/MCAL/NVIC/NVIC_interface.h"
#include "../Inc/MCAL/NVIC/MNVIC_private.h"
#include "../Inc/MCAL/NVIC/NVIC_configuration.h"

void MNVIC_voidInit (void)
{
	SCB_AIRCR = MNVIC_GRP_SUB;
}
void MNVIC_voidEnableInterrupt  (u8 Copy_u8IntNum)
{
	/*range check*/
	if (Copy_u8IntNum < 32)
	{
		NVIC_ISER0 = (1 << Copy_u8IntNum);
	}
	else if (Copy_u8IntNum >= 32 && Copy_u8IntNum < 64)
	{
		Copy_u8IntNum -=32;
		NVIC_ISER1 = (1 << Copy_u8IntNum );
	}else
	{
	}
}
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNum)
{
	/*range check*/
		if (Copy_u8IntNum < 32)
		{
			NVIC_ICER0 = (1 << Copy_u8IntNum);
		}
		else if (Copy_u8IntNum >= 32 && Copy_u8IntNum < 64)
		{
			Copy_u8IntNum -=32;

			NVIC_ICER1 = (1 << Copy_u8IntNum);
		}
		else
		{
		}
}

void MNVIC_voidSetPendingFlag   (u8 Copy_u8IntNum)
{
	/*range check*/
		if (Copy_u8IntNum < 32)
		{
			NVIC_ISPR0 = (1 << Copy_u8IntNum);
		}
		else if (Copy_u8IntNum >= 32 && Copy_u8IntNum < 64)
		{
			Copy_u8IntNum -=32;
			NVIC_ISPR1 = (1 << Copy_u8IntNum );
		}
		else
		{
		}
}
void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNum)
{
		/*range check*/
		if (Copy_u8IntNum < 32)
		{
			NVIC_ICPR0 = (1 << Copy_u8IntNum);
		}
		else if (Copy_u8IntNum >= 32 && Copy_u8IntNum < 64)
		{
			Copy_u8IntNum -=32;
			NVIC_ICPR1 = (1 << Copy_u8IntNum );
		}
			else
		{
		}
}

u8 MNVIC_u8GetAvticeFlag (u8 Copy_u8IntNum)
{
	u8 Local_u8Value = 0x55; /*because this function will return 1 or 0*/
	/*range check*/
		if (Copy_u8IntNum < 32)
		{
			Local_u8Value = GET_BIT(NVIC_IABR0, Copy_u8IntNum);
		}
		else if (Copy_u8IntNum >= 32 && Copy_u8IntNum < 64)
		{
			Copy_u8IntNum -=32;
			Local_u8Value = GET_BIT(NVIC_IABR1, Copy_u8IntNum );
		}
			else
		{
		}
		return Local_u8Value;
}



void MNVIC_voidSetPriority (u8 Copy_u8IntNum, u8 Copy_u8GroupNum, u8 Copy_u8SubNum)
{

	u8 Local_u8PriorityNum = 0;

#if MNVIC_GRP_SUB == NVIC_16_GROUP_0_SUB
	/*check range*/
	if ((Copy_u8GroupNum >= 0 ) && (Copy_u8GroupNum < 15) && (Copy_u8SubNum == 0))
	{
		Local_u8PriorityNum = Copy_u8GroupNum  ;
		NVIC_IPR [Copy_u8IntNum] = (Local_u8PriorityNum << 4);
	}
#elif MNVIC_GRP_SUB == NVIC_8_GROUP_2_SUB
	/*check range*/
	if ((Copy_u8GroupNum >= 0 ) && (Copy_u8GroupNum <= 7) && (Copy_u8SubNum >= 0) && (Copy_u8SubNum < 2) )
	{
		Local_u8PriorityNum = ( (Copy_u8GroupNum << 1) |  (Copy_u8SubNum) );
		NVIC_IPR [Copy_u8IntNum] = (Local_u8PriorityNum << 4);
	}
#elif MNVIC_GRP_SUB == NVIC_4_GROUP_4_SUB
	/*check range*/
	if ((Copy_u8GroupNum >= 0 ) && (Copy_u8GroupNum < 4) && (Copy_u8SubNum >= 0) && (Copy_u8SubNum < 4) )
	{
		Local_u8PriorityNum = ( (Copy_u8GroupNum << 2) |  (Copy_u8SubNum) );
		NVIC_IPR [Copy_u8IntNum] = (Local_u8PriorityNum << 4);
	}
#elif MNVIC_GRP_SUB == NVIC_2_GROUP_8_SUB
	/*check range*/
	if ((Copy_u8GroupNum >= 0 ) && (Copy_u8GroupNum < 2) && (Copy_u8SubNum >= 0) && (Copy_u8SubNum < 8) )
	{
		Local_u8PriorityNum = ( (Copy_u8GroupNum << 3) |  (Copy_u8SubNum) );
		NVIC_IPR [Copy_u8IntNum] = (Local_u8PriorityNum << 4);
	}
#elif MNVIC_GRP_SUB == NVIC_0_GROUP_16_SUB
	/*check range*/
	if ((Copy_u8GroupNum == 0 )  && (Copy_u8SubNum >= 0) && (Copy_u8SubNum < 16) )
	{
		Local_u8PriorityNum =   Copy_u8SubNum;
		NVIC_IPR [Copy_u8IntNum] = (Local_u8PriorityNum << 4);
	}
#endif
}
