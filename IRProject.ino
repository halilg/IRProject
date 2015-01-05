
#include <IRremote.h>
#include <IRremoteInt.h>
#include <SPI.h>
#include "ir_hex_input.h"
#include "ir_hex_SAT_Digiturk.h"
#include "ir_hex_TV_Samsung_UE40ES7000.h"
#include "ir_hex_AVR_HK_151.h"
#include "ir_hex_NP_AppleTV.h"
#include "samsung.h"

// Operation mode values.
#define MODOFF 1
#define MODSAT 2
#define MODTV 3
#define MODATV 4
#define MODPS3 5
#define MODWII 6
#define MODAUX 7

// Delay between multiple transmissions, in ms
#define TDELAY 30 

// Option to compile serial print codes
#define NOSERIAL

int RECV_PIN = 4;//4; // Pin of IR receiver
int led = 13;     // Pin of blinker LED
byte oMode=MODOFF;
byte Type=0, Crc;   // Samsung TV protocol variables
unsigned int Device=0x0707, Data=0; // Samsung TV data

IRrecv irrecv(RECV_PIN);
IRsend irsend;
decode_results results;
bool saton=false;
int cmd11bit=0;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(led, OUTPUT);   
}

// Remember SAT power state, transmit code accordingly (SAT has no seperate on/off codes)
void sat_power(bool state){
  irsend.SENDSAT(SATPWR);
  /*
  if (state){  
    if (saton) return; // already on
    irsend.SENDSAT(SATPWR);
    saton=true;
  }else{
    if (!saton) return; // already off
    irsend.SENDSAT(SATPWR);
    saton=false;
  }
  */
}

void evaluateIRCode(){
    if (results.decode_type == RC5){
        altbit=results.value & 0x800;
        cmd11bit=results.value & 0x3FF;
        #ifndef NOSERIAL
        Serial.print("Altbit, altbitstripped code:");
        Serial.print(altbit);
        Serial.print(", 0x");          
        Serial.println(cmd11bit, HEX);
        #endif
        switch(cmd11bit){
          case IPOWER:
              Serial.println("IPOWER: Turning off TV, SAT and AVR");
              sat_power(false); // SAT off
              delay(TDELAY);       
              irsend.SENDAVR(AVRPWROFF); // avr off
              delay(TDELAY);        
//              Data=0x98;
              Samsung_SendCommand(TVKEY_POWEROFF); // TV off
              oMode=MODOFF;
              break;
          case IN0:
              Serial.println("IN0: SAT");
              if (MODSAT) irsend.SENDSAT(SATN0);
              break;
          case IN1:
              Serial.println("IN1: -");
              switch(oMode){
                case MODTV:
                   Samsung_SendCommand(TVKEY_TOOLS);
                   break;
                case MODSAT:
                   irsend.SENDSAT(SATN1);
              }
              break;
          case IN2:
              Serial.println("IN2: -");
              switch(oMode){
                case MODATV:
                   irsend.SENDNP(NPUP);
                   break;
                case MODTV:
                   Samsung_SendCommand(TVKEY_UP);
                   break;
                case MODSAT:
                   irsend.SENDSAT(SATN2);
              }
              break;
          case IN3:
              Serial.println("IN3: -");
              if (MODSAT) irsend.SENDSAT(SATN3);
              break;
          case IN4:
              Serial.println("IN4: -");
              switch(oMode){
                case MODTV:
                   Samsung_SendCommand(TVKEY_LEFT);
                   break;
                case MODATV:
                   irsend.SENDNP(NPL);
                   break;
                case MODSAT:
                   irsend.SENDSAT(SATN4);
              }          
              break;
          case IN5:
              Serial.println("IN5: -");
              switch(oMode){
                case MODTV:
                   Samsung_SendCommand(TVKEY_ENTER);
                   break;                
                case MODATV:
                   irsend.SENDNP(NPOK);
                   break;
                case MODSAT:
                   irsend.SENDSAT(SATN5);
              }       
              break;
          case IN6:
              Serial.println("IN6: -"); 
              switch(oMode){
                case MODTV:
                   Samsung_SendCommand(TVKEY_RIGHT);
                   break;                
                case MODATV:
                   irsend.SENDNP(NPR);
                   break;
                case MODSAT:
                   irsend.SENDSAT(SATN6);
              }               
              break;
          case IN7:
              Serial.println("IN7: -");
              switch(oMode){
                case MODTV:
                   Samsung_SendCommand(TVKEY_RETURN);
                   break;
                case MODATV:
                   irsend.SENDNP(NPMENU);
                   break;
                case MODSAT:
                   irsend.SENDSAT(SATN7);
              } 
              break;
          case IN8:
              Serial.println("IN8: -");
              switch(oMode){
                case MODTV:
                   Samsung_SendCommand(TVKEY_DOWN);
                   break;                
                case MODATV:
                   irsend.SENDNP(NPD);
                   break;
                case MODSAT:
                   irsend.SENDSAT(SATN5);
              } 
              break;
          case IN9:
              Serial.println("IN9: -");
              switch(oMode){
                case MODTV:
                   Samsung_SendCommand(TVKEY_EXIT);
                   break;                
                case MODATV:
                   irsend.SENDNP(NPPLAY);
                   break;
                case MODSAT:
                   irsend.SENDSAT(SATN9);
              }           
              break;
          case IMUTE:
              Serial.println("IMUTE: Muting AVR");
              irsend.SENDAVR(AVRMUTE);
              break;
          case ICHU:
              Serial.print("ICHU: Mode: ");
              Serial.println(oMode);
              switch(oMode){
                case MODTV:
                   Samsung_SendCommand(TVKEY_UP);
                   break;                
                case MODATV:
                   irsend.SENDNP(NPUP);
                   break;
                case MODSAT:
                   irsend.SENDSAT(SATCHUP);
              }               
              break;
          case ICHD:
              Serial.print("ICHD: Mode: ");
              Serial.println(oMode);
              switch(oMode){
                case MODTV:
                   Samsung_SendCommand(TVKEY_DOWN);
                   break;                
                case MODATV:
                   irsend.SENDNP(NPD);
                   break;
                case MODSAT:
                   irsend.SENDSAT(SATCHD);
              }               
              break;
          case IVOLU:
              Serial.println("IVOLU: Sending Vol UP to AVR");
              irsend.SENDAVR(AVRVOLUP);          
              break;
          case IVOLD:
              Serial.println("IVOLD: Sending Vol DOWN to AVR");
              irsend.SENDAVR(AVRVOLD);
              break;
          case IAV:
              Serial.println("IAV: Switching to AUX");
              Samsung_SendCommand(TVKEY_POWERON);
              delay(TDELAY);        
              Samsung_SendCommand(TVKEY_HDMI);
              delay(TDELAY); 
              if (oMode == MODSAT) sat_power(false); // sat off              
              delay(TDELAY);        
              irsend.SENDAVR(AVRAUX); // switch to aux              
              oMode=MODAUX;
              break;
          case ITV:
              Serial.println("TV: switching to TV");         
              Samsung_SendCommand(TVKEY_POWERON);
              delay(TDELAY);
              irsend.SENDAVR(AVRTV); // avr to tv
              delay(TDELAY);              
              if (oMode == MODSAT) sat_power(false); // sat off
              delay(TDELAY);     
              Samsung_SendCommand(TVKEY_SOURCE);              
              oMode=MODTV;
              break;
          case ISMD:
              break;
          case IRLR:
              Serial.print("RLR: SAT is now: ");
              saton=!saton;               
              Serial.print(saton);              
              break;
          case ITTX0:
              break;
          case ITTX1:
              break;
          case ITTX2:
              break;              
          case ITTX4:
              break;
          case ITTX5:
              break;
          case ITTX6:
              break;
          case ITTX7:
              break;
          case IPP:
              break;
          case Iinfo:
              break;
              
        }
    }else{ // PROTOCOL XXX
        if(results.value == IXXXRED0 || results.value == IXXXRED1){ // ttx red : switch to sat
            Serial.println("IXXXRED: Switch to SAT");
            Samsung_SendCommand(TVKEY_POWERON);
            delay(TDELAY);
            sat_power(true); // sat on
            delay(TDELAY);
            irsend.SENDAVR(AVRPWRON); // avr on   
            delay(TDELAY);        
            irsend.SENDAVR(AVRCSAT); // avr to sat
            delay(TDELAY);
            sat_power(true);
            delay(TDELAY);
            Samsung_SendCommand(TVKEY_HDMI);
            oMode=MODSAT;
            
        } else if(results.value == IXXXGREEN0 || results.value == IXXXGREEN1){ // ttx green: switch to Apple TV
            Serial.println("IXXXGREEN: Switch to Apple TV");
            Samsung_SendCommand(TVKEY_POWERON);
            delay(TDELAY);
            irsend.SENDAVR(AVRSTB); // avr to STB
            delay(TDELAY);        
            if (oMode == MODSAT) sat_power(false);//irsend.SENDSAT(0x38C); // sat off
            delay(TDELAY);                                
            Samsung_SendCommand(TVKEY_HDMI);
            delay(TDELAY);
            irsend.SENDNP(NPMENU); // poke Apple TV            
            oMode=MODATV;
            
        } else if(results.value == IXXXYELLOW0 || results.value == IXXXYELLOW1){ // ttx yellow 
            Serial.println("IXXXYELLOW: Switch to PS3");  
            Samsung_SendCommand(TVKEY_POWERON);
            delay(TDELAY);
            irsend.SENDAVR(AVRGAME); // avr to game
            delay(TDELAY);        
            if (oMode == MODSAT) sat_power(false); // sat off
            delay(TDELAY);     
            Samsung_SendCommand(TVKEY_HDMI);
            oMode=MODPS3;            
            
        } else if(results.value == IXXXBLUE0 || results.value == IXXXBLUE1){ // ttx blue 
            Serial.println("IXXXBLUE: Wii");  
            Samsung_SendCommand(TVKEY_POWERON);
            delay(TDELAY);            
            irsend.SENDAVR(AVRTV); // avr to tv
            delay(TDELAY);  
            if (oMode == MODSAT) sat_power(false);// sat off
            delay(TDELAY);                                
            Samsung_SendCommand(TVKEY_COMPONENT1);
            oMode=MODWII;            
        } else if(results.value == IXXXMENU0 || results.value == IXXXMENU1){ // menu button 
            Serial.println("IXXXMENU: Menu");  
            switch(oMode){
              case MODTV:
                 Samsung_SendCommand(TVKEY_MENU);
                 break;                
              case MODATV:
                 irsend.SENDNP(NPOK);
                 break;
              case MODSAT:
                 irsend.SENDSAT(SATOK);
            }           
        }
    }
  
}

void loop()
{
    //Serial.println("asd");
    //delay(500);
    if (irrecv.decode(&results)) {
        digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
        #ifndef NOSERIAL
        if (results.decode_type == RC5) Serial.print("@@@ Protocol: RC5; Bits: ");
        else Serial.print("@@@ Protocol: Other; Bits: ");
        Serial.print(results.bits);
        Serial.print("; Code: 0x");
        Serial.println(results.value, HEX);
        #endif
        evaluateIRCode();  
        
        // prepare to receive the next command
        digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW  
        delay(TDELAY);  
        irrecv.enableIRIn();
    }
}
/*
        
      }   
      }else if(results.value == 0x80C || results.value == 0xC){ // key power: all off
        sat_power(false);//irsend.SENDSAT(0x38C); // digiturk off
        delay(200);       
        irsend.SENDAVR(AVRPWROFF); // avr off
        delay(200);        
        Data=0x98;
        Samsung::SendCommand(Type, Device, Data, ~Data);  // TV off
        
      } else if(results.value == IRC5MUTE0 || results.value == IRC5MUTE1){
        Serial.println("btn mute: Muting AVR");
        irsend.SENDAVR(AVRMUTE);
      } else if(results.value == 0x804 || results.value == 0x4){
        Serial.println("sending on to AVR");
        irsend.SENDAVR(AVRPWRON);
      } else if(results.value == 0x80C || results.value == 0xC){
        Serial.println("sending off to AVR");
        irsend.SENDAVR(AVRPWROFF);
      }else if(results.value == 0x810 || results.value == 0x10){ // vol u
        Serial.println("vol+: sending vol u to AVR");
        irsend.SENDAVR(AVRVOLUP);
      }else if(results.value == 0x811 || results.value == 0x11){ // vol d
        Serial.println("sending vol d to AVR");
        irsend.SENDAVR(AVRVOLD);
      }else if(results.value == 0x820 || results.value == 0x20){ // ch+
        Serial.println("sending ch+ to SAT");
        irsend.SENDSAT(SATCHUP);
      }else if(results.value == 0x821 || results.value == 0x21){ // ch-
        Serial.println("sending ch- to SAT");
        irsend.SENDSAT(SATCHD);
      }else if(results.value == IRC5N70 || results.value == IRC5N71){ // tv on
         Serial.println("sending on to TV");
         Data=TVKEY_POWERON;
         Samsung::SendCommand(Type, Device, Data, ~Data);  // TV on
      }else if(results.value == IRC5TV0 || results.value == IRC5TV1){ // tv button
            Serial.println("TV button: switching to TV");
            Data=TVKEY_POWERON;
            Samsung::SendCommand(Type, Device, Data, ~Data);  // TV on            
            delay(100);
            irsend.SENDAVR(AVRTV);//(0x10E8D72,32); // avr to tv
            delay(100);        
            sat_power(false);//irsend.SENDSAT(0x38C); // sat off
            delay(100);  
            //Data=TVKEY_SOURCE;
            //Samsung::SendCommand(Type, Device, Data, ~Data); 
      }else if(results.value == IRC5i0 || results.value == IRC5i1){ // info button
            Serial.println("info button");
            altbit=!altbit;
            irsend.SENDSAT(SATINFO);
      }

    // 32 bit commands      
    }else{ 
        if(results.value == IXXXRED0 || results.value == IXXXRED1){ // ttx red : switch to sat
            Serial.println("red button");  
            Data=TVKEY_POWERON;
            Samsung::SendCommand(Type, Device, Data, ~Data);  // TV on            
            delay(200);
            sat_power(true);//irsend.SENDSAT(0xB8C);// sat on
            delay(200);
            irsend.SENDAVR(AVRPWRON); // avr on   
            delay(200);        
            irsend.SENDAVR(AVRCSAT); // avr to sat
            delay(200);
            sat_power(true);
            delay(200);
            Data=TVKEY_HDMI;
            Samsung::SendCommand(Type, Device, Data, ~Data); // TV to HDMI
            
        } else if(results.value == IXXXGREEN0 || results.value == IXXXGREEN1){ // ttx green: switch to Apple TV
            Serial.println("green button: Apple TV");
            Data=TVKEY_POWERON;
            Samsung::SendCommand(Type, Device, Data, ~Data);  // TV on            
            delay(100);
            irsend.SENDAVR(AVRSTB); // avr to STB
            delay(100);        
            sat_power(false);//irsend.SENDSAT(0x38C); // sat off
            delay(100);                                
            Data=TVKEY_HDMI;
            Samsung::SendCommand(Type, Device, Data, ~Data); // TV to HDMI
            
        } else if(results.value == IXXXYELLOW0 || results.value == IXXXYELLOW1){ // ttx yellow 
            Serial.println("yellow button: PS3");  
            Data=TVKEY_POWERON;
            Samsung::SendCommand(Type, Device, Data, ~Data);  // TV on            
            delay(100);
            irsend.SENDAVR(AVRGAME); // avr to game
            delay(100);        
            sat_power(false);//irsend.SENDSAT(0x38C); // sat off
            delay(100);     
            Data=TVKEY_HDMI;
            Samsung::SendCommand(Type, Device, Data, ~Data); // TV to HDMI
            
        } else if(results.value == IXXXBLUE0 || results.value == IXXXBLUE1){ // ttx blue 
            Serial.println("blue button: Wii");  
            Data=TVKEY_POWERON;
            Samsung::SendCommand(Type, Device, Data, ~Data);  // TV on
            delay(100);            
            irsend.SENDAVR(AVRTV);//(0x10E8D72,32); // avr to tv
            delay(100);  
            sat_power(false);//irsend.SENDSAT(0x38C); // sat off
            delay(100);                                
            Data=TVKEY_COMPONENT1;
            Samsung::SendCommand(Type, Device, Data, ~Data);  // TV to component
        }
    } // green  
      // yellow
      // blue

    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW  
    delay(100);  
    irrecv.enableIRIn();
  } 
}
*/
/*

  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    // do nothing:
    while(true);
  }

*/
