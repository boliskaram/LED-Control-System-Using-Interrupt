/*
 * LED.h
 *
 * Created: 8/22/2023 11:50:18 PM
 *  Author: Bolis
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/DIO.h"


typedef enum EN_LED_STATUS_t{
	LED_OK = 0 ,
	LED_PIN_ERROR,
	LED_PORT_ERROR
}EN_LED_STATUS_t;

typedef struct ST_LED_Config_t{
	
	EN_pinNumber_t LED_Pin;
	EN_portName_t LED_Port;

}ST_LED_Config_t;


EN_LED_STATUS_t ECUAL_LED_Init(ST_LED_Config_t* LED_Config);
EN_LED_STATUS_t ECUAL_LED_ON(ST_LED_Config_t* LED_Config);
EN_LED_STATUS_t ECUAL_LED_OFF(ST_LED_Config_t* LED_Config);
EN_LED_STATUS_t ECUAL_LED_Toggle(ST_LED_Config_t* LED_Config);


#endif /* LED_H_ */