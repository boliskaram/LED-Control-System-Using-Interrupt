/*
 * BUTTON.c
 *
 * Created: 8/22/2023 11:49:46 PM
 *  Author: Bolis
 */ 

#include "BUTTON.h"

EN_BUTTON_STATUS_t ECUAL_BUTTON_Init(ST_BUTTON_Config_t* Button_Config){

	EN_BUTTON_STATUS_t buttonStatus = BUTTON_OK;
	EN_DIO_STATUS_t DIO_Error = DIO_OK ;
	
	ST_DIO_Config_t DIO_Config;
	
	DIO_Config.direction = INPUT ;
	DIO_Config.portName = Button_Config->buttonPort;
	DIO_Config.pinNumber = Button_Config->buttonPin;
	DIO_Error=MCAL_DIO_Init_Pin(&DIO_Config);
	
	if (DIO_Error == PORT_ERROR)
	{
		buttonStatus = BUTTON_PORT_ERROR;
	}
	else if (DIO_Error == PIN_ERROR)
	{
		buttonStatus = BUTTON_PIN_ERROR;
	}
	else{
		buttonStatus = BUTTON_OK;
	}
	
	return buttonStatus;
}

EN_BUTTON_STATUS_t ECUAL_BUTTON_Read(ST_BUTTON_Config_t* Button_Config , EN_pinValue_t* pinValue ){
	
	EN_BUTTON_STATUS_t buttonStatus = BUTTON_OK;
	EN_DIO_STATUS_t DIO_Error = DIO_OK ;
	ST_DIO_Data_Config_t DIO_Config;
	DIO_Config.portName = Button_Config->buttonPort;
	DIO_Config.pinNumber = Button_Config->buttonPin;
	
	
	DIO_Error = MCAL_DIO_Read_Pin(&DIO_Config,pinValue);
	
	if (DIO_Error == PORT_ERROR)
	{
		buttonStatus = BUTTON_PORT_ERROR;
	}
	else if (DIO_Error == PIN_ERROR)
	{
		buttonStatus = BUTTON_PIN_ERROR;
	}
	else{
		buttonStatus = BUTTON_OK;
		
	}
	return buttonStatus ;
}