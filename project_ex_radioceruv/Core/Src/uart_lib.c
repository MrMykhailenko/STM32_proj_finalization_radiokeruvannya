#include "uart_lib.h"



void uartPrintln(const char *mess)
{
	size_t lenght = strlen(mess);

	HAL_UART_Transmit(&huart2, (uint8_t *)mess, lenght, 100);
	HAL_UART_Transmit(&huart2, (uint8_t *)"\r\n", 2, 100);

}


void uartSendPacketLigh(const LedPWMStatus *leds)
{

	size_t lenght = sizeof(LedPWMStatus);
	HAL_UART_Transmit(&huart2, (uint8_t *)leds, lenght, 100);
	HAL_UART_Transmit(&huart2, (uint8_t *)"\r\n", 2, 100);

}
