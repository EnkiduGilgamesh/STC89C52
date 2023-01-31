#include "reg52.h"
#include "mylib.h"
#include "myled.h"
#include "mytube.h"
#include "mykey.h"
#include "mytimer.h" 

unsigned char sec = 0, min = 0, msec = 0;

void serviceT0() interrupt 1{
	TH0 = (65536 - 10000) / 256; 
	TH1 = (65535 - 10000) % 256;
	
	msec++;
	
	if(msec == 100){
		sec++;
		msec = 0;
		if(sec == 60){
			sec = 0;
			min++;
			if(min == 9){
				min = 0;
			}
		}
	}
}

void scanKeys(){
	if(SW1 == 0){
		delay(200);
		if(SW1 == 0){
			TR0 = 1;
			while(SW1 == 0){
				displayNumSep4_CA(sec / 10, sec % 10, msec / 10, msec % 10);
			}
		}
	}
	
	if(SW2 == 0){
		delay(200);
		if(SW2 == 0){
			TR0 = ~TR0;
			while(SW2 == 0){
				displayNumSep4_CA(sec / 10, sec % 10, msec / 10, msec % 10);
			}
		}
	}
	
	if(SW3 == 0){
		delay(200);
		if(SW3 == 0){
			min = 0, sec = 0, msec = 0;
			while(SW3 == 0){
				displayNumSep4_CA(sec / 10, sec % 10, msec / 10, msec % 10);
			}
		}
	}
}

void LEDDisplaying(){
	unsigned char i;
	for(i = 0; i <= min; i++){
		P1 = 0xff << i;
	}
}

void main(){
	initT0(10000, 0);
	P1 = 0xff;
	while(1){
		displayNumSep4_CA(sec / 10, sec % 10, msec / 10, msec % 10);
		scanKeys();
		LEDDisplaying();
	}
}
	