
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"

RF24 radio(7,8);

const char msg[] = "Hello World!";

void setup() {
  Serial.begin(9600);
  
  radio.begin();
  radio.setAutoAck(false);
  radio.openWritingPipe(0xF0F0F0F0AA); 
  radio.setChannel(64);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_2MBPS);
  radio.stopListening();       
  printf_begin();
  radio.printDetails();  
}

void loop() {
  // radio.write(&msg, sizeof(msg)); 
  printf("Hi!");
  delay(1000);
}
