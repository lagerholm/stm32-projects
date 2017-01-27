/*
 * interrupt_callbacks.c
 *
 *  Created on: 27 Jan 2017
 *      Author: Anton Lagerholm
 */

#include "stm32f4xx_hal.h"

extern UART_HandleTypeDef *gHuart;
extern uint8_t txChar;
extern uint8_t rxChar;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle)
{
	txChar = rxChar;
	if(UartHandle == gHuart)
	{
		HAL_UART_Transmit_IT(gHuart, &txChar, 1);
	}
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *UartHandle)
{
	if(UartHandle == gHuart)
	{
		HAL_UART_Receive_IT(gHuart, &rxChar, 1);
	}
}
