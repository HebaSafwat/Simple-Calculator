/**********************************************************************************************
 * Application.c
 *
 * Created on: 26/2/2020
 * Author:     Heba Safwat
 **********************************************************************************************/

/*********************************************************************************************
 *                                     Includes                                              *
 *********************************************************************************************/
#include "Keypad.h"
#include "LCD.h"

/*********************************************************************************************
 *                                     Global Variables                                      *
 *********************************************************************************************/
uint8 operation;               /*to hold the required operation*/
uint8 num[2];                  /*to hold the two numbers*/
uint8 result;                  /*to hold the result*/
uint8 i = 0;                   /*for looping and fill the array*/
uint8 flag = 0;                /*to make sure that the user enter only one operation*/

/*********************************************************************************************
 *                                     function Definitions                                  *
 *********************************************************************************************/
void Clear_AllGlopal_variables(void)
{
	i=0;
	flag = 0;               /*to be ready for receiving another operation*/
	result = 0;
	num[0] = 0;
	num[1] = 0;
	operation = 0;
	LCD_clear_screen();
}

/*********************************************************************************************
 *                                     Main Function                                         *
 *********************************************************************************************/
int main(void)
{
	uint8 key;                      /*to hold the pressed key from the keypad*/
	LCD_init();                     /*initialize the LCD*/

	while(1)
	{
		key = Keypad_get_pressed_key(); /* get the pressed key number */
		if((key <= 9) && (key >= 0))
		{
			LCD_display_integer(key);    /* display the pressed keypad switch */
			num[i]=num[i] * 10 + key;    /*case the number consist of more than one digit*/
		}
		else if((key=='+') || (key=='*') || (key=='-') || (key=='%'))
		{
			if(flag==0)
			{
				flag = 1;                 /*to prevent the user from entering other operation*/
				LCD_disply_character(key);
				operation = key;          /*store the operation*/
				i++;                      /*to start receiving the second number*/
			}
		}
		else if(key=='=')
		{
			if(flag !=1)                                //no operation entered.
			{
				Clear_AllGlopal_variables();
				LCD_display_string("invalid input");
			}
			else
			{
				LCD_disply_character(key);
				switch(operation)
				{
				case '+':
					result = num[0] + num[1];
					LCD_display_integer(result);
					break;
				case '-':
					result = num[0] - num[1];
					LCD_display_integer(result);
					break;
				case '*':
					result = num[0] * num[1];
					LCD_display_integer(result);
					break;
				case '%':
					if(num[0]%num[1]==0)          //no reminder
					{
						result = num[0] / num[1];
						LCD_display_integer(result);
					}
					else                          //reminder exist
					{
						result = num[0]*100/num[1];
						LCD_display_integer(result/100);
						LCD_disply_character('.');
						LCD_display_integer(result%100);
					}
					break;
				}
			}
		}
		if(key ==  13)                /*the user press the ON button*/
		{
			Clear_AllGlopal_variables();
		}
		_delay_ms(500);                    /* Press time */
	}
}


