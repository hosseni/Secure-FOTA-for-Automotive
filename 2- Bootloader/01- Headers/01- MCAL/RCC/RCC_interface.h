/*
 * RCC_interface.h
 *
 *  Created on: Aug 11, 2022
 *      Author: ELHOSSENI
 */

#ifndef MCAL_RCC_RCC_INTERFACE_H_
#define MCAL_RCC_RCC_INTERFACE_H_

#include "../Inc/LIB/STD_TYPES.h"
/**
 * @brief this function used to initialize RCC 
 */
void MRCC_voidInit (void);

/**
 * @brief MRCC_voidClkEnable : 
 *          this function used to Enable the selected clock source 
 * @param A_u8ClkSource  : (HSI - HSE - PLL)
 */
void MRCC_voidClkEnable (u8 A_u8ClkSource);
/**
 * @brief MRCC_voidClkDisable :
 *          this function used to Disable the selected clock source 
 * @param A_u8ClkSource :  (HSI - HSE - PLL)
 */
void MRCC_voidClkDisable (u8 A_u8ClkSource);

/**
 * @brief MRCC_u8CheckClockReady :
 *                  this fuction used to check the clock source is ready or not
 * @param A_u8ClkSource :  (HSI - HSE - PLL)
 * @return u8  return 1 if the clock source is ready 
 *             return 0 if the clock source does not ready             
 */
u8 MRCC_u8CheckClockReady (u8 A_u8ClkSource);

/**
 * @brief  MRCC_voidSetClkSource 
 *              this function is used to set the enabled clock source
 * @param A_u8ClkSource  :  (HSI - HSE - PLL)
 */
void MRCC_voidSetClkSource(u8 A_u8ClkSource);

/**
 * @brief MRCC_voidSetBusesPrescaler :
 *          this function used to set the prescaller for 
 *              (AHB - APB1 - APB2)
 * @param A_u8AHBPrescaler     AHB_PRESCALER   "setted by configuration"
 * @param A_u8APB1Prescaler    ABP1_PRESCALER  "setted by configuration"
 * @param A_u8APB2Prescaler    ABP2_PRESCALER  "setted by configuration"
 */
void MRCC_voidSetBusesPrescaler (u8 A_u8AHBPrescaler, u8 A_u8APB1Prescaler, u8 A_u8APB2Prescaler);

/**
 * @brief this function used to select the clock source for PLL
 *          and select the prescaller for the selected source 
 * @param A_u8ClkSource  PLL_SOURCE     "setted by configuration"
 * @param A_u8Prescaler  PLL_HSE_FACTOR "setted by configuration"
 */
void MRCC_voidSetPLLSource(u8 A_u8ClkSource, u8 A_u8Prescaler);

/**
 * @brief MRCC_voidSetPLLMulFactor :
 *          this function used to sellect the multiplication factor for PLL input
 * @param A_u8MulFactor PLL_MULTIPLICATION_FACTOR   "setted by configurations"
 */
void MRCC_voidSetPLLMulFactor(u8 A_u8MulFactor);

/**
 * @brief MRCC_voidPreipheralEnable
 *          this function is used to select the Bus and enable one of its peripherals
 * @param A_u8BusID         BUS_ID          "selected by the configuration"
 * @param A_u8PrephieralID  PERIPHERAL_ID   "selected by the configuration"
 */
void MRCC_voidPreipheralEnable (u8 A_u8BusID, u8 A_u8PrephieralID);

/**
 * @brief MRCC_voidPreipheralDisable
 *          this function is used to select the Bus and disable one of its peripherals
 * @param A_u8BusID         BUS_ID          "selected by the configuration"
 * @param A_u8PrephieralID  PERIPHERAL_ID   "selected by the configuration"
 */
void MRCC_voidPreipheralDisable (u8 A_u8BusID, u8 A_u8PrephieralID);

/******************Clock sources************/
#define  HSI 0
#define  HSE 1
#define  PLL 2


/******state of selected clock source*******/
#define NOT_READY 0
#define READY 1


/**************HSE Divided or Not**********/
#define HSE_NOT_DIVIDED 1
#define HSE_DIVIDED 2


/**********Peripheral buses**************/
#define AHB  0
#define APB1 1
#define APB2 2

/*APB2 peripheral*/
#define AFIO_ENABLE_BIT   0
#define IOPA_ENABLE_BIT   2
#define IOPB_ENABLE_BIT   3
#define IOPC_ENABLE_BIT   4
#define IOPD_ENABLE_BIT   5
#define IOPE_ENABLE_BIT   6
#define IOPF_ENABLE_BIT   7
#define IOPG_ENABLE_BIT   8
#define ADC1_ENABLE_BIT   9
#define ADC2_ENABLE_BIT   10
#define TIM1_ENABLE_BIT   11
#define SPI1_ENABLE_BIT   12
#define TIM8_ENABLE_BIT   13
#define USART1_ENABLE_BIT 14
#define ADC3_ENABLE_BIT   15
#define TIM9_ENABLE_BIT   19
#define TIM10_ENABLE_BIT  20
#define TIM11_ENABLE_BIT  21




/*APB1 peripheral*/
#define TIM2_ENABLE_BIT		0
#define TIM3_ENABLE_BIT		1
#define TIM4_ENABLE_BIT		2
#define TIM5_ENABLE_BIT		3
#define TIM6_ENABLE_BIT		4
#define TIM7_ENABLE_BIT		5
#define TIM12_ENABLE_BIT	6
#define TIM13_ENABLE_BIT	7
#define TIM14_ENABLE_BIT	8
#define WWDG_ENABLE_BIT		11
#define SPI2_ENABLE_BIT		14
#define SPI3_ENABLE_BIT		15
#define USART2_ENABLE_BIT	17
#define USART3_ENABLE_BIT	18
#define UART4_ENABLE_BIT	19
#define UART5_ENABLE_BIT	20
#define I2C1_ENABLE_BIT		21
#define I2C2_ENABLE_BIT		22
#define USB_ENABLE_BIT		23
#define CAN1_ENABLE_BIT		25
#define CAN2_ENABLE_BIT		26
#define BKP_ENABLE_BIT		27
#define PWR_ENABLE_BIT		28
#define DAC_ENABLE_BIT		29

/*AHB peripherals*/
#define DMA1_ENABLE_BIT		0
#define DMA2_ENABLE_BIT		1
#define SRAM_ENABLE_BIT		2
#define FLITF_ENABLE_BIT	4
#define CRCEN_ENABLE_BIT	6
#define FSMC_ENABLE_BIT		8
#define SDIO_ENABLE_BIT		10


/*  AHB
 *  APB1
 *  APB2 */
#define BUS_ID APB2

/*
 *************************      ***************************      *****************************
 In case of BUS_ID == APB2        In case of BUS_ID == APB1   		In case of BUS_ID == AHB
 *************************      ***************************		 *******************************
 AFIO_ENABLE_BIT			|	TIM2_ENABLE_BIT				|	DMA1_ENABLE_BIT
 IOPA_ENABLE_BIT			|	TIM3_ENABLE_BIT				|	DMA2_ENABLE_BIT
 IOPB_ENABLE_BIT			|	TIM4_ENABLE_BIT				|	SRAM_ENABLE_BIT
 IOPC_ENABLE_BIT            |	TIM5_ENABLE_BIT				|	FLITF_ENABLE_BIT
 IOPD_ENABLE_BIT			|	TIM6_ENABLE_BIT				|	CRCEN_ENABLE_BIT
 IOPE_ENABLE_BIT			|	TIM7_ENABLE_BIT				|	FSMC_ENABLE_BIT
 IOPF_ENABLE_BIT			|	TIM12_ENABLE_BIT			|	SDIO_ENABLE_BIT
 IOPG_ENABLE_BIT			|	TIM13_ENABLE_BIT			|
 ADC1_ENABLE_BIT			|	TIM14_ENABLE_BIT			|
 ADC2_ENABLE_BIT			|	WWDG_ENABLE_BIT				|
 TIM1_ENABLE_BIT			|	SPI2_ENABLE_BIT				|
 SPI1_ENABLE_BIT			|	SPI3_ENABLE_BIT				|
 TIM8_ENABLE_BIT			|	USART2_ENABLE_BIT			|
 USART1_ENABLE_BIT			|	USART3_ENABLE_BIT			|
 ADC3_ENABLE_BIT			|	UART4_ENABLE_BIT			|
 TIM9_ENABLE_BIT			|	UART5_ENABLE_BIT			|
 TIM10_ENABLE_BIT			|	I2C1_ENABLE_BIT				|
 TIM11_ENABLE_BIT  			|	I2C2_ENABLE_BIT				|
 	 	 	 	 	 	 	|	USB_ENABLE_BIT				|
 	 	 	 	 	 	 	|	CAN_ENABLE_BIT				|
 	 	 	 	 	 	 	|	BKP_ENABLE_BIT				|
 	 	 	 	 	 	 	|	PWR_ENABLE_BIT				|
 	 	 	 	 	 	 	|	DAC_ENABLE_BIT				|

 */
#define PERIPHERAL_ID 	IOPA_ENABLE_BIT

#endif /* MCAL_RCC_RCC_INTERFACE_H_ */
