int led = 13;
unsigned int Counter = 0;
unsigned long datalength, CheckSum, RLength;
unsigned short topiclength;
unsigned char topic[30];
char str[250];
unsigned char encodedByte;
int X;
unsigned short MQTTProtocolNameLength;
unsigned short MQTTClientIDLength;
unsigned short MQTTUsernameLength;
unsigned short MQTTPasswordLength;
const char MQTTHost[55] = "ec2-13-229-65-188.ap-southeast-1.compute.amazonaws.com";
const char MQTTPort[10] = "1883";
const char MQTTClientID[20] = "trakaka";
const char MQTTTopic[30] = "data";
const char MQTTProtocolName[10] = "MQTT";
const char MQTTLVL = 0x03;
const char MQTTFlags = 0xC2;
const unsigned int MQTTKeepAlive = 60;
const char MQTTUsername[30] = "demo";
const char MQTTPassword[35] = "demo";
const char MQTTQOS = 0x00;
const char MQTTPacketID = 0x0001;

#define sim7600 Serial5
#define DEBUG true

String response;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  sim7600.begin(115200);
  delay(1000);
  Serial.println("Arduino MQTT Tutorial, Valetron Systems @www.raviyp.com ");
  delay(3000);
  NetEnvi();
  APN();
}

void loop() {
  NetOpen();
  TCP();  
  sim7600.print("AT+CIPCLOSE=0\r\n");
  delay(2000);
  sim7600.print("AT+CSTT=\"www\",\"\",\"\"\r\n");
  delay(1000);
  sim7600.print("AT+CIPMODE=0\r\n");
  delay(1000);
  sim7600.print("AT+CIICR\r\n");
  delay(9000);
  sim7600.print("AT+CIPSTART=\"TCP\",\"ec2-13-229-65-188.ap-southeast-1.compute.amazonaws.com\",\"1883\"\r\n");
  delay(6000);
  SendConnectPacket();
  delay(5000);
  SendSubscribePacket();
  delay(5000);
  while (1) {
    if (Serial.available() > 0) {
      str[0] = Serial.read();
      Serial.write(str[0]);
      if (str[0] == 'N')
        digitalWrite(led, HIGH);
      if (str[0] == 'F')
        digitalWrite(led, LOW);
    }
  }
}
