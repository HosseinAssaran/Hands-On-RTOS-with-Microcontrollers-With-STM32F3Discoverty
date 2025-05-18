/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <SEGGER_SYSVIEW.h>
#include <stdio.h>
#include <FreeRTOS.h>
#include <task.h>
#include <F3Discovery_GPIO.h>
#include <F3Discovery_Init.h>

/* Private define ------------------------------------------------------------*/
void Task1(void *argument);
void Task2(void *argument);
void Task3(void *argument);
void lookBusy( void );

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
	const static uint32_t stackSize = 128;

	HWInit();
	SEGGER_SYSVIEW_Conf();

	if (xTaskCreate(Task1, "task1", stackSize, NULL, tskIDLE_PRIORITY + 2, NULL) == pdPASS)
	{
		if (xTaskCreate(Task2, "task2", stackSize, NULL, tskIDLE_PRIORITY + 1, NULL) == pdPASS)
		{
			if (xTaskCreate(Task3, "task3", stackSize, NULL, tskIDLE_PRIORITY + 1, NULL) == pdPASS)
			{
				//start the scheduler - shouldn't return unless there's a problem
				vTaskStartScheduler();
			}
		}
	}

  while (1)
  {
  }
}

void Task1(void *argument)
{
  while(1)
  {
	  SEGGER_SYSVIEW_PrintfHost("hey there!\n");
	  GreenLed.On();
	  vTaskDelay(105/ portTICK_PERIOD_MS);
	  GreenLed.Off();
	  vTaskDelay(100/ portTICK_PERIOD_MS);
  }
}

void Task2( void* argument )
{
	while(1)
	{
		SEGGER_SYSVIEW_PrintfHost("task 2 says 'Hi!'\n");
		BlueLed.On();
		vTaskDelay(200 / portTICK_PERIOD_MS);
		BlueLed.Off();
		vTaskDelay(200 / portTICK_PERIOD_MS);
	}
}

void Task3( void* argument )
{
	uint32_t itr = 0 ;
	volatile uint32_t __attribute__((unused)) remainder = 0;
	while(1)
	{
		remainder = ++itr % 4;
		lookBusy();

		SEGGER_SYSVIEW_PrintfHost("task3\n");
		RedLed.On();
		vTaskDelay(500/ portTICK_PERIOD_MS);
		RedLed.Off();
		vTaskDelay(500/ portTICK_PERIOD_MS);
	}
}

void lookBusy( void )
{
	volatile uint32_t __attribute__((unused)) dontCare = 0;
	for(int i = 0; i < 50E3; i++)
	{
		dontCare = i % 4;
	}
	SEGGER_SYSVIEW_PrintfHost("looking busy\n");
}
