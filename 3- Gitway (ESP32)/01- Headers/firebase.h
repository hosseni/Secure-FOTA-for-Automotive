  

/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef FIREBASE_H_
#define FIREBASE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
//#include <WiFi.h>

#include <Firebase_ESP_Client.h>

// Provide the token generation process info.
#include <addons/TokenHelper.h>

// Provide the RTDB payload printing info and other helper functions.
#include <addons/RTDBHelper.h>
/* Define the WiFi credentials */

#include <EEPROM.h>

#include "STD_TYPES.h"

#include <SPIFFS.h>
#include <WiFiManager.h> 

#define Debugging_Serial 1 
#define Debugging_TFT    1

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define WIFI_SSID "Elhosseni"
#define WIFI_PASSWORD "12345678"
// #define API_KEY "AIzaSyDOuZi2G5fpfZPNSZNwYay3qdi9-_tLGVU"
// #define DATABASE_URL "fota-99e9c-default-rtdb.firebaseio.com" //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app
// #define USER_EMAIL "elhossenenour@gmail.com"
// #define USER_PASSWORD "12345678"
// #define STORAGE_BUCKET_ID "fota-99e9c.appspot.com"


#define API_KEY "AIzaSyAk1M4OJ5ZBFkktzda_f1As9BEAslFripo"
#define DATABASE_URL "graduation-project-b758c-default-rtdb.firebaseio.com/" //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app
#define USER_EMAIL "elhossenenour@gmail.com"
#define USER_PASSWORD "12345678"
#define STORAGE_BUCKET_ID "graduation-project-b758c.appspot.com"


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void connect_wifi  ();
void firebase_init ();


 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
