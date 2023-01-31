/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \mytube.h                                                                                  *
* Project: lib                                                                                     *
* Created Date: Wednesday Jan 18th 2023, 9:14:23 pm                                                *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 28/01/2023 07:51:3                                                                *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2023 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/


#ifndef __MYTUBE_H
#define __MYTUBE_H

#include "reg52.h"

sbit C1 = P2^7;
sbit C2 = P2^6;
sbit C3 = P2^5;
sbit C4 = P2^4;

void delayNixieTube();

void displayNumBit_CA(unsigned char b, unsigned char n);

void displayNum4_CA(int n);

void displayNumSep4_CA(unsigned char n1, unsigned char n2, unsigned char n3, unsigned char n4);

void delay_t(unsigned int t, int cnt);

#endif
