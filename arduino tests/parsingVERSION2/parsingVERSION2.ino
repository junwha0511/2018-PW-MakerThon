#include<Adafruit_Thermal.h>
#include<SoftwareSerial.h>

#include<SPI.h>
#include<SD.h>

#define TX_PIN 6
#define RX_PIN 5

SoftwareSerial mySerial(RX_PIN, TX_PIN);
Adafruit_Thermal printer(&mySerial);

File f;

void setup() {
  Serial.begin(115200);
  pinMode(7,OUTPUT); digitalWrite(7,LOW);
  mySerial.begin(19200);
  printer.begin();
  if(!SD.begin(4)){
    Serial.println("fail");
    return;
  }
  printer.setTimes(32000, 2100);
  for(int i=1; i<=100; i++){
    String fp = String(i)+".txt";
    Serial.println(fp);
    f = SD.open(fp,FILE_READ);
    printBitmapSD(700,20);
    printer.feed(1);
  }
  printer.feed(2);
printer.sleep();
delay(3000L);
printer.wake();
printer.setDefault();
}

void loop() {
  
}
int parsingData(){
  int num = 0;
  char c;
  //(c=f.read())!=',' and c!='\n'
  while(true){
    c=f.read();
    if(c=='x'){
      int num;
      int first = f.read();
      int second = f.read();
      if(second!=44){
        num+=hexToDec(first)*16+hexToDec(second);   
      }else{
        num+=hexToDec(first);
      }
      return num;
    }
  }
}
int hexToDec(char a){
  char arr[16] = {48,49,50,51,52,53,54,55,56,57,97,98,99,100,101,102}; //0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f
  for(int i=0;i<16;i++){
    if(a==arr[i]){
      return i;
    }
  }
  return -1;
}
void printBitmapSD(int w, int h){
  uint8_t arr[1760];
  for(int i=0; i<1760; i++){
    arr[i] = parsingData();
    Serial.println("parsing");
  }
  printer.printBitmap(w,h,arr,false);
}
