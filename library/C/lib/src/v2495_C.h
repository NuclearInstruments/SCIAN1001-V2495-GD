
#include "NIErrorCode.h"
#include <stdint.h>
#include <stdbool.h>
#ifdef __cplusplus
#ifdef V2495_EXPORTS
#define V2495_API extern "C" __declspec(dllexport)
#else
#define V2495_API extern "C" __declspec(dllimport)
#endif
#else
#define V2495_API
#endif
V2495_API NI_RESULT NI_Startup();
V2495_API NI_RESULT NI_AttachNewDevice(int CONNECTION_MODE, 
									  char *IPAddress_or_SN, 
									  int TCPPort, 
									  int UDPPort, 
									  int *handle);

V2495_API NI_RESULT NI_DeleteDevice(int handle);


V2495_API int NI_ConnectionStatus( int *status,
								  int handle, 
								  int channel	);

V2495_API NI_RESULT NI_USBEnumerate( tUSBDevice *pvArg1, unsigned int *numDevs	);

V2495_API NI_RESULT NI_ETHEnumerate(tETHDevices *pvArg1);

V2495_API NI_RESULT ETHGetSerialNumber(short int port, char *IPAddress, char *SN);

V2495_API NI_RESULT NI_DHA_WriteReg(UINT32 value, 
									  UINT32 address,
									  int handle, 
									  int channel	);

V2495_API NI_RESULT NI_DHA_ReadReg(UINT32 *value, 
									  UINT32 address,
									  int handle, 
									  int channel	);

V2495_API NI_RESULT NI_DHA_ReadReg2(UINT32 *value,
										UINT32 address,
										int handle,
										int channel);

V2495_API NI_RESULT NI_DHA_WriteArray(UINT32 *value, 
									  UINT32 address,
									  UINT32 length,
									  bool AutoInc,
									  int handle, 
									  int channel	);

V2495_API NI_RESULT NI_DHA_ReadArray(UINT32 *value, 
									  UINT32 address,
									  UINT32 *length,
									  bool AutoInc,
									  int handle, 
									  int channel	);

V2495_API NI_RESULT NI_DHA_ReadArray2(UINT32 *value,
	UINT32 address,
	UINT32 *length,
	bool AutoInc,
	int handle,
	int channel);

V2495_API NI_RESULT programGateAndDelay(UINT32 channel,
	UINT32 gate,
	UINT32 delay,
	UINT32 fine_tune,
	UINT32 enable,
	int handle);

V2495_API NI_RESULT BypassGateAndDelay(UINT32 channel,
	UINT32 bypass,
	int handle);

V2495_API NI_RESULT programGateAndDelayBroadcast(
	UINT32 gate,
	UINT32 delay,
	UINT32 fine_tune,
	UINT32 enable,
	int handle);

V2495_API NI_RESULT NI_GateAndDelayRead(UINT32 channel,
	UINT32 *gate,
	UINT32 *delay,
	UINT32 *fine_tune,
	int handle);

V2495_API NI_RESULT Reset_delay(
	
	int handle);

V2495_API NI_RESULT Calibrate(

	int handle);




V2495_API NI_RESULT HardwareInfo(	
										UINT32  *HWREV,
										UINT32  *FWREV,
										UINT32  *HWOPTIONS,
										int handle);

V2495_API NI_RESULT InitFlashWrite(t_FPGA_V2495 FPGA,
	int handle);

V2495_API NI_RESULT DeleteSector(t_FPGA_V2495 FPGA,
	unsigned int page,
	int handle);


V2495_API NI_RESULT WriteData(t_FPGA_V2495 FPGA,
	unsigned int address,
	unsigned int *data,
	unsigned int length,
	int handle);

V2495_API NI_RESULT ReadData(t_FPGA_V2495 FPGA,
	unsigned int address,
	unsigned int *data,
	unsigned int length,
	int handle);
