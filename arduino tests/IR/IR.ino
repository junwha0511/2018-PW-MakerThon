#include <IRremote.h>

int RECV_PIN = A0; //값을 받을 핀

IRrecv irrecv(RECV_PIN); 
decode_results results;
void setup()
{
  Serial.begin(9600); //시리얼 모니터
  irrecv.enableIRIn(); //핀 활성화

}
void loop() {
  int num = 0; //입력 받은 값이 처리될 변수
  while(true){
    int value = -1; 
    while((value=receiveTheValue())<0); //value값을 받아와 함수의 리턴값이 0보다 클 때까지 처리. 
    if(value<=9){ //9보다 작거나 같을 경우
      num = insertNum(num, value); //숫자를 추가함
      Serial.println(num);
    }else if(value==10){ //OK
       break; //값 확정
    }else if(value==11){ //#
      num = eraseNum(num); //값을 지움
      Serial.println(num);
    }
  }
  Serial.println("your input: "+String(num));
  delay(1000);
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

