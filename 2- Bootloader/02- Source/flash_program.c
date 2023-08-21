/*
 * flash_program.c
 *
 *  Created on: Dec 7, 2022
 *      Author: ELHOSSENI
 */


#include "../Inc/MCAL/FLASH/flash_interface.h"
#include "../Inc/MCAL/FLASH/flash_configuration.h"
#include "../Inc/MCAL/FLASH/flash_private.h"
#include "../Inc/LIB/STD_TYPES.h"

u32 PAGE_ARRAY[32] = {
					  0x08000000, 0x08000400, 0x08000800, 0x08000C00,
					  0x08001000, 0x08001400, 0x08001800, 0x08001C00,
					  0x08002000, 0x08002400, 0x08002800, 0x08002C00,
					  0x08003000, 0x08003400, 0x08003800, 0x08003C00,
					  0x08004000, 0x08004400, 0x08004800, 0x08004C00,
					  0x08005000, 0x08005400, 0x08005800, 0x08005C00,
					  0x08006000, 0x08006400, 0x08006800, 0x08006C00,
					  0x08007000, 0x08007400, 0x08007800, 0x08007C00
					 };



void MFLASH_lock (void)
{
	FLASH->CR |= FLASH_CR_LOCK;
}

void MFLASH_unlock (void)
{
	FLASH->KEYR = KEY1;
	FLASH->KEYR = KEY2;
}


ReturnStatus MFLASH_programPage (const u32  desiredAddress, const u16 desiredValue)
{
	ReturnStatus status = OK;
	u16 programmedValue;
	u32 lockStatus;
	u16 programmingErr;

	
	/* Checking if flash is unlocked */
	lockStatus = FLASH->CR & FLASH_CR_LOCK;
	if (lockStatus == FLASH_CR_LOCK)
	{
		status = NOT_OK;
	}
	else
	{
		/* Checking that there is no flash memory operation is ongoing*/
		while ((FLASH->SR & FLASH_SR_BSY) == FLASH_SR_BSY);

		/* Choose flash programming */
		FLASH->CR |= FLASH_CR_PG;

		/* Programming half word */
		*((u16 *)desiredAddress) = desiredValue;

		/* Checking if address was erased before or not */
		programmingErr = FLASH->SR & FLASH_SR_PGERR;
		if (programmingErr == FLASH_SR_PGERR)
		{
			status = NOT_OK;
		}
		else
		{
			/* Waiting on busy flag */
			while ((FLASH->SR & FLASH_SR_BSY) == FLASH_SR_BSY);

			/* Checking the programmed value */
			programmedValue = (*((u16 *)desiredAddress));

			if (programmedValue != desiredValue)
			{
				status = NOT_OK;
			}
		}

		/* Stopping flash programming */
		FLASH->CR &= ~FLASH_CR_PG;
	}

	return status;
}


ReturnStatus MFLASH_erasePage (const u32  desiredAddress)
{
	ReturnStatus status = OK;
	u32 lockStatus;

	/* Checking if flash is unlocked */
	lockStatus = FLASH->CR & FLASH_CR_LOCK;
	if (lockStatus == FLASH_CR_LOCK)
	{
		status = NOT_OK;
	}
	else
	{
		/* Checking that there is no flash memory operation is ongoing*/
		while ((FLASH->SR & FLASH_SR_BSY) == FLASH_SR_BSY);

		/* Choose flash erasing */
		FLASH->CR |= FLASH_CR_PER;

		/* Choosing address to erase */
		FLASH->AR = desiredAddress;

		/* Starting erasing */
		FLASH->CR |= FLASH_CR_STRT;

		/* Waiting on busy flag */
		while ((FLASH->SR & FLASH_SR_BSY) == FLASH_SR_BSY);


		/* Stopping flash erasing */
		FLASH->CR &= ~FLASH_CR_PER;
	}
	return status;
}

ReturnStatus MFLASH_massErase(void)
{
	ReturnStatus status = OK;
	u32 lockStatus;

	/* Checking if flash is unlocked */
	lockStatus = FLASH->CR & FLASH_CR_LOCK;
	if (lockStatus == FLASH_CR_LOCK)
	{
		status = NOT_OK;
	}
	else
	{
		/* Checking that there is no flash memory operation is ongoing*/
		while ((FLASH->SR & FLASH_SR_BSY) == FLASH_SR_BSY);

		/* Choose flash mass erasing */
		FLASH->CR |= FLASH_CR_MER;

		/* Starting erasing */
		FLASH->CR |= FLASH_CR_STRT;

		/* Waiting on busy flag */
		while ((FLASH->SR & FLASH_SR_BSY) == FLASH_SR_BSY);

		/* Stopping flash erasing */
		FLASH->CR &= ~FLASH_CR_MER;
	}
	return status;
}
