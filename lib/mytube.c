/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \mytube.c                                                                                  *
* Project: lib                                                                                     *
* Created Date: Wednesday Jan 18th 2023, 9:14:06 pm                                                *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 28/01/2023 07:18:6                                                                *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2023 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/


#include "mytube.h"

unsigned char nixieTubeNoDot_CA[16] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
unsigned char nixieTubeDot_CA[16] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
unsigned char nixieTubeNoDot_CC[16] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
unsigned char nixieTubeDot_CC[16] = {0xbf,0x86,0xdb,0xcf,0xe6,0xed,0xfd,0x87,0xff,0xef,0xf7,0xfc,0xb9,0xde,0xf9,0xf1};

void delayNixieTube(){
    unsigned int t = 100;
    while(t--);
}

void displayNumBit_CA(unsigned char b, unsigned char n){
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

    P0 = nixieTubeNoDot_CA[n];
}

void displayNum4_CA(int n){
    displayNumBit_CA(1, n / 1000);
    delayNixieTube();

    displayNumBit_CA(2, (n % 1000) / 100);
    delayNixieTube();

    displayNumBit_CA(3, (n % 100) / 10);
    delayNixieTube();

    displayNumBit_CA(4, n % 10);
    delayNixieTube();
}

void displayNumSep4_CA(unsigned char n1, unsigned char n2, unsigned char n3, unsigned char n4){
    displayNumBit_CA(1, n1 % 10);
    delayNixieTube();

    displayNumBit_CA(2, n2 % 10);
    delayNixieTube();

    displayNumBit_CA(3, n3 % 10);
    delayNixieTube();

    displayNumBit_CA(4, n4 % 10);
    delayNixieTube();
}

void delay_t(unsigned int t, int cnt){
	while(t--){
		displayNum4_CA(cnt);
	}
}
