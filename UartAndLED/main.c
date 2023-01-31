#include "reg52.h"
#include "myled.h"
#include "myuart.h"

unsigned char cmd = 0;
unsigned char flag = 0;

void serviceUart() interrupt 4{
	if(RI == 1){
		RI = 0;
		cmd = SBUF;
		flag = 1;
	}
}

void controlLED(){
	switch(cmd){
		case 0xa1:
			D1 = 0;
			sendString("LED D1 now is on!\r\n");
			break;
		case 0xa2:
			D1 = 1;
			sendString("LED D1 now is off!\r\n");
			break;
		default:
			sendString("Wrong command!\r\n");
			break;
	}
}

void main(){
	initUart();
	while(1){
		if(flag == 1){
			flag = 0;
			// sendByte(++cmd);
			controlLED();
		}
	}
}
	
	
	
	
	
	