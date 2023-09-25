/*
 * LED.c
 *
 * Created: 8/22/2023 11:50:29 PM
 *  Author: Bolis
 */ 


#include "LED.h"

EN_LED_STATUS_t ECUAL_LED_Init(ST_LED_Config_t* LED_Config){
	EN_LED_STATUS_t errorStatus = LED_OK ;
	EN_DIO_STATUS_t DIO_Error = DIO_OK ;
	ST_DIO_Config_t DIO_Config;
	DIO_Config.direction = OUTPUT ;
	DIO_Config.portName = LED_Config->LED_Port;
	DIO_Config.pinNumber = LED_Config->LED_Pin;
	
	DIO_Error = MCAL_DIO_Init_Pin(&DIO_Config);
	
	if(DIO_Error == PIN_ERROR)
	{
		errorStatus = LED_PIN_ERROR ;
	}
	else if(DIO_Error == PORT_ERROR)
	{
		errorStatus = LED_PORT_ERROR ;
	}
	else
	{
		errorStatus = LED_OK ;
	}
	
	return errorStatus ;
}


EN_LED_STATUS_t ECUAL_LED_ON(ST_LED_Config_t* LED_Config){
	
	EN_LED_STATUS_t errorStatus = LED_OK ;
	EN_DIO_STATUS_t DIO_Error = DIO_OK ;
	
	ST_DIO_Data_Config_t DIO_DConfig;
	DIO_DConfig.portName = LED_Config->LED_Port;
	DIO_DConfig.pinNumber = LED_Config->LED_Pin;
	
	DIO_Error = MCAL_DIO_Write_Pin(&DIO_DConfig,High);
	
	if(DIO_Error == PIN_ERROR){
		errorStatus = LED_PIN_ERROR ;
		}else if(DIO_Error == PORT_ERROR){
		errorStatus = LED_PORT_ERROR ;
		}else{
		errorStatus = LED_OK ;
	}
	return errorStatus ;
}


EN_LED_STATUS_t ECUAL_LED_OFF(ST_LED_Config_t* LED_Config){
	
	EN_LED_STATUS_t errorStatus = LED_OK ;
	EN_DIO_STATUS_t DIO_Error = DIO_OK ;

	ST_DIO_Data_Config_t DIO_DConfig;
	DIO_DConfig.portName = LED_Config->LED_Port;
	DIO_DConfig.pinNumber = LED_Config->LED_Pin;

	DIO_Error = MCAL_DIO_Write_Pin(&DIO_DConfig,LOW);

	if(DIO_Error == PIN_ERROR){
		errorStatus = LED_PIN_ERROR ;
		}else if(DIO_Error == PORT_ERROR){
		errorStatus = LED_PORT_ERROR ;
		}else{
		errorStatus = LED_OK ;
	}
	return errorStatus ;
}


EN_LED_STATUS_t ECUAL_LED_Toggle(ST_LED_Config_t* LED_Config){
	
	EN_LED_STATUS_t errorStatus = LED_OK ;
	EN_DIO_STATUS_t DIO_Error = DIO_OK ;

	ST_DIO_Data_Config_t DIO_DConfig;
	DIO_DConfig.portName = LED_Config->LED_Port;
	DIO_DConfig.pinNumber = LED_Config->LED_Pin;

	DIO_Error = MCAL_DIO_Toggle_Pin(&DIO_DConfig);

	if(DIO_Error == PIN_ERROR){
		errorStatus = LED_PIN_ERROR ;
		}else if(DIO_Error == PORT_ERROR){
		errorStatus = LED_PORT_ERROR ;
		}else{
		errorStatus = LED_OK ;
	}
	return errorStatus ;	
}

