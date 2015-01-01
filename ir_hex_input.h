#ifndef ir_hex_input_h
#define ir_hex_input_h

// IR Codes for my generic remote

// Protocol specific definitions
#define IBITS 12
#define IALTBIT 12

// Button codes
#define IPOWER 0xC
#define IN0 0x0
#define IN1 0x1
#define IN2 0x2
#define IN3 0x3
#define IN4 0x4
#define IN5 0x5
#define IN6 0x6
#define IN7 0x7
#define IN8 0x8
#define IN9 0x9     
#define IMUTE 0xD   
#define ICHU 0x20
#define ICHD  0x21
#define IVOLU 0x10
#define IVOLD 0x11
#define IAV 0x38 
#define ITV 0x3F
#define ISMD 0x23  
#define IRLR 0x22
#define ITTX0 0x3C
#define ITTX1 0x2E
#define ITTX2 0x2A
#define ITTX4 0x29
#define ITTX5 0x2B
#define ITTX6 0x2D
#define ITTX7 0x82C
#define IPP 0x80E
#define Iinfo 0xF

//000 0000 1011 1111 1011 1000 1111 0010 1111 1110
#define IXXXMENU0 0xBFB8F2FE 
//000 0000 1101 1001 1111 1001 0111 000 0000 1011
#define IXXXMENU1 0xD9F9700B 
#define IXXXTTX30 0xC460AC26
#define IXXXTTX31 0xC460AC26 //!!
#define IXXX16_90 0xAD8C62D2
#define IXXX16_91 0xF280BC5B
#define IXXXRED0 0x1C102884
#define IXXXRED1 0x4B995E59
#define IXXXGREEN0 0xE050BDE6
#define IXXXGREEN1 0xEF4EDF53
#define IXXXYELLOW0 0xDF50BC53
#define IXXXYELLOW1 0xF04EE0E6
#define IXXXBLUE0 0x8533B77
#define IXXXBLUE1 0x5F564B6A

#endif
