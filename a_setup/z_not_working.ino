//void launchWeb()
//{
//  Serial.println ("starting web site");
//  createWebServer();
//  async_server.begin();
//  
//}
//
//void createWebServer()
//{
//  async_server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
//    request->send(SPIFFS, "/main.html", "text/html");
//  });
//  
//  // Route to load style.css file
//  async_server.on("/auto_curtain.css", HTTP_GET, [](AsyncWebServerRequest *request){
//    request->send(SPIFFS, "/style.css", "text/css");
//  });
//  async_server.on("/setting", HTTP_GET, [](AsyncWebServerRequest *request){
//
//    String sensor_stat = "";
//    if (request->hasParam("ssid")) 
//    {
//      ssid = request->getParam("ssid")->value();
//    }
//    if (request->hasParam("pass")) 
//    {
//      password = request->getParam("pass")->value();
//    }
//    if (request->hasParam("installed_sensor")) 
//    {
//      sensor_stat = request->getParam("installed_sensor")->value();
//      
//      if (sensor_stat == "1"){
//        installed_light = true;
//      }
//    }
//    request->send(200, "text/plain", "testing wifi");
//    
//    
//    // only store credentials if wifi name and pass exists
//    // and port number is a valid 5 digit positive number
//    // the sleep interval is a valid 5 digit positive number
//    int nextAddress = 0;
//    if (testWifi(ssid, password))
//    {
//      /*
//       * index 0: wifi name
//       * index 1: wifi password
//       * index 2: location name
//       * index 3: port number
//       * index 4: server IP
//       * index 5: sleep timer
//       * index 6: light sensor insatlled?
//       */    
//      nextAddress = writeToRom (ssid, nextAddress);
//      nextAddress = writeToRom (password, nextAddress);
//      nextAddress = writeToRom (sensor_stat, nextAddress);
//      
//      // write an S to the last byte in the rom for verification
//      // This letter is needed when the esp first start up
//      // and about to read the rom, it needs to know if there are anything
//      // writen to the rom before
//      // if this doesn't exist it'll not read the rom
//      writeToRom ("S", 510);
//      
//      EEPROM.commit(); // write value from memory to the physical flash
//      Serial.println ("restarting esp");
//      Serial.println ("sensor_stat: " + sensor_stat);
//
////      ESP.reset(); // restart the esp to close all server and access point
//    }
//    else
//    {
//      request->send(200, "text/plain", "incorrect values");
//    }
//  });
//}
