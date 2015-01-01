#ifndef ir_hex_AVR_HK_151_h
#define ir_hex_AVR_HK_151_h
// IR Codes
#include <SPI.h>
#define SENDAVR(a) sendNEC(a,32);

// Input Remote Codes

#define ALTBIT true
#define IPROTOCOL NEC
#define IBITS 32 // !!
#define AVRREPEAT 0xFFFFFFFF

#define AVRMUTE   0x10E837C
#define AVRPWRON  0x10E03FC
#define AVRPWROFF 0x10EF906

#define AVRCSAT   0x10E0DF2
#define AVRSTB    0x10ECB34
#define AVRTV     0x10E8D72
#define AVRDSC    0x10E0BF4

#define AVRSRV    0x10ECD32
#define AVRAUX    0x10EB34C
#define AVRAUD    0x10E2DD2
#define AVRGAME   0x10E4DB2
#define AVRAVR    0x10E03FC
#define AVRUSB    0x10EAF50
#define AVRNW     0x10EAD52
#define AVRRAD    0x10E817E

#define AVRVOLUP  0x10EE31C
#define AVRVOLD   0x10E13EC

#define AVRU      0x414E9966
#define AVRD      0x414E59A6
#define AVRL      0x414E837C
#define AVRR      0x414E43BC
#define AVROK     0x414E21DE

#define AVRSURRM  0x414E15EA
#define AVRBACKE  0x10EED12
#define AVRINFO   0x10E1DE2
#define AVROSD    0x414E3AC5

#define AVRNEXT   0x212E6A95
#define AVRPREV   0x212EAA55
#define AVRFF     0x212EDB24
#define AVRRR     0x212E5BA4
#define AVRSTOP   0x212E57A8
#define AVRPLAYP  0x212E7B84

#define AVR0      0x10E7986
#define AVR1      0x10EE11E
#define AVR2      0x10E11EE
#define AVR3      0x10E916E
#define AVR4      0x10E51AE
#define AVR5      0x10ED12E
#define AVR6      0x10E31CE
#define AVR7      0x10EB14E
#define AVR8      0x10E718E
#define AVR9      0x10EB946

#endif

