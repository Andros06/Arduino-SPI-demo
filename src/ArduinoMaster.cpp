#include <Arduino.h>
#include <SPI.h>

char str [] = "Hello Slave, We are Arduino Family";

void setup() {

  Serial.begin(115200); //setter "baud rate" til 115200
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8); //setter spi klokke og deler den på 8
  Serial.println("Hello I'm SPI master");

}

void loop() {
  
  digitalWrite(SS, LOW); // aktiverer Slave select
  // send test string
  for(int i=0; i< sizeof(str); i++){
    SPI.transfer(str[i]);
    digitalWrite(SS, HIGH); // deaktivere Slave select
    delay(2000);
  }
}

