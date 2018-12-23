void TCP() {
  OpenServer();
  SendConnectPacket();
  delay(500);
  SendSubscribePacket();
  delay(500);
  SendPublishPacket();
  delay(500);
}

void OpenServer() {
  String cipOpen = "at+cipopen=0,";
  cipOpen += "\"TCP\",\"";
  cipOpen += "\"ec2-13-229-65-188.ap-southeast-1.compute.amazonaws.com\",";
  cipOpen += "1883";
  //  TODO masih kurang
  SendAT(cipOpen, 1000, DEBUG);
  String openServer = response;
  Serial.println(openServer);
  response = "";
}
