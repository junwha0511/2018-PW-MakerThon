void initSD(){
  if(!SD.begin(4)){ //4번핀에 SD카드 모듈 연결 후 구동
    Serial.println("fail"); //실패시 fail출력
    return;
  }
}
