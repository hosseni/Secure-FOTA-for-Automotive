/*
 * DMA_configuration.h
 *
 *  Created on: Aug 24, 2022
 *      Author: ELKHOLY
 */

#ifndef MCAL_DMA_DMA_CONFIGURATION_H_
#define MCAL_DMA_DMA_CONFIGURATION_H_
#include "../Inc/LIB/STD_TYPES.h"

/*Set Configuration For Channel 1 */
#define Mem2Mem_1              Enable		 /*Select [Enable / Disable]*/
#define Periority_Level_1      Very_High   /*Select [Very_High / High / Medium / Low ] */
#define Memory_Size_1          _32_Bit     /*Select [_32_Bit / _16_Bit / _8_Bit ]*/
#define Peripheral_Size_1      _32_Bit     /*Select [_32_Bit / _16_Bit / _8_Bit ]*/
#define MemIncMode_1           Disable      /*Select [Enable / Disable]*/
#define PerIncMode_1           Disable      /*Select [Enable / Disable]*/
#define CircularMode_1         Disable		 /*Select [Enable / Disable]*/
#define DataDir_1			   RdFromMem   /*Select [RdFromMem / RdFromPer]*/

/*Set Configuration For Channel 2 */
#define Mem2Mem_2              Enable		 /*Select [Enable / Disable]*/
#define Periority_Level_2      Very_High   /*Select [Very_High / High / Medium / Low ] */
#define Memory_Size_2          _32_Bit     /*Select [_32_Bit / _16_Bit / _8_Bit ]*/
#define Peripheral_Size_2      _32_Bit     /*Select [_32_Bit / _16_Bit / _8_Bit ]*/
#define MemIncMode_2           Enable      /*Select [Enable / Disable]*/
#define PerIncMode_2           Enable      /*Select [Enable / Disable]*/
#define CircularMode_2         Enable		 /*Select [Enable / Disable]*/
#define DataDir_2			   RdFromMem   /*Select [RdFromMem / RdFromPer]*/

/*Set Configuration For Channel 3 */
#define Mem2Mem_3              Enable		 /*Select [Enable / Disable]*/
#define Periority_Level_3      Very_High   /*Select [Very_High / High / Medium / Low ] */
#define Memory_Size_3          _32_Bit     /*Select [_32_Bit / _16_Bit / _8_Bit ]*/
#define Peripheral_Size_3      _32_Bit     /*Select [_32_Bit / _16_Bit / _8_Bit ]*/
#define MemIncMode_3           Enable      /*Select [Enable / Disable]*/
#define PerIncMode_3           Enable      /*Select [Enable / Disable]*/
#define CircularMode_3         Enable		 /*Select [Enable / Disable]*/
#define DataDir_3			   RdFromMem   /*Select [RdFromMem / RdFromPer]*/

/*Set Configuration For Channel 4 */
#define Mem2Mem_4              Enable		 /*Select [Enable / Disable]*/
#define Periority_Level_4      Very_High   /*Select [Very_High / High / Medium / Low ] */
#define Memory_Size_4          _32_Bit     /*Select [_32_Bit / _16_Bit / _8_Bit ]*/
#define Peripheral_Size_4      _32_Bit     /*Select [_32_Bit / _16_Bit / _8_Bit ]*/
#define MemIncMode_4           Enable      /*Select [Enable / Disable]*/
#define PerIncMode_4           Enable      /*Select [Enable / Disable]*/
#define CircularMode_4         Enable		 /*Select [Enable / Disable]*/
#define DataDir_4			   RdFromMem   /*Select [RdFromMem / RdFromPer]*/

/*Set Configuration For Channel 5 */
#define Mem2Mem_5              Enable		 /*Select [Enable / Disable]*/
#define Periority_Level_5      Very_High   /*Select [Very_High / High / Medium / Low ] */
#define Memory_Size_5          _32_Bit     /*Select [_32_Bit / _16_Bit / _8_Bit ]*/
#define Peripheral_Size_5      _32_Bit     /*Select [_32_Bit / _16_Bit / _8_Bit ]*/
#define MemIncMode_5           Enable      /*Select [Enable / Disable]*/
#define PerIncMode_5           Enable      /*Select [Enable / Disable]*/
#define CircularMode_5         Enable		 /*Select [Enable / Disable]*/
#define DataDir_5			   RdFromMem   /*Select [RdFromMem / RdFromPer]*/

/*Set Configuration For Channel 6 */
#define Mem2Mem_6              Enable		 /*Select [Enable / Disable]*/
#define Periority_Level_6      Very_High   /*Select [Very_High / High / Medium / Low ] */
#define Memory_Size_6          _32_Bit     /*Select [_32_Bit / _16_Bit / _8_Bit ]*/
#define Peripheral_Size_6      _32_Bit     /*Select [_32_Bit / _16_Bit / _8_Bit ]*/
#define MemIncMode_6           Enable      /*Select [Enable / Disable]*/
#define PerIncMode_6           Enable      /*Select [Enable / Disable]*/
#define CircularMode_6         Enable		 /*Select [Enable / Disable]*/
#define DataDir_6		       RdFromMem   /*Select [RdFromMem / RdFromPer]*/

/*Set Configuration For Channel 7 */
#define Mem2Mem_7              Enable		 /*Select [Enable / Disable]*/
#define Periority_Level_7      Very_High   /*Select [Very_High / High / Medium / Low ] */
#define Memory_Size_7          _32_Bit     /*Select [_32_Bit / _16_Bit / _8_Bit ]*/
#define Peripheral_Size_7      _32_Bit     /*Select [_32_Bit / _16_Bit / _8_Bit ]*/
#define MemIncMode_7           Enable      /*Select [Enable / Disable]*/
#define PerIncMode_7           Enable      /*Select [Enable / Disable]*/
#define CircularMode_7         Enable		 /*Select [Enable / Disable]*/
#define DataDir_7			   RdFromMem   /*Select [RdFromMem / RdFromPer]*/

/*set interrupt config */
#define TrensferComplete_Interrupt    	   Enable	/*Select [Enable / Disable]*/
#define HalfTransferComplete_Interrupt	   Enable   /*Select [Enable / Disable]*/
#define TransferError_Interrupt            Enable  /*Select [Enable / Disable]*/

#endif /* MCAL_DMA_DMA_CONFIGURATION_H_ */
