void initSD(){
  if(!SD.begin(4)){ //4번핀에 SD카드 모듈 연결 후 구동
    Serial.println("fail"); //실패시 fail출력
    return;
  }
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
