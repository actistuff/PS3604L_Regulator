﻿/*!****************************************************************************
  	  _____   _____ ____    __   ___  _  _   _      _____                     *
 	 |  __ \ / ____|___ \  / /  / _ \| || | | |    |  __ \                    *
 	 | |__) | (___   __) |/ /_ | | | | || |_| |    | |__) |                   *
 	 |  ___/ \___ \ |__ <| '_ \| | | |__   _| |    |  _  /                    *
 	 | |     ____) |___) | (_) | |_| |  | | | |____| | \ \                    *
 	 |_|    |_____/|____/ \___/ \___/   |_| |______|_|  \_\                   *
*                                                                             *
* @mainpage                                                                   *
* @file    		main.c                                                        *
* @author  		Storozhenko Roman - D_EL                                      *
* @version 		V2.0                                                          *
* @date    		19-12-2014                                                    *
* @brief   		Main program body                                             *
* @copyright 	GNU Public License											  *
******************************************************************************/

/*!****************************************************************************
* Include
*/
#include "main.h"
#include "IQmathLib.h"
#include "debugCore.h"
#include "semihosting.h"

uint8_t iii = 1;

/*!****************************************************************************
* @brief    main function
*/
void main(void){
    Init_Hard();

    LED_ON();
    
    //Great mutex, semaphore, task, start scheduler
    OSinit();

    while(1){
    	__NOP();
    }
}	
	
/*************** GNU GPL ************** END OF FILE ********* D_EL ***********/