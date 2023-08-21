/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include "../Inc/LIB/STD_TYPES.h"
#include "../Inc/LIB/BIT_MATH.h"
#include "../Inc/LIB/DELAY.h"

#include "../Inc/MCAL/RCC/RCC_interface.h"
#include "../Inc/MCAL/GPIO/GPIO_interface.h"
#include "../Inc/MCAL/FLASH/flash_interface.h"
#include "../Inc/Bootloader/bootloader.h"
#include "../Inc/MCAL/UART/UART_interface.h"

#include "../Inc/MCAL/CAN/CAN_interface.h"
#include "../Inc/MCAL/CAN/CAN_config.h"
#include "../Inc/MCAL/CAN/CAN_private.h"

extern CAN_InitTypeDef CAN_InitStruct;
extern CAN_FilterInitTypeDef  CAN_FilterInitStruct_1;
CanRxMsg reMsg ={0};
CanTxMsg ACK_CAN_MSG;

int main(void)
{

	/*RCC init*/
 	MRCC_voidInit();
 	MRCC_voidPreipheralEnable(APB1, CAN1_ENABLE_BIT);
	MRCC_voidPreipheralEnable(APB2, IOPA_ENABLE_BIT);


	/*CAN1 pins */
		MGPIO_voidSetPinDirection(GPIO_U8_PORTA, GPIO_U8_PIN12, GPIO_OUTPUT_AF_OD_10MHZ); //CAN_TX
		MGPIO_voidSetPinDirection(GPIO_U8_PORTA, GPIO_U8_PIN11, GPIO_INPUT_FLOATING);	//CAN_RX

	/*CAN Init*/
		CAN_VoidInit(CAN1, &CAN_InitStruct);
		CAN_VoidFilterSet(&CAN_FilterInitStruct_1);

	for(;;)
	{
		Bootloader_Start();
	}
}