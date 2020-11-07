/*
 * led.c
 *
 *  Created on: Nov 4, 2020
 *      Author: maxi
 */

#include "sapi.h"
#include "led.h"


void turnOffLeds(){

	gpioWrite(LUZ_ROJA,false);
	gpioWrite(LUZ_AMARILLA,false);
	gpioWrite(LUZ_VERDE,false);
}

void turnOnRed(){
	gpioToggle(LUZ_ROJA);
}

void turnOnYellow(){
	gpioToggle(LUZ_AMARILLA);
}

void turnOnGreen(){
	gpioToggle(LUZ_VERDE);
}
