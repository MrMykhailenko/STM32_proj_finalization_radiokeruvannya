#ifndef INC_ADC_LIB_H_
#define INC_ADC_LIB_H_

#include <stdio.h>

#include "main.h"

#include "uart_lib.h"

#define TRESHOLD 450
#define CENTER_VALL 2050

#define MIN_VALUE 0
#define MAX_VALUE 4095

extern ADC_HandleTypeDef hadc1;


void initADC();
void stopADC();
void printJoystick();
void printSides();


#endif
