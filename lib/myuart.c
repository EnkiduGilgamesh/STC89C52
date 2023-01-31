/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \myuart.c                                                                                  *
* Project: lib                                                                                     *
* Created Date: Tuesday Jan 31st 2023, 11:22:11 am                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 31/01/2023 11:57:38                                                               *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2023 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/


#include "myuart.h"

void initUart(){
    // set the baud rate
    TMOD = 0x20;
    TH1  = 0Xf3;
    TL1  = 0xf3;
    TR1  = 1;

    // set the output
    SCON = 0x50;

    // energy the interruption
    ES   = 1;
    EA   = 1; 
}

void sendByte(unsigned char dat){
    SBUF = dat;
    while(TI == 0);
    TI = 0;
}

void sendString(unsigned char * str){
    while(*str != '\0'){
        sendByte(*str++);
    }
}