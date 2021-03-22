#include "STM32f10x.h"
#include "STM32f10x_gpio.h"
#include "STM32f10x_rcc.h"
#include "STM32f10x_bkp.h"
#include "STM32f10x_pwr.h"
#include "STM32f10x_rtc.h"
#include "gpio.h"
#include "STM32f10x_usart.h"
#include "STM32f10x_iwdg.h"
#include "dmd.h"
#include <string.h>
#include <stdio.h>
#include "dma.h"
#include "font.h"
#include "core_cm3.h"


//PinHandle pin;
DmdHandle dmd;
void NVIC_SystemReset(void)
{
 __DSB();                                                     /* Ensure all outstanding memory accesses included
                                                                 buffered write are completed before reset */
 SCB->AIRCR  = ((0x5FA << SCB_AIRCR_VECTKEY_Pos)      |
                (SCB->AIRCR & SCB_AIRCR_PRIGROUP_Msk) |
                SCB_AIRCR_SYSRESETREQ_Msk);                   /* Keep priority group unchanged */
 __DSB();                                                     /* Ensure completion of memory access */
 while(1);                                                    /* wait until reset */
}








uint8_t SplitString(char * str, char token, char ** string_list)
{
	char * head = str;
	char * iterator = str;
	uint8_t count = 0;
	uint8_t field_count = 1;
	for ( ; *iterator != 0; )
	{
		if (*iterator == token)
		{
			*iterator = 0;
			string_list[count++] = head;
			head = (iterator + 1);
			field_count++;
		}
		iterator++;
	}
	string_list[count++] = head;
	return field_count++;
}





int main(void)
{
	SystemCoreClockUpdate();
	dmd = InitDmdModule();
	ClearScreen(dmd);
	InitDma();
	DrawPic(dmd);

	//ClearScreen(dmd);

	//drawString(dmd, 0,0,"Sumon",5, 0x00FF);
	//drawString(dmd, 0,16,"Sumon",5, 0x00FF);
	//drawString(dmd, 0,32,"Sumon",5, 0x00FF);
	//drawString(dmd, 0,48,"Sumon",5, 0x00FF);
	//drawString(dmd, 0,0,"Sumon",5, 0x00FF);
	FlushScreen(dmd);

	while(1)
	{
		IWDG_ReloadCounter();
	}
}
