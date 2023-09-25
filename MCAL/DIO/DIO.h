/*
 * DIO.h
 *
 * Created: 8/22/2023 11:46:53 PM
 *  Author: Bolis
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../Register.h"



typedef enum EN_pinValue_t{
	LOW = 0,
	High
}EN_pinValue_t;

typedef enum EN_directionStatus_t{
	INPUT =	0,
	OUTPUT
}EN_directionStatus_t;

typedef enum EN_portName_t{
	PORT_A = 0,
	PORT_B,
	PORT_C, 
	PORT_D
}EN_portName_t;

typedef enum EN_pinNumber_t{
	PIN0 = 0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}EN_pinNumber_t;

typedef enum EN_DIO_STATUS_t{
	DIO_OK	= 0,
	PIN_ERROR	  ,
	DIRECTION_ERROR,
	PORT_ERROR,
	VALUE_ERROR
}EN_DIO_STATUS_t;

typedef struct ST_DIO_Config_t{
	EN_portName_t portName;
	EN_pinNumber_t pinNumber;
	EN_directionStatus_t direction;
}ST_DIO_Config_t;

typedef struct ST_DIO_Data_Config_t{
	EN_portName_t portName;
	EN_pinNumber_t pinNumber;
}ST_DIO_Data_Config_t;


EN_DIO_STATUS_t MCAL_DIO_Init_Pin(ST_DIO_Config_t* DIO_Config);
EN_DIO_STATUS_t MCAL_DIO_Write_Pin(ST_DIO_Data_Config_t* DIO_Config,EN_pinValue_t pinValue);
EN_DIO_STATUS_t MCAL_DIO_Read_Pin(ST_DIO_Data_Config_t* DIO_Config,uint8_t* pinValue);
EN_DIO_STATUS_t MCAL_DIO_Toggle_Pin(ST_DIO_Data_Config_t* DIO_Config);

#endif /* DIO_H_ */