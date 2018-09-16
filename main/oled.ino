void initOLED(){
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  
  display.display();
  delay(2000);

  display.clearDisplay();
}
