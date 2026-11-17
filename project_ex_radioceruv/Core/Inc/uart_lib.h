#ifndef INC_UART_LIB_H_
#define INC_UART_LIB_H_

#include "main.h"
#include "struct.h"
#include <string.h>

extern UART_HandleTypeDef huart2;


void uartPrintln(const char *mess);

void uartSendPacketLigh(const LedPWMStatus *leds);


#endif
