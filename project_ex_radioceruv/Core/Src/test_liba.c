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



CHANGE_STATUS changeColor(char *buffer, size_t bufferSize, LedPWMStatus *leds)
{


	if(listenStream(buffer, bufferSize) != LISTEN_OK)
	{
		uartPrintln("Incorrect command");
	}

		//Шукаємо символ = як розділювач

	    char *eq = strchr(buffer, '=');
	    if (eq == NULL)
	    {
	    	uartPrintln("Incorrect format");
	        return CHANGE_FATAL_ERROR;
	    }

	    *eq = '\0';
	    char *key = buffer;      	//Тут лишається назва кольору
	    char *val_str = eq + 1;		//Тут вказівник вже на на значення

	    if (*val_str == '\0')
	    {
	    	uartPrintln("Null value");
	        return CHANGE_NULL_VALUE;
	    }

	    char *endptr = NULL;
	    long val = strtol(val_str, &endptr, 10);

	    if (*endptr != '\0' || val < 0 || val > 255)
	    {
	    	uartPrintln("Incorrect value need 0..255");
	        return CHANGE_INCORRECT_NUMBER;
	    }


	    if (strcmp(key, "red") == 0)
	    {
	        leds->redLight = (uint8_t)val;
	    }
	    else if (strcmp(key, "yellow") == 0)
	    {
	        leds->yellowLight = (uint8_t)val;
	    }
	    else if (strcmp(key, "green") == 0)
	    {
	        leds->greenLight = (uint8_t)val;
	    }
	    else
	    {
	    	uartPrintln("Incorrect color");
	        return CHANGE_INCORRECT_COLOR; // Невідома назва кольору
	    }

	    return CHANGE_OK;

}
