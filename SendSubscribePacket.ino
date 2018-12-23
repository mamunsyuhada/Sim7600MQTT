void SendSubscribePacket(void) {
  sim7600.print("\r\nAT+CIPSEND==0,100\r\n");
  delay(3000);
  memset(str, 0, 250);
  topiclength = strlen(MQTTTopic);
  datalength = 2 + 2 + topiclength + 1;
  delay(1000);
  sim7600.write(0x82);
  X = datalength;
  do  {
    encodedByte = X % 128; X = X / 128;
    if ( X > 0 ) {
      encodedByte |= 128;
    }
    sim7600.write(encodedByte);
  }
  while ( X > 0 );
  sim7600.write(MQTTPacketID >> 8);
  sim7600.write(MQTTPacketID & 0xFF);
  sim7600.write(topiclength >> 8);
  sim7600.write(topiclength & 0xFF);
  sim7600.print(MQTTTopic);
  sim7600.write(MQTTQOS);
  sim7600.write(0x1A);
}
