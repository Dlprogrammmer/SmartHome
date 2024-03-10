#include "stm32f10x.h"
#include "dht11.h"
#include "delay.h"
#include "usart.h"
#include "time.h"
#include "oled.h"
#include "beep.h"
#include "onenet.h"
#include "esp8266.h"
u8 humidityH;
u8 humidityL;
u8 temperatureH;
u8 temperatureL;
u8 Light;
u8 alarmFlag;
unsigned short timeCount = 0;	//发送间隔变量
unsigned char *dataPtr = NULL;
const char *topics[]={"/mysmarthome/sub"};
int main(void)
{
	delay_init();
	LED_Init();
	TIM2_Int_Init(4999,7199);
	TIM3_Int_Init(4999,7199);
    DHT11_Init();
	BEEP_Init();
	Usart1_Init(115200);
	ESP8266_Init();
	while(OneNet_DevLink())
		delay_ms(500);
		OneNet_Subscribe(topics,1);
	while(1)
	{
		if(++timeCount >= 500)									//发送间隔5s
		{
			UsartPrintf(USART_DEBUG, "OneNet_Publish\r\n");
			
			OneNet_Publish("pcTopic", "MQTT Publish Test");
			
			timeCount = 0;
			ESP8266_Clear();
		}
		
		dataPtr = ESP8266_GetIPD(0);
		if(dataPtr != NULL)
			OneNet_RevPro(dataPtr);
		delay_ms(10);
	}
}
