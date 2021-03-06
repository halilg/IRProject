#ifndef ir_hex_TV_Samsung_UE40ES7000_h
#define ir_hex_TV_Samsung_UE40ES7000_h
// IR Codes

#define Samsung_SendCommand(a) Samsung::SendCommand(Type, Device, a, ~a)

// Input Remote Codes

#define ALTBIT false
#define IPROTOCOL Samsung
#define IBITS 32

#define TVKEY_SOURCE      0x01
#define TVKEY_MENU	  0x1A
#define TVKEY_TOOLS	  0x4B
#define TVKEY_UP	  0x60
#define TVKEY_DOWN	  0x61
#define TVKEY_RIGHT	  0x62
#define TVKEY_LEFT	  0x65
#define TVKEY_ENTER	  0x68
#define TVKEY_RETURN	  0x58
#define TVKEY_COMPONENT1  0x86
#define TVKEY_HDMI	  0x8B
#define TVKEY_POWEROFF	  0x98
#define TVKEY_POWERON	  0x99
#define TVKEY_EXIT	  0x2D

//02: on+off
//03: kapanis
//07:?
// 0b:? 0f 28 2b 6e
// 1b: TV
// 58: return
// 37: guncelle?
// 3f: destek
// 45: pgup
// 48: pgdn
// 4b: tools
// 60: up
// 61: down
// 62: R
// 65: L	
// 68: OK
// 6C: A button red
// 73: search
// 76: tv/sat
// 79: smart hub
// 7a: VIDEO
// 7b: kablo
// 7e: DVD
// 7f: stb
// 86: component
// 8b: hdmi1
// 8c: smart h
// 8d:
// 93? sleep
// ?
// 9f: 3d

/*
#define TVKEY_MTS	0x68 //?
#define TVKEY_SLEEP	0x61 //?
#define TVKEY_1	0x65
#define TVKEY_2	0x62
#define TVKEY_3	0x6
#define TVKEY_VOLUP	0x7
#define TVKEY_4	0x8
#define TVKEY_5	0x9
#define TVKEY_6	0x0A
#define TVKEY_VOLDOWN	0x0B
#define TVKEY_7	0x0C
#define TVKEY_8	0x0D
#define TVKEY_9	0x0E
#define TVKEY_MUTE	0x0F
#define TVKEY_CHDOWN	0x10
#define TVKEY_0	0x11
#define TVKEY_CHUP	0x12
#define TVKEY_PRECH	0x13
#define TVKEY_GREEN	0x14
#define TVKEY_YELLOW	0x15
#define TVKEY_CYAN	0x16
#define TVKEY_VAL_23	0x17
#define TVKEY_VAL_24	0x18
#define TVKEY_ADDDEL	0x19

#define TVKEY_TV	0x1B
#define TVKEY_VAL_28	0x1C
#define TVKEY_VAL_29	0x1D
#define TVKEY_VAL_30	0xFD
#define TVKEY_INFO	0x1F
#define TVKEY_PIP_ONOFF	0x20
#define TVKEY_PIP_SWAP	0x21
#define TVKEY_VAL_34	0x22
#define TVKEY_PLUS100 (acts as "-")	0x23
#define TVKEY_VAL_36	0x24
#define TVKEY_CAPTION	0x25
#define TVKEY_VAL_38	0x26
#define TVKEY_AD	0x27
#define TVKEY_PMODE	0x28
#define TVKEY_VAL_41	0x29
#define TVKEY_VAL_42	0x2A
#define TVKEY_VAL_43	0x2B
#define TVKEY_TTX_MIX	0x2C
#define TVKEY_VAL_43	0x2E
#define TVKEY_PIP_SIZE	0x2F
#define TVKEY_MAGIC_CHANNEL	0x30
#define TVKEY_PIP_SCAN	0x31
#define TVKEY_PIP_CHUP	0x32
#define TVKEY_PIP_CHDOWN	0x33
#define TVKEY_DEVICE_CONNECT	0x34
#define TVKEY_HELP	0x35
#define TVKEY_ANTENA	0x36
#define TVKEY_CONVERGENCE	0x37
#define TVKEY_11	0x38
#define TVKEY_12	0x39
#define TVKEY_AUTO_PROGRAM	0x3A
#define TVKEY_FACTORY	0x3B
#define TVKEY_3SPEED	0x3C
#define TVKEY_RSURF	0x3D
#define TVKEY_ASPECT	0x3E
#define TVKEY_TOPMENU	0x3F
#define TVKEY_GAME	0x40
#define TVKEY_QUICK_REPLAY	0x41
#define TVKEY_STILL_PICTURE	0x42
#define TVKEY_DTV	0x43
#define TVKEY_FAVCH	0x44
#define TVKEY_REWIND	0x45
#define TVKEY_STOP	0x46
#define TVKEY_PLAY	0x47
#define TVKEY_FF	0x48
#define TVKEY_REC	0x49
#define TVKEY_PAUSE	0x4A
#define TVKEY_INSTANT_REPLAY	0x4C
#define TVKEY_LINK	0x4D
#define TVKEY_FF_	0x4E
#define TVKEY_GUIDE	0x4F
#define TVKEY_REWIND_	0x50
#define TVKEY_ANGLE	0x51
#define TVKEY_RESERVED1	0x52
#define TVKEY_ZOOM1	0x53
#define TVKEY_PROGRAM	0x54
#define TVKEY_BOOKMARK	0x55
#define TVKEY_DISC_MENU	0x56
#define TVKEY_PRINT	0x57
#define TVKEY_SUB_TITLE	0x59
#define TVKEY_CLEAR	0x5A
#define TVKEY_VCHIP	0x5B
#define TVKEY_REPEAT	0x5C
#define TVKEY_DOOR	0x5D
#define TVKEY_OPEN	0x5E
#define TVKEY_WHEEL_LEFT	0x5F
#define TVKEY_DMA	0x63
#define TVKEY_TURBO	0xEF
#define TVKEY_FM_RADIO	0x66
#define TVKEY_DVR_MENU	0x67
//#define TVKEY_ENTER	0x0
#define TVKEY_PCMODE	0x69
#define TVKEY_TTX_SUBFACE	0x6A
#define TVKEY_CH_LIST	0x6B
#define TVKEY_RED	0x6C
#define TVKEY_DNIe	0x6D
#define TVKEY_SRS	0x6E
#define TVKEY_CONVERT_AUDIO_MAINSUB	0x6F
#define TVKEY_MDC	0x70
#define TVKEY_SEFFECT	0x71
#define TVKEY_DVR	0x72
#define TVKEY_DTV_SIGNAL	0xF0
#define TVKEY_LIVE	0x74
#define TVKEY_PERPECT_FOCUS	0x75
#define TVKEY_HOME	0x76
#define TVKEY_ESAVING	0x77
#define TVKEY_WHEEL_RIGHT	0x78
#define TVKEY_CONTENTS	0x79
#define TVKEY_VCR_MODE	0x7A
#define TVKEY_CATV_MODE	0x7B
#define TVKEY_DSS_MODE	0x7C
#define TVKEY_TV_MODE	0x7D
#define TVKEY_DVD_MODE	0x7E
#define TVKEY_STB_MODE	0x7F
#define TVKEY_CALLER_ID	0x80
#define TVKEY_SCALE	0x81
#define TVKEY_ZOOM_MOVE	0x82
#define TVKEY_CLOCK_DISPLAY	0x83
#define TVKEY_AV1	0x84
#define TVKEY_SVIDEO1	0x85
#define TVKEY_SETUP_CLOCK_TIMER	0x87
#define TVKEY_COMPONENT2	0x88
#define TVKEY_MAGIC_BRIGHT	0x89
#define TVKEY_DVI	0x8A
#define TVKEY_W_LINK	0x8C
#define TVKEY_DTV_LINK	0x8D
#define TVKEY_VAL_142	0x8E
#define TVKEY_APP_LIST	0x8F
#define TVKEY_BACK_MHP	0x90
#define TVKEY_ALT_MHP	0x91
#define TVKEY_DNSe	0x92
#define TVKEY_RSS	0x93
#define TVKEY_ENTERTAINMENT	0x94
#define TVKEY_ID_INPUT	0x95
#define TVKEY_ID_SETUP	0x96
#define TVKEY_ANYNET	0x97
#define TVKEY_ANYVIEW	0x9A
#define TVKEY_MS	0x9B
#define TVKEY_MORE	0x9C
#define TVKEY_PANNEL_POWER	0xB1
#define TVKEY_PANNEL_CHUP	0xB2
#define TVKEY_PANNEL_CHDOWN	0xB3
#define TVKEY_PANNEL_VOLUP	0xFB
#define TVKEY_PANNEL_VOLDOW	0x107
#define TVKEY_PANNEL_ENTER	0x108
#define TVKEY_PANEL_MENU	0x109


// #define TVKEY_PANNEL_SOURCE	0x103 //kapanis ayari
#define TVKEY_AV2	0x105
#define TVKEY_AV3	0x106
#define TVKEY_SVIDEO2	0x10A
#define TVKEY_SVIDEO3	0xFFFF
#define TVKEY_ZOOM2	0xFFFF
#define TVKEY_PANORAMA	0xFFFF
#define TVKEY_4_3	0xFFFF
#define TVKEY_16_9	0xFFFF
#define TVKEY_DYNAMIC	0xFFFF
#define TVKEY_STANDARD	0xFFFF
#define TVKEY_MOVIE1	0xFFFF
#define TVKEY_CUSTOM	0xF2
#define TVKEY_AUTO_ARC_RESET	0xF3
#define TVKEY_AUTO_ARC_LNA_ON	0xFFFF
#define TVKEY_AUTO_ARC_LNA_OFF	0xFFFF
#define TVKEY_AUTO_ARC_ANYNET_MODE_OK	0xFFFF
#define TVKEY_AUTO_ARC_ANYNET_AUTO_START	0xFFFF
#define TVKEY_AUTO_FORMAT	0xFFFF
#define TVKEY_DNET	0xFFFF
#define TVKEY_HDMI1	0xFFFF
#define TVKEY_AUTO_ARC_CAPTION_ON	0xFFFF
#define TVKEY_AUTO_ARC_CAPTION_OFF	0xFFFF
#define TVKEY_AUTO_ARC_PIP_DOUBLE	0xFFFF
#define TVKEY_AUTO_ARC_PIP_LARGE	0xB0
#define TVKEY_AUTO_ARC_PIP_SMALL	0xAD
#define TVKEY_AUTO_ARC_PIP_WIDE	0xD0
#define TVKEY_AUTO_ARC_PIP_LEFT_TOP	0xFFFF
#define TVKEY_AUTO_ARC_PIP_RIGHT_TOP	0x104
#define TVKEY_AUTO_ARC_PIP_LEFT_BOTTOM	0xFFFF
#define TVKEY_AUTO_ARC_PIP_RIGHT_BOTTOM	0xD1
#define TVKEY_AUTO_ARC_PIP_CH_CHANGE	0xFFFF
#define TVKEY_AUTO_ARC_AUTOCOLOR_SUCCESS	0xFFFF
#define TVKEY_AUTO_ARC_AUTOCOLOR_FAIL	0xD5
#define TVKEY_AUTO_ARC_C_FORCE_AGING	0xFC
#define TVKEY_AUTO_ARC_USBJACK_INSPECT	0xFD
#define TVKEY_AUTO_ARC_JACK_IDENT	0xFF
#define TVKEY_NINE_SEPERATE	0x100
#define TVKEY_ZOOM_IN	0x101
#define TVKEY_ZOOM_OUT	0xFFFF
#define TVKEY_MIC	0x102
#define TVKEY_HDMI2	0xFFFF
#define TVKEY_HDMI3	0xFFFF
#define TVKEY_AUTO_ARC_CAPTION_KOR	0xFFFF
#define TVKEY_AUTO_ARC_CAPTION_ENG	0xF6
#define TVKEY_AUTO_ARC_PIP_SOURCE_CHANGE	0xFA
#define TVKEY_HDMI4	0xF7
#define TVKEY_AUTO_ARC_ANTENNA_AIR	0xF8
#define TVKEY_AUTO_ARC_ANTENNA_CABLE	0xF9
#define TVKEY_AUTO_ARC_ANTENNA_SATELLITE	0xFE
#define TVKEY_EXT1	0x10B
#define TVKEY_EXT2	0x10B
#define TVKEY_EXT3	0x10B
#define TVKEY_EXT4	0x10B
#define TVKEY_EXT5	0x10B
#define TVKEY_EXT6	0x10B
#define TVKEY_EXT7	0x10B
#define TVKEY_EXT8	0x10B
#define TVKEY_EXT9	0xAF
#define TVKEY_EXT10	0xAE
#define TVKEY_EXT11	0x10B
#define TVKEY_EXT12	0xA9
#define TVKEY_EXT13	0xAA
#define TVKEY_EXT14	0xAB
#define TVKEY_EXT15	0xAC
#define TVKEY_EXT16	0xB9
#define TVKEY_EXT17	0x10B
#define TVKEY_EXT18	0x10B
#define TVKEY_EXT19	0x10B
#define TVKEY_EXT20	0xBB
#define TVKEY_EXT21	0x10B
#define TVKEY_EXT22	0xA5
#define TVKEY_EXT23	0xA6
#define TVKEY_EXT24	0xA7
#define TVKEY_EXT25	0x10B
#define TVKEY_EXT26	0x10B
#define TVKEY_EXT27	0x10B
#define TVKEY_EXT28	0x10B
#define TVKEY_EXT29	0x10B
#define TVKEY_EXT30	0x10B
#define TVKEY_EXT31	0x10B
#define TVKEY_EXT32	0x10B
#define TVKEY_EXT33	0x10B
#define TVKEY_EXT34	0x10B
#define TVKEY_EXT35	0x10B
#define TVKEY_EXT36	0x10B
#define TVKEY_EXT37	0x10B
#define TVKEY_EXT38	0xA8
#define TVKEY_EXT39	0x10B
#define TVKEY_EXT40	0x10B
#define TVKEY_EXT41	0x10B
*/
#endif
