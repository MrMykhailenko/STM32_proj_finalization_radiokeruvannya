#include "test_liba.h"


void blinkTest()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);


	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
	HAL_Delay(1000);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
	HAL_Delay(1000);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1);
	HAL_Delay(1000);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
}



void ledUpdate(LedStatus *leds)
{

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, leds->redLight);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, leds->yellowLight);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, leds->greenLight);

}



void initPWM()
{
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim16, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim17, TIM_CHANNEL_1);
}



void ledPWMUpdate(LedPWMStatus *leds)
{

	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, leds->redLight);
	__HAL_TIM_SET_COMPARE(&htim16, TIM_CHANNEL_1, leds->yellowLight);
	__HAL_TIM_SET_COMPARE(&htim17, TIM_CHANNEL_1, leds->greenLight);

}


