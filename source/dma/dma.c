#include <string.h>
#include "STM32f10x.h"
#include "STM32f10x_gpio.h"
#include "STM32f10x_rcc.h"
#include "STM32f10x_dma.h"
#include "STM32f10x_tim.h"
#include "dma.h"
#include "gpio.h"

TIM_OCInitTypeDef  TIM_OCInitStructure;
//uint16_t SRC_Buffer[3] = {0, 0, 0};
uint16_t TimerPeriod = 0, TimerPeriod1;
//uint8_t vb[514] = "01021103434E5311074C494D49544544";

uint16_t time_period[] = {7999, 10999, 14999, 17999};


void ChangeTimerPeriod(uint16_t period)
{

	TIM_DeInit(TIM1);

	TIM_TimeBaseInitTypeDef config_timer;
	TimerPeriod1 = period;
	config_timer.TIM_Prescaler = 1;
	config_timer.TIM_Period = TimerPeriod1;
	config_timer.TIM_ClockDivision = TIM_CKD_DIV1;
	config_timer.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM1,&config_timer);

	uint16_t Channel1Pulse = (uint16_t) (((uint32_t) 99 * (TimerPeriod1 +10)) / 100);


	//TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_Low;
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Disable;
	//TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;
	TIM_OCInitStructure.TIM_Pulse = Channel1Pulse;
	TIM_OC2Init(TIM1, &TIM_OCInitStructure);


	TIM_CtrlPWMOutputs(TIM1, ENABLE);
	TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
	TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE);
	NVIC_SetPriority(TIM1_UP_IRQn, 2);
	NVIC_EnableIRQ(TIM1_UP_IRQn);

	TIM_Cmd(TIM1, ENABLE);
}


void InitDma()
{

	TIM_TimeBaseInitTypeDef config_timer;

	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_14|GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOB, &GPIO_InitStruct);



	  /* Compute the value to be set in ARR regiter to generate signal frequency at 17.57 Khz */
	  TimerPeriod = 45;
	  /* Compute CCR1 value to generate a duty cycle at 50% for channel 1 and 1N */
	  uint16_t  Channel1Pulse = (uint16_t) (((uint32_t) 70 * (TimerPeriod - 1)) / 100);


	config_timer.TIM_Prescaler = 1;
	config_timer.TIM_CounterMode = TIM_CounterMode_Up;
	config_timer.TIM_Period = TimerPeriod;
	config_timer.TIM_ClockDivision = TIM_CKD_DIV1;
	config_timer.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3,&config_timer);



	TimerPeriod1 = 10999;
	config_timer.TIM_Prescaler = 1;
	config_timer.TIM_Period = TimerPeriod1;
	config_timer.TIM_ClockDivision = TIM_CKD_DIV1;
	config_timer.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM1,&config_timer);


	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
	TIM_OCInitStructure.TIM_Pulse = Channel1Pulse;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;


	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
	//TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCIdleState_Set;


	TIM_OC3Init(TIM3, &TIM_OCInitStructure);


	Channel1Pulse = (uint16_t) (((uint32_t) 99 * (TimerPeriod1 +100)) / 100);


	//TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_Low;
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Disable;
	//TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;
	TIM_OCInitStructure.TIM_Pulse = Channel1Pulse;
	TIM_OC2Init(TIM1, &TIM_OCInitStructure);

	/* 7 (Enable TIM for DMA events) */
	TIM_DMACmd(TIM3, TIM_DMA_CC1, ENABLE);
	TIM_CtrlPWMOutputs(TIM3, ENABLE);
	TIM_CtrlPWMOutputs(TIM1, ENABLE);
	TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
	TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE);
	NVIC_SetPriority(TIM1_UP_IRQn, 2);
	NVIC_EnableIRQ(TIM1_UP_IRQn);

//	TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
//	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
//
//	NVIC_SetPriority(TIM4_IRQn, 13);
//	NVIC_EnableIRQ(TIM4_IRQn);


	TIM_Cmd(TIM1, ENABLE);


//	TIM_Cmd(TIM4, ENABLE);
}


void DMA_config(uint32_t mem_address)
{
	DMA_InitTypeDef DMA_InitStructure;
	DMA_DeInit(DMA1_Channel6);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&GPIOA->ODR;
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)mem_address;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
	DMA_InitStructure.DMA_BufferSize = 192;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;

	DMA_Init(DMA1_Channel6, &DMA_InitStructure);
	DMA_ClearITPendingBit(DMA1_IT_TC6);
	DMA_ITConfig(DMA1_Channel6, DMA_IT_TC, ENABLE);
	  /* DMA1 Channel2 enable */
	DMA_Cmd(DMA1_Channel6, ENABLE);

	NVIC_SetPriority(DMA1_Channel6_IRQn, 1);

	NVIC_EnableIRQ(DMA1_Channel6_IRQn);
	TIM_Cmd(TIM3, ENABLE);
}





void DMA1_Channel6_IRQHandler(void)
{
	DMA_ClearITPendingBit(DMA1_IT_TC6);
	//DMA_config((uint32_t)vb);
	TIM_Cmd(TIM3, DISABLE);
	DMA_Cmd(DMA1_Channel6, DISABLE);
}


void TIM1_UP_IRQHandler()
{
	TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
	extern void DisplayScanner();
	DisplayScanner();

//	extern uint32_t GetSlot();


//	ChangeTimerPeriod(time_period[GetSlot()]);


	extern uint32_t GetBaseAddress();



	DMA_config((uint32_t)GetBaseAddress());
}
