#ifndef INC_TEST_LIBA_H_
#define INC_TEST_LIBA_H_

#include "main.h"

#include "struct.h"

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim16;
extern TIM_HandleTypeDef htim17;

void initPWM();

void blinkTest();

void ledUpdate(LedStatus *leds);

void ledPWMUpdate(LedPWMStatus *leds);


#endif
