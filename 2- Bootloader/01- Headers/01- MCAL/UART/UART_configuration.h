/*
 * UART_configuration.h
 *
 *  Created on: Aug 30, 2022
 *      Author: ELHOSSENI
 */

#ifndef MCAL_UART_UART_CONFIGURATION_H_
#define MCAL_UART_UART_CONFIGURATION_H_



/***********modes in UART ************/
#define ENABLE                  1
#define DISABLE                 0
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



/*
UART_BAUDRATE_1200_CLK_1M
UART_BAUDRATE_2400_CLK_1M
UART_BAUDRATE_4800_CLK_1M
UART_BAUDRATE_9600_CLK_1M
UART_BAUDRATE_19200_CLK_1M
UART_BAUDRATE_1200_CLK_8M
UART_BAUDRATE_2400_CLK_8M
UART_BAUDRATE_4800_CLK_8M
UART_BAUDRATE_9600_CLK_8M
UART_BAUDRATE_19200_CLK_8M
*/
#define UART_BAUDRATE                   UART_BAUDRATE_9600_CLK_8M


#define IDLE_INTERRUPT                      DISABLE_INTERRUPT  /*[DISABLE_INTERRUPT - ENABLE_INTERRUPT] */
#define RECEIVER_COMPLETE_INTERRUPT         DISABLE_INTERRUPT   /*[DISABLE_INTERRUPT - ENABLE_INTERRUPT] */
#define TRANSMITTER_COMPLETE_INTERRUPT      DISABLE_INTERRUPT   /*[DISABLE_INTERRUPT - ENABLE_INTERRUPT] */
#define TRANSMITTER_EMPTY_INTERRUPT         DISABLE_INTERRUPT  /*[DISABLE_INTERRUPT - ENABLE_INTERRUPT] */
#define PARITY_INTERRUPT                    DISABLE_INTERRUPT  /*[DISABLE_INTERRUPT - ENABLE_INTERRUPT] */
#define ERROR_INTERRUPT                     DISABLE_INTERRUPT  /*[DISABLE_INTERRUPT - ENABLE_INTERRUPT] */
#define LIN_BREAK_DETEC_INTERRUPT           DISABLE_INTERRUPT  /*[DISABLE_INTERRUPT - ENABLE_INTERRUPT] */


#define SEND_BREAK                          DISABLE           /*[ENABLE - DISABLE]*/
#define RECEIVER_WAKEUP                     DISABLE           /*[ENABLE - DISABLE]*/

#define RECEIVER_ENABLE                     ENABLE            /*[ENABLE - DISABLE]*/
#define TRANSMITTER_ENABLE                  ENABLE            /*[ENABLE - DISABLE]*/

#define PARITY_SELECTION                    DISABLE           /*[ENABLE - DISABLE]*/
#define PARITY_CONTROL                      DISABLE			  /*[ENABLE - DISABLE]*/
#define WAKEUP_METHOD                       DISABLE			  /*[ENABLE - DISABLE]*/

#define WORD_LENGTH                         WORD_9_BITS		  /*[WORD_8_BITS - WORD_9_BITS] */

#define IRDA_MODE                           DISABLE            /*[ENABLE - DISABLE]*/
#define IRDA_LOW_POWER                      DISABLE            /*[ENABLE - DISABLE]*/
#define HALF_DUPLEX                         DISABLE            /*[ENABLE - DISABLE]*/
#define SMARTCARD_NACK                      DISABLE            /*[ENABLE - DISABLE]*/
#define SMARTCARD_MODE                      DISABLE            /*[ENABLE - DISABLE]*/
#define DMA_RECEIVER                        DISABLE            /*[ENABLE - DISABLE]*/
#define DMA_TRANSMITTER                     DISABLE            /*[ENABLE - DISABLE]*/
#define RTS_MODE                            DISABLE            /*[ENABLE - DISABLE]*/
#define CTS_MODE                            DISABLE            /*[ENABLE - DISABLE]*/


#define NODE_ADDRESS                 DISABLE
#define LIN_BREAK_DETEC_LENGTH       DISABLE
#define LAST_BIT_CLOCK_PULSE         DISABLE
#define CLOCK_PHASE                  CLOCK_PHASE_CAP_SECOND
#define CLOCK_POLARITY               CLOCK_POLARITY_LOW
#define CLOCK_PIN_ENABLE             DISABLE
#define STOP_BIT_NUMBER              STOB_1_BITS
#define LIN_MODE                     DISABLE
#define CTS_INTERRUPT                DISABLE

#endif /* MCAL_UART_UART_CONFIGURATION_H_*/
