/*=============================================================================
 * Copyright (c) 2019, Eric Pernia <ericpernia@gmail.com>
 * All rights reserved.
 * License: bsd-3-clause (see LICENSE file)
 * Date: 2019/05/03
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "sapi.h"
#include "semaphore.h"
#include <stdio.h>
#include <stdbool.h>

int normalDelay[3] = {3000,500,1000};
int desconectedDelay = 500;
int alarmDelay = 1000;
bool firstTime=true;

/*=====[Definition macros of private constants]==============================*/
void changeColor(struct semaphore_st * sm){
	switch(sm->state)
	{
		case NORMAL:
			normalNextSequence(sm);
			break;
		case DESCONECTADO:
			desconectadoNextSequence(sm);
			break;
		case ALARMA:
			alarmaNextSequence(sm);
			break;
	}
}

void normalNextSequence(struct semaphore_st * sm){
	switch(sm->actualLight)
	{
		case LIGHT_ROJA:
			sm->actualLight=LIGHT_AMARILLA;
			turnOnRed();
			turnOnYellow();
			delayWrite( &sm->myDelay, normalDelay[sm->actualLight] );
			break;
		case LIGHT_AMARILLA:
			sm->actualLight=LIGHT_VERDE;
			turnOnYellow();
			turnOnGreen();
			delayWrite( &sm->myDelay, normalDelay[sm->actualLight] );
			break;
		case LIGHT_VERDE:
			sm->actualLight=LIGHT_ROJA;
			turnOnGreen();
			turnOnRed();
			delayWrite( &sm->myDelay, normalDelay[sm->actualLight] );
			break;
	}
}

void desconectadoNextSequence(struct semaphore_st * sm){
	turnOnYellow();
}

void alarmaNextSequence(struct semaphore_st * sm){
	turnOnYellow();
	turnOnRed();
}

void setNormal(struct semaphore_st * sm){
	if(sm->state!=NORMAL){
		//Turn off all leds
		turnOffLeds();
		sm->state=NORMAL;
		sm->actualLight=0;
		//Turn on necesary leds
		turnOnRed();

		if(firstTime){
			delayConfig( &sm->myDelay, normalDelay[sm->actualLight] );
			firstTime=false;
		}else{
			delayWrite( &sm->myDelay, normalDelay[sm->actualLight] );
		}
	}//Else, continue with same state
}

void setDesconectado(struct semaphore_st * sm){
	if(sm->state!=DESCONECTADO){
		//Turn off all leds
		turnOffLeds();
		sm->state=DESCONECTADO;
		//Turn on necesary leds
		turnOnYellow();
		delayWrite(&sm->myDelay, desconectedDelay );
	}//Else, continue with same state
}

void setAlarma(struct semaphore_st * sm){
	if(sm->state!=ALARMA){
		//Turn off all leds
		turnOffLeds();
		sm->state=ALARMA;
		//Turn on necesary leds
		turnOnYellow();
		turnOnRed();
		delayWrite(&sm->myDelay, alarmDelay );
	}//Else, continue with same state
}

