#include <Servo.h>
#include <ESP8266HTTPClient.h>
#include <Hash.h>
#include <DoubleResetDetector.h>
#include <EEPROM.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>
// #include <ESPAsyncTCP.h>
// #include <ESPAsyncWebServer.h>
#include <ESP8266WebServer.h>
#define DRD_TIMEOUT 10 // double reset timeout
#define DRD_ADDRESS 0  // double reset address
#define lightPin 4     // D2 pin
#define motorPin 1     // D1 pin
#define trigPin 12     // D6
#define echoPin 14     // D5
#define baud_rate 115200
#define eeprom_size 512

int curtain_position = 100;
String curtain_mode = "manual";
const float minDistance = 5.0;
const float maxDistance = 12;
const int arrayLength = 3;
String infoArr[arrayLength]; // for storing wifi credential read from eeprom
String ssid = "";
String password = "";
bool installed_light = false;
bool resetWifi = false;
bool APactive = false; // if the AP is active make sure wifi cannot be connected
WiFiClient client;     // for invoking wifi connection
DoubleResetDetector drd(DRD_TIMEOUT, DRD_ADDRESS);
ESP8266WebServer server(80);          // making a server object that listens on port 80
ESP8266WebServer portal_server(3000); // making a server object that listens on port 3000
Servo servo;
// AsyncWebServer async_server(80);

void startSPIFFS()
{
  if (SPIFFS.begin()) // start SPIFFS for reading HTML and CSS file
  {
    Serial.println("opened SPIFFS");
  }
  else
  {
    Serial.println("failed to open SPIFFS");
  }
}

void setup()
{
  Serial.begin(baud_rate);      // initialize baud rate
  EEPROM.begin(eeprom_size);    // Initialasing EEPROM
  pinMode(LED_BUILTIN, OUTPUT); // set the esp 8266 LED  to output mode
  pinMode(trigPin, OUTPUT);     // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);      // Sets the echoPin as an Input
  servo.attach(2);
  Serial.print("last character: " + EEPROM.read(510));
  checkDoubleReset(); // check if rest button is pressed twice
  startSPIFFS();
  if (EEPROM.read(510) != 83 || resetWifi)
  {
    Serial.println("clearing rom");
    // clear the rom first before writing
    clearRom(eeprom_size);

    // start the web server and AP to get the credentials
    setupAP();
    launchWeb(); // launch async webserver
    Serial.println("waiting for credentials");
    Serial.println("");
    while ((WiFi.status() != WL_CONNECTED) && APactive)
    {

      Serial.print(".");
      delay(200);
      server.handleClient();
    }
  }
  // credential already exist
  // read the info from EEPROM
  else
  {
    // helper function that reads everything in the rom and store it infoArr
    /*
     * index 0: wifi name
     * index 1: wifi password
     * index 2: location name
     * index 3: port number
     * index 4: server IP
     * index 5: sleep timer
     * index 6: light sensor insatlled?
     */
    readFromRomHelper();                  // read credential from EEPROM
    ssid = infoArr[0];                    // wifi name
    password = infoArr[1];                // wifi password
    installed_light = infoArr[2].toInt(); // is the esp equiped with light sensor? The value is either 1 or 0, true or false
    wifiConnect();                        // connect to wifi
  }
  launchDashboard();
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
