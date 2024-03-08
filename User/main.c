#include "stm32f10x.h"
#include "dht11.h"
#include "delay.h"
#include "usart.h"
#include "time.h"
#include "oled.h"
#include "beep.h"
u8 humidityH;
u8 humidityL;
u8 temperatureH;
u8 temperatureL;
u8 Light;
u8 alarmFlag;
int main(void)
{
	delay_init();
	LED_Init();
	TIM2_Int_Init(4999,7199);
	TIM3_Int_Init(4999,7199);
    DHT11_Init();
	BEEP_Init();
	Usart1_Init(115200);
	while(1)
	{
		DHT11_Read_Data(&humidityH,&humidityL,&temperatureH,&temperatureL);
		UsartPrintf(USART1,"666");
		
	}
}
