#include "RegisterFile.h"
#include "NIErrorCode.h"
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
#ifdef SCICOMPILER_EXPORTS
#define SCILIB extern "C" __declspec(dllexport) 
#else
#define SCILIB extern "C" __declspec(dllimport)
#endif
#else
#define SCILIB __declspec(dllexport) 
#endif
typedef enum {
	USB=0,
	ETH=1
}tConnectionMode;

SCILIB NI_RESULT V2495_Startup();
SCILIB NI_RESULT V2495_AttachNewDevice(tConnectionMode CONNECTION_MODE, char *IPAddress_or_SN, uint32_t TCPPort, int32_t *handle);
SCILIB NI_RESULT V2495_DeleteDevice(int32_t *handle);
SCILIB NI_RESULT V2495_ConnectionStatus( uint32_t *status, int32_t *handle);
SCILIB NI_RESULT V2495_USBEnumerate( tUSBDevice *pvArg1, uint32_t *numDevs	);
SCILIB NI_RESULT V2495_ETHEnumerate(tETHDevices *pvArg1);
SCILIB NI_RESULT V2495_ETHGetSerialNumber(uint32_t port, char *IPAddress, char *SN);
SCILIB NI_RESULT V2495_HardwareInfo(	uint32_t  *HWREV, uint32_t  *FWREV, uint32_t  *HWOPTIONS, int32_t *handle);
SCILIB NI_RESULT __abstracted_reg_write(uint32_t value, uint32_t address, int32_t *handle);
SCILIB NI_RESULT __abstracted_reg_read(uint32_t *value, uint32_t address, int32_t *handle);
SCILIB NI_RESULT __abstracted_mem_write(uint32_t *value, uint32_t address, uint32_t size, uint32_t timeout, int32_t *handle);
SCILIB NI_RESULT __abstracted_mem_read(uint32_t *value, uint32_t address, uint32_t size, uint32_t timeout, int32_t *handle);
SCILIB NI_RESULT __abstracted_fifo_write(uint32_t *value, uint32_t address, uint32_t size, uint32_t timeout, int32_t *handle);
SCILIB NI_RESULT __abstracted_fifo_read(uint32_t *data, uint32_t count, 
										uint32_t address, 
										uint32_t address_status, 
										bool blocking,
										uint32_t timeout_ms, int32_t *handle, 
										uint32_t *read_data, uint32_t *valid_data);

										
SCILIB NI_RESULT GateDelay_Program(UINT32 channel,
	UINT32 gate,
	UINT32 delay,
	UINT32 fine_tune,
	UINT32 enable,
	int32_t *handle);
	
SCILIB NI_RESULT GateDelay_Bypass(UINT32 channel,
	UINT32 bypass,
	int32_t *handle);
	
SCILIB NI_RESULT GateDelay_programBroadcast(
	UINT32 gate,
	UINT32 delay,
	UINT32 fine_tune,
	UINT32 enable,
	int32_t *handle);

SCILIB NI_RESULT GateDelay_Read(UINT32 channel,
	UINT32 *gate,
	UINT32 *delay,
	UINT32 *fine_tune,
	int32_t *handle);

SCILIB NI_RESULT GateDelay_Reset_delay(
	int32_t *handle);

SCILIB NI_RESULT GateDelay_Calibrate(
	int32_t *handle);	
