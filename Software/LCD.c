/**********************************************************************************************
 * LCD.c
 *
 * Created on: 26/2/2020
 * Author:     Heba Safwat
 **********************************************************************************************/

/*********************************************************************************************
 *                                     Includes                                              *
 *********************************************************************************************/
#include "LCD.h"
/*********************************************************************************************
 *                                     Global Variables                                              *
 *********************************************************************************************/
LCD_config LCD;              /*to program the LCD according to your configuration*/

/********************************************************************************************
 *                                   Functions Definitions                                  *
 ********************************************************************************************/
/*function to initialize the LCD*/
void LCD_init(void)
{
	LCD_CTRL_PORT_DIR |= (1<<E) | (1<<RS) | (1<<RW); /* Configure the control pins(E,RS,RW) as output pins */

	/*structure to hold the configuration*/

	LCD = Configure_LCD();

	if(LCD.type == LCD_Four_BIT_MODE)
	{
        if(LCD.bit_mode==Upper_mode)
        {
        	LCD_DATA_PORT_DIR |= 0xF0; /* Configure the highest 4 bits of the data port as output pins */
        }
		else if(LCD.bit_mode==lower_mode)
		{
			LCD_DATA_PORT_DIR |= 0x0F; /* Configure the lowest 4 bits of the data port as output pins */
		}
		LCD_sendCommand(LCD_Four_BIT_MODE); /* initialize LCD in 4-bit mode */
	}
	else if(LCD.type == TWO_LINE_LCD_Eight_BIT_MODE)
	{
		LCD_DATA_PORT_DIR = 0xFF;           /* Configure the data port as output port */
	}
	LCD_sendCommand(LCD.type);
	LCD_sendCommand(LCD.cursor);
	LCD_sendCommand(CLEAR_COMMAND);
}
/*function to send a command to the LCD*/
void LCD_sendCommand(uint8 command)
{
	LCD = Configure_LCD();
	CLEAR_BIT(LCD_CTRL_PORT,RS); /* Instruction Mode RS=0 */
	CLEAR_BIT(LCD_CTRL_PORT,RW); /* write data to LCD so RW=0 */
	_delay_ms(1); /* delay for processing Tas = 50ns */
	SET_BIT(LCD_CTRL_PORT,E); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
	if(LCD.type ==LCD_Four_BIT_MODE )
	{
		/* out the highest 4 bits of the required command to the data bus D4 --> D7 */
		if(LCD.bit_mode==Upper_mode)
		{
			LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (command & 0xF0);
		}
		else if(LCD.bit_mode==lower_mode)
		{
			LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | ((command & 0xF0) >> 4);
		}
		_delay_ms(1); /* delay for processing Tdsw = 100ns */
		CLEAR_BIT(LCD_CTRL_PORT,E); /* disable LCD E=0 */
		_delay_ms(1); /* delay for processing Th = 13ns */
		SET_BIT(LCD_CTRL_PORT,E); /* Enable LCD E=1 */
		_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
		/* out the lowest 4 bits of the required command to the data bus D4 --> D7 */
		if(LCD.bit_mode==Upper_mode)
		{
			LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | ((command & 0x0F) << 4);
		}
	    else if(LCD.bit_mode==lower_mode)
	    {
	    	LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | (command & 0x0F);
	    }
		_delay_ms(1); /* delay for processing Tdsw = 100ns */
		CLEAR_BIT(LCD_CTRL_PORT,E); /* disable LCD E=0 */
		_delay_ms(1); /* delay for processing Th = 13ns */
	}
	else if (LCD.type ==TWO_LINE_LCD_Eight_BIT_MODE)
	LCD_DATA_PORT = command; /* out the required command to the data bus D0 --> D7 */
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	CLEAR_BIT(LCD_CTRL_PORT,E); /* disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
}


/*function to display a character in the LCD*/
void LCD_disply_character(char data)
{
	LCD = Configure_LCD();
	SET_BIT(LCD_CTRL_PORT,RS); /* Data Mode RS=1 */
	CLEAR_BIT(LCD_CTRL_PORT,RW); /* write data to LCD so RW=0 */
	_delay_ms(1); /* delay for processing Tas = 50ns */
	SET_BIT(LCD_CTRL_PORT,E); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
	if(LCD.type ==LCD_Four_BIT_MODE)
	{
       if(LCD.bit_mode==Upper_mode)
       {
    	   LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (data & 0xF0);
       }
       else if(LCD.bit_mode==lower_mode)
       {
    	   LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | ((data & 0xF0) >> 4);
       }
	   _delay_ms(1); /* delay for processing Tdsw = 100ns */
	   CLEAR_BIT(LCD_CTRL_PORT,E); /* disable LCD E=0 */
	   _delay_ms(1); /* delay for processing Th = 13ns */
	   SET_BIT(LCD_CTRL_PORT,E); /* Enable LCD E=1 */
	   _delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	   /* out the lowest 4 bits of the required data to the data bus D4 --> D7 */
	   if(LCD.bit_mode==Upper_mode)
	   {
		   LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | ((data & 0x0F) << 4);
	   }
       else if(LCD.bit_mode==lower_mode)
       {
    	   LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | (data & 0x0F);
       }
	   _delay_ms(1); /* delay for processing Tdsw = 100ns */
	   CLEAR_BIT(LCD_CTRL_PORT,E); /* disable LCD E=0 */
	  _delay_ms(1); /* delay for processing Th = 13ns */
    }

	else if(LCD.type ==TWO_LINE_LCD_Eight_BIT_MODE)
	{
		LCD_DATA_PORT = data; /* out the required command to the data bus D0 --> D7 */
		_delay_ms(1); /* delay for processing Tdsw = 100ns */
		CLEAR_BIT(LCD_CTRL_PORT,E); /* disable LCD E=0 */
		_delay_ms(1); /* delay for processing Th = 13ns*/
	}
}

/*function to display a string in the LCD*/
void LCD_display_string(const char *string)
{
	uint8 i = 0;
	while(string[i] != '\0')
	{
		LCD_disply_character(string[i]);
		i++;
	}
}

/*function to display integer in the LCD*/
void LCD_display_integer(uint8 data)
{
   char buff[16];            /* String to hold the ASCII result */
   itoa(data,buff,10);       /* 10 for decimal */
   LCD_display_string(buff);
}

/*function to go to specific row and column in the LCD*/
void LCD_goToRowColumn(uint8 row,uint8 col)
{
	uint8 Address;
	LCD = Configure_LCD();
	/* first of all calculate the required address */
	switch(row)
	{
		case 0:
				Address=col;
				break;
		case 1:
				Address=col+0x40;
				break;
		case 2:
				Address=col+0x10;
				break;
		case 3:
				Address=col+0x50;
				break;
	}					
	/* to write to a specific address in the LCD 
	 * we need to apply the corresponding command 0b10000000+Address */
	LCD_sendCommand(Address | SET_CURSOR_LOCATION); 
}

/*function to display a string in specific row and column in the LCD*/
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_goToRowColumn(row,col); /* go to to the required LCD position */
	LCD_display_string(Str); /* display the string */
}

/*function to clear the LCD*/
void LCD_clear_screen(void)
{
	LCD_sendCommand(CLEAR_COMMAND); //clear display 
}
