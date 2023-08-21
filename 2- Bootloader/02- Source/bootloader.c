/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  bootloader.c
 *         \brief
 *
 *         \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "../Inc/Bootloader/bootloader.h"
#include "../Inc/MCAL/CAN/CAN_interface.h"
#include "../Inc/MCAL/UART/UART_interface.h"
#include "../Inc/LIB/DELAY.h"


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
CanTxMsg CAN_ACK_MSG = {0, 0, 0x6, 1, 10};
CanTxMsg CAN_NACK_MSG = {0, 0, 0x6, 1, 9};

static u8 BL_Host_Buffer [BL_HOST_BUFFER_RX_LENGTH];


/**********************************************************************************************************************
 *  Static FUNCTION PROTOTYPES
 *********************************************************************************************************************/


static void  		         Bootloader_Send_ACK  							( );
static void           	     Bootloader_Send_NACK						    ( );
static Address_VerifyType    Bootloader_Address_Verify   					( u32 Address);
static ReturnStatus			 Bootloader_Preform_Flash_Erase 				( u8 pageNum , u8 NumOfPage);

static void           Bootloader_Jumb_To_Address                   	        ( u32 Address);
static ReturnStatus   Bootloader_Erase_Flash 					  			( u8 *Host_Buffer);
static ReturnStatus   Bootloader_Memory_Write 				      			( u8 *Host_Buffer);


/******************************************************************************
* \Syntax          : BL_StatusType BL_UART_Featch_Host_Command (void)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
ReturnStatus Bootloader_Start (void)
{
	ReturnStatus BL_status = NOT_OK;
	u8 Data_Length = 0;


	/*To clear BL host buffer*/
	memset(BL_Host_Buffer, 0, BL_HOST_BUFFER_RX_LENGTH);

	/*Receive Packet Length*/
	ReturnStatus state = Can_u8SynRecieveNumOfByte(CAN1, 0, &BL_Host_Buffer[0],1);
	if (state == NOT_OK) Bootloader_Jumb_To_Address(APPLICATION_START_ADDRESS_V1);
	if (BL_Host_Buffer[0] == 0)
	{
	 BL_status = NOT_OK;
	}
	else
	{
		/*Send ACK to get next */
		Bootloader_Send_ACK ();
		/*Receive Command Id */
	    Can_u8SynRecieveNumOfByte(CAN1, 0, &BL_Host_Buffer[1],1);
		Bootloader_Send_ACK ();
		Data_Length = BL_Host_Buffer[0];
		/*Recieve actual data that has length (Data_Length)*/
		Can_u8SynRecieveNumOfByte(CAN1, 0, &BL_Host_Buffer[2],Data_Length);

		switch (BL_Host_Buffer[1])
			{
			case RUN_CURRENT_VERSION:
				Bootloader_Jumb_To_Address (0x08004400);
				break;
			case  CBL_FLASH_ERASE_CMD       :
				BL_status = Bootloader_Erase_Flash(BL_Host_Buffer);
				if (BL_status == OK)
					Bootloader_Send_ACK ();
				break;
			case  CBL_MEM_WRITE_CMD          :
				BL_status = Bootloader_Memory_Write(BL_Host_Buffer);
				if (BL_status == OK)
					Bootloader_Send_ACK ();
				break;

			default :
				break;
			}
	}

  return BL_status;
}


static void           Bootloader_Send_ACK ()
{
	  CAN_VoidTransmit(CAN1, &CAN_ACK_MSG);

}
static void           Bootloader_Send_NACK						  ()
{
	u8 NACK_Val = CBL_SEND_NACK;
	 MUART_voidTransmitSynch(BL_HOST_COMMUNICATION_UART, &NACK_Val, 1);
}

static Address_VerifyType  Bootloader_Address_Verify   ( u32 Address)
{
	Address_VerifyType Address_Status = ADDRESS_IS_INVALID;
	
	if ((Address >= FLASH_BASE)&&(Address <= FLASH_END_ADDRESS))
		Address_Status = ADDRESS_IS_VALID;

	else if ((Address >= SRAM_BASE)&&(Address <= SRAM_END_ADDRESS))
		Address_Status = ADDRESS_IS_VALID;

	else 
	Address_Status = ADDRESS_IS_INVALID;

		
	return Address_Status;
}

static ReturnStatus Bootloader_Preform_Flash_Erase (u8 pageNum , u8 NumOfPage)
{
	ReturnStatus Erase_Status = NOT_OK;
	
	if (FLASH_MAX_PAGE_NUM >= NumOfPage)
	{
		
		/*Num of page is in range*/
		if ((FLASH_MAX_PAGE_NUM > pageNum) || (MASS_ERASE == pageNum))
		{
			/*Unlock Falsh*/
			if (MASS_ERASE == pageNum)
			{
				/*mass erase*/
				MFLASH_unlock();
				Erase_Status = MFLASH_massErase();
			}
			else 
			{
				/*sector erase*/
				u8 PageCounter = 0;
				u8 PageMAxCounter = (pageNum + NumOfPage);
				for ( PageCounter = pageNum; PageCounter < PageMAxCounter ; PageCounter ++)
				{
					if ( pageNum < FLASH_MAX_PAGE_NUM  )
					{
						/*Unlock Flash*/
						MFLASH_unlock();
						Erase_Status	= MFLASH_erasePage(PAGE_ARRAY[PageCounter]);
					}
					else 
					{
						Erase_Status = NOT_OK;
					}
				}//for  ( PageCounter =....)
			}
		}//if((FLASH_MAX_PAGE_NUM > pageNum) .....

		MFLASH_lock();
   }
 return Erase_Status;
}

static ReturnStatus   Bootloader_Erase_Flash ( u8 *Host_Buffer)
{

	/*******************************************************
	 ************BOOTLOADER PACKET (4Byte)******************
	 *******|    1     |   2  | 	3 	|    4
	 *******|Packet_Len|CMD_ID|PageNum|NumOfPages***********
	 *******************************************************/
	ReturnStatus Erase_Status = NOT_OK ;
		
	Erase_Status =	Bootloader_Preform_Flash_Erase(Host_Buffer[2], Host_Buffer[3]);

	return Erase_Status;
}

static ReturnStatus   Bootloader_Memory_Write 				      			( u8 *Host_Buffer)
{
	u8 j = 0;
	u8 				       		   App_Version 				    = 0;
	u16  						   Payload_len					= 0;
	u8 							   Flash_Payload_Write_Status   = FLASH_PAYLOAD_WRITE_FAILED;
	u32 volatile				   Start_Address				= 0;
	u32 volatile 				   Current_Address				= 0;


		App_Version = Host_Buffer[2];
		Payload_len = *((u16*)(&Host_Buffer[3]));

		// 1-   APPLICATION_START_ADDRESS_V1 =  0x08004400
		// 2-   APPLICATION_START_ADDRESS_V2 =  0x08003C00

		if (App_Version == 1)
		{
			Start_Address   = APPLICATION_START_ADDRESS_V1;
			Current_Address = Start_Address;
			//send ACK to start receive file
			Bootloader_Send_ACK();
			for (int i = 0; i < Payload_len ; i+=8)
			{
				Can_u8SynRecieveNumOfByte(CAN1, 0, &Host_Buffer[5], 8);
				u8 decrypted[8] = {0};
				//decreption the
				decryptFile (&Host_Buffer[5], &decrypted[0]);

				MFLASH_unlock();
				j = 0;
				while ( j < 7)
				{
					//Flash_Payload_Write_Status = MFLASH_programPage(Current_Address, *((u16*)(&Host_Buffer[5 + j])) );
					Flash_Payload_Write_Status = MFLASH_programPage(Current_Address, *((u16*)(&decrypted[0 + j])) );
					Current_Address += 2;
					j += 2;
				}
				MFLASH_lock();
				if (Flash_Payload_Write_Status == OK)
				{
				Bootloader_Send_ACK();
				}
				else
				{
					break;
				}
			}
		}
		else if (App_Version == 2)
		{
			Start_Address = APPLICATION_START_ADDRESS_V2;

		}

		Bootloader_Jumb_To_Address (Start_Address);

		return Flash_Payload_Write_Status;
}


 void Bootloader_Jumb_To_Address         	      ( u32 Address)
{
	u32 Host_Jumb_Address = 0;
	Host_Jumb_Address = Address;

	void (*app_reset_handler)(void) = (void *)(*((volatile u32 *)(Host_Jumb_Address + 4U)));
		app_reset_handler();


}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
