/*
 * EXTI.h
 *
 * Created: 8/30/2023 7:59:54 PM
 *  Author: Bolis
 */ 


#ifndef EXTI_H_
#define EXTI_H_

#include "../DIO/DIO.h"
#include "../../Types.h"
#include "../../Register.h"

#define Global_Interrupt_BIT	7

#define ISC00		0
#define ISC01		1
#define ISC10		2
#define ISC11		3

#define INT0_Enable_BIT		6
#define INT1_Enable_BIT		7
			

typedef enum EN_EXTI_STATUS_t{
	EXTI_OK			= 0	,
	EXTI_NAME_ERROR		,
	EXTI_MODE_ERROR		,
}EN_EXTI_STATUS_t;

typedef enum EN_EXTI_NAME_t{
	INT_0 = 0,
	INT_1
}EN_EXTI_NAME_t;

typedef enum EN_EXTI_Mode_t{
	LOW_LEVEL_MODE		= 0,
	LOGICAL_CHANGE_MODE	   ,
	FALLING_EDGE_MODE	   ,
	RISING_EDGE_MODE
}EN_EXTI_Mode_t;

typedef struct ST_EXTI_Config_t{
	EN_EXTI_NAME_t EXTI_NAME;
	EN_EXTI_Mode_t EXTI_MODE;
	void (*P_IRQ_CallBack) (void);
}ST_EXTI_Config_t;


EN_EXTI_STATUS_t MCAL_EXTI_Init(ST_EXTI_Config_t* EXTI_config);



#endif /* EXTI_H_ */