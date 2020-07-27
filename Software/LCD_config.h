/**********************************************************************************************
 * LCD_config.h
 *
 * Created on: 26/2/2020
 * Author:     Heba Safwat
 **********************************************************************************************/


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*********************************************************************************************
 *                                     Includes                                              *
 *********************************************************************************************/

/*********************************************************************************************
 *                                 Data Structure                                            *
 *********************************************************************************************/
typedef enum
{
	LCD_Four_BIT_MODE = 0x02,
	ONE_LINE_LCD_Eight_BIT_MODE = 0x30,
	TWO_LINE_LCD_Eight_BIT_MODE = 0x38,
	TWO_LINE_LCD_Four_BIT_MODE = 0x28
}LCD_type;

typedef enum
{
	Upper_mode = 0x00,
	lower_mode = 0x01
}four_bit_mode;

typedef enum
{
	CURSOR_OFF = 0x0C,
	CURSOR_ON = 0x0E
}cursor_mode;

enum command
{
	CLEAR_COMMAND = 0x01,
	SET_CURSOR_LOCATION = 0x80
};


typedef struct
{
	LCD_type type;                  /*4_bit or 8_bit data mode */
	cursor_mode cursor;             /*cursor on or off*/
	four_bit_mode bit_mode;         /*case four bit mode:upper mode or lower mode*/
}LCD_config;
/*********************************************************************************************
 *                                 Common MAcros                                             *
 *********************************************************************************************/

/*********************************************************************************************
 *                               Functions Prototype                                         *
 *********************************************************************************************/
/*function to configure the LCD*/
LCD_config Configure_LCD(void);

#endif /* LCD_CONFIG_H_ */
