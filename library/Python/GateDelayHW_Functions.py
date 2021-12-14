
import os
import GateDelayHW_RegisterFile
from ctypes import *

mydll = cdll.LoadLibrary(os.path.dirname(__file__) + '/v2495_API.dll')


def Init():
    err = mydll.NI_Startup()
    return err

def ConnectDevice(ConnectionMode, board, TCPPort, UDPPort):
    handle = c_void_p(256)
    err = mydll.NI_AttachNewDevice(ConnectionMode, board, TCPPort, UDPPort, byref(handle))
    return err, handle

def CloseConnect(board, handle):
    err = mydll.NI_Deletedevice(byref(handle))
    return err	
	
def ListUSBDevices():
    count = c_int(0)
    s = create_string_buffer(2048)
    err = mydll.NI_USBEnumerateString(byref(s), 2048, byref(count))
    str_con = (s.value.decode('ascii')) 
    str_devices = str_con.split(';')
    dev_count = count.value
    return str_devices, dev_count 

def __abstracted_reg_write(data, address, handle):
    err = mydll.NI_DHA_WriteReg(value, address, (handle), 0)
    return err

def __abstracted_reg_read(address, handle):
    data = c_uint(0)
    err = mydll.NI_DHA_ReadReg2(byref(data), address, (handle), 0)
    return err, data.value

def __abstracted_mem_write(data, count, address, handle):
    written_data = c_uint(0)
    err = mydll.NI_DHA_WriteArray(data, address, count, 1, (handle), 0)
    return err

def __abstracted_mem_read(count, address, handle):
    data = (c_uint * (2* count))()
    err = mydll.NI_DHA_ReadArray2(byref(data), address, count, 1, (handle))
    return err, data, read_data.value, valid_data.value

def __abstracted_fifo_write(data, count, address, handle):
    written_data = c_uint(0)
    err = mydll.NI_DHA_WriteArray(data, address, count, 0, (handle), 0)
    return err, written_data.value

def __abstracted_fifo_read(count, address, address_status, blocking, timeout_ms, handle):
    data = (c_uint * (2 * count))()
    err = mydll.NI_DHA_ReadArray2(byref(data), address, count, 0, (handle))
    return err, data, read_data, valid_data 	

def GateDelay_Program(channel, gate, delay, fine_tune, enable, handle):
    err = mydll.programGateAndDelay(channel, gate, delay, fine_tune, enable, (handle));
    return err
	
def GateDelay_Bypass(channel, bypass, handle):
    err = mydll.BypassGateAndDelay(channel, bypass, (handle));
    return err	
	
def GateDelay_programBroadcast(gate, delay, fine_tune, enable, handle):
    err = mydll.programGateAndDelayBroadcast(gate, delay, fine_tune, enable, (handle));
    return err

def GateDelay_Read(channel, handle):
    data_gate = c_uint(0)
    data_delay = c_uint(0)
    data_fine_tune = c_uint(0)
    err = mydll.NI_GateAndDelayRead(channel, byref(data_gate), byref(data_delay), byref(data_fine_tune), (handle));
    return err, data_gate, data_delay, data_fine_tune	

def GateDelay_Reset_delay(handle):
    err = mydll.Reset_delay((handle));
    return err		
	
def GateDelay_Calibrate(handle):
    err = mydll.Calibrate((handle));
    return err		
	

