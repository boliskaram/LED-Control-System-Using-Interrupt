/*
 * BUTTON.h
 *
 * Created: 8/22/2023 11:50:03 PM
 *  Author: Bolis
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/EXTI/EXTI.h"
#include "../../MCAL/DIO/DIO.h"

typedef enum EN_BUTTON_STATUS_t{
	BUTTON_OK = 0 ,
	BUTTON_PIN_ERROR,
	BUTTON_PORT_ERROR
}EN_BUTTON_STATUS_t;


typedef struct ST_BUTTON_Config_t{
	EN_pinNumber_t buttonPin;
	EN_portName_t buttonPort;
}ST_BUTTON_Config_t;


EN_BUTTON_STATUS_t ECUAL_BUTTON_Init(ST_BUTTON_Config_t* LED_Config);
EN_BUTTON_STATUS_t ECUAL_BUTTON_Read(ST_BUTTON_Config_t* LED_Config , uint8_t* pinValue );


#endif /* BUTTON_H_ */