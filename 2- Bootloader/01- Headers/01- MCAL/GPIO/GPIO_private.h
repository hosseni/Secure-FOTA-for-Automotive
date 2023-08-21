/*
 * GPIO_private.h
 *
 *  Created on: Aug 14, 2022
 *      Author: ELHOSSENI
 */

#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_

#define PORTA ((volatile PortA_t *) 0x40010800)
#define PORTB ((volatile PortB_t *) 0x40010C00)
#define PORTC ((volatile PortC_t *) 0x40011000)

typedef struct
{
	volatile u32 GPIOA_CRL;
	volatile u32 GPIOA_CRH;
	volatile u32 GPIOA_IDR;
	volatile u32 GPIOA_ODR;
	volatile u32 GPIOA_BSRR;
	volatile u32 GPIOA_BRR;
	volatile u32 GPIOA_LCKR;

}PortA_t;
typedef struct
{
	volatile u32 GPIOB_CRL;
	volatile u32 GPIOB_CRH;
	volatile u32 GPIOB_IDR;
	volatile u32 GPIOB_ODR;
	volatile u32 GPIOB_BSRR;
	volatile u32 GPIOB_BRR;
	volatile u32 GPIOB_LCKR;
}PortB_t;
typedef struct
{
	volatile u32 GPIOC_CRL;
	volatile u32 GPIOC_CRH;
	volatile u32 GPIOC_IDR;
	volatile u32 GPIOC_ODR;
	volatile u32 GPIOC_BSRR;
	volatile u32 GPIOC_BRR;
	volatile u32 GPIOC_LCKR;
}PortC_t;

#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
