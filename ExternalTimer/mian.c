#include "reg52.h"
#include "myled.h"

void initT0(){
	TMOD = 0x06;						// 0000 0110
	TH0  = 256 - 3;					// ������ֵ�ĸ�8λ
	TL0  = 256 - 3;					// ������ֵ�ĵ�8λ
	
	ET0 = 1;								// ʹ�ܶ�ʱ��0�ж�
	EA  = 1;								// ʹ�����ж�
	TR0 = 1;								// ������ʱ��0
}

void serviceT0() interrupt 1{
	D1 = ~D1;
}

void main(){
	initT0();
	while(1);
}




