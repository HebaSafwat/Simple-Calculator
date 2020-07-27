/*
 * Keypad_config.c
 *
 * Created on: 26/2/2020
 * Author:     Heba Safwat
 * Description: this file contain the configuration of the Keypad:
 *              =>number of rows.
 *              =>number of columns.
 **********************************************************************************************/

/*********************************************************************************************
 *                                     Includes                                              *
 *********************************************************************************************/
#include"Keypad_config.h"

/*********************************************************************************************
 *                                     Functions Definitions                                 *
 *********************************************************************************************/
extern keypad_config Configure_Keypad(void)
{
	keypad_config keypad_type;
	/*initialize the keypad type*/
	keypad_type.num_column = 4;         //four column
	keypad_type.num_row = 4;            //four rows
	return keypad_type;
}


