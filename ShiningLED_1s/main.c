#include "reg52.h"
#include "myled.h"

unsigned int cnt = 0;

void initT0(){
	TMOD = 0x01;										// 0000 0001
	TH0  = (65536 - 50000) / 256;		//
	TL0  = (65536 - 50000) % 256;		//
	
	ET0  = 1;
	EA   = 1;
	TR0  = 1;
}

void serviceT0() interrupt 1{
	TH0 = (65536 - 50000) / 256;
	TL0 = (65536 - 50000) % 256;
	
	cnt++;
	if(cnt == 20){
		cnt = 0;
		D1 = ~D1;
	}
}

void main(){
	initT0();
	while(1);
}



