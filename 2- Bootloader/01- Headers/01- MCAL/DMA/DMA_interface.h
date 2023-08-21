/*
 * DMA_interface.h
 *
 *  Created on: Aug 24, 2022
 *      Author: ELKHOLY
 */

#ifndef MCAL_DMA_DMA_INTERFACE_H_
#define MCAL_DMA_DMA_INTERFACE_H_

#include <MCAL/DMA/DMA_private.h>
#include "../Inc/LIB/STD_TYPES.h"


void MDMA_voidInit ( Channel_T Copy_u8DMA_Channel);
void MDMA1_voidChannel_Start (Channel_T Copy_u8ChannelNum, u32 *Copy_u32Source_Address, u32 *Copy_u32Destination_Address, u16 Copy_u16Block_Length);
void MDMA_voidSetChannelStatus (Channel_T Copy_u8ChannelNum, status_t status);
void MDMA_voidSetSource_Dest_Address ( Channel_T Copy_u8ChannelNum,u32 *Copy_u32Source_Address, u32 *Copy_u32Destination_Address, u16 Copy_u16Block_Length);
void DMA_voidInterruptEnable (  Channel_T Copy_u8ChannelNum, Interrupt_T Copy_u8DMAIntType);
void DMA_voidInterruptDisable ( Channel_T Copy_u8ChannelNum, Interrupt_T Copy_u8DMAIntType);

void DMA_voidClearFlag( Channel_T Copy_u8DMA_Channel , Flag_T Copy_u8Flag );
u8   DMA_u8ReadFlag( Channel_T Copy_u8DMA_Channel , Flag_T Copy_u8Flag );

void DMA_SetCallBack(Channel_T Copy_u8DMA_Channel , void (*pf)(void) );
#endif /* MCAL_DMA_DMA_INTERFACE_H_ */
