#ifndef ir_hex_NP_AppleTV_h
#define ir_hex_NP_AppleTV_h
// IR Codes

// Input Remote Codes

//#define ALTBIT true
#define IPROTOCOL NEC
#define IBITS 42
//#define SENDSAT(a) sendRC5(a,12)
#define SENDNP(a) sendNEC(a, 32)

// Codes
// from: http://random-stuff-of-chris.blogspot.com.tr/2013/07/apple-tv-and-f-tv-remote-control-with.html
#define NPUP     0x77E15057
#define NPD      0x77E13057
#define NPL      0x77E19057
#define NPR      0x77E16057
#define NPMENU   0x77E1C057
#define NPOK     0x77E13A57
#define NPPLAY   0x77E1FA57


#endif
