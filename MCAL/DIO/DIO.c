/*
 * DIO.c
 *
 * Created: 8/22/2023 11:46:41 PM
 *  Author: Bolis
 */ 
#include "DIO.h"

EN_DIO_STATUS_t MCAL_DIO_Init_Pin(ST_DIO_Config_t* DIO_Config){
	
	EN_DIO_STATUS_t errorStatus = DIO_OK;
	switch(DIO_Config->portName){
		
		case PORT_A:
			if(DIO_Config->direction == OUTPUT){
				if(DIO_Config->pinNumber >=0 && DIO_Config->pinNumber <=7 ){
					SET_BIT(DDRA,DIO_Config->pinNumber);
				}else{
					errorStatus = PIN_ERROR;
				}
			}else if(DIO_Config->direction == INPUT){
				if(DIO_Config->pinNumber >=0 && DIO_Config->pinNumber <=7 ){
					RESET_BIT(DDRA,DIO_Config->pinNumber);
				}else{
					errorStatus = PIN_ERROR;
				}
			}else{
				errorStatus = DIRECTION_ERROR ;
			}
			break;
			
		case PORT_B:
			if(DIO_Config->direction == OUTPUT){
				if(DIO_Config->pinNumber >=0 && DIO_Config->pinNumber <=7 ){
					SET_BIT(DDRB,DIO_Config->pinNumber);
				}else{
					errorStatus = PIN_ERROR;
				}
			}else if(DIO_Config->direction == INPUT){
				if(DIO_Config->pinNumber >=0 && DIO_Config->pinNumber <=7 ){
					RESET_BIT(DDRB,DIO_Config->pinNumber);
				}else{
					errorStatus = PIN_ERROR;
				}
			}else{
				errorStatus = DIRECTION_ERROR ;
			}
			break;
			
		case PORT_C:
			if(DIO_Config->direction == OUTPUT){
				if(DIO_Config->pinNumber >=0 && DIO_Config->pinNumber <=7 ){
					SET_BIT(DDRC,DIO_Config->pinNumber);
				}else{
					errorStatus = PIN_ERROR;
				}
			}else if(DIO_Config->direction == INPUT){
				if(DIO_Config->pinNumber >=0 && DIO_Config->pinNumber <=7 ){
					RESET_BIT(DDRC,DIO_Config->pinNumber);
				}else{
					errorStatus = PIN_ERROR;
				}		
			}else{
				errorStatus = DIRECTION_ERROR ;
			}
			break;
			
		case PORT_D:
			if(DIO_Config->direction == OUTPUT){
				if(DIO_Config->pinNumber >=0 && DIO_Config->pinNumber <=7 ){
					SET_BIT(DDRD,DIO_Config->pinNumber);
				}else{
					errorStatus = PIN_ERROR;
				}
			}else if(DIO_Config->direction == INPUT){
				if(DIO_Config->pinNumber >=0 && DIO_Config->pinNumber <=7 ){
					RESET_BIT(DDRD,DIO_Config->pinNumber);
				}else{
					errorStatus = PIN_ERROR;
				}
			}else{
				errorStatus = DIRECTION_ERROR ;
			}
			break;
		default:
			errorStatus = PORT_ERROR ;
			break;
	}
	return errorStatus ;
}


EN_DIO_STATUS_t MCAL_DIO_Write_Pin(ST_DIO_Data_Config_t* DIO_Config, EN_pinValue_t pinValue){
	
	EN_DIO_STATUS_t errorStatus = DIO_OK;
		
	switch(DIO_Config->portName){
		case PORT_A:
			if(DIO_Config->pinNumber >=0 && DIO_Config->pinNumber <=7 ){
				if(pinValue==High){
					SET_BIT(PORTA,DIO_Config->pinNumber);
				}else if(pinValue==LOW){
					RESET_BIT(PORTA,DIO_Config->pinNumber);
				}else{
					errorStatus = VALUE_ERROR;
				}
				
			}else{
				errorStatus = PIN_ERROR;
			}
			break;
			
		case PORT_B:
			if(DIO_Config->pinNumber >=0 && DIO_Config->pinNumber <=7 ){
				if(pinValue==High){
					SET_BIT(PORTB,DIO_Config->pinNumber);
				}else if(pinValue==LOW){
					RESET_BIT(PORTB,DIO_Config->pinNumber);
				}else{
					errorStatus = VALUE_ERROR;
				}
			}else{
				errorStatus = PIN_ERROR;
			}
			break;
			
		case PORT_C:
			if(DIO_Config->pinNumber >=0 && DIO_Config->pinNumber <=7 ){
				if(pinValue==High){
					SET_BIT(PORTC,DIO_Config->pinNumber);
				}else if(pinValue==LOW){
					RESET_BIT(PORTC,DIO_Config->pinNumber);
				}else{
					errorStatus = VALUE_ERROR;
				}
			}else{
				errorStatus = PIN_ERROR;
			}
			break;
		
		case PORT_D:
			if(DIO_Config->pinNumber >=0 && DIO_Config->pinNumber <=7 ){
				if(pinValue==High){
					SET_BIT(PORTD,DIO_Config->pinNumber);
				}else if(pinValue==LOW){
					RESET_BIT(PORTD,DIO_Config->pinNumber);
				}else{
					errorStatus = VALUE_ERROR;
				}
			}else{
				errorStatus = PIN_ERROR;
			}
			break;
			
		default:
			errorStatus =PORT_ERROR;
			break;
	}
	return errorStatus;
}

EN_DIO_STATUS_t MCAL_DIO_Read_Pin(ST_DIO_Data_Config_t* DIO_Config,EN_pinValue_t* pinValue){
	
	EN_DIO_STATUS_t errorStatus = DIO_OK;
		
	switch(DIO_Config->portName){

		case PORT_A:
			if(DIO_Config->pinNumber >=0 && DIO_Config->pinNumber <=7 ){
				*pinValue = READ_BIT(PINA,DIO_Config->pinNumber);
			}else{
				errorStatus = PIN_ERROR;
			}
			break;
			
		case PORT_B:
			if(DIO_Config->pinNumber >=0 && DIO_Config->pinNumber <=7 ){
				*pinValue = READ_BIT(PINB,DIO_Config->pinNumber);
			}else{
				errorStatus = PIN_ERROR;
			}
			break;
			
		case PORT_C:
			if(DIO_Config->pinNumber >=0 && DIO_Config->pinNumber <=7 ){
				*pinValue = READ_BIT(PINC,DIO_Config->pinNumber);
			}else{
				errorStatus = PIN_ERROR;
			}
			break;
			
		case PORT_D:
			if(DIO_Config->pinNumber >=0 && DIO_Config->pinNumber <=7 ){
				*pinValue = READ_BIT(PIND,DIO_Config->pinNumber);
			}else{
				errorStatus = PIN_ERROR;
			}
			break;
		default:
			errorStatus =PORT_ERROR;
			break;
	}
	return errorStatus;
}

EN_DIO_STATUS_t MCAL_DIO_Toggle_Pin(ST_DIO_Data_Config_t* DIO_Config){
	
	EN_DIO_STATUS_t errorStatus = DIO_OK;
	
	switch(DIO_Config->portName){
		case PORT_A:
			if(DIO_Config->pinNumber >=0 && DIO_Config->pinNumber <=7 ){
				TOGGLE_BIT(PORTA,DIO_Config->pinNumber);
			}else{
				errorStatus = PIN_ERROR;
			}
			break;
		
		case PORT_B:
			if(DIO_Config->pinNumber >=0 && DIO_Config->pinNumber <=7 ){
				TOGGLE_BIT(PORTB,DIO_Config->pinNumber);
			}else{
				errorStatus = PIN_ERROR;
			}
			break;
		
		case PORT_C:
			if(DIO_Config->pinNumber >=0 && DIO_Config->pinNumber <=7 ){
				TOGGLE_BIT(PORTC,DIO_Config->pinNumber);
			}else{
				errorStatus = PIN_ERROR;
			}
			break;
		
		case PORT_D:
			if(DIO_Config->pinNumber >=0 && DIO_Config->pinNumber <=7 ){
				TOGGLE_BIT(PORTD,DIO_Config->pinNumber);
			}else{
				errorStatus = PIN_ERROR;
			}
			break;
			
		default:
			errorStatus =PORT_ERROR;
			break;
	}
	return errorStatus;
	
}