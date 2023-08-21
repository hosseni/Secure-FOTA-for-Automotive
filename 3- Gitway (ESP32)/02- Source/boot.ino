#include "boot.h"
#include "firebase.h"

BL_Return_Type Send_Node_Id (int NodeNum)
{
   BL_Return_Type command_status = NOT_OK;

   switch (NodeNum)
  {
    case 1 :     
        CAN.beginPacket (Node1_Flashing_Id);  //sets the ID and clears the transmit buffer
        command_status = OK;
        break;
    case 2 :     
        CAN.beginPacket (Node2_Flashing_Id);  //sets the ID and clears the transmit buffer
        command_status = OK;
        break;
    case 3 :     
        CAN.beginPacket (Node3_Flashing_Id);  //sets the ID and clears the transmit buffer
        command_status = OK;
        break;
    case 4 :     
        CAN.beginPacket (Node4_Flashing_Id);  //sets the ID and clears the transmit buffer
        command_status = OK;
        break;   
    default: 
        command_status = NOT_OK;
  }                 
        return command_status; 
}
BL_Return_Type Send_Packet_Length (int NodeNum, int Packet_Length)
{
 BL_Return_Type command_status = NOT_OK;

   #ifdef Debugging_Serial
   Serial.println("Sending Packet Length ");
    #endif
    #ifdef Debugging_TFT 
    // disply on TFT
    #endif

   Send_Node_Id(NodeNum);  //sets the ID
   CAN.write (Packet_Length); //write data to buffer. data is not sent until endPacket() is called.
   CAN.endPacket();
   
   int prev_time=millis();
   while (10 != canReceiver())
   {
    if(((millis()-prev_time) >= Time_Out))
    {  
     #ifdef Debugging_Serial 
     Serial.print ("\nTime Out while Sending Packet Length......\n");
     #endif
     #ifdef Debugging_TFT 
     // disply on TFT
     #endif
      return command_status;
    }
   } 
    command_status = OK;
    #ifdef Debugging_Serial
    Serial.println (" Packet Length ACK ");
    #endif
    #ifdef Debugging_TFT 
    // disply on TFT
    #endif
     return command_status;
}

BL_Return_Type Send_Command_Id (int NodeNum,int Packet_Id)
{
  
  BL_Return_Type command_status = NOT_OK;
  #ifdef Debugging_Serial
  Serial.println ("Sending Command Id");
  #endif
  #ifdef Debugging_TFT 
  // disply on TFT
  #endif
  Send_Node_Id(NodeNum);  
  CAN.write (Packet_Id);
  CAN.endPacket();

   int prev_time=millis();
   while (10 != canReceiver())
   {
    if(((millis()-prev_time) >= Time_Out))
    {  
     #ifdef Debugging_Serial 
     Serial.print ("\nTime Out while Sending Command Id\n");
    #endif
    #ifdef Debugging_TFT 
    // disply on TFT
    #endif
      return command_status;
    }
   } 
     command_status = OK;
     #ifdef Debugging_Serial
     Serial.println (" Command ID  ACK ");
    #endif
    #ifdef Debugging_TFT 
    // disply on TFT
    #endif
     return command_status;
}

BL_Return_Type Preform_Erase (int NodeNum, int App_Version)
{
  BL_Return_Type command_status = NOT_OK;

  #ifdef Debugging_Serial
  Serial.printf("Preforming Erase On Node %d", NodeNum);
  #endif
  #ifdef Debugging_TFT 
  // disply on TFT
  #endif

  Send_Node_Id(NodeNum);
  if (App_Version == 1) 
  {
  #ifdef Debugging_Serial
  Serial.println ("Erase version 1 section"); 
  #endif
  #ifdef Debugging_TFT 
  // disply on TFT
  #endif

  CAN.write (17);    // pageNum
  CAN.write (9); //NumOfPages
  }
  else if (App_Version == 2) 
  {
  #ifdef Debugging_Serial
  Serial.println ("Erase version 2 section");
  #endif
  #ifdef Debugging_TFT 
  // disply on TFT
  #endif

  CAN.write (9);
  CAN.write (6);  
  }
  else 
  {
   #ifdef Debugging_Serial
   Serial.println ("Erase feiled");  
   #endif
   #ifdef Debugging_TFT 
   // disply on TFT
   #endif
  }
  CAN.endPacket();

   int prev_time=millis();
   while (10 != canReceiver())
   {
    if(((millis()-prev_time) >= Time_Out))
    {  
     #ifdef Debugging_Serial
     Serial.print ("Time Out while Erasing......\n");
     #endif
     #ifdef Debugging_TFT 
     // disply on TFT
     #endif
      return command_status;
    }
   } 
     command_status = OK;
     #ifdef Debugging_Serial
     Serial.println (" Erasing Info ACK...");
     #endif
     #ifdef Debugging_TFT 
     // disply on TFT
     #endif
     return command_status;
}

BL_Return_Type Preform_Flash (int NodeNum, int AppVersion)
{
  BL_Return_Type command_status = NOT_OK;/**/
  int file_size = 0;
  File file;
  file_size = get_file_size (NodeNum, AppVersion);
  
  int msb   = (file_size & 0xFF);
  int lsb   = (  (file_size>>8) & 0xFF);

  #ifdef Debugging_Serial
  Serial.printf("\nPreforming Flash On Node %d\n", NodeNum);
  #endif
  #ifdef Debugging_TFT 
  // disply on TFT
  #endif

  Send_Node_Id(NodeNum);
  CAN.write (AppVersion);
  CAN.write (msb);
  CAN.write (lsb);
  CAN.endPacket();
   int prev_time=millis();
   while (10 != canReceiver())
   {
    if(((millis()-prev_time) >= Time_Out))
    {  
     #ifdef Debugging_Serial
     Serial.print ("Time Out while ......\n");
     #endif
     #ifdef Debugging_TFT 
     // disply on TFT
     #endif
     return command_status;
    }
   } 
 file = get_file (NodeNum, AppVersion);
            int i = 0;
         int presentage = 0;

      while (file.available ())
      {

           #ifdef Debugging_TFT 
              if (!(presentage % 30) ) 
              {
              i+= 10;
              TFT_WriteText(" Flashing    Firmware ..", ST7735_GREEN,2 ,10, 10);
              delay(250);
              updateProgressBar(i);
              delay(250);
              }
              presentage++;
           #endif
           #ifdef Debugging_Serial
              Serial.println("Flashing...");
           #endif
          
          Send_Node_Id(NodeNum);
          for (int i = 0; i < 8; i++)
          {
          CAN.write (file.read());
          }
          CAN.endPacket();
            int prev_time=millis();
            while (10 != canReceiver())
            {
              if(((millis()-prev_time) >= Time_Out))
              {  
              #ifdef Debugging_Serial
              Serial.print ("Time Out while ......\n");
              #endif
              #ifdef Debugging_TFT 
              // disply on TFT
              #endif
                return command_status;
              }
            } 
        command_status = OK;
      }
    
  
  
  return command_status;
            
}
//==================================================================================//
BL_Return_Type BL_Erase_Command(int Node_Num, int App_version)
{
  Command_Return_Type command_status = NOT_OK;
    
  command_status = Send_Packet_Length (Node_Num, Erase_Packet_Command_Length); 
  if (command_status == OK)
  {
    command_status = Send_Command_Id (Node_Num, Erase_Command_Id);
     if (command_status == OK)
      {
       command_status = Preform_Erase(Node_Num, App_version);
        if (command_status == OK)
        {
         #ifdef Debugging_Serial
         Serial.println ("Erase Done ..");
         #endif
         #ifdef Debugging_TFT 
         // disply on TFT
         #endif
         return command_status;
        }
      }
 }
   
}

Command_Return_Type BL_Run_Current_Version (int Node_Num, int App_Version)
{

  Command_Return_Type command_status = NOT_OK;
    
  command_status = Send_Packet_Length (Node_Num, Run_Crrent_Version_Command_Length); 
  if (command_status == OK)
  {
    command_status = Send_Command_Id (Node_Num, Run_Current_Veriosn_Id);
 }
  return command_status; 
   
}

Command_Return_Type BL_Flash_Command (int Node_Num, int App_Version)
{

  Command_Return_Type command_status = NOT_OK;
    
  command_status = Send_Packet_Length (Node_Num, Flash_Packet_Command_Length); 
  if (command_status == OK)
  {
    command_status = Send_Command_Id (Node_Num, Flash_Command_Id);
     if (command_status == OK)
      {
        command_status = Preform_Flash(Node_Num, App_Version);
        if (command_status == OK)
        {
         #ifdef Debugging_Serial
         Serial.println ("Flash Done ..");
         #endif
         #ifdef Debugging_TFT 
         // disply on TFT
         #endif
         return command_status;
        }
        else 
        {
          command_status == NOT_OK;
        }
      }
 }
  return command_status; 
}

/***************************************************************/
BL_Return_Type BL_Start (int * Node_Num, int * App_Version)
{
  BL_Return_Type start_status       = NOT_OK;
  Version_Status_Type Version_Status = No_Version_Exist;
  BL_Return_Type Download_Status    = NOT_OK; 
  
 //Get the selected Node
  *Node_Num = which_Node();
      if (0 != *Node_Num)
      {  
           //check if the version up to date
            Version_Status = Version_Is_New (*Node_Num, App_Version);
            if(Version_Status == New_Version)
            {
              // *App_Version = Get_App_Version(*Node_Num);
              Download_Status = Download_update (*Node_Num,*App_Version);
              if (Download_Status == OK)
              {
              #ifdef Debugging_Serial
              Serial.println("\nDownload Done........"); 
              #endif
              #ifdef Debugging_TFT 
              // disply on TFT
              #endif                 
              start_status = OK;                                         
              }
              else 
              {
              #ifdef Debugging_Serial
              Serial.println("\nDownload failed.......");   
              #endif
              #ifdef Debugging_TFT 
              // disply on TFT
              #endif     
              } 
            }
            else if ((Version_Status == Current_Version)&&(Current_Version != 0))
            {
              BL_Run_Current_Version(*Node_Num, *App_Version);
            }
      } 
      else 
      {
        #ifdef Debugging_Serial
        Serial.println("\nNo Updates .......");   
        #endif
        #ifdef Debugging_TFT 
        // disply on TFT
        #endif     
      }  
return start_status;
}

char canReceiver() {

  // try to parse packet
  int packetSize = CAN.parsePacket();
      // only print packet data for non-RTR packets
      while (CAN.available()) 
      {
        return CAN.read();
      }
}

void EEPROM_Reset ()
{
    EEPROM.begin(APPS_NUM);
    EEPROM.write (1,0);
    EEPROM.write (2,0);
    EEPROM.write (3,0);
    EEPROM.write (4,0);
    EEPROM.commit();
}