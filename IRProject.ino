#include <IRremote.h>
#include <IRremoteInt.h>
#include <SPI.h>
//#include <Ethernet.h>

//ETH 
/*byte mac[] = {0x90, 0xA2, 0xDA, 0x0E, 0x40, 0x9F};
byte ip[] = {192, 168, 0, 172};
byte server[] = {192,168,0,160};
int port = 1700;
EthernetClient client;
*/
//IR
#define IRPIN      3    // IR led is connected on pin 8
int RECV_PIN = 4;
int led = 13;
byte Type=0, Crc;
unsigned int Device=0x0707, Data=0;

IRrecv irrecv(RECV_PIN);
IRsend irsend;
decode_results results;


// ---------------------------------------------------------------------
 // Samsung IR class
 // ---------------------------------------------------------------------
 
 class Samsung
 {
   private:
   // Send a 36kHz-modulated pulse
   static void Pulse(void)
   {
     byte i;
     for (i=0; i<21; i++)
     {
       digitalWrite(IRPIN, HIGH);
       delayMicroseconds(10); // Value adjusted with oscilloscope
       digitalWrite(IRPIN, LOW);
       delayMicroseconds(10); // Value adjusted with oscilloscope
     }
   }
   // Send a bit
   static void SendIRBit(byte b)
   {
     Pulse(); 
     if (b) 
       delayMicroseconds(1390);
     else
       delayMicroseconds(430);
   }
   // Send 4 bits
   static void SendIRNibble(byte b)
   {
     byte i;
     for (i=0; i<4; i++)
       SendIRBit((b>>i)&1);
   }
   // Send a byte
   static void SendIRByte(byte b)
   {
     byte i;
     for (i=0; i<8; i++)
       SendIRBit((b>>i)&1);
   }
 
   public:
   // Send an IR command
   // Type is 0 for TV, 1 for BD
   // Device is 0x0707 for TV, 0x301A for BD
   // Crc should be ~Command, except for tests
   static void SendCommand(char Type, unsigned int Device, unsigned int Command, unsigned char Crc)
   {
     byte i;
    
     // Disable interrupts
     cli();
     pinMode(IRPIN, OUTPUT); // start the transmitter
     digitalWrite(IRPIN, HIGH);   
     // Start bit
     for (i=0; i<8; i++)	Pulse();
     delayMicroseconds(4500);
 
     // Send Device Id
     SendIRByte(Device>>8);
     SendIRByte(Device&0xff);
 
     // BD Player
     if (Type==1)
     {
       // Stop bit
       Pulse();
       delayMicroseconds(4500);
       // Send Data
       SendIRNibble(Command>>8);
     }
     
     SendIRByte(Command);
     SendIRByte(Crc);
 
     // Stop bit
     Pulse();
     delayMicroseconds(4500);
   
     // Re-enable interrupts
     sei();
   }
 };


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
    // IR Led
   //pinMode(IRPIN, OUTPUT); // start the transmitter
   //digitalWrite(IRPIN, HIGH); 
//  if (Ethernet.begin(mac) == 0) {
//    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    // try to congifure using IP address instead of DHCP:
    //Ethernet.begin(mac, ip);
    // give the Ethernet shield a second to initialize:
    //delay(1000);
//  }
    // if you get a connection, report back via serial:
//  if (client.connect(server, port)) {
//    Serial.println("connected");
//  } 
//  else {
//    // if you didn't get a connection to the server:
//    Serial.println("connection failed");
//  }  
//  Serial.println("connecting...");
  pinMode(led, OUTPUT);   
}

void loop()
{
  
 /* if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }*/  
  
 if (irrecv.decode(&results)) {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
/*    if (results.decode_type == NEC) {
      Serial.print("NEC: ");
    } else if (results.decode_type == SONY) {
      Serial.print("SONY: ");
    } else if (results.decode_type == RC5) {
      Serial.print("RC5: ");
    } else if (results.decode_type == RC6) {
      Serial.print("RC6: ");
    } else if (results.decode_type == UNKNOWN) {
      Serial.print("UNKNOWN: ");
    }
*/    
    /*
    if (client.connected()) {
      client.print(results.decode_type); 
      client.print(results.value); 
    }*/

    if (results.decode_type == RC5) Serial.print("RC5:");
    Serial.println(results.value, HEX);
    
    if (results.decode_type == RC5){
      if (results.value == 0x801 || results.value == 0x1){
        Serial.println("sending on to digiturk");
        irsend.sendRC5(0xB8C,12); // sat on
      }else if(results.value == 0x802 || results.value == 0x2){
        Serial.println("sending off to digiturk");
        irsend.sendRC5(0x38C,12);
      }else if(results.value == 0x80C || results.value == 0xC){ // all off
        Serial.println("sending off to digiturk");
        irsend.sendRC5(0x38C,12);
        delay(100);  
        Serial.println("sending off to AVR");      
        irsend.sendNEC(0x10EF906,32);
        Serial.println("sending off to TV");
        delay(100);        
        Data=0x98;
        Samsung::SendCommand(Type, Device, Data, ~Data);        
      } else if(results.value == 0x804 || results.value == 0x4){
        Serial.println("sending on to AVR");
        irsend.sendNEC(0x10E03FC,32);
      } else if(results.value == 0x80C || results.value == 0xC){
        Serial.println("sending off to AVR");
        irsend.sendNEC(0x10EF906,32);
      }else if(results.value == 0x810 || results.value == 0x10){ // vol u
        Serial.println("sending vol u to AVR");
        irsend.sendNEC(0x10EE31C,32);
      }else if(results.value == 0x811 || results.value == 0x11){ // vol d
        Serial.println("sending vol d to AVR");
        irsend.sendNEC(0x10E13EC,32);
      }else if(results.value == 0x820 || results.value == 0x20){ // ch+
        Serial.println("sending ch+ to SAT");
        irsend.sendRC5(0x392,12);
      }else if(results.value == 0x821 || results.value == 0x21){ // ch-
        Serial.println("sending ch- to SAT");
        irsend.sendRC5(0xBAE,12);
      }else if(results.value == 0x807 || results.value == 0x7){ // tv on
         Serial.println("sending on to TV");
         Data=0x60; // TV on
         Samsung::SendCommand(Type, Device, Data, ~Data); // TV on
      }else if(results.value == 0x808 || results.value == 0x8){ // tv off
        Serial.println("sending off to TV");
         Data=0x98; // tv off
         Samsung::SendCommand(Type, Device, Data, ~Data); // tv off

      }else if(results.value == 0x83C || results.value == 0x3C){ // bt sat
        Serial.println("Switching to SAT");
        irsend.sendRC5(0xB8C,12);// sat on
        delay(100);
        irsend.sendNEC(0x10E03FC,32); // avr on   
        delay(100);        
        irsend.sendNEC(0x10E0DF2,32); // avr to sat
        delay(100);        
      }else if(results.value == 0x82E || results.value == 0x2E){ // ttx1 // bt TV
        Serial.println("Switching to TV");      
        irsend.sendNEC(0x10E8D72,32); // avr to tv
        delay(100);        
        irsend.sendRC5(0x38C,12); // sat off
        delay(100);        
      }else if(results.value == 0x82A || results.value == 0x2A){ // ttx2 // bt PS3
        Serial.println("Switching to ps3");      
        irsend.sendNEC(0x10E4DB2,32); // avr to game
        delay(100);        
        irsend.sendRC5(0x38C,12); // sat off
        delay(100);        
      }else if(results.value == 0x82B || results.value == 0x2B){ // ttx3 // bt Wii
        Serial.println("Switching to TV");      
        irsend.sendNEC(0x10E8D72,32); // avr to tv
        delay(100);        
        Data=0x86; // TV to component
        Samsung::SendCommand(Type, Device, Data, ~Data);     
      }else if(results.value == 0x829 || results.value == 0x29){ // ttx4 // bt Apple TV
        Serial.println("Switching to Apple TV");      
        irsend.sendNEC(0x10ECB34,32); // avr to STB
        delay(100);        
        irsend.sendRC5(0x38C,12); // sat off
        delay(100);        
      }
      
    }else{ // other protocols
        if(results.value == 0x1C102884 || results.value == 0x4B995E59){ // ttx red 
            // switch to sat
            Serial.println("red button");  
            irsend.sendRC5(0xB8C,12);// sat on
            delay(100);
            irsend.sendNEC(0x10E03FC,32); // avr on   
            delay(100);        
            irsend.sendNEC(0x10E0DF2,32); // avr to sat
            delay(100); // sat on
        } else if(results.value == 0xE050BDE6 || results.value == 0xEF4EDF53){ // ttx green
           // switch to TV
           Serial.println("Switching to TV");      
           irsend.sendNEC(0x10E8D72,32); // avr to tv
           delay(100);        
           irsend.sendRC5(0x38C,12); // sat off
           delay(100);                   
        } else if(results.value == 0xDF50BC53 || results.value == 0xF04EE0E6){ // ttx yellow 
           Serial.println("Switching to Apple TV");  
           irsend.sendNEC(0x10ECB34,32); // avr to STB
           delay(100);        
           irsend.sendRC5(0x38C,12); // sat off
           delay(100);    
        }
        else if(results.value == 0x8533B77 || results.value == 0x5F564B6A){ // ttx blue 
           Serial.println("Switching to PS3");      
           irsend.sendNEC(0x10E4DB2,32); // avr to game
           delay(100);        
           irsend.sendRC5(0x38C,12); // sat off
           delay(100);  
        }
    } // green  
      // yellow
      // blue

    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW  
    delay(100);  
    irrecv.enableIRIn();
  } 
}

/*

  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    // do nothing:
    while(true);
  }

*/
