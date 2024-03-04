#include "stm32f10x.h"

int main(void)
{
    //RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	//RCC->APB2ENR=0x00000010;
	//GPIOC->CRH=0X00300000;
	//GPIOC->ODR=0X00000000;
	//GPIO_InitTypeDef GPIO_InitStructure;
	///GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	//GPIO_InitStructure.GPIO_Pin=GPIO_Pin_All;
	//GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	//GPIO_Init(GPIOA,&GPIO_InitStructure);
	//高电平
	//GPIO_SetBits(GPIOA,GPIO_Pin_0);
	//低电平
	//GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	//写入数据值
	
	while(1)
	{
//		GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);
//		Delay_ms(500);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_SET);
//		Delay_ms(500);
		//GPIO_Write(GPIOA,~0x0001);//0000 0000 0000 0001
		//Delay_ms(500);
		//GPIO_Write(GPIOA,~0x0002);//0000 0000 0000 0010
		//Delay_ms(500);
		//GPIO_Write(GPIOA,~0x0004);//0000 0000 0000 0100
		//Delay_ms(500);
		//GPIO_Write(GPIOA,~0x0008);//0000 0000 0000 1000
		//Delay_ms(500);
		//GPIO_Write(GPIOA,~0x0010);//0000 0000 0001 0000
		//Delay_ms(500);
		//GPIO_Write(GPIOA,~0x0020);//0000 0000 0010 0000
		//Delay_ms(500);
		//GPIO_Write(GPIOA,~0x0040);//0000 0000 0100 0000
        //Delay_ms(500);
		//GPIO_Write(GPIOA,~0x0080);//0000 0000 1000 0000
		//Delay_ms(500);
	}
}
