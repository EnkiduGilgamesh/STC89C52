#include "reg52.h"
#include "myled.h"

void initT0(){
	TMOD = 0x06;						// 0000 0110
	TH0  = 256 - 3;					// 最大计数值的高8位
	TL0  = 256 - 3;					// 最大计数值的低8位
	
	ET0 = 1;								// 使能定时器0中断
	EA  = 1;								// 使能总中断
	TR0 = 1;								// 启动定时器0
}

void serviceT0() interrupt 1{
	D1 = ~D1;
}

void main(){
	initT0();
	while(1);
}




