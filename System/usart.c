
#include "usart.h"
#include "delay.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
void Usart1_Init(unsigned int baud)
{

	GPIO_InitTypeDef gpio_initstruct;
	USART_InitTypeDef usart_initstruct;
	NVIC_InitTypeDef nvic_initstruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	
	//PA9	TXD
	gpio_initstruct.GPIO_Mode = GPIO_Mode_AF_PP;
	gpio_initstruct.GPIO_Pin = GPIO_Pin_9;
	gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &gpio_initstruct);
	
	//PA10	RXD
	gpio_initstruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	gpio_initstruct.GPIO_Pin = GPIO_Pin_10;
	gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &gpio_initstruct);
	
	usart_initstruct.USART_BaudRate = baud;
	usart_initstruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;		//ΞӲ¼þÁ÷¿؊	usart_initstruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;						//½ӊպͷ¢ˍ
	usart_initstruct.USART_Parity = USART_Parity_No;									//ΞУѩ
	usart_initstruct.USART_StopBits = USART_StopBits_1;								//1λֹͣλ
	usart_initstruct.USART_WordLength = USART_WordLength_8b;							//8λʽ¾ݎ»
	USART_Init(USART1, &usart_initstruct);
	
	USART_Cmd(USART1, ENABLE);														//ʹĜ´®¿ڊ	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);									//ʹĜ½ӊՖжϊ	
	nvic_initstruct.NVIC_IRQChannel = USART1_IRQn;
	nvic_initstruct.NVIC_IRQChannelCmd = ENABLE;
	nvic_initstruct.NVIC_IRQChannelPreemptionPriority = 0;
	nvic_initstruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&nvic_initstruct);

}

void Usart2_Init(unsigned int baud)
{

	GPIO_InitTypeDef gpio_initstruct;
	USART_InitTypeDef usart_initstruct;
	NVIC_InitTypeDef nvic_initstruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	
	//PA2	TXD
	gpio_initstruct.GPIO_Mode = GPIO_Mode_AF_PP;
	gpio_initstruct.GPIO_Pin = GPIO_Pin_2;
	gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &gpio_initstruct);
	
	//PA3	RXD
	gpio_initstruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	gpio_initstruct.GPIO_Pin = GPIO_Pin_3;
	gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &gpio_initstruct);
	
	usart_initstruct.USART_BaudRate = baud;
	usart_initstruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;		//ΞӲ¼þÁ÷¿؊	usart_initstruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;						//½ӊպͷ¢ˍ
	usart_initstruct.USART_Parity = USART_Parity_No;									//ΞУѩ
	usart_initstruct.USART_StopBits = USART_StopBits_1;								//1λֹͣλ
	usart_initstruct.USART_WordLength = USART_WordLength_8b;							//8λʽ¾ݎ»
	USART_Init(USART2, &usart_initstruct);
	
	USART_Cmd(USART2, ENABLE);														//ʹĜ´®¿ڊ	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);									//ʹĜ½ӊՖжϊ	
	nvic_initstruct.NVIC_IRQChannel = USART2_IRQn;
	nvic_initstruct.NVIC_IRQChannelCmd = ENABLE;
	nvic_initstruct.NVIC_IRQChannelPreemptionPriority = 0;
	nvic_initstruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&nvic_initstruct);

}

/*
************************************************************
*	º¯ʽû³ƣº	Usart_SendString
*
*	º¯ʽ¹¦Ĝ£º	´®¿ڊý¾ݷ¢ˍ
*
*	ȫ¿ڲΊý£º	USARTx£º´®¿ڗ銪				str£ºҪ·¢ˍµĊý¾݊*				len£ºʽ¾ݳ¤¶Ȋ*
*	·µ»زΊý£º	Ξ
*
*	˵÷£º		
************************************************************
*/
void Usart_SendString(USART_TypeDef *USARTx, unsigned char *str, unsigned short len)
{

	unsigned short count = 0;
	
	for(; count < len; count++)
	{
		USART_SendData(USARTx, *str++);									//·¢ˍʽ¾݊		while(USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET);		//µȴý·¢ˍͪ³Ɋ	}

}
}
void UsartPrintf(USART_TypeDef *USARTx, char *fmt,...)
{

	unsigned char UsartPrintfBuf[296];
	va_list ap;
	unsigned char *pStr = UsartPrintfBuf;
	
	va_start(ap, fmt);
	vsnprintf((char *)UsartPrintfBuf, sizeof(UsartPrintfBuf), fmt, ap);							
	va_end(ap);
	
	while(*pStr != 0)
	{
		USART_SendData(USARTx, *pStr++);
		while(USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET);
	}
}


void DEBUG_LOG(char *fmt,...)
{
	unsigned char UsartPrintfBuf[296];
	va_list ap;
	unsigned char *pStr = UsartPrintfBuf;
	
	va_start(ap, fmt);
	vsnprintf((char *)UsartPrintfBuf, sizeof(UsartPrintfBuf), fmt, ap);							//¸񊽻¯
	va_end(ap);
	UsartPrintf(USART_DEBUG, "[LOG] /> ");
	while(*pStr != 0)
	{
		USART_SendData(USART_DEBUG, *pStr++);
		while(USART_GetFlagStatus(USART_DEBUG, USART_FLAG_TC) == RESET);
	}
	UsartPrintf(USART_DEBUG, "\r\n");
}

void USART1_IRQHandler(void)
{

	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET){
		USART_ClearFlag(USART1, USART_FLAG_RXNE);
	}
}
