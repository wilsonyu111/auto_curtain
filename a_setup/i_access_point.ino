void setupAP(void)
{
  APactive = true;
  Serial.println ("starting AP");
  WiFi.softAP("esp", ""); // launch access point
  delay(10);


}
