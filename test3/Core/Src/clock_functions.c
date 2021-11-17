/*
 * clock_functions.c
 *
 *  Created on: Nov 16, 2021
 *      Author: mohsen
 */

#include "clock_functions.h"
#include "stepper.h"
#include "DWT_Delay.h"
#include "eeprom.h"

#define STEPPER_MOTOR1   0
#define STEPPER_MOTOR2   1


extern uint32_t AD_RES[2];
extern uint32_t flag;
extern uint32_t flag_1;
extern uint32_t i;
extern uint8_t  chenge_Data;
extern uint8_t  buffer[30];
extern uint16_t n;


void set_id(void)
{
	if(chenge_Data==1)
	{
		HAL_FLASH_Unlock();

		EE_Init();

		EE_WriteVariable(0, buffer[1]);

		chenge_Data = 0;
	}
}

void start_clock(void)
{
	if(buffer[5*n+1] != n)
	{
		STEPPER_Stop(STEPPER_MOTOR1);
		STEPPER_Stop(STEPPER_MOTOR2);
		chenge_Data=0;
		return;
	}
	if(AD_RES[0] <100)
	{
		flag = 1;
	}
	if(AD_RES[1] <100)
	{
		flag_1 = 1;
	}
	if(flag!=1)
	{
		STEPPER_Step_NonBlocking(STEPPER_MOTOR1, 1, DIR_CW);
	}
	else
	{
		STEPPER_Stop(STEPPER_MOTOR1);
	}
	if(flag_1!=1)
	{
		STEPPER_Step_NonBlocking(STEPPER_MOTOR2, 1, DIR_CW);
	}
	else
	{
		STEPPER_Stop(STEPPER_MOTOR2);
	}
}

void spec_position(uint8_t Direction_1, uint32_t step_1 ,uint8_t Direction_2, uint32_t step_2)
{
	if(buffer[5*n+1] != n)
	{
		STEPPER_Stop(STEPPER_MOTOR1);
		STEPPER_Stop(STEPPER_MOTOR2);
		chenge_Data=0;
		return;
	}

	if(chenge_Data == 1 && i == 1 && buffer[5*n+1] == n)
	{
		STEPPER_Step_NonBlocking(STEPPER_MOTOR1, step_1, Direction_1);
		STEPPER_Step_NonBlocking(STEPPER_MOTOR2, step_2, Direction_2);
		chenge_Data = 0;
		i=0;
	}
}




