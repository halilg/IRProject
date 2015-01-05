#ifndef ir_hex_SAT_Digiturk_h
#define ir_hex_SAT_Digiturk_h
// IR Codes

// Input Remote Codes

#define ALTBIT true
#define IPROTOCOL RC5
#define IBITS 12 // !!
//#define SENDSAT(a) sendRC5(a,12)
#define SENDSAT(a) sendRC5(altCode(a),12)

// bit alternator for 12 bit code
bool altbit=false;
int altCode(int code){
  return code | (altbit*0x800);
}

// Protocol and #bits

//0000 0000 0011 1000 1100
#define SATPWR     0x38C
//0000 0000 1011 1000 1100
//#define SATOFF     0x38C

// 0011 1011 1010
// 1011 1011 1010  
#define SATIQ     0x3BA 
// 0011 1011 1000                        
#define SATMOD    0x3B8
#define SATFAV    0x38E
#define SATGUIDE  0x395
#define SATMENU   0x3AA
//0000 0000 0011 1010 1100
#define SATINFO   0x3AC
#define SATVOLUP  0x3B1
#define SATVOLD   0x3B2
#define SATOK     0x391
#define SATCHUP   0x392
#define SATCHD    0x3AE
#define SATPLUS   0x38A
#define SATNEXT   0x3AF
#define SATPREV   0x396
#define SATEXIT   0x3AB
#define SATPP     0x390
#define SATPLAY   0x3B5
#define SATRED    0x38D
#define SATGREEN  0x3A0
#define SATYELLOW 0x3B9
#define SATBLUE   0x3B4
#define SATN0      0x380
#define SATN1      0x388
#define SATN2      0x382
#define SATN3      0x383
#define SATN4      0x384
#define SATN5      0x385
#define SATN6      0x386
#define SATN7      0x387
#define SATN8      0x381
#define SATN9      0x389

#define SATREVB 0x8A3BC1B3
#define SATREVB 0x21DEEF28
#define SATREVF 0xD0305131
#define SATREVF 0xD0305131

// 1101 0101 1101 0100 1110 1011 0110 0001
#define SATVOD0 0xD5D4EB61

// 0101 1101 1000 0001 0010 1000 1111 1010
#define SATVOD1 0x5D8128FA 

#endif
