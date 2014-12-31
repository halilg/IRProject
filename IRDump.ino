/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>
#include <IRremoteInt.h>

int RECV_PIN = 4;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
     int count = results.rawlen;
      if (results.decode_type == UNKNOWN) {
    Serial.print("Unknown encoding: ");
  } 
  else if (results.decode_type == NEC) {
    Serial.print("Decoded NEC: ");
  } 
  else if (results.decode_type == SONY) {
    Serial.print("Decoded SONY: ");
  } 
  else if (results.decode_type == RC5) {
    Serial.print("Decoded RC5: ");
  } 
  else if (results.decode_type == RC6) {
    Serial.print("Decoded RC6: ");
  }
  else if (results.decode_type == PANASONIC) {	
    Serial.print("Decoded PANASONIC - Address: ");
    Serial.print(results.panasonicAddress,HEX);
    Serial.print(" Value: ");
  }
  else if (results.decode_type == LG) {
     Serial.print("Decoded LG: ");
  }
  else if (results.decode_type == JVC) {
     Serial.print("Decoded JVC: ");
  }
  else if (results.decode_type == SAMSUNG) {
    Serial.print("Decoded SAMSUNG: ");
  }
  int val1 = results.value;
  Serial.print(val1, HEX);
  Serial.print(" (");
  int valbits = results.bits;
  Serial.print(valbits, DEC);
  Serial.println(" bits)");
  Serial.print("Raw (");
  Serial.print(count, DEC);
  Serial.print("): ");
  for (int i = 0; i < count; i++) {
    if ((i % 2) == 1) {
      int valen = results.rawbuf[i]*USECPERTICK;
      Serial.print(valen, DEC);
 
    } 
    else {
      int negvalen =-(int)results.rawbuf[i]*USECPERTICK;
      Serial.print(negvalen, DEC);
    }
    Serial.print(", ");
  }
  Serial.println("");  
    
    //Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
