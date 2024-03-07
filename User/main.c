#include "stm32f10x.h"
#include "dht11.h"
#include "delay.h"
#include "usart.h"
u8 humidityH;
u8 humidityL;
u8 temperatureH;
u8 temperatureL;
int main(void)
{
	delay_init();
	LED_Init();
    DHT11_Init();
	Usart1_Init(115200);
	while(1)
	{
		DHT11_Read_Data(&humidityH,&humidityL,&temperatureH,&temperatureL);
		UsartPrintf(USART1,"666");
	}
}
