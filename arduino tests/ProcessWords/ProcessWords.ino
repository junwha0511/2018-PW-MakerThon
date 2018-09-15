#include<SPI.h>
#include<SD.h>

File f; //파일 클래스

/*
 * 전체적인 로직
 * 1. 텍스트 파일은 외우지 않은 단어, 외우지 못한 단어 두개의 파일이 있음(시간 여유 있으면 세개로 구현)
 * 2. 두개의 파일은 매일 지우고 다시 새로 생성됨
 * 3. 아두이노의 Setup 함수에서 두개의 파일을 읽어와 배열로 파싱함
 * 4. 외우지 않은 단어에서 당일에 선별된 인덱스는 0으로 바뀜, 0으로 바뀐 데이터는 저장 시 포함되지 않음
 * 5. 매일 단어를 선별할 때 외우지 못한 단어가 5개 이하가 될 때까지 외우지 못한 단어 5개씩을 포함시킴
 */
if(!SD.begin(4)){ //4번핀에 SD카드 모듈 연결 후 구동
    Serial.println("fail"); //실패시 fail출력
    return;
}
  
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
