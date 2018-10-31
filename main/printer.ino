void initPrinter(){
  pinMode(7,OUTPUT); digitalWrite(7,LOW); //프린터 초기화
  mySerial.begin(19200); //지정된 핀의 시리얼 시작
  printer.begin(); //프린터 시작
  printer.setTimes(32000, 2100); //프린팅 시간 연장
}

void printWord(int a){
  String fp = String(a)+".txt"; //파일 경로(유동적)
  f = SD.open(fp,FILE_READ); //파일 열기
  printBitmapSD(700,20); //printBitmapSD 함수 실행
  printer.feed(1); //빈 칸 한 칸 출력
  f.close();
  delay(3000);
  Serial.write(1);
  delay(500);
}

//Thermal printer 라이브러리에 프린팅을 걸어주는 함수
void printBitmapSD(int w, int h){
  uint8_t arr[1760]; //1760크기의 uint8_t형 배열 정의 (20x88)
  for(int i=0; i<1760; i++){ 
    arr[i] = parsingData(); //데이터를 파싱해서 배열에 저장
  }
  printer.printBitmap(w,h,arr,false); //printBitmap함수에 생성된 배열과 함께 전달
}
