#include "adc_lib.h"

volatile uint16_t adc_buf[2] = {0};
char msg[32];


void initADC()
{

	HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);

	HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adc_buf, 2);

}


void stopADC()
{

	HAL_ADC_Stop_DMA(&hadc1);

}


void printJoystick()
{

	snprintf(msg, sizeof(msg), "VRx = %u, VRy = %u\r\n", adc_buf[0], adc_buf[1]);

	uartPrintln(msg);

}


void printSides()
{

	if(adc_buf[0] >= (CENTER_VALL - TRESHOLD) && adc_buf[0] <= (CENTER_VALL + TRESHOLD))
	{

	}

	else if (adc_buf[0] < (MAX_VALUE - TRESHOLD))
	{
		uartPrintln("Left");
	}

	else if (adc_buf[0] > (MIN_VALUE + TRESHOLD))
	{
		uartPrintln("Right");
	}



	if (adc_buf[1] >= (CENTER_VALL - TRESHOLD) && adc_buf[1] <= (CENTER_VALL + TRESHOLD))
	{

	}

	else if (adc_buf[1] < (MAX_VALUE - TRESHOLD))
	{
		uartPrintln("Up");
	}

	else if (adc_buf[1] > (MIN_VALUE + TRESHOLD))
	{
		uartPrintln("Down");
	}

}

