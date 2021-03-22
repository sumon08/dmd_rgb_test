




#include "stm32f10x.h"
#include "stm32f10x_adc.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_gpio.h"
#include "temp.h"


float temperature = 25.0;




void InitTemperatureService()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	ADC_InitTypeDef adc_config;
	adc_config.ADC_ContinuousConvMode = DISABLE;
	adc_config.ADC_DataAlign =ADC_DataAlign_Right;
	adc_config.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	adc_config.ADC_Mode = ADC_Mode_Independent;
	adc_config.ADC_NbrOfChannel = 1;
	adc_config.ADC_ScanConvMode = DISABLE;
	ADC_RegularChannelConfig(ADC1,ADC_Channel_7,1,ADC_SampleTime_239Cycles5);
	ADC_Init(ADC1, &adc_config);

	ADC_ITConfig(ADC1, ADC_IT_EOC,ENABLE);

	GPIO_InitTypeDef gpio_config;
	gpio_config.GPIO_Mode = GPIO_Mode_AIN;
	gpio_config.GPIO_Pin = GPIO_Pin_7;
	gpio_config.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOA,&gpio_config);



	NVIC_SetPriority(ADC1_2_IRQn, 11);
	NVIC_EnableIRQ(ADC1_2_IRQn);
	ADC_Cmd(ADC1, ENABLE);
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}

void ADC1_2_IRQHandler()
{
	if(ADC_GetITStatus(ADC1, ADC_IT_EOC) == SET)
	{
		ADC_ClearITPendingBit(ADC1, ADC_IT_EOC);

		temperature = 330.0 *  ADC_GetConversionValue(ADC1)/4095.0 ;
	}
}


float GetTemperature()
{
	return 0.0;
}
