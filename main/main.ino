#include <IRremote.h>//IR 라이브러리

#include<Adafruit_Thermal.h> //열전사 프린터 라이브러리
#include<SoftwareSerial.h> //시리얼 핀을 설정하는 라이브러리 

#include<SPI.h> //SPI 통신을 위한 라이브러리
#include<SD.h> //SD 카드를 위한 라이브러리

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define TX_PIN 6
#define RX_PIN 5

#define OLED_RESET 4

Adafruit_SSD1306 display(OLED_RESET);

int RECV_PIN = A0; //값을 받을 핀

String lines[4];

IRrecv irrecv(RECV_PIN); 
decode_results results;

SoftwareSerial mySerial(RX_PIN, TX_PIN);
Adafruit_Thermal printer(&mySerial); //프린터 클래스

File f; //파일 클래스

void setup()
{
  Serial.begin(115200); //시리얼 모니터
  initIR();
  initOLED();
  initSD();
  initPrinter();
  scene1();
}

void loop(){
  
}

