/*
 * RCC_configuration.h
 *
 *  Created on: Aug 11, 2022
 *      Author: ELHOSSENI
 */

#ifndef MCAL_RCC_RCC_CONFIGURATION_H_
#define MCAL_RCC_RCC_CONFIGURATION_H_


/*
 * HSI - HSE - PLL
 */
#define CLK_SOURCE HSI

/*
 * 0xxx: SYSCLK not divided
 * 1000: SYSCLK divided by 2
 * 1001: SYSCLK divided by 4
 * 1010: SYSCLK divided by 8
 * 1011: SYSCLK divided by 16
 * 1100: SYSCLK divided by 64
 * 1101: SYSCLK divided by 128
 * 1110: SYSCLK divided by 256
 * 1111: SYSCLK divided by 512*/

#define AHB_PRESCALER 0b0000

/*HSI-
 * HSE*/
#define PLL_SOURCE HSI


/* 0xx: HCLK not divided
 * 100: HCLK divided by 2
 * 101: HCLK divided by 4
 * 110: HCLK divided by 8
 * 111: HCLK divided by 16*/
#define ABP1_PRESCALER 0b0000
#define ABP2_PRESCALER 0b0000


/* HSE_NOT_DIVIDED
 * -  HSE_DIVIDED */
#define PLL_HSE_FACTOR HSE_NOT_DIVIDED

/*
0000: PLL input clock x 2
0001: PLL input clock x 3
0010: PLL input clock x 4
0011: PLL input clock x 5
0100: PLL input clock x 6
0101: PLL input clock x 7
0110: PLL input clock x 8
0111: PLL input clock x 9
1000: PLL input clock x 10
1001: PLL input clock x 11
1010: PLL input clock x 12
1011: PLL input clock x 13
1100: PLL input clock x 14
1101: PLL input clock x 15
1110: PLL input clock x 16
1111: PLL input clock x 16
*/
#define PLL_MULTIPLICATION_FACTOR 0b0101


#endif /* MCAL_RCC_RCC_CONFIGURATION_H_ */
