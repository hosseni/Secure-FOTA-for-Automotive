
#ifndef ESP_BOOT_H_ 
#define ESP_BOOT_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include <EEPROM.h>
#include <CAN.h>
#include "STD_TYPES.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define StartPin         22
#define TX_GPIO_NUM      33  // Connects to CTX
#define RX_GPIO_NUM      32  // Connects to CRX

/**********************BL Maximum response time*************************************/
#define Time_Out         40000


/***********************Nodes Identifier*****************************************/
#define Node1_Flashing_Id   3
#define Node2_Flashing_Id   2
#define Node3_Flashing_Id   4
#define Node4_Flashing_Id   5

#define Num_Of_Nodes        4


/***********************Nodes Identifier*****************************************/
#define Run_Current_Veriosn_Id 14
#define Erase_Command_Id       15
#define Flash_Command_Id       16

#define Erase_Packet_Command_Length       2  
#define Flash_Packet_Command_Length       3  
#define Run_Crrent_Version_Command_Length 1



#define WIFI_SSID "Elhosseni"
#define WIFI_PASSWORD "12345678"

#define APPS_NUM           4
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
BL_Return_Type Send_Packet_Length (int NodeNum, int Packet_Length);
BL_Return_Type Send_Command_Id (int NodeNum,int Packet_Id);

BL_Return_Type Preform_Erase (int NodeNum, int App_Version);

BL_Return_Type BL_Erase_Command(int Node_Num, int App_Version);
BL_Return_Type BL_Flash_Command(int Node_Num, int App_Version);
BL_Return_Type BL_Start        (int * Node_Num, int * App_Version);
void           EEPROM_Reset();


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif /*ESP_BOOT_H_*/


/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
