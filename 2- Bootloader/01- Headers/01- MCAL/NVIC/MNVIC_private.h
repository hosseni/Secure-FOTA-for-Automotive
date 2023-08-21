	/*
 * MNVIC_private.h
 *
 *  Created on: ١٧‏/٠٨‏/٢٠٢٢
 *      Author: ELKHOLY
 */

#ifndef MCAL_NVIC_MNVIC_PRIVATE_H_
#define MCAL_NVIC_MNVIC_PRIVATE_H_



#define NVIC_BASE_ADD (0xE000E100)

 // Enable the external interrupts from 0 to 31
#define NVIC_ISER0		*((volatile u32 *)(NVIC_BASE_ADD + 0x00))
#define NVIC_ISER1		*((volatile u32 *)(NVIC_BASE_ADD + 0x04))
#define NVIC_ISER2		*((volatile u32 *)(NVIC_BASE_ADD + 0x08))


 // Disable the external interrupts from 0 to 31
#define NVIC_ICER0		*((volatile u32 *)(NVIC_BASE_ADD + 0x80))
#define NVIC_ICER1		*((volatile u32 *)(NVIC_BASE_ADD + 0x84))
#define NVIC_ICER2		*((volatile u32 *)(NVIC_BASE_ADD + 0x88))


// Enable the external interrupts from 0 to 31
#define NVIC_ISPR0		*((volatile u32 *)(NVIC_BASE_ADD + 0x100))
#define NVIC_ISPR1		*((volatile u32 *)(NVIC_BASE_ADD + 0x104))
#define NVIC_ISPR2		*((volatile u32 *)(NVIC_BASE_ADD + 0x108))

 // Disable the external interrupts from 0 to 31
#define NVIC_ICPR0		*((volatile u32 *)(NVIC_BASE_ADD + 0x180))
#define NVIC_ICPR1		*((volatile u32 *)(NVIC_BASE_ADD + 0x184))
#define NVIC_ICPR2		*((volatile u32 *)(NVIC_BASE_ADD + 0x188))

#define NVIC_IABR0		*((volatile u32 *)(NVIC_BASE_ADD + 0x200))
#define NVIC_IABR1		*((volatile u32 *)(NVIC_BASE_ADD + 0x204))
#define NVIC_IABR2		*((volatile u32 *)(NVIC_BASE_ADD + 0x208))


#define 	NVIC_16_GROUP_0_SUB  (0x05FA0300)
#define 	NVIC_8_GROUP_2_SUB   (0x05FA0400)
#define 	NVIC_4_GROUP_4_SUB   (0x05FA0500)
#define 	NVIC_2_GROUP_8_SUB   (0x05FA0600)
#define 	NVIC_0_GROUP_16_SUB  (0x05FA0700)


/*used NVIC_IPR as array name of (u8)
 * because IPR sectioned to 8 bit sections  */
#define NVIC_IPR  ((volatile u8 *)(NVIC_BASE_ADD + 0x300))

#define SCB_BASE_ADD 0xE000ED00
#define SCB_AIRCR *((volatile u32 *)(SCB_BASE_ADD + 0x0C))


#endif /* MCAL_NVIC_MNVIC_PRIVATE_H_ */
