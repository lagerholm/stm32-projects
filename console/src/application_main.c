/*
 * application_main.c
 *
 *  Created on: 24 Jan 2017
 *      Author: Anton Lagerholm
 */

#include "console.h"

extern UART_HandleTypeDef huart1;
extern uint8_t rxChar;

void applicationMain(void)
{
	consoleInit(&huart1);
	printf("test");
	HAL_UART_Receive_IT(&huart1, &rxChar, 1);
}
