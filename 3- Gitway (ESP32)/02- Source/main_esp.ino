#include "boot.h"
#include "firebase.h"
#include "tft.h"
 

void setup()
{
  
   Serial.begin(115200);
  
   TFT_init();

   /*Firebase set up*/
   firebase_init();
      
  //TFT_WriteText("Bootloader   Starting....", ST7735_GREEN,2, 10, 10);

  // Set the pins
  CAN.setPins (RX_GPIO_NUM, TX_GPIO_NUM);

  // start the CAN bus at 500 kbps
  if (!CAN.begin (500E3)) 
  {
    #ifdef Debugging_Serial
    Serial.println ("Starting CAN failed!");
    #endif
    #ifdef Debugging_TFT 
    // disply on TFT
    #endif
    while (1);
  }
  else 
  {
    #ifdef Debugging_Serial
    Serial.println ("CAN Initialized");
    #endif
    #ifdef Debugging_TFT 
    // disply on TFT
    #endif
  }
    /*reset apps version number*/
  EEPROM_Reset();
}
/***************************************************************/

void loop() 
{
  #ifdef Debugging_TFT
  TFT_WriteText("Bootloader  Starting....", ST7735_GREEN,2, 10, 30);
  #endif

  int Node_Num, App_Version;
  BL_Return_Type BL_Status  = NOT_OK;
    BL_Status = BL_Start(&Node_Num, &App_Version);
    if (NOT_OK == BL_Status)
    {
        delay (3000);
    }
    else 
    {
     #ifdef Debugging_Serial 
     Serial.print ("Bootloader Starts ..\n"); 
     #endif
    #ifdef Debugging_TFT 
    // disply on TFT
    #endif

     BL_Status = BL_Erase_Command(Node_Num, App_Version);
     if (BL_Status == OK)
     {
      #ifdef Debugging_Serial 
      Serial.print ("Erase Done Successfully.. \n");
      Serial.print ("Receive ACK From EraseCommand \n");
      #endif
      
      #ifdef Debugging_TFT 
      // disply on TFT
      #endif
      BL_Status = BL_Flash_Command (Node_Num, App_Version);  
               
        if (BL_Status == OK)
        {
          #ifdef Debugging_Serial
          Serial.print ("Flash Done Successfully.. \n");
          #endif
          #ifdef Debugging_TFT 
          // disply on TFT
          #endif
        } 
        else 
        {
          #ifndef Debugging_Serial
          Serial.print ("Flash Failed.. \n");
          #endif
          #ifdef Debugging_TFT 
          // disply on TFT
          #endif
        }
   }
     else 
     {
       #ifdef Debugging_Serial
      Serial.print ("Erase Failed.. \n");
      #endif
      #ifdef Debugging_TFT 
      // disply on TFT
      #endif
     }
    }

}
//==================================================================================//