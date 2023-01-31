#include "reg52.h"
#include "mytube.h"
#include "mylib.h"
#include "mytube.c"
#include "mylib.c"

unsigned int cnt = 998;

void delay_t(unsigned int t){
	while(t--){
		displayNum_CA(cnt);
	}
}

void main(){
	while(1){
		displayNum_CA(cnt);
		delay_t(500);
		
		cnt++;
		if(cnt == 10000) cnt = 0;
	}
}