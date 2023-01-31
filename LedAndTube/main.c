#include "reg52.h"
#include "mytube.h"
#include "mylib.h"
#include "mytube.c"
#include "mylib.c"
#include "myled.h"

unsigned int cnt1 = 0, cnt2 = 0;

void displayBit(unsigned char b, unsigned char n){
    P0 = 0xff;

    switch (b){
    case 1:
        C1 = 1, C2 = 0, C3 = 0, C4 = 0;
        break;
    case 2:
        C1 = 0, C2 = 1, C3 = 0, C4 = 0;
        break;
    case 3:
        C1 = 0, C2 = 0, C3 = 1, C4 = 0;
        break;
    case 4:
        C1 = 0, C2 = 0, C3 = 0, C4 = 1;
        break;

    default:
        C1 = 0, C2 = 0, C3 = 0, C4 = 0;
        break;
    }

    P0 = n;
}

void displayNum(int n1, int n2){
    displayBit(1, (nixieTubeNoDot_CA[n2]));
    delayNixieTube();

    displayBit(2, 0xbf);
    delayNixieTube();

    displayBit(3, (nixieTubeNoDot_CA[n1 / 10]));
    delayNixieTube();

    displayBit(4, (nixieTubeNoDot_CA[n1 % 10]));
    delayNixieTube();
}

void delay_t(unsigned int t){
	while(t--){
		displayNum(cnt1, cnt2);
	}
}

void main(){
	D1 = 1, D2 = 1;
	while(1){
		// displayNum(, 0);
		delay_t(100);
		D1 = ~D1;
		delay_t(100);
		D1 = ~D1;
		cnt1++;
		if(cnt1 % 10 == 0){
			D2 = ~D2;
			cnt2++;
			if(cnt2 == 10){
				cnt2 = 0;
			}
		}
		
		if(cnt1 == 100){
			cnt1 = 0;
		}
	}
}