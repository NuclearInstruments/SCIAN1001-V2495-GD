
#include "V2495_C.h"
#include  <stdlib.h>
#include <stdbool.h>

#include "stdafx.h"
#include "RegisterFile.h"
#include  "GateDelayHW_lib.h"

SCILIB NI_RESULT V2495_Startup()
{
 return NI_Startup();
}

SCILIB NI_RESULT V2495_AttachNewDevice(tConnectionMode CONNECTION_MODE, char *IPAddress_or_SN, uint32_t TCPPort, int32_t *handle)
{
	return NI_AttachNewDevice((uint32_t) CONNECTION_MODE, IPAddress_or_SN, TCPPort, 6240, handle);
}

SCILIB NI_RESULT V2495_DeleteDevice(int32_t *handle)
{
	NI_DeleteDevice(*handle);
}

SCILIB NI_RESULT V2495_ConnectionStatus( uint32_t *status,
								  int32_t *handle)
{
	NI_ConnectionStatus(status, *handle, 0);
}


SCILIB NI_RESULT V2495_USBEnumerate( tUSBDevice *pvArg1, uint32_t *numDevs	)
{
	return NI_USBEnumerate(pvArg1,numDevs);
}

SCILIB NI_RESULT V2495_ETHEnumerate(tETHDevices *pvArg1)
{
	return V2495_ETHEnumerate(pvArg1);
}

SCILIB NI_RESULT V2495_ETHGetSerialNumber(uint32_t port, char *IPAddress, char *SN)
{
	return V2495_ETHGetSerialNumber(port,IPAddress, SN);
}

SCILIB NI_RESULT V2495_HardwareInfo(	uint32_t  *HWREV,
										uint32_t  *FWREV,
										uint32_t  *HWOPTIONS,
										int32_t *handle)
{
	
	return HardwareInfo(HWREV, FWREV, HWOPTIONS, *handle);
}

SCILIB NI_RESULT __abstracted_reg_write(uint32_t value, uint32_t address, int32_t *handle)
{
	return  NI_DHA_WriteReg(value, address, *handle, 0);
}

SCILIB NI_RESULT __abstracted_reg_read(uint32_t *value, uint32_t address, int32_t *handle)
{
	return  NI_DHA_ReadReg2(value, address, *handle, 0);
}


SCILIB NI_RESULT __abstracted_mem_write(uint32_t *value, uint32_t address, uint32_t size, uint32_t timeout, int32_t *handle)
{
	return  NI_DHA_WriteArray(value, address, size, true, *handle, 0);
}

SCILIB NI_RESULT __abstracted_mem_read(uint32_t *value, uint32_t address, uint32_t size, uint32_t timeout, int32_t *handle)
{
	return  NI_DHA_ReadArray2(value, address, size, true, *handle, 0);
}

SCILIB NI_RESULT __abstracted_fifo_write(uint32_t *value, uint32_t address, uint32_t size, uint32_t timeout, int32_t *handle)
{
	return  NI_DHA_WriteArray(value, address, size, false, *handle, 0);
}

SCILIB NI_RESULT __abstracted_fifo_read(uint32_t *data, uint32_t count, 
										uint32_t address, 
										uint32_t address_status, 
										bool blocking,
										uint32_t timeout_ms, int32_t *handle, 
										uint32_t *read_data, uint32_t *valid_data)
{
	return  NI_DHA_ReadArray2(data, address, count, false, *handle, 0);
}



SCILIB NI_RESULT GateDelay_Program(UINT32 channel,
	UINT32 gate,
	UINT32 delay,
	UINT32 fine_tune,
	UINT32 enable,
	int32_t *handle)
	{
		return programGateAndDelay(channel,
			gate,
			delay,
			fine_tune,
			enable,
			*handle);	
	}

SCILIB NI_RESULT GateDelay_Bypass(UINT32 channel,
	UINT32 bypass,
	int32_t *handle)
	{
		return BypassGateAndDelay(channel,
			bypass,
			*handle);		
	}

SCILIB NI_RESULT GateDelay_programBroadcast(
	UINT32 gate,
	UINT32 delay,
	UINT32 fine_tune,
	UINT32 enable,
	int32_t *handle)
	{
		programGateAndDelayBroadcast(
			gate,
			delay,
			fine_tune,
			enable,
			*handle);	
	
	}

SCILIB NI_RESULT GateDelay_Read(UINT32 channel,
	UINT32 *gate,
	UINT32 *delay,
	UINT32 *fine_tune,
	int32_t *handle)
	{
		return NI_GateAndDelayRead(channel,
			gate,
			delay,
			fine_tune,
			*handle);	
	}

SCILIB NI_RESULT GateDelay_Reset_delay(
	int32_t *handle)
	{
		Reset_delay(*handle);	
	}

SCILIB NI_RESULT GateDelay_Calibrate(
	int32_t *handle)
	{
		Calibrate(*handle);	
	}