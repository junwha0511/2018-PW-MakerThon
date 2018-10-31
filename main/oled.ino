void initOLED(){
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  
  display.display();
  delay(2000);

  display.clearDisplay();
}

//Scene을 출력하는 함수
void printScene(String *args){
  //기존의 Scene을 지우고
  display.clearDisplay();
  for(int i=0; i<4; i++){
    display.setTextSize(1);
    display.setTextColor(WHITE);
    //줄 간격: 8
    display.setCursor(0,i*8);
    //전달 받은 String 배열 출력
    display.print(args[i]);
    display.display();
  }
}

//각 라인의 텍스트를 지정하는 함수
void setLine(int line, String s){
  lines[line] = s;
}

//외부 명령을 기다리는 중앙 처리 함수(시간, 리모컨)
int central(int sceneNumber){
  int a=-1;
  switch(sceneNumber){
    case 1:
      while((a=receiveTheValue())<0);
      break;
  }
  return a;
}

//Scene1, 첫 화면
void scene1(){
  setLine(0,"");
  setLine(1,"Hi");
  setLine(2,"English word printer");
  setLine(3,"");
  printScene(lines);

  int ok=-1;
  while((ok=central(4))<0); //값이 들어올 때까지 기다린다.
  
  
}

void scene4(){
  setLine(0,"English words Printer");
  setLine(1,"");
  setLine(2,"#: erase, *:comma ,OK: finish");
  setLine(3,"           [OK]              ");
  printScene(lines);

  int ok=-1;
  while((ok=central(4))<0); //값이 들어올 때까지 기다린다.
  
  if(ok){
    scene1();
  }
}

void scene5(){



}

