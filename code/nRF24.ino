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

/*
引入函式庫：程式一開始引入了幾個函式庫，分別是 SPI.h、nRF24L01.h、RF24.h 和 printf.h。這些函式庫提供了操作SPI介面、nRF24L01模組和RF24函式的功能。
宣告變數：程式宣告了一個 RF24 物件 radio，這將用來和nRF24L01模組進行通訊。
設定傳輸訊息：程式中定義了一個常數字串 msg，內容為 "Hello World!"，這將作為要傳送的訊息。

setup() 函式：這個函式在Arduino啟動時執行一次，主要用來進行初始化設定。
Serial.begin(9600);：開啟串口通訊，設定傳輸速率為 9600 bits per second，這樣可以在Serial Monitor中觀察程式執行的訊息。

radio.begin();：初始化nRF24L01模組，準備進行無線通訊。
radio.setAutoAck(false);：關閉自動ACK功能，ACK是確認傳送成功的回應，這裡設定為false表示不需要回應確認。
radio.openWritingPipe(0xF0F0F0F0AA);：設定通訊的寫入管道位址，這是用來指定要發送訊息的目的地。
radio.setChannel(64);：設定無線頻道編號為64。
radio.setPALevel(RF24_PA_MAX);：設定傳輸功率為最大。
radio.setDataRate(RF24_2MBPS);：設定資料傳輸速率為2Mbps。
radio.stopListening();：將模組設定為發送模式，不再接收訊息。

printf_begin();：初始化 printf 函式，這樣可以使用 radio.printDetails() 函式來顯示nRF24L01的設定詳細資訊。
radio.printDetails();：顯示nRF24L01的設定詳細資訊。

loop() 函式：這個函式會不斷循環執行。
radio.write(&msg, sizeof(msg));：將 msg 訊息透過無線模組 radio 發送出去。&msg 是 msg 的記憶體位置的指標，sizeof(msg) 是訊息的大小，這樣可以確保將整個訊息發送出去。
delay(1000);：等待一秒的時間，然後再次執行下一次的發送訊息。
*/

void loop() {
  // radio.write(&msg, sizeof(msg)); 
  printf("Hi!");
  delay(1000);
}
