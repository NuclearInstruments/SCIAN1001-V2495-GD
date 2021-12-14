from GateDelayHW_Functions import *
from ctypes import *


[ListOfDevices, count] = ListUSBDevices()
if (count > 0):

    board = ListOfDevices[0].encode('utf-8')

    Init()
    EthConnection = 0
    TCPPort = 0
    UDPPort = 0
    [err, handle] = ConnectDevice(EthConnection, board, TCPPort, UDPPort)
    if (err == 0):
        print("Successful connection to board ", board)
    else:
        print("Connection Error")
    
    GateDelay_Calibrate(handle)
    GateDelay_Bypass(0, 0, handle)	#Disable delay bypass
    GateDelay_Program(0,
				50,					#GATE
				1,					#DELAY
				0,					#FINE
				1,					#ENABLE
				handle)

    err, gate, delay, fine_tune   =  GateDelay_Read(0, handle)
    print (" Gate: " + str(gate) + " Delay: " + str(delay) + " Fine: " + str(fine_tune) + "\n")
	
	