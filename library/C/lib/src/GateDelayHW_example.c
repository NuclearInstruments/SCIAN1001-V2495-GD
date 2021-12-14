
#include "V2495_C.h"
#include  <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include  "GateDelayHW_lib.h"

#define BOARD_SERIAL_NUMBER "0020"




int main(int argc, char* argv[])
{
	int       handle;
	int ret;
	NI_RESULT res;
	UINT32    val;
	UINT32 gate;
	UINT32 delay;
	UINT32 fine_tune;
	V2495_Startup();
	if (V2495_AttachNewDevice(0, BOARD_SERIAL_NUMBER, 0, &handle) != NI_OK) { printf("Unable to connect to the board!\n"); return (-1); };

	GateDelay_Calibrate(&handle);
	GateDelay_Bypass(0, 0, &handle);		//Disable delay bypass
	
	GateDelay_Program(0,
		50,					//GATE
		1,					//DELAY
		0,					//FINE
		1,					//ENABLE
		&handle);
	GateDelay_Read(0,
		&gate,
		&delay,
		&fine_tune,
		&handle);
	printf(" Gate: %d  Delay: %d Fine:%d\n", gate, delay, fine_tune);
	
	

	return 0;
}