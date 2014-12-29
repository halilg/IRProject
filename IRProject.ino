#include <IRremote.h>
#include <IRremoteInt.h>
#include <SPI.h>
#include <Ethernet.h>

//ETH 
byte mac[] = {0x90, 0xA2, 0xDA, 0x0E, 0x40, 0x9F};
byte ip[] = {192, 168, 0, 172};
byte server[] = {192,168,0,160};
int port = 1700;
EthernetClient client;

//IR
int RECV_PIN = 4;
int led = 13;
IRrecv irrecv(RECV_PIN);
IRsend irsend;
decode_results results;


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
//  if (Ethernet.begin(mac) == 0) {
//    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    // try to congifure using IP address instead of DHCP:
    Ethernet.begin(mac, ip);
    // give the Ethernet shield a second to initialize:
    delay(1000);
//  }
    // if you get a connection, report back via serial:
  if (client.connect(server, port)) {
    Serial.println("connected");
  } 
  else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }  
  Serial.println("connecting...");
  pinMode(led, OUTPUT);   
}


void loop()
{
  
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }  

  
 if (irrecv.decode(&results)) {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    if (results.decode_type == NEC) {
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
    
    if (client.connected()) {
      client.print(results.decode_type); 
      client.print(results.value); 
    }
    
    Serial.println(results.value, HEX);
    if (results.decode_type == RC5){
      if (results.value == 0x80C){
        Serial.println("sending on/off to digiturk");
        irsend.sendRC5(0xB8C,12);
      }else if(results.value == 0xC){
        Serial.println("sending on/off to digiturk");
        irsend.sendRC5(0x38C,12);
      }
    }    
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


Codes:
-------------------------------------------
Transmitter: RC5
On off: C 80C
1:1 801
2:2 802
3:3 803
4:4 804
5:
6:
7:
8:
9:
0:
Mute:D 80D
16:9: AD8C62D2 F280BC5B
ReD: 4B995E59 1C102884
Green: E050BDE6 EF4EDF53
Yellow: DF50BC53 F04EE0E6
Blue: 8533B77
P+: 820 20
P-:  821 21
V+: 810 10
V-: 811 11
AV: 38 838
TV: 83F 3F
SMD: 823 23
RLR: 822 22
MENU: BFB8F2FE D9F9700B
TTX0: 83C 3C
TTX1: 82E 2E
TTX2: 82A 2A
TTX3: C460AC26
TTX4: 829 29
TTX5: 82B 2B
TTX6: 82D 2D
TTX7: 82C
PP: 80E
i: 80F
-------------------------------------------
Samsung TV: None : 32 bit
on: E0E040BF
-------------------------------------------
HK: NEC: 32 bit
On: 10E03FC+FFFFFFFF
Off: 10EF906+FFFFFFFF
-------------------------------------------
Digiturk: RC5: 12 bit
on: B8C 38C

Apple TV
Menu: 

*/
