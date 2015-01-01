#ifndef samsung_h
#define samsung_h

// ---------------------------------------------------------------------
 // Samsung IR class
 // ---------------------------------------------------------------------
#define IRPIN      3    // IR led is connected on pin 8

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
 
 
#endif
