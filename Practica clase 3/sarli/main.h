/*
 * main.h
 *
 *  Created on: Nov 4, 2020
 *      Author: maxi
 */

#include "sapi.h"
#include "semaphore.h"

#ifndef MY_PROGRAMS_SEMAPHORE_SRC_MAIN_H_
#define MY_PROGRAMS_SEMAPHORE_SRC_MAIN_H_


uint8_t tec1_value;
uint8_t tec2_value;
uint8_t tec3_value;

struct semaphore_st s1;


void readTECValues();



#endif /* MY_PROGRAMS_SEMAPHORE_SRC_MAIN_H_ */
