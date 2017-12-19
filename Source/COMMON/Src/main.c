
/***********************************************************
* 文 件 名：main.c 
 
* 描    述：程序主函数

***********************************************************/


#include <includes.h>		 
#include "header.h"
#include "core_cm3.h"
#include "setup.h"

#pragma import(__use_no_semihosting)

#pragma diag_suppress 870 

 
/******************************************************************************  
*标准库需要的支持函数  
******************************************************************************/  
_sys_exit(int x)  
{  
   x = x;  
}
void (*theKernel)(int zero, int arch, unsigned int param);	//此定义必须放在本文件的开头，wyw,20131225


extern void SystemInit(void);
u8 *g_strShowBoot = "Boot程序引导";
u8 *g_strShowUpdate = "应用程序";
#if 1						
u8 *g_strShowJump = "跳转到内核启动"; 	
#else
u8 *g_strShowJump = "Try jump to the kernel \r\n";
#endif

u8 *g_strShowInfo = "应用程序错误";
u8 *g_strShow = "Try to junmp to the kernel";
#if   BOOTSTART_InOrOut
char *g_strCmdLine = "noinitrd root=mtd1 ro rootfstype=jffs2 init=/linuxrc console=ttyS0";
#else
char *g_strCmdLine = "init=/linuxrc console=ttyS0";
#endif
int main (void)
{		 
	
	/*
	 * 初始化硬件配置
	 */
	/* SYSCLK, HCLK, PCLK2 and PCLK1 configuration -----------------------------*/
	SystemInit();

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2|RCC_APB1Periph_TIM4, ENABLE); // TIM2的时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR|RCC_APB1Periph_BKP, ENABLE); // TIM2的时钟
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);

	GPIO_Configuration(); // 相关 GPIO配置
	GPIO_SetBits(GPIOB,GPIO_Pin_0);

	FSMC_SRAM_Init(); // SRAM初始化
	FSMC_NOR_Init(); // NOR初始化	
	
	USART1_Configuration(USART1_BPS); // RS232配置						 	 		

	setup_start_tag();
	//setup_memory_tags();
	setup_commandline_tag(g_strCmdLine);
	setup_end_tag();
		
	theKernel = (void (*)(int, int, unsigned int))((uint32_t)KernelStartAddrss);
	theKernel(0, 2189, ((uint32_t)TagStartAddress));

	
	while (1) 
	{
		
	}                                 
}
