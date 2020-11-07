/*
 * main.c
 *
 *  Created on: Nov 4, 2020
 *      Author: maxi
 */


#include "sapi.h"
#include "main.h"

void readTECValues(){
   tec1_value=gpioRead( (gpioMap_t) TEC1 );
   tec2_value=gpioRead( (gpioMap_t) TEC2 );
   tec3_value=gpioRead( (gpioMap_t) TEC3 );
}

int main( void )
{
   // ----- Setup -----------------------------------
   boardInit();
   setNormal(&s1);

   // ----- Repeat for ever -------------------------
   while( true ) {

	   //Read tecs
	   readTECValues();

	   //If for separate multiple actions occurrences
	   if(tec1_value==0 || tec2_value==0 || tec3_value==0){
		   //depend tec, set semaphore mode
		   if (tec1_value==0){
			   setNormal(&s1);
		   }
		   else if (tec2_value==0){
			   setDesconectado(&s1);
		   }
		   else if (tec3_value==0){
			   setAlarma(&s1);
		   }
	   }else{
		   //read delay value
		   bool_t result_delay=delayRead( &s1.myDelay );

		   //If delay finish, change color depending semaphore mode
		   if(result_delay){
			   changeColor(&s1);
		   }
	   }
   }

   return 0;
}
