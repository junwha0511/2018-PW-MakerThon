void initPrinter(){
  pinMode(7,OUTPUT); digitalWrite(7,LOW); //프린터 초기화
  mySerial.begin(19200); //지정된 핀의 시리얼 시작
  printer.begin(); //프린터 시작
  printer.setTimes(32000, 2100); //프린팅 시간 연장
}
