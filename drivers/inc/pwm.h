﻿/*!****************************************************************************
* @file    		pwm.h
* @author  		d_el
* @version 		V1.0
* @date    		02.05.2016, Storozhenko Roman
* @copyright 	GNU Public License
*/
#ifndef pwm_H
#define pwm_H

/*!****************************************************************************
* Include
*/
#include "stm32f3xx.h"
#include "board.h"
#include "gpio.h"

/*!****************************************************************************
* User define
*/
#define PWM_FAN_FREQ    20000   //[Hz]
#define PWM_LED_FREQ    2000    //[Hz]

/*!****************************************************************************
* User enum
*/

/*!****************************************************************************
* User typedef
*/

/*!****************************************************************************
* Extern viriables
*/

/*!****************************************************************************
* Macro functions
*/
/*!****************************************************************************
* @brief    set duty cycle  [X_XX %]
*/
#define FanPwmSet(x)    TIM15->CCR2 = ((uint32_t)TIM15->ARR * x) / 1000
#define LedPwmSet(x)    TIM12->CCR1 = ((uint32_t)TIM12->ARR * x) / 1000

/*!****************************************************************************
* Prototypes for the functions
*/
void pwmFan_init(void);
void Init_PwmLed(void);

#endif //pwm_H
/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/