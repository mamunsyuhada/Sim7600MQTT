void SendConnectPacket(void) {
  sim7600.print("\r\nAT+CIPSEND=0,100\r\n");
  delay(3000);
  sim7600.write(0x10);
  MQTTProtocolNameLength = strlen(MQTTProtocolName);
  MQTTClientIDLength = strlen(MQTTClientID);
  MQTTUsernameLength = strlen(MQTTUsername);
  MQTTPasswordLength = strlen(MQTTPassword);
  datalength = MQTTProtocolNameLength + 2 + 4 + MQTTClientIDLength + 2 + MQTTUsernameLength + 2 + MQTTPasswordLength + 2;
  X = datalength;
  do {
    encodedByte = X % 128;
    X = X / 128;
    if ( X > 0 ) {
      encodedByte |= 128;
    }
    sim7600.write(encodedByte);
  }
  while ( X > 0 );
  sim7600.write(MQTTProtocolNameLength >> 8);
  sim7600.write(MQTTProtocolNameLength & 0xFF);
  sim7600.print(MQTTProtocolName);
  sim7600.write(MQTTLVL); // LVL
  sim7600.write(MQTTFlags); // Flags
  sim7600.write(MQTTKeepAlive >> 8);
  sim7600.write(MQTTKeepAlive & 0xFF);
  sim7600.write(MQTTClientIDLength >> 8);
  sim7600.write(MQTTClientIDLength & 0xFF);
  sim7600.print(MQTTClientID);
  sim7600.write(MQTTUsernameLength >> 8);
  sim7600.write(MQTTUsernameLength & 0xFF);
  sim7600.print(MQTTUsername);
  sim7600.write(MQTTPasswordLength >> 8);
  sim7600.write(MQTTPasswordLength & 0xFF);
  sim7600.print(MQTTPassword);
  sim7600.write(0x1A);
}
