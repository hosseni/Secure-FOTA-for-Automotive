/*
 * UART_private.h
 *
 *  Created on: Aug 30, 2022
 *      Author: ELHOSSENI
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_

#include "../Inc/LIB/STD_TYPES.h"
#include "../Inc/MCAL/GPIO/GPIO_interface.h"



#define UART_1_BASE_ADDRESS   0x40013800
#define UART_2_BASE_ADDRESS   0x40004400
#define UART_3_BASE_ADDRESS   0x40004800
#define UART_4_BASE_ADDRESS   0x40004C00
#define UART_5_BASE_ADDRESS   0x40005000


#define UART_1_TX                   GPIO_U8_PIN9
#define UART_1_RX                   GPIO_U8_PIN10
#define UART_2_TX                   GPIO_U8_PIN2
#define UART_2_RX                   GPIO_U8_PIN3
#define UART_3_TX                   GPIO_U8_PIN10
#define UART_3_RX                   GPIO_U8_PIN11



#define UART_NUMBER_OF_CHANNELS    5
#define UART_NUMBER_OF_INTERRUPT   8
#define CLR_REGISTER          0X00000000


typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR[3];
	volatile u32 GTPR;

}UART_Reg_t;

typedef enum
{
	UART_1 = 0,
	UART_2,
	UART_3,
	UART_4,
	UART_5
}UART_Num_t;

typedef enum
{
	IDLE_Interrupt_,
	RECEIVE_COMPLETE_Interrupt_,
	TRANSMITTER_COMPLET_Interrupt_,
	TRANSMITTER_EMPTY_Interrupt_,
	PARITY_Interrupt_,
	ERROR_Interrupt_,
	LIN_BREAK_DETEC_Interrupt_,
	CTS_Interrupt_,
}Interrupt_t;


static volatile UART_Reg_t * const UARTChannel[UART_NUMBER_OF_CHANNELS] =
{
    ((volatile UART_Reg_t * const)(UART_1_BASE_ADDRESS)),
    ((volatile UART_Reg_t * const)(UART_2_BASE_ADDRESS)),
    ((volatile UART_Reg_t * const)(UART_3_BASE_ADDRESS)),
    ((volatile UART_Reg_t * const)(UART_4_BASE_ADDRESS)),
    ((volatile UART_Reg_t * const)(UART_5_BASE_ADDRESS))
};



//Clock: 1 MHz
#define UART_BAUDRATE_1200_CLK_1M       0X0341
#define UART_BAUDRATE_2400_CLK_1M       0X01A0
#define UART_BAUDRATE_4800_CLK_1M       0X00D0
#define UART_BAUDRATE_9600_CLK_1M       0X0068
#define UART_BAUDRATE_19200_CLK_1M      0X0034
//Clock: 8 MHz
#define UART_BAUDRATE_1200_CLK_8M       0X1A0B
#define UART_BAUDRATE_2400_CLK_8M       0X0D05
#define UART_BAUDRATE_4800_CLK_8M       0X0683
#define UART_BAUDRATE_9600_CLK_8M       0X0341
#define UART_BAUDRATE_19200_CLK_8M      0X01A1

/*
#define ENABLE                  1
#define DISABLE               	0
#define ENABLE_UART             1
#define DISABLE_UART            0
#define ENABLE_INTERRUPT        1
#define DISABLE_INTERRUPT       0
#define WORD_8_BITS             0
#define WORD_9_BITS             1
#define CLOCK_PHASE_CAP_FIRST   0
#define CLOCK_PHASE_CAP_SECOND  1
#define CLOCK_POLARITY_LOW      0
#define CLOCK_POLARITY_HIGH     1
#define Enable_CLOCK            1
#define DISABLE_CLOCK           0
#define STOB_1_BITS             0
#define STOB_2_BITS             10
#define STOB_5_BITS             01
#define STOB_1_5_BITS           11

*/
/*reg bit */
// SR bits register definition.
#define PE                    0
#define FE                    1
#define OREE                  2
#define NE                    3
#define IDLE                  4
#define RXNE                  5
#define TC                    6
#define TXE                   7
#define LDB                   8
#define CTS                   9
// CR1 bits register definition.
#define SPK                   0
#define RWU                   1
#define RE                    2
#define TE                    3
#define IDLEIE                4
#define RXNEIE                5
#define TCIE                  6
#define TXEIE                 7
#define PEIE                  8
#define PS                    9
#define PCE                   10
#define WAKE                  11
#define M                     12
#define UE                    13
// CR2 bits register definition.
#define ADD                   0
#define LBDL                  5
#define LBDIE                 6
#define LBCL                  8
#define CPHA                  9
#define CPOL                  10
#define CLKEN                 11
#define STOP                  12
#define LINEN                 14
// CR3 bits register definition.
#define EIE                   0
#define IREN                  1
#define IRLP                  2
#define HDSEL                 3
#define NACK                  4
#define SCEN                  5
#define DMAR                  6
#define DMAT                  7
#define RTSE                  8
#define CTSE                  9
#define CTSIE                 10
// GTPR bits register definition.
#define PSC                   0
#define GT                    1
#endif /* MCAL_UART_UART_PRIVATE_H_ */
