#include<Adafruit_Thermal.h> //열전사 프린터 라이브러리
#include<SoftwareSerial.h> //시리얼 핀을 설정하는 라이브러리 

#include<SPI.h> //SPI 통신을 위한 라이브러리
#include<SD.h> //SD 카드를 위한 라이브러리

#define TX_PIN 6
#define RX_PIN 5

SoftwareSerial mySerial(RX_PIN, TX_PIN);
Adafruit_Thermal printer(&mySerial); //프린터 클래스

File f; //파일 클래스

void setup() {
  Serial.begin(115200); //시리얼 모니터
  pinMode(7,OUTPUT); digitalWrite(7,LOW); //프린터 초기화
  mySerial.begin(19200); //지정된 핀의 시리얼 시작
  printer.begin(); //프린터 시작
  if(!SD.begin(4)){ //4번핀에 SD카드 모듈 연결 후 구동
    Serial.println("fail"); //실패시 fail출력
    return;
  }
  printer.setTimes(32000, 2100); //프린팅 시간 연장
  for(int i=1; i<=100; i++){
    String fp = String(i)+".txt"; //파일 경로(유동적)
    f = SD.open(fp,FILE_READ); //파일 열기
    printBitmapSD(700,20); //printBitmapSD 함수 실행
    printer.feed(1); //빈 칸 한 칸 출력
  }
  printer.feed(2); //빈 칸 두 칸 출력
printer.sleep();
delay(3000L);
printer.wake();
printer.setDefault();
}

void loop() {
  
}
//SD카드에 저장된 텍스트 파일의 데이터를 파싱하는 함수
int parsingData(){
  char c; //바이트 단위로 읽어올 변수
  while(true){
    c=f.read(); //c에 1바이트를 읽어옴
    if(c=='x'){ //c의 값이 x일 경우(0x의 x),
      
      int num; //값이 저장될 변수
      
      int first = f.read();//1바이트를 읽어옴
      int second = f.read();//1바이트를 읽어옴
      
      if(second!=44){//두번째 바이트가 ,가 아닐 경우,
        num+=hexToDec(first)*16+hexToDec(second);//첫번째 바이트는 16자리 수로, 두번째 바이트는 1자리 수로 계산 
      }else{//두번째 바이트가 ,일 경우
        num+=hexToDec(first); //첫번째 바이트를 1자리 수로 계산 (ex: 0x6)
      }
      return num; //num을 return
    }
  }
}

//16진수를 10진수로 변환하는 함수
int hexToDec(char a){
  char arr[16] = {48,49,50,51,52,53,54,55,56,57,97,98,99,100,101,102}; //0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f
  
  for(int i=0;i<16;i++){
    if(a==arr[i]){//배열의 값과 a가 일치할 경우
      return i;//i를 리턴
    }
  }
  
  return -1;//16진수가 아닐 경우 음수를 리턴
}

//Thermal printer 라이브러리에 프린팅을 걸어주는 함수
void printBitmapSD(int w, int h){
  uint8_t arr[1760]; //1760크기의 uint8_t형 배열 정의 (20x88)
  for(int i=0; i<1760; i++){ 
    arr[i] = parsingData(); //데이터를 파싱해서 배열에 저장
  }
  printer.printBitmap(w,h,arr,false); //printBitmap함수에 생성된 배열과 함께 전달
}
