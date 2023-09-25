/*
 * Register.h
 *
 * Created: 8/22/2023 11:10:47 PM
 *  Author: Bolis
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_

#include "Types.h"
//#include <stdint.h>

/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------*/
/*-------------------------------DIO Registers-------------------------------------*/
/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------*/


#define PORTA	*((volatile uint8_t*)0x3B)
#define DDRA	*((volatile uint8_t*)0x3A)
#define PINA	*((volatile uint8_t*)0x39)

#define PORTB	*((volatile uint8_t*)0x38)
#define DDRB	*((volatile uint8_t*)0x37)
#define PINB	*((volatile uint8_t*)0x36)

#define PORTC	*((volatile uint8_t*)0x35)
#define DDRC	*((volatile uint8_t*)0x34)
#define PINC	*((volatile uint8_t*)0x33)

#define PORTD	*((volatile uint8_t*)0x32)
#define DDRD	*((volatile uint8_t*)0x31)
#define PIND	*((volatile uint8_t*)0x30)


/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------*/
/*----------------------------- EXTI Registers ------------------------------------*/
/*---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------*/

#define MCUCR	*((volatile uint8_t*)0x55)
#define MCUCSR	*((volatile uint8_t*)0x54)
#define GICR	*((volatile uint8_t*)0x5B)
#define GIFR	*((volatile uint8_t*)0x5A)



#define SREG	*((volatile uint8_t*)0x5F)


#endif /* REGISTER_H_ */