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


void listenEcho(char *buffer, size_t bufferSize)
{
	if(listenStream(buffer, bufferSize) != LISTEN_OK)
	{
		uartPrintln("Error to read");
	}

	else
	{
		uartPrintln(buffer);
	}

}


LISTEN_STATUS listenStream(char *buffer, size_t bufferSize)
{

	if(buffer == NULL)
	{
		return LISTEN_BUFFER_NULL;
	}

	if(bufferSize < 0)
	{
		return LISTEN_BUFFER_SIZE_ERROR;
	}

	uint8_t rx_byte = 0;
	size_t rx_index = 0;
	size_t drain_count = 0;
	uint8_t is_overflow = 0;

	while (1)
	    {
	        if (HAL_UART_Receive(&huart2, &rx_byte, 1, 50) == HAL_OK)
	        {
	            if (rx_byte == '\r' || rx_byte == '\n')
	            {
	                if (is_overflow)
	                {
	                	buffer[0] = '\0';
	                    return LISTEN_OVERLOAD;
	                }

	                if (rx_index > 0)
	                {
	                	buffer[rx_index] = '\0';
	                    return LISTEN_OK;
	                }
	            }
	            else if (!is_overflow)
	            {
	                if (rx_index < (bufferSize - 1))
	                {
	                	buffer[rx_index++] = (char)rx_byte;
	                }
	                else
	                {
	                    is_overflow = 1;
	                }
	            }
	            else
	            {
	                if (++drain_count >= MAX_DRAIN_BYTES)
	                {
	                	buffer[0] = '\0';
	                    return LISTEN_FATAL_ERROR; // Сміття не закінчується — примусово рубаємо
	                }
	            }
	        }
	        else
	        {
	            if (rx_index > 0 || is_overflow)
	            {
	            	buffer[0] = '\0';
	                return LISTEN_PACKET_WITHOUT_END; // Обірваний пакет без кінця рядка
	            }
	        }
	    }

}
