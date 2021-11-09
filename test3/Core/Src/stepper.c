/*
 * stepper.c
 *
 *  Created on: ۱۸ آبان ۱۴۰۰
 *      Author: mohse
 */
#include "main.h"
#include "stepper.h"

extern uint32_t AD_RES[2];
extern uint32_t flag;
extern uint32_t flag_1 ;
uint32_t i=0;

void start_stepper(void)
{
	if(AD_RES[0] <100)
	{
		flag = 1;
	}
	if(AD_RES[1] <100)
	{
		flag_1 = 1;
	}

	if(flag == 0)
	{
		GPIOD->ODR = 0xC000;
		HAL_Delay(1);
		GPIOD->ODR = 0x6000;
		HAL_Delay(1);
		GPIOD->ODR = 0x3000;
		HAL_Delay(1);
		GPIOD->ODR = 0x9000;
		HAL_Delay(1);
	}
	if(flag_1 == 0)
	{
		GPIOB->ODR = 0xC000;
		HAL_Delay(1);
		GPIOB->ODR = 0x6000;
		HAL_Delay(1);
		GPIOB->ODR = 0x3000;
		HAL_Delay(1);
		GPIOB->ODR = 0x9000;
		HAL_Delay(1);
	}
}


void motor1 (uint8_t Direction, uint32_t step)
{
	if(Direction == 0)
	{
		for(int i =0 ;i<step ; i++)
		{
			GPIOD->ODR = 0xC000;
			HAL_Delay(1);
			GPIOD->ODR = 0x6000;
			HAL_Delay(1);
			GPIOD->ODR = 0x3000;
			HAL_Delay(1);
			GPIOD->ODR = 0x9000;
			HAL_Delay(1);
		}
	}
	else
	{
		for(int i =0 ;i<step ; i++)
		{
			GPIOD->ODR = 0x9000;
			HAL_Delay(1);
			GPIOD->ODR = 0x3000;
			HAL_Delay(1);
			GPIOD->ODR = 0x6000;
			HAL_Delay(1);
			GPIOD->ODR = 0xC000;
			HAL_Delay(1);
		}
	}

}

void motor2 (uint8_t Direction, uint32_t step)
{
	if(Direction == 0)
	{
		for(int i =0 ;i<step ; i++)
		{
			GPIOB->ODR = 0xC000;
			HAL_Delay(1);
			GPIOB->ODR = 0x6000;
			HAL_Delay(1);
			GPIOB->ODR = 0x3000;
			HAL_Delay(1);
			GPIOB->ODR = 0x9000;
			HAL_Delay(1);
		}
	}
	else
	{
		for(int i =0 ;i<step ; i++)
		{
			GPIOB->ODR = 0x9000;
			HAL_Delay(1);
			GPIOB->ODR = 0x3000;
			HAL_Delay(1);
			GPIOB->ODR = 0x6000;
			HAL_Delay(1);
			GPIOB->ODR = 0xC000;
			HAL_Delay(1);
		}
	}

}


void motors(uint8_t Direction_1, uint32_t step_1 ,uint8_t Direction_2, uint32_t step_2)
{
	if(Direction_1==0 && i<step_1 && Direction_2==0 && i<step_2)
	{
		GPIOD->ODR = 0xC000;
		HAL_Delay(1);
		GPIOB->ODR = 0xC000;
		HAL_Delay(1);
		GPIOD->ODR = 0x6000;
		HAL_Delay(1);
		GPIOB->ODR = 0x6000;
		HAL_Delay(1);
		GPIOD->ODR = 0x3000;
		HAL_Delay(1);
		GPIOB->ODR = 0x3000;
		HAL_Delay(1);
		GPIOD->ODR = 0x9000;
		HAL_Delay(1);
		GPIOB->ODR = 0x9000;
		HAL_Delay(1);
	}
	else if(Direction_1==0 && i<step_1 && Direction_2==1 && i<step_2)
	{
		GPIOD->ODR = 0xC000;
		HAL_Delay(1);
		GPIOB->ODR = 0x9000;
		HAL_Delay(1);
		GPIOD->ODR = 0x6000;
		HAL_Delay(1);
		GPIOB->ODR = 0x3000;
		HAL_Delay(1);
		GPIOD->ODR = 0x3000;
		HAL_Delay(1);
		GPIOB->ODR = 0x6000;
		HAL_Delay(1);
		GPIOD->ODR = 0x9000;
		HAL_Delay(1);
		GPIOB->ODR = 0xC000;
		HAL_Delay(1);
	}
	else if(Direction_1==0 && i<step_1 && i>=step_2)
	{
		GPIOD->ODR = 0xC000;
		HAL_Delay(2);
		GPIOD->ODR = 0x6000;
		HAL_Delay(2);
		GPIOD->ODR = 0x3000;
		HAL_Delay(2);
		GPIOD->ODR = 0x9000;
		HAL_Delay(2);

	}
	else if(Direction_1==1 && i<step_1 && Direction_2==0 && i<step_2)
	{
		GPIOD->ODR = 0x9000;
		HAL_Delay(1);
		GPIOB->ODR = 0xC000;
		HAL_Delay(1);
		GPIOD->ODR = 0x3000;
		HAL_Delay(1);
		GPIOB->ODR = 0x6000;
		HAL_Delay(1);
		GPIOD->ODR = 0x6000;
		HAL_Delay(1);
		GPIOB->ODR = 0x3000;
		HAL_Delay(1);
		GPIOD->ODR = 0xC000;
		HAL_Delay(1);
		GPIOB->ODR = 0x9000;
		HAL_Delay(1);

	}
	else if(Direction_1==1 && i<step_1 && Direction_2==1 && i<step_2)
	{
		GPIOD->ODR = 0x9000;
		HAL_Delay(1);
		GPIOB->ODR = 0x9000;
		HAL_Delay(1);
		GPIOD->ODR = 0x3000;
		HAL_Delay(1);
		GPIOB->ODR = 0x3000;
		HAL_Delay(1);
		GPIOD->ODR = 0x6000;
		HAL_Delay(1);
		GPIOB->ODR = 0x6000;
		HAL_Delay(1);
		GPIOD->ODR = 0xC000;
		HAL_Delay(1);
		GPIOB->ODR = 0xC000;
		HAL_Delay(1);

	}
	else if(Direction_1==1 && i<step_1 && i>=step_2)
	{
		GPIOD->ODR = 0x9000;
		HAL_Delay(2);
		GPIOD->ODR = 0x3000;
		HAL_Delay(2);
		GPIOD->ODR = 0x6000;
		HAL_Delay(2);
		GPIOD->ODR = 0xC000;
		HAL_Delay(2);

	}
	else if(i>=step_1 && Direction_2==0 && i<step_2)
	{
		GPIOB->ODR = 0xC000;
		HAL_Delay(2);
		GPIOB->ODR = 0x6000;
		HAL_Delay(2);
		GPIOB->ODR = 0x3000;
		HAL_Delay(2);
		GPIOB->ODR = 0x9000;
		HAL_Delay(2);

	}
	else if(i>=step_1 && Direction_2==1 && i<step_2)
	{
		GPIOB->ODR = 0x9000;
		HAL_Delay(2);
		GPIOB->ODR = 0x3000;
		HAL_Delay(2);
		GPIOB->ODR = 0x6000;
		HAL_Delay(2);
		GPIOB->ODR = 0xC000;
		HAL_Delay(2);

	}
	i++;

}
