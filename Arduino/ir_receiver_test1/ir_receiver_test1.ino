#include "IRremote.h"

int receiver = 11; //Port digital 11

IRrecv irrecv(receiver); 
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    sendIRCode();
    irrecv.resume();
  }
}

void sendIRCode() {
  Serial.println(results.value);
  delay(200);
}

