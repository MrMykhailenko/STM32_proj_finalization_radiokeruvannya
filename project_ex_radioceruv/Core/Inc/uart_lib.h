#ifndef INC_UART_LIB_H_
#define INC_UART_LIB_H_

#include "main.h"
#include "struct.h"
#include <string.h>

extern UART_HandleTypeDef huart2;


#define MAX_DRAIN_BYTES 64


typedef enum {

	LISTEN_OK = 0x00,
	LISTEN_OVERLOAD = 0x01,
	LISTEN_BUFFER_NULL = 0x02,
	LISTEN_BUFFER_SIZE_ERROR = 0x03,
	LISTEN_PACKET_WITHOUT_END = 0x04,
	LISTEN_FATAL_ERROR = 0x05

} LISTEN_STATUS;

void uartPrintln(const char *mess);

void listenEcho(char *buffer, size_t bufferSize);

void uartSendPacketLigh(const LedPWMStatus *leds);

LISTEN_STATUS listenStream(char *buffer, size_t bufferSize);


#endif
