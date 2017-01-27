/*
 * console.c
 *
 *  Created on: 22 Jan 2017
 *      Author: Anton Lagerholm
 */

#include <stdio.h>
#include <errno.h>
#include "console.h"

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

UART_HandleTypeDef *gHuart;

void consoleInit(UART_HandleTypeDef *huart)
{
	gHuart = huart;

	/* Disable I/O buffering for STDOUT stream, so that
	 * chars are sent out as soon as they are printed. */
	setvbuf(stdout, NULL, _IONBF, 0);
}
#if 1
int _write(int fd, char* ptr, int len)
{
	(void)fd;

	HAL_StatusTypeDef hstatus = HAL_UART_Transmit(gHuart, (uint8_t *) ptr, (uint16_t)len, HAL_MAX_DELAY);

	return (hstatus == HAL_OK) ? len : EIO;
}
#endif
