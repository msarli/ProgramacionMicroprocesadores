/*
 * led.h
 *
 *  Created on: Nov 4, 2020
 *      Author: maxi
 */
#include "sapi.h"

#ifndef MY_PROGRAMS_SEMAPHORE_SRC_LED_H_
#define MY_PROGRAMS_SEMAPHORE_SRC_LED_H_


#define LUZ_ROJA     LED2
#define LUZ_AMARILLA LED1
#define LUZ_VERDE    LED3

enum Lights {LIGHT_ROJA = 0, LIGHT_AMARILLA = 1, LIGHT_VERDE = 2};

void turnOffLeds();

void turnOnRed();

void turnOnYellow();

void turnOnGreen();


//delayConfig( &myDelay, 1000 );

#endif /* MY_PROGRAMS_SEMAPHORE_SRC_LED_H_ */
