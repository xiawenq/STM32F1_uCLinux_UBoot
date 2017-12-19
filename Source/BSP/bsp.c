#define  BSP_GLOBALS
#include <includes.h>
#include "system_stm32f10x.h"
#include "stm32f10x.h"
#include "header.h"

/*******************************************************************************
	函数名：GPIO_Configuration
	输  入:
	输  出:
	功能说明：

*/
void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	// 第1步：打开GPIOA GPIOC GPIOD GPIOF GPIOG的时钟
	//  注意：这个地方可以一次性全打开
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 |RCC_APB2Periph_TIM1 | RCC_APB2Periph_AFIO 
			| RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD 
			| RCC_APB2Periph_GPIOE | RCC_APB2Periph_GPIOF | RCC_APB2Periph_GPIOG 
			| RCC_APB2Periph_SPI1 | RCC_APB2Periph_USART1, ENABLE);

    RCC_APB1PeriphClockCmd( RCC_APB1Periph_WWDG | RCC_APB1Periph_USART2 | RCC_APB1Periph_USART3
			| RCC_APB1Periph_UART4 | RCC_APB1Periph_CAN | RCC_APB1Periph_BKP, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOF, &GPIO_InitStructure);				// F11=CPLD_IO1

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;	  //net int
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);			   //BUZZER
	GPIO_SetBits(GPIOD,  GPIO_Pin_7);	  //BUZZER_OFF

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);				// B1=CPLD_IO2

	GPIO_SetBits(GPIOF,  GPIO_Pin_11);
	GPIO_SetBits(GPIOB,  GPIO_Pin_1);
	GPIO_ResetBits(GPIOB,GPIO_Pin_0);

	
	
	//配置PSAM 复位控制引脚 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOG, &GPIO_InitStructure);
	GPIO_SetBits(GPIOC,  GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
	
	 //LED
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOG, &GPIO_InitStructure);
	GPIO_SetBits(GPIOG,  GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14);
	
	//Configure CAN pin: RX 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//Configure CAN pin: TX 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);			 

}
