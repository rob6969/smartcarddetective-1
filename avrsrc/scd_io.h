/** \file
 *	\brief scd_io.h header file
 *
 *  This file provides the function definitions for all micro-controller
 *  I/O functions, including control of LCD, leds and buttons
 *
 *  Copyright (C) 2010 Omar Choudary (osc22@cam.ac.uk)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 */

#ifndef _SCD_IO_H_
#define _SCD_IO_H_

#include<stdio.h>

/// Delay of LCD commands
#define LCD_COMMAND_DELAY 40

/// value for Button A in result from GetButton function
#define BUTTON_A 0x01

/// value for Button B in result from GetButton function
#define BUTTON_B 0x02

/// value for Button C in result from GetButton function
#define BUTTON_C 0x04

/// value for Button D in result from GetButton function
#define BUTTON_D 0x08

// this is needed for the delay on the new avr-libc-1.7.0
#ifndef __DELAY_BACKWARD_COMPATIBLE__
#define __DELAY_BACKWARD_COMPATIBLE__
#endif


/* Led functions */

/// Turn on Led1
void Led1On();

/// Turn on Led2
void Led2On();

/// Turn on Led3
void Led3On();

/// Turn on Led4
void Led4On();

/// Turn off Led1
void Led1Off();

/// Turn off Led2
void Led2Off();

/// Turn off Led3
void Led3Off();

/// Turn off Led4
void Led4Off();

/* Other signals */
void T_C4On();
void T_C8On();
void T_C4Off();
void T_C8Off();
void JTAG_P1On();
void JTAG_P3On();
void JTAG_P1Off();
void JTAG_P3Off();

/* Button functions */

/// Get status of button A
uint8_t GetButtonA();

/// Get status of button B
uint8_t GetButtonB();

/// Get status of button C
uint8_t GetButtonC();

/// Get status of button D
uint8_t GetButtonD();

/// Returs a 1-hot encoded list of buttons pressed
uint8_t GetButton();

/* LCD functions */

///Return the state (on/off) of the LCD
uint8_t GetLCDState();

/// Set the state of the LCD
void SetLCDState(uint8_t state);

/// Initialize LCD
void InitLCD();

/// Display a string on LCD
void WriteStringLCD(char *string, uint8_t len);

/// Send character to the LCD display
int LcdPutchar(char c, FILE *unused);

/// Check if the LCD is working properly
uint8_t CheckLCD();

/// Switch LCD off
void LCDOff();

/// Switch LCD on
void LCDOn();


/* EEPROM stuff */

/// Write a single byte to EEPROM
void WriteSingleByteEEPROM(uint16_t addr, uint8_t data);

/// Read a single byte from EEPROM
uint8_t ReadSingleByteEEPROM(uint16_t addr);

/// Write multiple bytes to EEPROM
void WriteBytesEEPROM(uint16_t addr, uint8_t *data, uint16_t len);

/// Read multiple bytes from EEPROM
uint8_t* ReadBytesEEPROM(uint16_t addr, uint16_t len);

/// Read multiple bytes from EEPROM
uint16_t Read16bitRegister(volatile uint16_t *reg);

#endif // _SCD_IO_H_
