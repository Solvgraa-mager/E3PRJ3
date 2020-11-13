// VR address and mask defines
#pragma	ioport	VR_Data_ADDR:	0x0
BYTE			VR_Data_ADDR;
#pragma	ioport	VR_DriveMode_0_ADDR:	0x100
BYTE			VR_DriveMode_0_ADDR;
#pragma	ioport	VR_DriveMode_1_ADDR:	0x101
BYTE			VR_DriveMode_1_ADDR;
#pragma	ioport	VR_DriveMode_2_ADDR:	0x3
BYTE			VR_DriveMode_2_ADDR;
#pragma	ioport	VR_GlobalSelect_ADDR:	0x2
BYTE			VR_GlobalSelect_ADDR;
#pragma	ioport	VR_IntCtrl_0_ADDR:	0x102
BYTE			VR_IntCtrl_0_ADDR;
#pragma	ioport	VR_IntCtrl_1_ADDR:	0x103
BYTE			VR_IntCtrl_1_ADDR;
#pragma	ioport	VR_IntEn_ADDR:	0x1
BYTE			VR_IntEn_ADDR;
#define VR_MASK 0x2
// RX address and mask defines
#pragma	ioport	RX_Data_ADDR:	0x4
BYTE			RX_Data_ADDR;
#pragma	ioport	RX_DriveMode_0_ADDR:	0x104
BYTE			RX_DriveMode_0_ADDR;
#pragma	ioport	RX_DriveMode_1_ADDR:	0x105
BYTE			RX_DriveMode_1_ADDR;
#pragma	ioport	RX_DriveMode_2_ADDR:	0x7
BYTE			RX_DriveMode_2_ADDR;
#pragma	ioport	RX_GlobalSelect_ADDR:	0x6
BYTE			RX_GlobalSelect_ADDR;
#pragma	ioport	RX_IntCtrl_0_ADDR:	0x106
BYTE			RX_IntCtrl_0_ADDR;
#pragma	ioport	RX_IntCtrl_1_ADDR:	0x107
BYTE			RX_IntCtrl_1_ADDR;
#pragma	ioport	RX_IntEn_ADDR:	0x5
BYTE			RX_IntEn_ADDR;
#define RX_MASK 0x40
// LCD_1D4 address and mask defines
#pragma	ioport	LCD_1D4_Data_ADDR:	0x8
BYTE			LCD_1D4_Data_ADDR;
#pragma	ioport	LCD_1D4_DriveMode_0_ADDR:	0x108
BYTE			LCD_1D4_DriveMode_0_ADDR;
#pragma	ioport	LCD_1D4_DriveMode_1_ADDR:	0x109
BYTE			LCD_1D4_DriveMode_1_ADDR;
#pragma	ioport	LCD_1D4_DriveMode_2_ADDR:	0xb
BYTE			LCD_1D4_DriveMode_2_ADDR;
#pragma	ioport	LCD_1D4_GlobalSelect_ADDR:	0xa
BYTE			LCD_1D4_GlobalSelect_ADDR;
#pragma	ioport	LCD_1D4_IntCtrl_0_ADDR:	0x10a
BYTE			LCD_1D4_IntCtrl_0_ADDR;
#pragma	ioport	LCD_1D4_IntCtrl_1_ADDR:	0x10b
BYTE			LCD_1D4_IntCtrl_1_ADDR;
#pragma	ioport	LCD_1D4_IntEn_ADDR:	0x9
BYTE			LCD_1D4_IntEn_ADDR;
#define LCD_1D4_MASK 0x1
// LCD_1D4 Shadow defines
//   LCD_1D4_DataShadow define
extern BYTE Port_2_Data_SHADE;
#define LCD_1D4_DataShadow (*(unsigned char*)&Port_2_Data_SHADE)
//   LCD_1D4_DriveMode_0Shadow define
extern BYTE Port_2_DriveMode_0_SHADE;
#define LCD_1D4_DriveMode_0Shadow (*(unsigned char*)&Port_2_DriveMode_0_SHADE)
//   LCD_1D4_DriveMode_1Shadow define
extern BYTE Port_2_DriveMode_1_SHADE;
#define LCD_1D4_DriveMode_1Shadow (*(unsigned char*)&Port_2_DriveMode_1_SHADE)
// LCD_1D5 address and mask defines
#pragma	ioport	LCD_1D5_Data_ADDR:	0x8
BYTE			LCD_1D5_Data_ADDR;
#pragma	ioport	LCD_1D5_DriveMode_0_ADDR:	0x108
BYTE			LCD_1D5_DriveMode_0_ADDR;
#pragma	ioport	LCD_1D5_DriveMode_1_ADDR:	0x109
BYTE			LCD_1D5_DriveMode_1_ADDR;
#pragma	ioport	LCD_1D5_DriveMode_2_ADDR:	0xb
BYTE			LCD_1D5_DriveMode_2_ADDR;
#pragma	ioport	LCD_1D5_GlobalSelect_ADDR:	0xa
BYTE			LCD_1D5_GlobalSelect_ADDR;
#pragma	ioport	LCD_1D5_IntCtrl_0_ADDR:	0x10a
BYTE			LCD_1D5_IntCtrl_0_ADDR;
#pragma	ioport	LCD_1D5_IntCtrl_1_ADDR:	0x10b
BYTE			LCD_1D5_IntCtrl_1_ADDR;
#pragma	ioport	LCD_1D5_IntEn_ADDR:	0x9
BYTE			LCD_1D5_IntEn_ADDR;
#define LCD_1D5_MASK 0x2
// LCD_1D5 Shadow defines
//   LCD_1D5_DataShadow define
extern BYTE Port_2_Data_SHADE;
#define LCD_1D5_DataShadow (*(unsigned char*)&Port_2_Data_SHADE)
//   LCD_1D5_DriveMode_0Shadow define
extern BYTE Port_2_DriveMode_0_SHADE;
#define LCD_1D5_DriveMode_0Shadow (*(unsigned char*)&Port_2_DriveMode_0_SHADE)
//   LCD_1D5_DriveMode_1Shadow define
extern BYTE Port_2_DriveMode_1_SHADE;
#define LCD_1D5_DriveMode_1Shadow (*(unsigned char*)&Port_2_DriveMode_1_SHADE)
// LCD_1D6 address and mask defines
#pragma	ioport	LCD_1D6_Data_ADDR:	0x8
BYTE			LCD_1D6_Data_ADDR;
#pragma	ioport	LCD_1D6_DriveMode_0_ADDR:	0x108
BYTE			LCD_1D6_DriveMode_0_ADDR;
#pragma	ioport	LCD_1D6_DriveMode_1_ADDR:	0x109
BYTE			LCD_1D6_DriveMode_1_ADDR;
#pragma	ioport	LCD_1D6_DriveMode_2_ADDR:	0xb
BYTE			LCD_1D6_DriveMode_2_ADDR;
#pragma	ioport	LCD_1D6_GlobalSelect_ADDR:	0xa
BYTE			LCD_1D6_GlobalSelect_ADDR;
#pragma	ioport	LCD_1D6_IntCtrl_0_ADDR:	0x10a
BYTE			LCD_1D6_IntCtrl_0_ADDR;
#pragma	ioport	LCD_1D6_IntCtrl_1_ADDR:	0x10b
BYTE			LCD_1D6_IntCtrl_1_ADDR;
#pragma	ioport	LCD_1D6_IntEn_ADDR:	0x9
BYTE			LCD_1D6_IntEn_ADDR;
#define LCD_1D6_MASK 0x4
// LCD_1D6 Shadow defines
//   LCD_1D6_DataShadow define
extern BYTE Port_2_Data_SHADE;
#define LCD_1D6_DataShadow (*(unsigned char*)&Port_2_Data_SHADE)
//   LCD_1D6_DriveMode_0Shadow define
extern BYTE Port_2_DriveMode_0_SHADE;
#define LCD_1D6_DriveMode_0Shadow (*(unsigned char*)&Port_2_DriveMode_0_SHADE)
//   LCD_1D6_DriveMode_1Shadow define
extern BYTE Port_2_DriveMode_1_SHADE;
#define LCD_1D6_DriveMode_1Shadow (*(unsigned char*)&Port_2_DriveMode_1_SHADE)
// LCD_1D7 address and mask defines
#pragma	ioport	LCD_1D7_Data_ADDR:	0x8
BYTE			LCD_1D7_Data_ADDR;
#pragma	ioport	LCD_1D7_DriveMode_0_ADDR:	0x108
BYTE			LCD_1D7_DriveMode_0_ADDR;
#pragma	ioport	LCD_1D7_DriveMode_1_ADDR:	0x109
BYTE			LCD_1D7_DriveMode_1_ADDR;
#pragma	ioport	LCD_1D7_DriveMode_2_ADDR:	0xb
BYTE			LCD_1D7_DriveMode_2_ADDR;
#pragma	ioport	LCD_1D7_GlobalSelect_ADDR:	0xa
BYTE			LCD_1D7_GlobalSelect_ADDR;
#pragma	ioport	LCD_1D7_IntCtrl_0_ADDR:	0x10a
BYTE			LCD_1D7_IntCtrl_0_ADDR;
#pragma	ioport	LCD_1D7_IntCtrl_1_ADDR:	0x10b
BYTE			LCD_1D7_IntCtrl_1_ADDR;
#pragma	ioport	LCD_1D7_IntEn_ADDR:	0x9
BYTE			LCD_1D7_IntEn_ADDR;
#define LCD_1D7_MASK 0x8
// LCD_1D7 Shadow defines
//   LCD_1D7_DataShadow define
extern BYTE Port_2_Data_SHADE;
#define LCD_1D7_DataShadow (*(unsigned char*)&Port_2_Data_SHADE)
//   LCD_1D7_DriveMode_0Shadow define
extern BYTE Port_2_DriveMode_0_SHADE;
#define LCD_1D7_DriveMode_0Shadow (*(unsigned char*)&Port_2_DriveMode_0_SHADE)
//   LCD_1D7_DriveMode_1Shadow define
extern BYTE Port_2_DriveMode_1_SHADE;
#define LCD_1D7_DriveMode_1Shadow (*(unsigned char*)&Port_2_DriveMode_1_SHADE)
// LCD_1E address and mask defines
#pragma	ioport	LCD_1E_Data_ADDR:	0x8
BYTE			LCD_1E_Data_ADDR;
#pragma	ioport	LCD_1E_DriveMode_0_ADDR:	0x108
BYTE			LCD_1E_DriveMode_0_ADDR;
#pragma	ioport	LCD_1E_DriveMode_1_ADDR:	0x109
BYTE			LCD_1E_DriveMode_1_ADDR;
#pragma	ioport	LCD_1E_DriveMode_2_ADDR:	0xb
BYTE			LCD_1E_DriveMode_2_ADDR;
#pragma	ioport	LCD_1E_GlobalSelect_ADDR:	0xa
BYTE			LCD_1E_GlobalSelect_ADDR;
#pragma	ioport	LCD_1E_IntCtrl_0_ADDR:	0x10a
BYTE			LCD_1E_IntCtrl_0_ADDR;
#pragma	ioport	LCD_1E_IntCtrl_1_ADDR:	0x10b
BYTE			LCD_1E_IntCtrl_1_ADDR;
#pragma	ioport	LCD_1E_IntEn_ADDR:	0x9
BYTE			LCD_1E_IntEn_ADDR;
#define LCD_1E_MASK 0x10
// LCD_1E Shadow defines
//   LCD_1E_DataShadow define
extern BYTE Port_2_Data_SHADE;
#define LCD_1E_DataShadow (*(unsigned char*)&Port_2_Data_SHADE)
//   LCD_1E_DriveMode_0Shadow define
extern BYTE Port_2_DriveMode_0_SHADE;
#define LCD_1E_DriveMode_0Shadow (*(unsigned char*)&Port_2_DriveMode_0_SHADE)
//   LCD_1E_DriveMode_1Shadow define
extern BYTE Port_2_DriveMode_1_SHADE;
#define LCD_1E_DriveMode_1Shadow (*(unsigned char*)&Port_2_DriveMode_1_SHADE)
// LCD_1RS address and mask defines
#pragma	ioport	LCD_1RS_Data_ADDR:	0x8
BYTE			LCD_1RS_Data_ADDR;
#pragma	ioport	LCD_1RS_DriveMode_0_ADDR:	0x108
BYTE			LCD_1RS_DriveMode_0_ADDR;
#pragma	ioport	LCD_1RS_DriveMode_1_ADDR:	0x109
BYTE			LCD_1RS_DriveMode_1_ADDR;
#pragma	ioport	LCD_1RS_DriveMode_2_ADDR:	0xb
BYTE			LCD_1RS_DriveMode_2_ADDR;
#pragma	ioport	LCD_1RS_GlobalSelect_ADDR:	0xa
BYTE			LCD_1RS_GlobalSelect_ADDR;
#pragma	ioport	LCD_1RS_IntCtrl_0_ADDR:	0x10a
BYTE			LCD_1RS_IntCtrl_0_ADDR;
#pragma	ioport	LCD_1RS_IntCtrl_1_ADDR:	0x10b
BYTE			LCD_1RS_IntCtrl_1_ADDR;
#pragma	ioport	LCD_1RS_IntEn_ADDR:	0x9
BYTE			LCD_1RS_IntEn_ADDR;
#define LCD_1RS_MASK 0x20
// LCD_1RS Shadow defines
//   LCD_1RS_DataShadow define
extern BYTE Port_2_Data_SHADE;
#define LCD_1RS_DataShadow (*(unsigned char*)&Port_2_Data_SHADE)
//   LCD_1RS_DriveMode_0Shadow define
extern BYTE Port_2_DriveMode_0_SHADE;
#define LCD_1RS_DriveMode_0Shadow (*(unsigned char*)&Port_2_DriveMode_0_SHADE)
//   LCD_1RS_DriveMode_1Shadow define
extern BYTE Port_2_DriveMode_1_SHADE;
#define LCD_1RS_DriveMode_1Shadow (*(unsigned char*)&Port_2_DriveMode_1_SHADE)
// LCD_1RW address and mask defines
#pragma	ioport	LCD_1RW_Data_ADDR:	0x8
BYTE			LCD_1RW_Data_ADDR;
#pragma	ioport	LCD_1RW_DriveMode_0_ADDR:	0x108
BYTE			LCD_1RW_DriveMode_0_ADDR;
#pragma	ioport	LCD_1RW_DriveMode_1_ADDR:	0x109
BYTE			LCD_1RW_DriveMode_1_ADDR;
#pragma	ioport	LCD_1RW_DriveMode_2_ADDR:	0xb
BYTE			LCD_1RW_DriveMode_2_ADDR;
#pragma	ioport	LCD_1RW_GlobalSelect_ADDR:	0xa
BYTE			LCD_1RW_GlobalSelect_ADDR;
#pragma	ioport	LCD_1RW_IntCtrl_0_ADDR:	0x10a
BYTE			LCD_1RW_IntCtrl_0_ADDR;
#pragma	ioport	LCD_1RW_IntCtrl_1_ADDR:	0x10b
BYTE			LCD_1RW_IntCtrl_1_ADDR;
#pragma	ioport	LCD_1RW_IntEn_ADDR:	0x9
BYTE			LCD_1RW_IntEn_ADDR;
#define LCD_1RW_MASK 0x40
// LCD_1RW Shadow defines
//   LCD_1RW_DataShadow define
extern BYTE Port_2_Data_SHADE;
#define LCD_1RW_DataShadow (*(unsigned char*)&Port_2_Data_SHADE)
//   LCD_1RW_DriveMode_0Shadow define
extern BYTE Port_2_DriveMode_0_SHADE;
#define LCD_1RW_DriveMode_0Shadow (*(unsigned char*)&Port_2_DriveMode_0_SHADE)
//   LCD_1RW_DriveMode_1Shadow define
extern BYTE Port_2_DriveMode_1_SHADE;
#define LCD_1RW_DriveMode_1Shadow (*(unsigned char*)&Port_2_DriveMode_1_SHADE)
// TX address and mask defines
#pragma	ioport	TX_Data_ADDR:	0x8
BYTE			TX_Data_ADDR;
#pragma	ioport	TX_DriveMode_0_ADDR:	0x108
BYTE			TX_DriveMode_0_ADDR;
#pragma	ioport	TX_DriveMode_1_ADDR:	0x109
BYTE			TX_DriveMode_1_ADDR;
#pragma	ioport	TX_DriveMode_2_ADDR:	0xb
BYTE			TX_DriveMode_2_ADDR;
#pragma	ioport	TX_GlobalSelect_ADDR:	0xa
BYTE			TX_GlobalSelect_ADDR;
#pragma	ioport	TX_IntCtrl_0_ADDR:	0x10a
BYTE			TX_IntCtrl_0_ADDR;
#pragma	ioport	TX_IntCtrl_1_ADDR:	0x10b
BYTE			TX_IntCtrl_1_ADDR;
#pragma	ioport	TX_IntEn_ADDR:	0x9
BYTE			TX_IntEn_ADDR;
#define TX_MASK 0x80
// TX Shadow defines
//   TX_DataShadow define
extern BYTE Port_2_Data_SHADE;
#define TX_DataShadow (*(unsigned char*)&Port_2_Data_SHADE)
//   TX_DriveMode_0Shadow define
extern BYTE Port_2_DriveMode_0_SHADE;
#define TX_DriveMode_0Shadow (*(unsigned char*)&Port_2_DriveMode_0_SHADE)
//   TX_DriveMode_1Shadow define
extern BYTE Port_2_DriveMode_1_SHADE;
#define TX_DriveMode_1Shadow (*(unsigned char*)&Port_2_DriveMode_1_SHADE)
