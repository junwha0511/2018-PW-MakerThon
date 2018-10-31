void initIR(){
  irrecv.enableIRIn(); //핀 활성화
}

//값을 추가하는 함수
int insertNum(int ext, int plus){
  return ext*10+plus;
}

//값을 지우는 함수
int eraseNum(int ext){
  return (int)(ext/10);
}

//값을 받는 함수
int receiveTheValue(){
    if (irrecv.decode(&results)) {
      delay(50); //값을 비울 때까지 기다림
      irrecv.resume(); // 다음 값을 받을 수 있도록 함
      return mappingData(results.value); //mappingData에서 해시값을 결과값으로 변환해 리턴
      
    }
    delay(50);
  return -1; //값을 입력받지 못했을 경우 음수 리턴
}

//해시값을 결과값으로 변환하는 함수
int mappingData(int a){
  int key[12] = {
      16753245,16736925,16769565,16720605,16712445,16761405,16769055,16754775,16748655,16750695,16726215,16756815
  }; //각각의 해시값
  int value[12] = {1,2,3,4,5,6,7,8,9,0,10,11}; //1~9,0: number, 10: OK, 11: #
  
  for(int i=0; i<12; i++){
    if(a==key[i]){ //a와 키값이 일치할 경우
      return value[i]; //value를 출력함
    }
  }
  return -1; //지정된 버튼이 아닐 경우 음수를 리턴함
}
