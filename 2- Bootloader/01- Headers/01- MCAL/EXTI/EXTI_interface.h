/*
 * EXTI_interface.h
 *
 *  Created on: ١٨‏/٠٨‏/٢٠٢٢
 *      Author: ELKHOLY
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

#include "../Inc/LIB/STD_TYPES.h"
#include "../Inc/LIB/BIT_MATH.h"


#define MEXTI_RISING_EDGE	  0
#define MEXTI_FALLING_EDGE    1
#define MEXTI_OnChange_EDGE   2

#define MEXTI_LIN0  0
#define MEXTI_LIN1  1
#define MEXTI_LIN2  2

void	MEXTI_voidInit(void);
void	MEXTI_voidEnableEXTI(u8 Copy_u8Line);
void	MEXTI_voidDisableEXTI(u8 Copy_u8Line);
void	MEXTI_voidSetEdge(u8 Copy_u8Line, u8 Copy_u8Edge);
void	MEXTI_voidEnableSWI(u8 v);
void    MEXTI_voidClearPending(u8 Copy_u8Line);
void    MEXTI_voidSetCallBack_EXTI0 (void (*ptr) (void));
void    MEXTI_voidSetCallBack_EXTI1 (void (*ptr) (void));
void    MEXTI_voidSetCallBack_EXTI2 (void (*ptr) (void));


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
