﻿/*!****************************************************************************
 * @file		crc.h
 * @author		d_el - Storozhenko Roman
 * @version		V2.0
 * @date		12.12.2017
 * @copyright	Copyright (C) 2017 Storozhenko Roman
 *				All rights reserved
 *				This software may be modified and distributed under the terms
 *				of the BSD license.	 See the LICENSE file for details
 */

#ifndef crc_H
#define crc_H

/*!****************************************************************************
* Include
*/
#include "stdint.h"

/*!****************************************************************************
 * Enumeration
 */
typedef enum{
	crc_modbus,
	crc_can,
	crc_1wire
}crc_type;

/*!****************************************************************************
 * Typedef
 */
typedef struct{
	uint16_t	table[256];
	uint16_t	initVal;
	uint16_t	finalXorValue;
}crc16Struct_type;

typedef struct{
	uint8_t		table[256];
	uint8_t		initVal;
	uint8_t		finalXorValue;
}crc8Struct_type;

/*!****************************************************************************
 * Exported variables
 */
extern crc16Struct_type crcModBus;
extern crc16Struct_type crcCan;
extern crc8Struct_type crc1Wire;

/*!****************************************************************************
 * Function declaration
 */
uint16_t crc16Calc(crc16Struct_type *dat, void *src, uint32_t len);
uint16_t crc16CalcWithInit(crc16Struct_type *dat, void *src, uint32_t len, uint16_t initVal);
uint8_t crc8Calc(crc8Struct_type *dat, void *src, uint32_t len);

#endif	//crc_H
/***************** Copyright (C) Storozhenko Roman ******* END OF FILE *******/
