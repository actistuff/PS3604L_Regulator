﻿/*!****************************************************************************
* @file			ds18b20.c
* @author		d_el
* @version		V2.1
* @date			30.03.2014
* @date			04.08.2014	remade for 1wire on uart
* @brief		ds18b20 driver
* @copyright	GNU Public License
*/

/*!****************************************************************************
* Include
*/
#include "gpio.h"
#include "crc.h"
#include "ds18b20.h"

/*!****************************************************************************
* MEMORY
*/
volatile	tmpr_type	tem;

/*!****************************************************************************
* @brief	Init ds18b20
*/
ds18b20state_type ds18b20Init(void){
	owSt_type result;
	uint8_t buff[8];
	uint8_t crc = 0;

	result = ow_reset();
	if(result != 0){
		return result;
	}
	buff[0] = READ_ROM;
	result = ow_write(buff, 1);
	if(result != owOk){
		return result;
	}

	result = ow_read(buff, 8);
	if(result != owOk){
		return result;
	}

	crc = crc8Calc(&crc1Wire, buff, 8);
	if(crc != 0){
		return ds18b20st_errorCrc;
	}

	if(buff[0] != 0x28){
		return ds18b20st_notDs18b20;
	}

	//Set TH, TL, Resolution
	buff[0] = SKIP_ROM;
	buff[1] = WRITE_SCRATCHPAD;
	buff[2] = 127;				//TH
	buff[3] = 0;				//TL
	buff[4] = 0x7F;				//12bit 750ms	0.0625
	result = ow_reset();
	if(result != 0){
		return result;
	}

	result = ow_write(buff, 5);
	if(result != 0){
		return result;
	}

	buff[0] = SKIP_ROM;
	buff[1] = CONVERT_T;

	result = ow_reset();
	if(result != 0){
		return result;
	}

	result = ow_write(buff, 2);
	if(result != 0){
		return result;
	}
	return ds18b20st_ok;
}

/*!****************************************************************************
* @param	rl - low temperature register
* @param	rh - hight temperature register
* @retval	temperature X_XX
*/
uint16_t reg2tmpr(uint8_t rl, uint8_t rh){
	union{
		struct{
			uint8_t		rl;
			uint8_t		rh;
		}byte;
		uint16_t	word;
	}scratchpad;

	scratchpad.byte.rl = rl;
	scratchpad.byte.rh = rh;

	return (scratchpad.word * 10U + (16/2)) / 16;	//Деление с округлением
}

/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/
