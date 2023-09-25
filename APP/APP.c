/*
 * APP.c
 *
 * Created: 8/26/2023 3:57:24 AM
 *  Author: Bolis
 */ 


#include "APP.h"

static uint8_t Count = 0 ;
EN_LED_STATUS_t LED_ERROR = LED_OK ;
EN_EXTI_STATUS_t EXTI_ERROR = EXTI_OK ;

void EXTI0_ISR(void){
	if (Count == 8)
	{
		Count = 1; 
	}
	else
	{
		Count++ ;
	}
}

void APP_Init(void){
	
	//---------------------------------------------------------------------------------------------	
	//------------------------------------- INIT LED peripheral -----------------------------------
	//---------------------------------------------------------------------------------------------
	
	ST_LED_Config_t LED_Config;
	
	
	LED_Config.LED_Port = PORT_A ;
	LED_Config.LED_Pin = PIN0 ;
	LED_ERROR = ECUAL_LED_Init(&LED_Config);
	
	LED_Config.LED_Port = PORT_A ;
	LED_Config.LED_Pin = PIN1 ;
	LED_ERROR = ECUAL_LED_Init(&LED_Config);
	
	LED_Config.LED_Port = PORT_A ;
	LED_Config.LED_Pin = PIN2 ;
	LED_ERROR = ECUAL_LED_Init(&LED_Config);
	
	LED_Config.LED_Port = PORT_A ;
	LED_Config.LED_Pin = PIN3 ;
	LED_ERROR = ECUAL_LED_Init(&LED_Config);
	
	LED_Config.LED_Port = PORT_B ;
	LED_Config.LED_Pin = PIN0 ;
	LED_ERROR = ECUAL_LED_Init(&LED_Config);
	
	LED_Config.LED_Port = PORT_B ;
	LED_Config.LED_Pin = PIN1 ;
	LED_ERROR = ECUAL_LED_Init(&LED_Config);
	
	//---------------------------------------------------------------------------------------------	
	//------------------------------------- INIT EXTI peripheral ----------------------------------
	//---------------------------------------------------------------------------------------------
	
	
	ST_EXTI_Config_t EXTI_config;
	
	EXTI_config.EXTI_NAME = INT_0;
	EXTI_config.EXTI_MODE = RISING_EDGE_MODE;
	EXTI_config.P_IRQ_CallBack = EXTI0_ISR;
	EXTI_ERROR = MCAL_EXTI_Init(&EXTI_config);
}
	
	
void APP_Update(void){
	
	ST_LED_Config_t LED_Config;
		
	if (EXTI_ERROR == EXTI_NAME_ERROR )
	{
		LED_Config.LED_Port = PORT_B ;
		LED_Config.LED_Pin = PIN0;
		LED_ERROR = ECUAL_LED_ON(&LED_Config);
	}
	else if (EXTI_ERROR == EXTI_MODE_ERROR)
	{
		LED_Config.LED_Port = PORT_B ;
		LED_Config.LED_Pin = PIN1;
		LED_ERROR = ECUAL_LED_ON(&LED_Config);
	}
	else
	{
		if(Count >= 1 && Count <= 4){
			LED_Config.LED_Port = PORT_A ;
			LED_Config.LED_Pin = PIN0 + (Count-1) ;
			LED_ERROR = ECUAL_LED_ON(&LED_Config);
		}
		else if(Count >= 5 && Count <= 8 ){
			LED_Config.LED_Port = PORT_A ;
			LED_Config.LED_Pin = PIN0 + (Count-5);
			LED_ERROR = ECUAL_LED_OFF(&LED_Config);
		}
	}
	
	
}


