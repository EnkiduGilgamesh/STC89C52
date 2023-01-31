#include "reg52.h"
#include "mylib.h"
#include "myled.h"
#include "mykey.h"

void scanKey(){
	if(SW3 == 0){
	 delay(200);
	 if(SW3 == 1){
	 while(SW3 == 0);
	 D1 = ~D1;
	 }
 }
}

int main(){
	while(1){
		//programTest();
		scanKey();
	}
}
