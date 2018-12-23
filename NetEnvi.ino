void NetEnvi() {
  CheckSignal();  
  RegInternet();
  GetProvider();
  GetReg();
}

void CheckSignal() {
  SendAT("at+csq", 100, DEBUG);
  String signalValue = response;
  Serial.println(signalValue);
  response = "";
}

void RegInternet() {
  SendAT("at+creg?", 100, DEBUG);
  String regValue = response;
  Serial.println(regValue);
  response = "";
}

void GetProvider() {
  SendAT("at+cpsi?", 100, DEBUG);
  String providerValue = response;
  Serial.println(providerValue);
  response = "";
}

void GetReg() {
  SendAT("at+cgreg?", 100, DEBUG);
  String registrasiValue = response;
  Serial.println(registrasiValue);
  response = "";
}   
