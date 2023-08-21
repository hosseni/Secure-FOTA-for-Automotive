/*
 * UART_interface.h
 *
 *  Created on: Aug 30, 2022
 *      Author: ELHOSSENI
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_




#include "../Inc/LIB/STD_TYPES.h"
#include "UART_private.h"

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
//UART Characterstics
#define UART_NUMBER_OF_CHANNELS    5
#define UART_1                     0
#define UART_2                     1
#define UART_3                     2
#define UART_4                     3
#define UART_5                     4
//UART Pins

/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
void MUART_voidInit(u8 Copy_u8UartNumber);
ReturnStatus MUART_voidTransmitSynch(u8 Copy_u8UartNumber, u8 *Copy_u8DataArray, u8 sizeOfTransmittedData);
ReturnStatus MUART_u8ReceiveByteSynch(u8 Copy_u8UartNumber, u8  ReceivedData[], u8 sizeOfReceivedData);

#endif /* MCAL_UART_UART_INTERFACE_H_ */
