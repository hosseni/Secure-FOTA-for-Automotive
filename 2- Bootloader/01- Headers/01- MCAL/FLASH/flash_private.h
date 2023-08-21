/*
 * flash_private.h
 *
 *  Created on: Dec 7, 2022
 *      Author: ELKHOLY
 */

#ifndef MCAL_FLASH_FLASH_PRIVATE_H_
#define MCAL_FLASH_FLASH_PRIVATE_H_

#include "../Inc/LIB/STD_TYPES.h"



/* Unlocking FPEC block keys*/
#define KEY1  ((u32)0x45670123)
#define KEY2  ((u32)0xCDEF89AB)


/* Flash status register masks */
#define FLASH_SR_BSY					  0x00000001
#define FLASH_SR_PGERR					0x00000004
#define FLASH_SR_WRPRTERR				0x00000010
#define FLASH_SR_EOP					  0x00000020

/* Flash control register masks */
#define FLASH_CR_PG						0x00000001
#define FLASH_CR_PER    				0x00000002
#define FLASH_CR_MER  					0x00000004
#define FLASH_CR_OPTPG  				0x00000010
#define FLASH_CR_OPTER 					0x00000020
#define FLASH_CR_STRT   				0x00000040
#define FLASH_CR_LOCK   				0x00000080
#define FLASH_CR_OPTWRE 				0x00000200
#define FLASH_CR_ERRIE  				0x00000400
#define FLASH_CR_EOPIE  				0x00001000

/* Flash base address on AHB bus */
#define FLASH_BASE_ADDRESS ((volatile void*) 0x40022000)

/* FLASH registers */
typedef struct
{
	u32 ACR;
	u32 KEYR;
	u32 OPTKEYR;
	u32 SR;
	u32 CR;
	u32 AR;
	u32 Reserved;
	u32 OBR;
	u32 WRPR;

} FLASH_t;


volatile FLASH_t * const  FLASH = (FLASH_t *) FLASH_BASE_ADDRESS;



#endif /* MCAL_FLASH_FLASH_PRIVATE_H_ */
