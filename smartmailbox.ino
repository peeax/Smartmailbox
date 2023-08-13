#include <TridentTD_LineNotify.h>  
#include <ESP8266WiFi.h>

#define ssid "Redmi Note 5"  
#define pass "8888888888"  
#define LINE_TOKEN "XX4RTT6FIPAZ7rPE78gnmiFsf4RSsqSrCa1XdkdZ3fS"  


TridentTD_LineNotify myLINE(LINE_TOKEN);

int sensorValue;
int isFlamePin = D6;
int isFlame = HIGH;


bool flame1 = 0;

void setup() {
  Serial.begin(115200);
  pinMode(isFlamePin, INPUT);
  
  WiFi.begin(ssid, pass);
  
}

void loop() {
  flameDetect();
  Serial.println(flame1);

  if (flame1 == 1) {
    myLINE.notify("จดหมายมาส่งจ้า");  
    Serial.println("Warnig, Warning, Warning");
    delay(5000);
  }

  delay(2000);
}

void flameDetect() {
  isFlame = digitalRead(isFlamePin);
  if (isFlame == LOW) {
    flame1 = 1;
    Serial.println("FLAME, FLAME, FLAME");
  } else {
    flame1 = 0;
    Serial.println("no flame");
  }
}
