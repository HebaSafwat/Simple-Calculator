/**********************************************************************************************
 * LCD.h
 *
 * Created on: 26/2/2020
 * Author:     Heba Safwat
 **********************************************************************************************/

#ifndef LCD_H_
#define LCD_H_
/*********************************************************************************************
 *                                     Includes                                              *
 *********************************************************************************************/
#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"
#include "LCD_config.h"

/***********************************************************************************************
 *                                     Preprocessor Macros                                    *
 ***********************************************************************************************/

/* LCD HW Pins */
#define RS                PB4
#define RW                PB5
#define E                 PB6
#define LCD_CTRL_PORT     PORTB
#define LCD_CTRL_PORT_DIR DDRB
#define LCD_DATA_PORT     PORTD
#define LCD_DATA_PORT_DIR DDRD

/*********************************************************************************************
 *                               Functions Prototype                                         *
 *********************************************************************************************/
/*function to initialize the LCD*/
extern void LCD_init(void);
/*function to send a command to the LCD*/
extern void LCD_sendCommand(uint8 command);
/*function to display a character in the LCD*/
extern void LCD_disply_character(char character);
/*function to display a string in the LCD*/
extern void LCD_display_string(const char *string);
/*function to display integer in the LCD*/
extern void LCD_display_integer(uint8 number);
/*function to go to specific row and column in the LCD*/
extern void LCD_goToRowColumn(uint8 row,uint8 column);
/*function to display a string in specific row and column in the LCD*/
extern void LCD_displayStringRowColumn(uint8 row,uint8 column,const char *str);
/*function to clear the LCD*/
extern void LCD_clear_screen(void);

#endif /* LCD_H_ */
