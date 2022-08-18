void launchDashboard()
{
  Serial.println ("starting web site");
  createWebPortal();
  portal_server.begin();
  
}

// make a web server that sends a html file
// and handles submission from client
void createWebPortal()
{
  portal_server.on("/", sendDashboard);
  portal_server.on("/mode", handleMode);
  portal_server.on("/slider", handleSlider);
  portal_server.on("/curtain.css", sendCSSFile);
  portal_server.on("/funset.js", sendJSFile);
}

void sendDashboard()
{
  File html_file = SPIFFS.open("/index.html", "r");  
  portal_server.streamFile(html_file, "text/html");  
  html_file.close();
   
}

void handleMode()
{
  String changeModeTo = portal_server.arg("value");
  Serial.println(changeModeTo);
  portal_server.send(200, "text/plain", "got value");
}

void handleSlider()
{
  String sliderValue = portal_server.arg("value");
  Serial.println(sliderValue);
  portal_server.send(200, "text/plain", "got value");
}

void sendCSSFile()
{
  File css_file = SPIFFS.open("/curtain.css", "r");
  portal_server.streamFile(css_file, "text/css");
  css_file.close();
}

void sendJSFile()
{
  File js_file = SPIFFS.open("/funset.js", "r");
  portal_server.streamFile(js_file, "text/js");
  js_file.close();
}
