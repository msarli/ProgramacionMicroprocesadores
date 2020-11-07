/*
 * semaphore.h
 *
 *  Created on: Nov 4, 2020
 *      Author: maxi
 */
#include "sapi.h"
#include "led.h"

#ifndef MY_PROGRAMS_SEMAPHORE_SRC_SEMAPHORE_H_
#define MY_PROGRAMS_SEMAPHORE_SRC_SEMAPHORE_H_


enum State {NORMAL = 1, DESCONECTADO = 2, ALARMA=3};

struct semaphore_st {
   int   state;
   delay_t myDelay;
   int actualLight;
};

void changeColor(struct semaphore_st * sm);

void setNormal(struct semaphore_st * sm);

void setDesconectado(struct semaphore_st * sm);

void setAlarma(struct semaphore_st * sm);

void normalNextSequence(struct semaphore_st * sm);

void desconectadoNextSequence(struct semaphore_st * sm);

void alarmaNextSequence(struct semaphore_st * sm);

#endif /* MY_PROGRAMS_SEMAPHORE_SRC_SEMAPHORE_H_ */
