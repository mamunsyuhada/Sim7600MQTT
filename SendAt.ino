void SendAT(String atCommand,
            const int timeout,
            boolean debug) {

  sim7600.println(atCommand + "\r");
  delay(5);
  if (debug) {
    long int time = millis();
    while ( (time + timeout) > millis()) {
      while (sim7600.available() > 1) {
        response += char(sim7600.read());
      }
    }
    //    Serial.print(response);
  }
}

void AT() {
  SendAT("at", 10, DEBUG);
  String atValue = response;
  Serial.println(atValue);
  response = "";
}
