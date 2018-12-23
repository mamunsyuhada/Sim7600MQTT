void APN() {
  SetAPN("telkomsel");
  SockePN();
  SetCipMode();
}

void NetOpen(){
  OpenNet();
  GetIpDevice();
}
void SetAPN(String apn) {
  String atAPN = "at+cgsockcont=1,";
  atAPN += "\"IP\",";
  atAPN += "\"" + apn + "\"";
  SendAT(atAPN, 100, DEBUG);
  String regValue = response;
  Serial.println(regValue);
  response = "";
}

void SockePN() {
  SendAT("at+csocksetpn=1", 100, DEBUG);
  String setPN = response;
  Serial.println(setPN);
  response = "";
}

void SetCipMode() {
  SendAT("at+cipmode=0", 100, DEBUG);
  String setCipMode = response;
  Serial.println(setCipMode);
  response = "";
}

//loop...

void OpenNet() {
  SendAT("at+netopen", 100, DEBUG);
  String netOpen = response;
  Serial.println(netOpen);
  response = "";
}

void GetIpDevice() {
  SendAT("at+ipddr", 100, DEBUG);
  String netOpen = response;
  Serial.println(netOpen);
  response = "";
}
