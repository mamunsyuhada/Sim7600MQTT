void SendPublishPacket(void) {
  sim7600.print("\r\nAT+CIPSEND=0,100\r\n");
  delay(3000);
  memset(str, 0, 250);
  topiclength = sprintf((char*)topic, MQTTTopic);
  datalength = sprintf((char*)str, "%s%u", topic, Counter);
  delay(1000);
  sim7600.write(0x30);
  X = datalength + 2;
  do {
    encodedByte = X % 128;
    X = X / 128;
    if ( X > 0 ) {
      encodedByte |= 128;
    }
    sim7600.write(encodedByte);
  }
  while ( X > 0 );
  sim7600.write(topiclength >> 8);
  sim7600.write(topiclength & 0xFF);
  sim7600.print(str);
  sim7600.write(0x1A);
}
