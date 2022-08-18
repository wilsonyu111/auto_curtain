//#include <AsyncEventSource.h>
//#include <AsyncJson.h>
//#include <AsyncWebSocket.h>
//#include <AsyncWebSynchronization.h>
//#include <ESPAsyncWebServer.h>
//#include <SPIFFSEditor.h>
//#include <StringArray.h>
//#include <WebAuthentication.h>
//#include <WebHandlerImpl.h>
//#include <WebResponseImpl.h>
//
///*
//   Copyright (c) 2015, Majenko Technologies
//   All rights reserved.
//
//   Redistribution and use in source and binary forms, with or without modification,
//   are permitted provided that the following conditions are met:
//
// * * Redistributions of source code must retain the above copyright notice, this
//     list of conditions and the following disclaimer.
//
// * * Redistributions in binary form must reproduce the above copyright notice, this
//     list of conditions and the following disclaimer in the documentation and/or
//     other materials provided with the distribution.
//
// * * Neither the name of Majenko Technologies nor the names of its
//     contributors may be used to endorse or promote products derived from
//     this software without specific prior written permission.
//
//   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
//   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
//   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
//   ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
//   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
//   LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
//   ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
//   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//*/
//
//#include <ESP8266WiFi.h>
//#include <WiFiClient.h>
//#include <ESP8266WebServer.h>
//#include <ESP8266mDNS.h>
//
//#ifndef STASSID
//#define STASSID "2.4ghz"
//#define STAPSK  "wilsonyu"
//#endif
//
//const char *ssid = STASSID;
//const char *password = STAPSK;
//
//ESP8266WebServer server(80);
//
//const int led = 13;
//
//void handleNotFound() {
//  digitalWrite(led, 1);
//  String message = "File Not Found\n\n";
//  message += "URI: ";
//  message += server.uri();
//  message += "\nMethod: ";
//  message += (server.method() == HTTP_GET) ? "GET" : "POST";
//  message += "\nArguments: ";
//  message += server.args();
//  message += "\n";
//
//  for (uint8_t i = 0; i < server.args(); i++) {
//    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
//  }
//
//  server.send(404, "text/plain", message);
//  digitalWrite(led, 0);
//}
//
//
//void setup(void) {
//  if (SPIFFS.begin()) // start SPIFFS for reading HTML and CSS file
//    {
//      Serial.println("opened SPIFFS");
//    }
//    else
//    {
//      Serial.println("failed to open SPIFFS");
//    }
//  pinMode(led, OUTPUT);
//  digitalWrite(led, 0);
//  Serial.begin(115200);
//  WiFi.mode(WIFI_STA);
//  WiFi.begin(ssid, password);
//  Serial.println("");
//
//  // Wait for connection
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.print(".");
//  }
//
//  Serial.println("");
//  Serial.print("Connected to ");
//  Serial.println(ssid);
//  Serial.print("IP address: ");
//  Serial.println(WiFi.localIP());
//
//  server.onNotFound(handleNotFound);
//  server.begin();
//  server.on("/", handleMain);
//  server.on("/setting", handleSubmitValue);
//  Serial.println("HTTP server started");
//}
//
//void handleMain()
//{
//  //File html_file = SPIFFS.open("/index.html", "r"); // working html submission template
//  File html_file = SPIFFS.open("/main.html", "r");
//  File css_file = SPIFFS.open("/style.css", "r");
//  server.streamFile(html_file, "text/html");
//  server.streamFile(css_file, "text/css");
//  html_file.close();
//  css_file.close();
//  
//}
//
//
//// accept values from client and write it to eeprom
//void handleSubmitValue()
//{
//  Serial.println ("handling submitted value");
//  int nextAddress = 0;
//  String wifiName = server.arg("ssid");
//  String wifiPass = server.arg("pass");
//  String sensor_present = server.arg("installed_sensor");
//  String http_msg = wifiName+wifiPass+sensor_present;
//
//  // only store credentials if wifi name and pass exists
//  // and port number is a valid 5 digit positive number
//  // the sleep interval is a valid 5 digit positive number
//  server.send(200, "text/plain", http_msg);
//}
//
//void loop(void) {
//  server.handleClient();
//}
