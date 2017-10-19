/*
* Arduino Wireless Communication Tutorial
*       Example 1 - Receiver Code
*                
* credits: Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define ledPin 2
boolean buttonState = 0;

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setDataRate(RF24_250KBPS);

  //PA Level options: RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH and RF24_PA_MAX
  radio.setPALevel(RF24_PA_MAX);
  radio.setChannel(108);
  radio.startListening();
}
void loop() {
  if (radio.available()) {
    radio.read(&buttonState, sizeof(buttonState));
    if(buttonState == HIGH)
    {
      Serial.println("turn on led");
      digitalWrite(ledPin, HIGH);
    }
    else {
      digitalWrite(ledPin, LOW);
    }
  }
}
