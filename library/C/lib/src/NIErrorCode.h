#include <windows.h>
#pragma once
typedef ULONG	NI_RESULT;

#define		NI_OK									0x00000000
#define		NI_ERROR_GENERIC						0x00000001
#define		NI_ERROR_INTERFACE						0x00000002
#define		NI_ERROR_FPGA							0x00000003
#define		NI_ERROR_TRANSFER_MAX_LENGTH			0x00000004
#define		NI_ERROR_NOTCONNECTED					0x00000005
#define		NI_NO_DATA_AVAILABLE					0x00000006
#define		NI_TOO_MANY_DEVICES_CONNECTED			0x00000007
#define		NI_INVALID_HANDLE						0x00000008
#define		NI_INVALID_HARDWARE						0x00000009

typedef ULONG	NI_STATUS;
#define		NI_ONLINE				0x00000000
#define		NI_ERROR				0x00000001
#define		NI_OFFLINE				0x00000002
#define		NI_UCBOOTLOADER			0x00000003
#define		NI_FPGABOOTLOADER		0x00000004


#define		NI_CONNECTED			0x00000001
#define		NI_NOTCONNECTED			0x00000000


#define		GET_VERSION		1
#define		ERASE_FLASH		2
#define		UPLOAD_FW		3
#define		READ_CRC	    4
#define		RUN_APPLICATION	5
#define		ERASE_CONFIG	0x10
#define		WRITE_CONFIG	0x11
#define		READ_CONFIG		0x12
#define		REBOOT_BOARD	0xFF


#define		NUCLEAR_INSTRUMENTS_PIC32_BOOTLOADER	0x01
#define		NUCLEAR_INSTRUMENTS_DPP_ETHERNET		0x02
#define		NUCLEAR_INSTRUMENTS_EMULATOR_ETHERNET	0x03

typedef struct _tUSBDevice
{
	unsigned int id;
	char SN[64];
	char DESC[64];
} tUSBDevice;

typedef struct _tETHDevice
{
	unsigned char HW_CODE[4];
	unsigned char pic_version_high;
	unsigned char pic_version_low;
	char serial_number[8];
	unsigned char ip_address[4];
	unsigned char mac_address[6];
	unsigned int UDP_port;
	unsigned int TCP_port;
	char SIPAddress[16];
} tETHDevice;


typedef struct _tETHDevices
{
	int Count;
	tETHDevice Devices[32];
} tETHDevices;

typedef struct _tBOARDConfig
{
	unsigned char IPAddress[4];
	unsigned char NETMask[4];
	unsigned char IPGateway[4];
	unsigned char PriDNS[4];
	unsigned char MAC[6];
	unsigned int UDPPort;
	unsigned int HW_Code_Number;
	unsigned char CompanyInfo[256];
	unsigned char FriendlyName[128];
	unsigned int HW_Revision;
	unsigned int HW_Bootloader_Delay;
	unsigned char HW_SerialNumber[8];
	unsigned int TCPPort;
} tBOARDConfig;




#define		NI_CONNECT_USB									0x00000000
#define		NI_CONNECT_ETH									0x00000001
#define		NI_CONNECT_BT									0x00000002


typedef enum
{
	FPGA_MAIN = 0,
	FPGA_USER = 1,
	FPGA_DELAY = 2
} t_FPGA_V2495;