/*
 * NVIC_interface.h
 *
 *  Created on: ١٧‏/٠٨‏/٢٠٢٢
 *      Author: ELKHOLY
 */

#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_

#include "../Inc/LIB/STD_TYPES.h"

/*group priority*/
#define Group0  0
#define Group1  1
#define Group2  2
#define Group3  3
#define Group4  4
#define Group5  5
#define Group6  6
#define Group7  7
#define Group8  8
#define Group9  9
#define Group10 10
#define Group11 11
#define Group12 12
#define Group13 13
#define Group14 14
#define Group15 15

/*sub priority*/
#define Sub0  0
#define Sub1  1
#define Sub2  2
#define Sub3  3
#define Sub4  4
#define Sub5  5
#define Sub6  6
#define Sub7  7
#define Sub8  8
#define Sub9  9
#define Sub10 10
#define Sub11 11
#define Sub12 12
#define Sub13 13
#define Sub14 14
#define Sub15 15
/*EXTI FROM VECTOR TABLE*/
#define  EXTI0_Num_From_VT 	   		 6
#define  EXTI1_Num_From_VT 		     7
#define  EXTI2_Num_From_VT           8
#define  EXTI3_Num_From_VT           9
#define  EXTI4_Num_From_VT           10
#define  DMA1_Channel1_Num_From_VT   11
#define  DMA1_Channel2_Num_From_VT   12
#define  DMA1_Channel3_Num_From_VT   13
#define  DMA1_Channel4_Num_From_VT   14
#define  DMA1_Channel5_Num_From_VT   15
#define  DMA1_Channel6_Num_From_VT   16
#define  DMA1_Channel7_Num_From_VT   17
#define  ADC1_2_Num_From_VT		     18
#define  USB_HP_CAN_TX_Num_From_VT   19
#define  USB_LP_CAN_RX_Num_From_VT   20
#define  CAN_RX1_Num_From_VT         21
#define  CAN_SCE_Num_From_VT         22
#define  EXTI9_5_Num_From_VT		 23
#define  TIM1_BRK_Num_From_VT        24
#define  TIM1_UP_Num_From_VT	     25
#define  TIM1_TRG_COM_Num_From_VT    26
#define  TIM1_CC_Num_From_VT	     27
#define  TIM2_Num_From_VT		     28
#define  TIM3_Num_From_VT		     29
#define  TIM4_Num_From_VT		     30
#define  I2C1_EV_Num_From_VT		 31
#define  I2C1_ER_Num_From_VT		 32
#define  I2C2_EV_Num_From_VT		 33
#define  I2C2_ER_Num_From_VT		 34
#define  SPI1_Num_From_VT		     35
#define  SPI2_Num_From_VT		     36
#define  USART1_Num_From_VT		     37
#define  USART2_Num_From_VT		     38
#define  USART3_Num_From_VT		     39
#define  EXTI15_10_Num_From_VT	     40
#define  RTCAlarm_Num_From_VT		 41
#define  USBWakeup_Num_From_VT		 42
#define  TIM8_BRK_Num_From_VT		 43
#define  TIM8_UP_Num_From_VT		 44
#define  TIM8_TRG_COM_Num_From_VT    45
#define  TIM8_CC_Num_From_VT	 	 46
#define  ADC3_Num_From_VT			 47
#define  FSMC_Num_From_VT			 48
#define  SDIO_Num_From_VT			 49
#define  TIM5_Num_From_VT			 50
#define  SPI3_Num_From_VT			 51
#define  UART4_Num_From_VT			 52
#define  UART5_Num_From_VT			 53
#define  TIM6_Num_From_VT		     54
#define  TIM7_Num_From_VT		     55
#define  DMA2_Channel1_Num_From_VT	 56
#define  DMA2_Channel2_Num_From_VT	 57
#define  DMA2_Channel3_Num_From_VT   58
#define  DMA2_Channel4_5 59


void MNVIC_voidInit (void);

void MNVIC_voidEnableInterrupt  (u8 Copy_u8IntNum);
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNum);

void MNVIC_voidSetPendingFlag   (u8 Copy_u8IntNum);
void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNum);

u8 MNVIC_u8GetAvticeFlag (u8 Copy_u8IntNum);
void MNVIC_voidSetPriority (u8 Copy_u8IntNum, u8 Copy_u8GroupNum, u8 Copy_u8SubNum);
#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
