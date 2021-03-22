


#include <string.h>
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_i2c.h"
#include "STM32f10x_exti.h"
#include "STM32f10x_tim.h"
#include "STM32f10x_adc.h"
#include "rtc.h"
#include "core_cm3.h"
#include "gpio.h"

#define RTC_WRITE_ADDRESS		0xD0
#define RTC_READ_ADDRESS		0xD1



void InitRTC()
{
	//Configure PB6 PB7 to alternate function.

	GPIO_InitTypeDef gpio_config;
	gpio_config.GPIO_Mode = GPIO_Mode_AF_OD;
	gpio_config.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;
	gpio_config.GPIO_Speed = GPIO_Speed_50MHz;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_Init(GPIOB, &gpio_config);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);

	I2C_InitTypeDef i2c_config;
	i2c_config.I2C_ClockSpeed = 400000;
	i2c_config.I2C_Ack = I2C_Ack_Disable;
	i2c_config.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	i2c_config.I2C_DutyCycle = I2C_DutyCycle_2;
	i2c_config.I2C_Mode = I2C_Mode_I2C;
	i2c_config.I2C_OwnAddress1 = 0;

	I2C_Init(I2C1, &i2c_config);
	I2C_Cmd(I2C1, ENABLE);
}



volatile int time_counter = 0;
void TIM4_IRQHandler()
{
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) == SET) {
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
		time_counter++;
	}

}

void ResetDelayCounter()
{
	time_counter = 0;
}

uint32_t GetCounterValue()
{
		return time_counter;
}

uint8_t CheckFlag(uint32_t event_name)
{

	ErrorStatus error = I2C_CheckEvent(I2C1, event_name);
	ResetDelayCounter();
	while((error == ERROR) && (GetCounterValue() < 200))
	{
		error = I2C_CheckEvent(I2C1, event_name);
	}
	if (error  == ERROR) {
		return 0;
	}
	return 1;
}


uint8_t SendByte(uint16_t address, uint8_t data)
{
	I2C_GenerateSTART(I2C1, ENABLE);

//	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
	if(CheckFlag(I2C_EVENT_MASTER_MODE_SELECT) == 0)
		return 0;


	I2C_Send7bitAddress(I2C1, RTC_WRITE_ADDRESS, I2C_Direction_Transmitter );

//	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	if(CheckFlag(I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) == 0)
			return 0;
	I2C_SendData(I2C1, address);

	/* Test on EV8 and clear it */
//	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	if(CheckFlag(I2C_EVENT_MASTER_BYTE_TRANSMITTED) == 0)
		return 0;
	I2C_SendData(I2C1, data);

		/* Test on EV8 and clear it */
//	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	if(CheckFlag(I2C_EVENT_MASTER_BYTE_TRANSMITTED) == 0)
		return 0;
	I2C_GenerateSTOP(I2C1, ENABLE);

	return 1;
}


uint8_t SendData(uint16_t address, uint8_t * buffer, uint8_t length)
{
	I2C_GenerateSTART(I2C1, ENABLE);

//	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
	if(CheckFlag(I2C_EVENT_MASTER_MODE_SELECT) == 0)
		return 0;

	I2C_Send7bitAddress(I2C1, RTC_WRITE_ADDRESS, I2C_Direction_Transmitter );

//	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	if(CheckFlag(I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) == 0)
		return 0;
	I2C_SendData(I2C1, address);

	/* Test on EV8 and clear it */
//	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	if(CheckFlag(I2C_EVENT_MASTER_BYTE_TRANSMITTED) == 0)
		return 0;
	for (int i = 0; i < length; ++i) {
		I2C_SendData(I2C1, buffer[i]);

			/* Test on EV8 and clear it */
	//	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
		if(CheckFlag(I2C_EVENT_MASTER_BYTE_TRANSMITTED) == 0)
			return 0;
	}

	I2C_GenerateSTOP(I2C1, ENABLE);

	return 1;
}









uint8_t I2cReadByte(uint8_t * val, uint16_t ReadAddr)
{


		/* While the bus is busy */
	//while(I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));

	/* Send START condition */
	I2C_GenerateSTART(I2C1, ENABLE);

	/* Test on EV5 and clear it */
	//while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
	if(CheckFlag(I2C_EVENT_MASTER_MODE_SELECT) == 0)
		return 0;

	/* Send EEPROM address for write */
	I2C_Send7bitAddress(I2C1, RTC_WRITE_ADDRESS, I2C_Direction_Transmitter);

	/* Test on EV6 and clear it */
	//while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	if(CheckFlag(I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) == 0)
		return 0;

	/* Send the EEPROM's internal address to read from: MSB of the address first */
	I2C_SendData(I2C1, ReadAddr);

	/* Test on EV8 and clear it */
//	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	if(CheckFlag(I2C_EVENT_MASTER_BYTE_TRANSMITTED) == 0)
		return 0;
	/* Send the EEPROM's internal address to read from: LSB of the address */


	/* Send STRAT condition a second time */
	I2C_GenerateSTART(I2C1, ENABLE);

	/* Test on EV5 and clear it */
//	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
	if(CheckFlag(I2C_EVENT_MASTER_MODE_SELECT) == 0)
		return 0;
	/* Send EEPROM address for read */
	I2C_Send7bitAddress(I2C1, RTC_READ_ADDRESS, I2C_Direction_Receiver);

	/* Test on EV6 and clear it */


//	while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_RECEIVED));//I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
	if(CheckFlag(I2C_EVENT_MASTER_BYTE_RECEIVED) == 0)
		return 0;
	*val =I2C_ReceiveData(I2C1);



	I2C_AcknowledgeConfig(I2C1, DISABLE);
	I2C_GenerateSTOP(I2C1, ENABLE);
	return 1;
}




uint8_t I2CRecieveAck()
{
	uint8_t data;
	I2C_AcknowledgeConfig(I2C1, ENABLE);
	while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_RECEIVED));//I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
	data =I2C_ReceiveData(I2C1);

	return data;
}

uint8_t I2CRecieveNack()
{
	uint8_t data;
	I2C_AcknowledgeConfig(I2C1, DISABLE);
	I2C_GenerateSTOP(I2C1, ENABLE);
	while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_RECEIVED));//I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
	data =I2C_ReceiveData(I2C1);

	return data;
}


uint8_t I2cRead(uint8_t * val, uint16_t ReadAddr, uint32_t length)
{
	/* While the bus is busy */
//	while(I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));
//	if(CheckFlag(I2C_FLAG_BUSY) == 1)
//		return 0;

	/* Send START condition */
	I2C_GenerateSTART(I2C1, ENABLE);

	/* Test on EV5 and clear it */
//	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
	if(CheckFlag(I2C_EVENT_MASTER_MODE_SELECT) == 0)
		return 0;

	/* Send EEPROM address for write */
	I2C_Send7bitAddress(I2C1, RTC_WRITE_ADDRESS, I2C_Direction_Transmitter);

	/* Test on EV6 and clear it */
//	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	if(CheckFlag(I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) == 0)
		return 0;


	/* Send the EEPROM's internal address to read from: LSB of the address */
	I2C_SendData(I2C1, ReadAddr);

	/* Test on EV8 and clear it */
//	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	if(CheckFlag(I2C_EVENT_MASTER_BYTE_TRANSMITTED) == 0)
		return 0;

	/* Send STRAT condition a second time */
	I2C_GenerateSTART(I2C1, ENABLE);

	/* Test on EV5 and clear it */
//	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));
	if(CheckFlag(I2C_EVENT_MASTER_MODE_SELECT) == 0)
		return 0;
	/* Send EEPROM address for read */
	I2C_Send7bitAddress(I2C1, RTC_READ_ADDRESS, I2C_Direction_Receiver);

	for (int i = 0; i < length; i++) {
		if (i == length-1) {
			I2C_AcknowledgeConfig(I2C1, DISABLE);
			I2C_GenerateSTOP(I2C1, ENABLE);
			//while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_RECEIVED));//I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
			if(CheckFlag(I2C_EVENT_MASTER_BYTE_RECEIVED) == 0)
				return 0;
			val[i] =I2C_ReceiveData(I2C1);
		//	val[i]  = I2CRecieveNack();
		}
		else {

			I2C_AcknowledgeConfig(I2C1, ENABLE);
//			while(!I2C_CheckEvent(I2C1,I2C_EVENT_MASTER_BYTE_RECEIVED));//I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
			if(CheckFlag(I2C_EVENT_MASTER_BYTE_RECEIVED) == 0)
				return 0;
			val[i] =I2C_ReceiveData(I2C1);
		//	val[i] = I2CRecieveAck();
		}
	}
	return 1;
}

volatile Time time;



uint8_t SetTime(Time * t)
{
		uint8_t temp[10];

		temp[0] = ((t->sec / 10) << 4) | (t->sec % 10);
		temp[1] = ((t->minute / 10) << 4) | (t->minute % 10);
		temp[2] = ((t->hour / 10)   << 4) | (t->hour % 10);
		if (t->am_pm == 1) {
			temp[2] |= 1 << 5;
		}
		else {
			temp[2] &= ~(1 << 5);
		}

		temp[2] |= 1 << 6;
		temp[3] = t->day;
		temp[4] = ((t->date / 10)   << 4) | (t->date % 10);
		temp[5] = ((t->month / 10)   << 4) | (t->month % 10);
		temp[6] = ((t->year / 10)   << 4) | (t->year % 10);


		uint8_t df = SendData(0, temp, 7);
		extern volatile uint8_t flag;
		flag = 2;
		return df;

}


void ReadTime()
{
	uint8_t buffer[10];
	memset(buffer, 0, 10);
	Time temp_time;
	if (I2cRead(buffer, 0, 7) == 1) {
		temp_time.sec = ((buffer[0] & 0b11110000) >> 4) * 10 + (buffer[0] & 0b00001111);
		temp_time.minute = ((buffer[1] & 0b11110000) >> 4) * 10 + (buffer[1] & 0b00001111);
		temp_time.hour   = ((buffer[2]   & 0b00010000) >> 4) * 10 + (buffer[2]   & 0b00001111);
		temp_time.day     = buffer[3];
		if (buffer[2] & 0b00100000) {
			temp_time.am_pm = 1;
		}
		else {
			temp_time.am_pm = 0;
		}
		temp_time.date    = ((buffer[4]    & 0b11110000) >> 4) * 10 + (buffer[4]    & 0b00001111);
		temp_time.month   = ((buffer[5]   & 0b11110000) >> 4) * 10 + (buffer[5]   & 0b00001111);
		temp_time.year    = ((buffer[6]    & 0b11110000) >> 4) * 10 + (buffer[6]    & 0b00001111);
		time = temp_time;
	}
}


void ConfigureRtc()
{
	uint8_t byte;
	if(I2cReadByte(&byte, 2) == 1)
	{
		if(byte & (1 << 6))
		{
			// RTC Configured. leave as like it.
		}
		else {
			SendByte( 2,byte|=(1<<6));
		}
	}
}


PinHandle pin1;

int sec_counter = 0;

void EXTI9_5_IRQHandler()
{
	if (EXTI_GetITStatus(EXTI_Line5) == SET) {
		EXTI_ClearITPendingBit(EXTI_Line5);
		TogglePinState(pin1);
		extern volatile uint8_t flag;
		if (sec_counter == 59) {
			sec_counter = 0;
			flag = 2;
		}
		sec_counter++;


		//ADC_SoftwareStartConvCmd(ADC1, ENABLE);
	}
}

void EnableOneHzInterrupt()
{

//	TIM_TimeBaseInitTypeDef config_timer;


	GPIO_InitTypeDef gpio_config;
	gpio_config.GPIO_Mode = GPIO_Mode_IPU;
	gpio_config.GPIO_Pin = GPIO_Pin_5;
	gpio_config.GPIO_Speed = GPIO_Speed_50MHz;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_Init(GPIOB, & gpio_config);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);


	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource5);

	EXTI_InitTypeDef exti_config;
	exti_config.EXTI_Line = EXTI_Line5;
	exti_config.EXTI_LineCmd = ENABLE;
	exti_config.EXTI_Mode = EXTI_Mode_Interrupt;
	exti_config.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_Init(&exti_config);

	NVIC_SetPriority(EXTI9_5_IRQn, 5);
	NVIC_EnableIRQ(EXTI9_5_IRQn);

	pin1 = InitPin(PORTC, PIN13, OUTPUT);
}
