/*
 * EXTI.c
 *
 * Created: 8/30/2023 7:59:41 PM
 *  Author: Bolis
 */ 


#include "EXTI.h"


void (*GP_EXTI_callback[2])(void) = {NULL,NULL} ;

static EN_EXTI_STATUS_t MCAL_EXTI_MODE(ST_EXTI_Config_t* EXTI_MODE_config)
{
	EN_EXTI_STATUS_t errorStatus = EXTI_OK ;
	
	if (EXTI_MODE_config->EXTI_NAME == INT_0)
	{
		if (EXTI_MODE_config->EXTI_MODE == LOW_LEVEL_MODE)
		{
			RESET_BIT(MCUCR,ISC00);
			RESET_BIT(MCUCR,ISC01);
		}
		else if (EXTI_MODE_config->EXTI_MODE == LOGICAL_CHANGE_MODE)
		{
			SET_BIT(MCUCR,ISC00);
			RESET_BIT(MCUCR,ISC01);
		}
		else if (EXTI_MODE_config->EXTI_MODE == FALLING_EDGE_MODE)
		{
			RESET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
		}
		else if (EXTI_MODE_config->EXTI_MODE == RISING_EDGE_MODE)
		{
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
		}
		else{
			errorStatus = EXTI_MODE_ERROR;
		}
	}
	
	else if (EXTI_MODE_config->EXTI_NAME == INT_1)
	{
		if (EXTI_MODE_config->EXTI_MODE == LOW_LEVEL_MODE)
		{
			RESET_BIT(MCUCR,ISC10);
			RESET_BIT(MCUCR,ISC11);
		}
		else if (EXTI_MODE_config->EXTI_MODE == LOGICAL_CHANGE_MODE)
		{
			SET_BIT(MCUCR,ISC10);
			RESET_BIT(MCUCR,ISC11);
		}
		else if (EXTI_MODE_config->EXTI_MODE == FALLING_EDGE_MODE)
		{
			RESET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
		}
		else if (EXTI_MODE_config->EXTI_MODE == RISING_EDGE_MODE)
		{
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
		}
		else{
			errorStatus = EXTI_MODE_ERROR;
		}
	}
	else{
		errorStatus = EXTI_NAME_ERROR;
	}
	
	return errorStatus ;
	
}

static EN_EXTI_STATUS_t MCAL_EXTI_Enable(ST_EXTI_Config_t* EXTI_config)
{
	EN_EXTI_STATUS_t errorStatus = EXTI_OK ;
	
	if (EXTI_config->EXTI_NAME == INT_0)
	{
		SET_BIT(GICR,INT0_Enable_BIT);
	}
	else if (EXTI_config->EXTI_NAME == INT_1)
	{
		SET_BIT(GICR,INT1_Enable_BIT);
	}
	else
	{
		errorStatus = EXTI_NAME_ERROR;
	}
	
	return errorStatus ;
}



EN_EXTI_STATUS_t MCAL_EXTI_Init(ST_EXTI_Config_t* EXTI_config){
	
	EN_EXTI_STATUS_t EXTI_ERROR_STATUS = EXTI_OK ;
	ST_DIO_Config_t DIO_config ; 
	
	SET_BIT(SREG , Global_Interrupt_BIT);
	
	if(EXTI_config->EXTI_NAME == INT_0)
	{
		DIO_config.direction = INPUT ;
		DIO_config.pinNumber = PIN2;
		DIO_config.portName = PORT_D;
		MCAL_DIO_Init_Pin(&DIO_config);
	}
	else if (EXTI_config->EXTI_NAME == INT_1)
	{
		DIO_config.direction = INPUT ;
		DIO_config.pinNumber = PIN3;
		DIO_config.portName = PORT_D;
		MCAL_DIO_Init_Pin(&DIO_config);
	}
	else
	{
		EXTI_ERROR_STATUS = EXTI_NAME_ERROR ;
	}
	if (EXTI_ERROR_STATUS == EXTI_OK)
	{
		EXTI_ERROR_STATUS = MCAL_EXTI_MODE(EXTI_config);
		if (EXTI_ERROR_STATUS == EXTI_OK)
		{
			EXTI_ERROR_STATUS = MCAL_EXTI_Enable(EXTI_config);
		}
		
	}
	
	
	
	GP_EXTI_callback[EXTI_config->EXTI_NAME] = EXTI_config->P_IRQ_CallBack;	
	
	return EXTI_ERROR_STATUS ;
}

void __vector_1(void) __attribute__((signal,used));
void __vector_1(void){
	if(GP_EXTI_callback[0] != NULL){
		GP_EXTI_callback[0]();
	}
}

void __vector_2(void) __attribute__((signal,used));
void __vector_2(void){
	if(GP_EXTI_callback[1] != NULL){
		GP_EXTI_callback[1]();
	}
}
