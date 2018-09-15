s#include<Adafruit_Thermal.h>
#include<SoftwareSerial.h>

const int tx_pin = 1;
const int rx_pin = 2;

SoftwareSerial mySerial(rx_pin, tx_pin);

Adafruit_Thermal printer(&Serial1);

void setup() {
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);

  mySerial.begin(19200);
  printer.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

}
