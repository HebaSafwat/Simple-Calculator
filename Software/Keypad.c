/*********************************************************************************************
 * Keypad.c
 *
 * Created on: 26/2/2020
 * Author:     Heba Safwat
 *********************************************************************************************/
/*********************************************************************************************
 *                                     Includes                                              *
 *********************************************************************************************/
#include"Keypad.h"

/*********************************************************************************************
 *                                   private functions prototype                             *
 *********************************************************************************************/
static uint8 keybad_4x4_adjust_number(uint8 switch_number);
static uint8 keybad_4x3_adjust_number(uint8 switch_number);

/*********************************************************************************************
 *                                     Functions Declaration                                 *
 *********************************************************************************************/
/*function to initialize the keypad*/
/*this function to configure the keypad port as input port and configure the type of the keypad*/
extern uint8 Keypad_get_pressed_key(void)
{
	/*configure the keypad*/
	keypad_config keypab_type;
	keypab_type = Configure_Keypad();

	uint8 row,column;
	while(1)
	{
		for(column = 0;column<keypab_type.num_column;column++)
		{
			/*only one column will be output and the others are input*/
			keypad_port_direction = (0b00010000<<column);
			/*put one on this output pin(column)*/
			keypad_port_output = ~(0b00010000<<column);
			/*loop on the rows to see which row read the zero*/
			for(row=0;row<keypab_type.num_row;row++)
			{
				if(BIT_IS_CLEAR(keypad_port_input,row))
				{
					/*now you get the row pin which read the zero from the column*/
					/*call the function to calculate the button value*/
					if(keypab_type.num_column == 3)
					{
						return keybad_4x3_adjust_number((row*keypab_type.num_column)+column +1);
					}
					else if(keypab_type.num_column == 4)
					{
						return keybad_4x4_adjust_number((row*keypab_type.num_column)+column +1);
					}
				}
			}
		}
	}
}

static uint8 keybad_4x4_adjust_number(uint8 switch_number)
{
	switch(switch_number)
	{
	case 1:
		return 7;
		break;
	case 2:
		return 8;
		break;
	case 3:
		return 9;
		break;
	case 4:
		return '%';
		break;
	case 5:
		return 4;
		break;
	case 6:
		return 5;
		break;
	case 7:
		return 6;
		break;
	case 8:
		return '*';
		break;
	case 9:
		return 1;
		break;
	case 10:
		return 2;
		break;
	case 11:
		return 3;
		break;
	case 12:
		return '-';
		break;
	case 13:
		return 13;            /*ASCII of the enter*/
		break;
	case 14:
		return 0;
		break;
	case 15:
		return '=';
		break;
	case 16:
		return '+';
		break;
	default:
		return switch_number;
	}
}

static uint8 keybad_4x3_adjust_number(uint8 switch_number)
{
	switch(switch_number)
	{
	case 10:
		return '*';
		break;
	case 11:
		return 0;
		break;
	case 12:
		return '#';
		break;
	default:
		return switch_number;
	}
}

