#ifndef INC_TEST_LIBA_H_
#define INC_TEST_LIBA_H_

#include "main.h"

#include "struct.h"

#include "uart_lib.h"

#include <stdlib.h>


extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim16;
extern TIM_HandleTypeDef htim17;


typedef enum
{
	CHANGE_OK = 0x00,
	CHANGE_INCORRECT_COLOR = 0x01,
	CHANGE_INCORRECT_NUMBER = 0x02,
	CHANGE_NULL_VALUE = 0x03,
	CHANGE_FATAL_ERROR = 0x04

} CHANGE_STATUS;

void initPWM();

void blinkTest();

void ledUpdate(LedStatus *leds);

void ledPWMUpdate(LedPWMStatus *leds);

CHANGE_STATUS changeColor(char *buffer, size_t bufferSize, LedPWMStatus *leds);


#endif
