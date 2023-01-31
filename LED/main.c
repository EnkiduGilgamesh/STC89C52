/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \main.c                                                                                    *
* Project: LED                                                                                     *
* Created Date: Monday Jan 16th 2023, 11:20:31 pm                                                  *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 28/01/2023 11:25:45                                                               *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2023 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/


#include "reg52.h"

sbit D1 = P1^0;
sbit D2 = P1^1;
sbit D3 = P1^2;
sbit D4 = P1^3;
sbit D5 = P1^4;
sbit D6 = P1^5;
sbit D7 = P1^6;
sbit D8 = P1^7;

void delay(unsigned int t){
	while(t--);
}

void LEDShining(){
	char i;
	for(i = 0; i < 3; i++){
		P1 = 0x00;
		delay(40000);
		P1 = 0xff;
		delay(40000);
	}
}

void LEDRunning(){
	unsigned char i;
	for(i = 0; i < 8; i++){
		P1 = 0xff << i;
		delay(100000);       
	}
	
	for(i = 0; i < 8; i++){
		P1 = ~(0xff << i);
		delay(100000);
	}
}

void main(){
	while(1){
		LEDShining();
		LEDRunning();
	}
}