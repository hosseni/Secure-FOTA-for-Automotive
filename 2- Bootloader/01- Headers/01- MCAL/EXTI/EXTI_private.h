/*
 * EXTI_private.h
 *
 *  Created on: ١٨‏/٠٨‏/٢٠٢٢
 *      Author: ELHOSSENI
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

#include "../Inc/LIB/STD_TYPES.h"

#define EXTI ((volatile EXTI_t*)0x40010400)
typedef struct
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;

}EXTI_t;
#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
