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

