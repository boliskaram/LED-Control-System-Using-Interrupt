/*
 * LED Sequence V2.0.c
 *
 * Created: 8/30/2023 7:05:17 PM
 * Author : Bolis
 */ 

//#include <avr/io.h>
#include "APP/APP.h"


int main(void)
{
	APP_Init();
    /* Replace with your application code */
    while (1) 
    {
		APP_Update();
    }
}

