/*
 * flash_interface.h
 *
 *  Created on: Dec 7, 2022
 *      Author: ELKHOLY
 */

#ifndef MCAL_FLASH_FLASH_INTERFACE_H_
#define MCAL_FLASH_FLASH_INTERFACE_H_
/************************************************/
/* Author: Alzahraa Elsallakh                   */
/* Version: V01                                 */
/* Date: 05 Apr 2020                            */
/* Layer: MCAL                                  */
/* Component: FLASH                             */
/* File Name: FLASH.h                           */
/************************************************/



/*
  Description: This function shall lock FPEC block
  Input:  void
  Output: void
*/
#include "../Inc/LIB/STD_TYPES.h"



void 		 MFLASH_lock (void);
void 		 MFLASH_unlock (void);
ReturnStatus MFLASH_programPage (const u32  desiredAddress, const u16 desiredValue);
ReturnStatus MFLASH_erasePage (const u32  desiredAddress);
ReturnStatus MFLASH_massErase(void);




#endif /* MCAL_FLASH_FLASH_INTERFACE_H_ */
