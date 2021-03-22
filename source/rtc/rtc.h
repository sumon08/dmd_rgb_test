


#ifndef RTC_H
#define RTC_H


typedef struct
{
	int sec;
	int minute;
	int hour;
	int day;
	int date;
	int month;
	int year;
	int am_pm;
}Time;


extern volatile Time time;

void InitRTC();
uint8_t SendByte(uint16_t address, uint8_t data);
void EnableOneHzInterrupt();
uint32_t GetCounterValue();
void ResetDelayCounter();
void ConfigureRtc();
uint8_t SetTime(Time * t);
#endif //RTC_H
