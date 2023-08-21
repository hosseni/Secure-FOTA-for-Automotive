#include "firebase.h"
#include "boot.h"
#include "tft.h"

// Define Firebase Data object
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
bool taskCompleted = false;
File file;
Command_Return_Type download_status = OK;


  // Other setup code


void configModeCallback(WiFiManager *myWiFiManager)
{
  #ifdef Debugging_Serial    
    Serial.println("Entered config mode");
    Serial.println("Please connect to the WiFi network 'MyDeviceSetup' and open a web browser to configure.");
    Serial.println(WiFi.softAPIP());
  #endif

}


void  connect_wifi()
{
  WiFiManager wm;

    Serial.begin (115200);
    bool res;
    
    wm.setConfigPortalTimeout(60); // Timeout in seconds
    wm.setAPCallback(configModeCallback);
    
    res = wm.autoConnect("ESP","12345678"); // password protected ap

    if(!res) 
    {
        #ifdef Debugging_TFT
        TFT_WriteText("Entered     Config Mode ", ST7735_RED,2 ,10, 10);
        #endif
        #ifdef Debugging_Serial
        Serial.println("Failed to connect");
        Serial.println("connect to configuration mode with ip : 192.168.4.1");
        #endif
      
    } 
    else 
    {
        //if you get here you have connected to the WiFi
        #ifdef Debugging_Serial
              Serial.println("connected");
        #endif
          TFT_WriteText("Connected    Sucessfully .. ", ST7735_GREEN,2 ,10, 10);
    }

}

void firebase_init ()
{
  connect_wifi();

  #ifdef Debugging_Serial
  Serial.println("Firebase set up");
  #endif
  #ifdef Debugging_TFT 
  // disply on TFT
  #endif

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the user sign in credentials */
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h


  // Limit the size of response payload to be collected in FirebaseData
  fbdo.setResponseSize(2048);

  Firebase.begin(&config, &auth);

  // The WiFi credentials are required for Pico W
  // due to it does not have reconnect feature.

  // Comment or pass false value when WiFi reconnection will control by your code or third party library
  Firebase.reconnectWiFi(true);

  Firebase.setDoubleDigits(5);

  config.timeout.serverResponse = 10 * 1000;

  
    // reading files:
    if(!SPIFFS.begin(true))
    {
        #ifdef Debugging_Serial
        Serial.println("An Error has occurred while mounting SPIFFS");
        #endif
        #ifdef Debugging_TFT 
        // disply on TFT
        #endif
        return;
   }

}
int which_Node ()
{
    int node_num = 0;
    Firebase.RTDB.getInt(&fbdo, F("/test/Selected_Node"), &node_num);
    if (0 != node_num)
    {
    #ifdef Debugging_Serial
    Serial.printf("Selected Node is : %d\n", node_num); //Firebase.RTDB.getInt(&fbdo, F("/test/Selected_Node"), &node_num) ? String(node_num).c_str() : fbdo.errorReason().c_str()
    #endif
    #ifdef Debugging_TFT 
    // disply on TFT
    #endif
    }
    else 
    {
      #ifdef Debugging_Serial
      Serial.println("No Node Selected\n");
      #endif
      #ifdef Debugging_TFT 
      // disply on TFT
      #endif
    }
   return   node_num;
}

int Get_App_Version (int node_num)
{
   int app_version = 0;
  if (Firebase.ready())
  {
  switch (node_num)
   {
    case 1:
    #ifdef Debugging_Serial
      Serial.printf("App version for node 1  is : %s\n", Firebase.RTDB.getInt(&fbdo, F("/test/Node1_Version"), &app_version) ? String(app_version).c_str() : fbdo.errorReason().c_str());
    #endif
    #ifdef Debugging_TFT 
    // disply on TFT
    #endif
      break;
    case 2:
    #ifdef Debugging_Serial
      Serial.printf("App version for node 2  is : %s\n", Firebase.RTDB.getInt(&fbdo, F("/test/Node2_Version"), &app_version) ? String(app_version).c_str() : fbdo.errorReason().c_str());
    #endif
    #ifdef Debugging_TFT 
      // disply on TFT
    #endif
    break;
    case 3:
    #ifdef Debugging_Serial
      Serial.printf("App version for node 3  is : %s\n", Firebase.RTDB.getInt(&fbdo, F("/test/Node3_Version"), &app_version) ? String(app_version).c_str() : fbdo.errorReason().c_str());   
    #endif
    #ifdef Debugging_TFT 
      // disply on TFT
    #endif
      break;
    case 4:
    #ifdef Debugging_Serial
      Serial.printf("App version for node 4  is : %s\n", Firebase.RTDB.getInt(&fbdo, F("/test/Node4_Version"), &app_version) ? String(app_version).c_str() : fbdo.errorReason().c_str());   
    #endif
    #ifdef Debugging_TFT 
    // disply on TFT
    #endif
           break;
     }
  }
  return app_version;
}

Version_Status_Type Version_Is_New (int Node_Num, int *Node_Version_Num)
{
  Version_Status_Type Version_Status = No_Version_Exist;
  *Node_Version_Num = Get_App_Version(Node_Num); 

  /*check the application version*/
  if  (EEPROM.read(Node_Num) < *Node_Version_Num)
  {
    #ifdef Debugging_Serial
    Serial.printf("\nthere is a new application version for node %d", Node_Num);
    #endif
    #ifdef Debugging_TFT 
    // disply on TFT
    #endif
    EEPROM.write(Node_Num, *Node_Version_Num);
    EEPROM.commit();
    delay (100);
    Version_Status = New_Version;
  }
  else if ((EEPROM.read(Node_Num) == *Node_Version_Num )&& (*Node_Version_Num != 0))
  {
    #ifdef Debugging_Serial
    Serial.printf("There is no  new applications for node %d", Node_Num);
    Serial.printf("\nThe current applications for node %d will run now\n", Node_Num);
    #endif
    #ifdef Debugging_TFT 
    // disply on TFT
    #endif
    Version_Status = Current_Version;
  } 
  else  
  {
    #ifdef Debugging_Serial
    Serial.printf("There is no  applications exist for node %d", Node_Num);
    #endif
    #ifdef Debugging_TFT 
    // disply on TFT
    #endif
    Version_Status = No_Version_Exist;
  }  
  return Version_Status;
}

Command_Return_Type Download_update (int NodeNum, int AppVersion)
{
      // Firebase.ready() should be called repeatedly to handle authentication tasks.
    if (Firebase.ready() && !taskCompleted)
    {
        taskCompleted = true;

        #ifdef Debugging_Serial
        Serial.println("\nDownload file...\n");
        #endif
        #ifdef Debugging_TFT 
        // disply on TFT
        #endif

    switch (NodeNum)
      {
        case 1:
            if (AppVersion == 1) 
            {
              if (!Firebase.Storage.download(&fbdo, STORAGE_BUCKET_ID /* Firebase Storage bucket id */, "App1.bin" /* path of remote file stored in the bucket */, "/Apps/App1/App1_V1.bin" /* path to local file */, mem_storage_type_flash /* memory storage type, mem_storage_type_flash and mem_storage_type_sd */, fcsDownloadCallback /* callback function */))
                  #ifdef Debugging_Serial
                  Serial.println(fbdo.errorReason());    
                  #endif
                  #ifdef Debugging_TFT 
                  // disply on TFT
                  #endif      
            } 
            else if (AppVersion == 2) 
            {
                if (!Firebase.Storage.download(&fbdo, STORAGE_BUCKET_ID /* Firebase Storage bucket id */, "App1.bin" /* path of remote file stored in the bucket */, "/Apps/App1/App1_V2.bin" /* path to local file */, mem_storage_type_flash /* memory storage type, mem_storage_type_flash and mem_storage_type_sd */, fcsDownloadCallback /* callback function */))
                  #ifdef Debugging_Serial
                  Serial.println(fbdo.errorReason());  
                  #endif
                  #ifdef Debugging_TFT 
                  // disply on TFT
                  #endif               
            }
        break;
        case 2:
          if (AppVersion == 1) 
            {
              if (!Firebase.Storage.download(&fbdo, STORAGE_BUCKET_ID /* Firebase Storage bucket id */, "App2.bin" /* path of remote file stored in the bucket */, "/Apps/App2/App2_V1.bin" /* path to local file */, mem_storage_type_flash /* memory storage type, mem_storage_type_flash and mem_storage_type_sd */, fcsDownloadCallback /* callback function */))
                  #ifdef Debugging_Serial
                  Serial.println(fbdo.errorReason());    
                  #endif
                  #ifdef Debugging_TFT 
                  // disply on TFT
                  #endif      
            } 
            else if (AppVersion == 2) 
            {
                if (!Firebase.Storage.download(&fbdo, STORAGE_BUCKET_ID /* Firebase Storage bucket id */, "App2.bin" /* path of remote file stored in the bucket */, "/Apps/App2/App2_V2.bin" /* path to local file */, mem_storage_type_flash /* memory storage type, mem_storage_type_flash and mem_storage_type_sd */, fcsDownloadCallback /* callback function */))
                  #ifdef Debugging_Serial
                  Serial.println(fbdo.errorReason());     
                  #endif
                  #ifdef Debugging_TFT 
                  // disply on TFT
                  #endif            
            }   
            break;
        case 3:
            if (AppVersion == 1) 
            {
              if (!Firebase.Storage.download(&fbdo, STORAGE_BUCKET_ID /* Firebase Storage bucket id */, "App3.bin" /* path of remote file stored in the bucket */, "/Apps/App3/App3_V1.bin" /* path to local file */, mem_storage_type_flash /* memory storage type, mem_storage_type_flash and mem_storage_type_sd */, fcsDownloadCallback /* callback function */))
                  #ifdef Debugging_Serial
                  Serial.println(fbdo.errorReason()); 
                  #endif
                  #ifdef Debugging_TFT 
                  // disply on TFT
                  #endif         
            } 
            else if (AppVersion == 2) 
            {
                if (!Firebase.Storage.download(&fbdo, STORAGE_BUCKET_ID /* Firebase Storage bucket id */, "App3.bin" /* path of remote file stored in the bucket */, "/Apps/App3/App3_V2.bin" /* path to local file */, mem_storage_type_flash /* memory storage type, mem_storage_type_flash and mem_storage_type_sd */, fcsDownloadCallback /* callback function */))
                  #ifdef Debugging_Serial
                  Serial.println(fbdo.errorReason());    
                  #endif
                  #ifdef Debugging_TFT 
                  // disply on TFT
                  #endif             
            }    
           break;
        case 4:
                if (AppVersion == 1) 
            {
              if (!Firebase.Storage.download(&fbdo, STORAGE_BUCKET_ID /* Firebase Storage bucket id */, "App4.bin" /* path of remote file stored in the bucket */, "/Apps/App4/App4_V1.bin" /* path to local file */, mem_storage_type_flash /* memory storage type, mem_storage_type_flash and mem_storage_type_sd */, fcsDownloadCallback /* callback function */))
                  #ifdef Debugging_Serial
                  Serial.println(fbdo.errorReason());     
                  #endif
                  #ifdef Debugging_TFT 
                  // disply on TFT
                  #endif     
            } 
            else if (AppVersion == 2) 
            {
                if (!Firebase.Storage.download(&fbdo, STORAGE_BUCKET_ID /* Firebase Storage bucket id */, "App4.bin" /* path of remote file stored in the bucket */, "/Apps/App4/App4_V2.bin" /* path to local file */, mem_storage_type_flash /* memory storage type, mem_storage_type_flash and mem_storage_type_sd */, fcsDownloadCallback /* callback function */))
                  #ifdef Debugging_Serial
                  Serial.println(fbdo.errorReason());   
                  #endif
                  #ifdef Debugging_TFT 
                  // disply on TFT
                  #endif              
            }
           break;
       }
    //get_file_size     (NodeNum, AppVersion);  
     // view_file_serial  (NodeNum, AppVersion);     
 }
 return download_status;
  
}

// The Firebase Storage download callback function
void fcsDownloadCallback(FCS_DownloadStatusInfo info)
{
if (info.status == fb_esp_fcs_download_status_init)
    {
        #ifdef Debugging_Serial
        Serial.printf("Downloading file %s (%d) to %s\n", info.remoteFileName.c_str(), info.fileSize, info.localFileName.c_str());
        #endif
        #ifdef Debugging_TFT 
        // disply on TFT
        #endif
    }
    else if (info.status == fb_esp_fcs_download_status_download)
    {
        #ifdef Debugging_Serial
        Serial.printf("Downloaded %d%s, Elapsed time %d ms\n", (int)info.progress, "%", info.elapsedTime);
        #endif
        #ifdef Debugging_TFT 
        // disply on TFT
        #endif
    }
    else if (info.status == fb_esp_fcs_download_status_complete)
    {
        #ifdef Debugging_Serial
        Serial.println("Download completed\n");
        #endif
        #ifdef Debugging_TFT 
        // disply on TFT
        #endif
        //view_file_serial();
        download_status = OK;
      
    }
    else if (info.status == fb_esp_fcs_download_status_error)
    {
        #ifdef Debugging_Serial
        Serial.printf("Download failed, %s\n", info.errorMsg.c_str());
        #endif
        #ifdef Debugging_TFT 
        // disply on TFT
        #endif
                download_status = NOT_OK;
    }
}

int get_file_size (int NodeNum, int AppVersion)
{
  int file_size = 0;
 switch (NodeNum)
      {
        case 1:
            if (AppVersion == 1) 
            {
            file = SPIFFS.open("/Apps/App1/App1_V1.bin");
             #ifdef Debugging_Serial
             Serial.printf("\n App1_V1 Size %d\n",file.size() );   
             #endif
             #ifdef Debugging_TFT 
             // disply on TFT
             #endif  
            } 
            else if (AppVersion == 2) 
            {
             file = SPIFFS.open("/Apps/App1/App1_V2.bin");
             #ifdef Debugging_Serial
             Serial.printf("\n App1_V2 Size %d\n",file.size() ); 
             #endif
             #ifdef Debugging_TFT 
             // disply on TFT
             #endif  
            }
            break;
            
        case 2:
           if (AppVersion == 1) 
            {
             file = SPIFFS.open("/Apps/App2/App2_V1.bin");
             #ifdef Debugging_Serial
             Serial.printf("\n App2_V1 Size %d\n",file.size() );   
             #endif
             #ifdef Debugging_TFT 
             // disply on TFT
             #endif
            } 
            else if (AppVersion == 2) 
            {
             file = SPIFFS.open("/Apps/App2/App2_V2.bin");
             #ifdef Debugging_Serial
             Serial.printf("\n App2_V2 Size %d\n",file.size() );  
             #endif
             #ifdef Debugging_TFT 
             // disply on TFT
             #endif 
            }
           break;
        case 3:
           if (AppVersion == 1) 
            {
             file = SPIFFS.open("/Apps/App3/App3_V1.bin");
             #ifdef Debugging_Serial
             Serial.printf("\n App3_V1 Size %d\n",file.size() );  
             #endif
             #ifdef Debugging_TFT 
             // disply on TFT
             #endif   
            } 
            else if (AppVersion == 2) 
            {
             file = SPIFFS.open("/Apps/App3/App3_V2.bin");
             #ifdef Debugging_Serial
             Serial.printf("\n App3_V2 Size %d\n",file.size() );  
             #endif
             #ifdef Debugging_TFT 
             // disply on TFT
             #endif
            }
           break;
        case 4:
           if (AppVersion == 1) 
            {
             file = SPIFFS.open("/Apps/App4/App4_V1.bin");
             #ifdef Debugging_Serial
             Serial.printf("\n App4_V1 Size %d\n",file.size() );   
             #endif
             #ifdef Debugging_TFT 
             // disply on TFT
             #endif
            } 
            else if (AppVersion == 2) 
            {
             file = SPIFFS.open("/Apps/App4/App4_V2.bin");
             #ifdef Debugging_Serial
             Serial.printf("\n App4_V2 Size %d\n",file.size() ); 
             #endif
             #ifdef Debugging_TFT 
             // disply on TFT
             #endif
            }
         break;
       }
  file_size = file.size();
  delay(200);

return file_size;
}


void view_file_serial (int NodeNum, int AppVersion)
{ 
   file = get_file (NodeNum, AppVersion);

  #ifdef Debugging_Serial
  Serial.printf("\nView App %d File Version %d in hex : ", NodeNum, AppVersion);
  #endif
  #ifdef Debugging_TFT 
  // disply on TFT
  #endif
  
        delay(300);
        while(file.available())
        {
            Serial.write(file.read());
            delay(3);
        }
  file.close();

  delay(500);
  #ifdef Debugging_Serial
  Serial.println("End of file");
  #endif
  #ifdef Debugging_TFT 
  // disply on TFT
  #endif
}


File get_file (int NodeNum, int AppVersion)
{ 

   switch (NodeNum)
      {
        case 1:
            if (AppVersion == 1) 
            {
            #ifdef Debugging_Serial
            Serial.println("Openning App1_V1");  
            #endif
            #ifdef Debugging_TFT 
            // disply on TFT
            #endif   
            file = SPIFFS.open("/Apps/App1/App1_V1.bin");

            } 
            else if (AppVersion == 2) 
            {
              #ifdef Debugging_Serial
              Serial.println("Openning App1_V2");    
              #endif
              #ifdef Debugging_TFT 
              // disply on TFT
              #endif 
              file = SPIFFS.open("/Apps/App1/App1_V2.bin");
            }
            break;
            
        case 2:
           if (AppVersion == 1) 
            {
              #ifdef Debugging_Serial
              Serial.println("Openning App2_V1");     
              #endif
              #ifdef Debugging_TFT 
              // disply on TFT
              #endif
              file = SPIFFS.open("/Apps/App2/App2_V1.bin");

            } 
            else if (AppVersion == 2) 
            {
              #ifdef Debugging_Serial
              Serial.println("Openning App2_V2");  
              #endif
              #ifdef Debugging_TFT 
              // disply on TFT
              #endif   
              file = SPIFFS.open("/Apps/App2/App2_V2.bin");
            }
           break;
        case 3:
           if (AppVersion == 1) 
            {
              #ifdef Debugging_Serial
              Serial.println("Openning App3_V1");   
              #endif
              #ifdef Debugging_TFT 
              // disply on TFT
              #endif  
              file = SPIFFS.open("/Apps/App3/App3_V1.bin");

            } 
            else if (AppVersion == 2) 
            {
              #ifdef Debugging_Serial
              Serial.println("Openning App3_V2"); 
              #endif
              #ifdef Debugging_TFT 
              // disply on TFT
              #endif                  
              file = SPIFFS.open("/Apps/App3/App3_V2.bin");
            }
           break;
        case 4:
           if (AppVersion == 1) 
            {
              #ifdef Debugging_Serial
              Serial.println("Openning App4_V1");     
              #endif
              #ifdef Debugging_TFT 
              // disply on TFT
              #endif
              file = SPIFFS.open("/Apps/App4/App4_V1.bin");

            } 
            else if (AppVersion == 2) 
            {
              #ifdef Debugging_Serial
              Serial.println("Openning App4_V2"); 
              #endif
              #ifdef Debugging_TFT 
              // disply on TFT
              #endif    
              file = SPIFFS.open("/Apps/App4/App4_V2.bin");
            }
         break;
       }
  return file;
}
