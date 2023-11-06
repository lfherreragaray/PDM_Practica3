#include "../Inc/API_delay.h"
#define MAXDURATION 1000//maxima duracion de 100 s
#define MINDURATION 0

void delayInit(delay_t * delay, tick_t duration)
{
	assert(MINDURATION<duration && MAXDURATION>duration);
	delay->duration=duration;
	delay->running=false;
	delay->startTime=0;
}

uint32_t getTickTime(tick_t time)
{
return time;
}


bool_t delayRead(delay_t * delay)
{
	if(delay->running==false)//si no esta en delay, entra
	{
		delay->running=true;
		delay->startTime=HAL_GetTick();//obtiene el tiempo actual
	}
	else
	{
		if(HAL_GetTick()-delay->startTime>=delay->duration)//compara la delta del tiempo actual contra la duracion en ms
			{
			delay->running=false;//si se ha cumplido la condicion el retardo cambia false
			return true;//retorna un valor verdadero y regresa

			}
	}
	return false;//si no se ha cumplido la condicion de tiempo, retorna falso
}

void delayWrite(delay_t*delay, tick_t duration)
{
	delay->duration=duration;//permite cambiar el valor de duracion
}/*
 * API_delay.c
 *
 *  Created on: Nov 5, 2023
 *      Author: ubuntu
 */


