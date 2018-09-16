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
  int a = -1;
  if(Serial.available()){
      a=(Serial.read()-48);
  }
  Serial.println(a);
  return a;
}

//Scene1, 첫 화면
void scene1(){
  setLine(0,"English words Printer");
  setLine(1,"1.Set the print Time");
  setLine(2,"2.Set the current Time");
  setLine(3,"3.help");
  printScene(lines);
  
  int order = -1;
  while((order=central(1))<0); //order가 들어올 때까지 기다린다.
  
  if(order==1){//Call Scene2
    scene2();
  }else if(order==2){//Call Scene3
    scene3();
  }else if(order==3){//Call Scene4
    scene4();
  }else if(order==4){//Call Scene5
    scene5(); //Scene5 호출
  }
}


//Scene2, 프린트 시간 설정 화면
void scene2(){
  setLine(0,"Please Set the Print Time");
  setLine(1,"This time is 00:00");
  setLine(2,"hour: ");
  setLine(3,"");
  printScene(lines);
  //시 설정
  int hour=-1;
  while((hour=central(2))<0); //값이 들어올 때까지 기다린다.
  setLine(2,"hour: "+String(hour));
  setLine(3,"minutes: ");
  printScene(lines);
  //분 설정
  int minutes=-1;
  while((minutes=central(2))<0); //값이 들어올 때까지 기다린다.
  setLine(3,"minutes: "+String(minutes));
}

//Scene3, 현재 시간 설정 화면
void scene3(){
  setLine(0,"Please Set the Current Time");
  setLine(1,"This time is 00:00");
  setLine(2,"hour: ");
  setLine(3,"");
  printScene(lines);
  //시 설정
  int hour=-1;
  while((hour=central(3))<0); //값이 들어올 때까지 기다린다.
  setLine(2,"hour: "+String(hour));
  setLine(3,"minutes: ");
  printScene(lines);
  //분 설정
  int minutes=-1;
  while((minutes=central(3))<0); //값이 들어올 때까지 기다린다.
  setLine(3,"minutes: "+String(minutes));
}

//Scene4, Help
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

