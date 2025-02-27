/**********************************************************************************************
 * micro_config.h
 *
 * Created on: 26/2/2020
 * Author:     Heba Safwat
 **********************************************************************************************/
#ifndef MICRO_CONFIG_H_
#define MICRO_CONFIG_H_

#ifndef F_CPU
#define F_CPU 1000000UL //1MHz Clock frequency
#endif
/**********************************************************************************************
 *                                         Includes                                           *
 **********************************************************************************************/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#endif /* MICRO_CONFIG_H_ */
