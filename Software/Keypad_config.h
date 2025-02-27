/*
 * Keypad_config.h
 *
 * Created on: 26/2/2020
 * Author:     Heba Safwat
 **********************************************************************************************/


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

/*********************************************************************************************
 *                                     Includes                                              *
 *********************************************************************************************/
#include"std_types.h"

/*********************************************************************************************
 *                                 Data Structure                                            *
 *********************************************************************************************/
/*structure for the type of the Keypad (4*4 keypad) or (4*3keypad)*/
typedef struct
{
	uint8 num_column;
	uint8 num_row;
}keypad_config;


/*********************************************************************************************
 *                               Functions Prototype                                         *
 *********************************************************************************************/
/*function to configure the Keypad*/
extern keypad_config Configure_Keypad(void);


#endif /* KEYPAD_CONFIG_H_ */
