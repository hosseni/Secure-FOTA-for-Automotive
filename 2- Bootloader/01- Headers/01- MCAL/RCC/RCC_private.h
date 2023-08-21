/*
 * RCC_private.h
 *
 *  Created on: Aug 11, 2022
 *      Author: ELHOSSENI
 */

#ifndef MCAL_RCC_RCC_PRIVATE_H_
#define MCAL_RCC_RCC_PRIVATE_H_

/* this address from Register boundary address */
#define RCC ((volatile RCC_t *) 0x40021000)


/*** this structure for RCC registers ***/
typedef struct
{
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
}RCC_t;

/**clock source ON bit**/
#define HSI_ON_BIT  0
#define HSE_ON_BIT  16
#define PLL_ON_BIT  24

/**clock source Ready bit**/
#define HSI_RDY_BIT 1
#define HSE_RDY_BIT 17
#define PLL_RDY_BIT 25

#define  SYSTEM_CLOCK_BIT0 0
#define  SYSTEM_CLOCK_BIT1 1

#define BUSES_PRESCALER_RESET_MASK 1023<<AHB_PRESCALER_FBIT
#define AHB_PRESCALER_FBIT 4
#define APB1_PRESCALER_FBIT 8
#define APB2_PRESCALER_FBIT 11


#define PLLSRC_BIT 16
#define PLLXTPRE_BIT 17


#define MULTIPLICATION_FACTOR_RESET_MASK 0b1111 << 18
#define PLL_MUL_FBIT 18







#endif /* MCAL_RCC_RCC_PRIVATE_H_ */
