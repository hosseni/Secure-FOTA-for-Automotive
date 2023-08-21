/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <bootloader.h>
 *       Module:  bootloader
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef BOOTLOADER_BOOTLOADER_H_
#define BOOTLOADER_BOOTLOADER_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "../Inc/MCAL/UART/UART_interface.h"
#include "../Inc/MCAL/CRC/CRC_interface.h"
#include "../Inc/MCAL/FLASH/flash_interface.h"
#include "../Inc/SERVICES/decription.h"

extern u32 PAGE_ARRAY[];


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 ******************************	***************************************************************************************/
#define BL_HOST_COMMUNICATION_UART 		  UART_1
//#define BL_DEBUG_INFO
#define CBL_FLASH_ERASE_CMD         15
#define CBL_MEM_WRITE_CMD           16
#define RUN_CURRENT_VERSION			14

#define CBL_SEND_NACK                 0xAB
#define CBL_SEND_ACK                  0xCD

#define APPLICATION_START_ADDRESS_V1     0x08004400
#define APPLICATION_START_ADDRESS_V2     0x08003C00


#define DEBUG_METHOD    ENABLE_UART_DEBUG_MESSAGE

#define BL_HOST_BUFFER_RX_LENGTH 200
/**/
/*Memory boundary*/
#define FLASH_BASE            ((u32)0x08000000) /*!< FLASH base address in the alias region */
#define SRAM_BASE             ((u32)0x20000000) /*!< SRAM base address in the alias region */
#define FLASH_SIZE   				(64 * 1024)     /*FLASH SIZE : 64Kbyte*/       
#define SRAM_SIZE 	 				(20 * 1024)		 /*SRAM  SIZE : 20Kbyte*/
#define FLASH_END_ADDRESS    (FLASH_BASE + FLASH_SIZE)
#define SRAM_END_ADDRESS    (SRAM_BASE + SRAM_SIZE)


#define FLASH_MAX_PAGE_NUM     32
#define MASS_ERASE						0xFF


#define FLASH_PAYLOAD_WRITE_FAILED  0
#define FLASH_PAYLOAD_WRITE_PASSED  1

#define FLASH_STATUS_LOCK           0X00
#define FLASH_STATUS_UNLOCK         0x01     

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
	CRC_FAILD,
	CRC_PASSED
}CRC_VerifyType;

typedef u8 Address_VerifyType;
#define 	ADDRESS_IS_INVALID 0
#define	  ADDRESS_IS_VALID   1
	

typedef u8 Erase_VerifyType;

	




/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
ReturnStatus Bootloader_Start (void);
u8 Bootloader_Version_Existance_Check ();



#endif  /* BOOTLOADER_BOOTLOADER_H_ */

/**********************************************************************************************************************
 *  END OF FILE: bootloader.h
 *********************************************************************************************************************/
