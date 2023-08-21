/*
 * AFIO_private.h
 *
 *  Created on: Aug 21, 2022
 *      Author: ELHOSSENI
 */

#ifndef MCAL_AFIO_AFIO_PRIVATE_H_
#define MCAL_AFIO_AFIO_PRIVATE_H_


#define AFIO ((volatile AFIO_t*)0x40010000)

typedef struct
{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR1;
	volatile u32 EXTICR2;
	volatile u32 EXTICR3;
	volatile u32 EXTICR4;
	volatile u32 MAPR2;
}AFIO_t;


#endif /* MCAL_AFIO_AFIO_PRIVATE_H_ */
