#ifndef _USART_H
#define _USART_H
#include <includes.h>
#include "header.h"
#define USART1_BPS	115200

struct Usart_Driver
{	
	// 发送一帧数据
	uint8 (* write)(uint8 *buf, uint32 len);
	
	// 接收一帧数据,0:成功接收一帧 1:接收不成功
	uint8 (* read)(uint8 *buf, uint32 *len);
	
	// 清空接收缓冲区
	uint8 (* flush)(void);
};

void USART1_Configuration(uint32 bps);
void USART3_Configuration(uint32 bps);
void USART4_Configuration(uint32 bps);
void FSMC_CPLD_Init(void);

void Usart232SendData(uint8 data);
void Usart422SendByte(uint8 data);


void Uart4SendData(uint8 data);
void Uart4SendBuf(uint8 *Buf,uint8 len);
void my_print(u8* str);

extern const struct Usart_Driver usart_232_driver;
extern const struct Usart_Driver usart_422_driver;

/***********************************************************
// 用法说明

在main()函数中对uart0进行初始化
	uart0_driver->init();
	
	// 发送数据
	uart0_driver->write(cmd, len);
	
	// 接收数据,需配合超时函数使用
	while (1) {
		if (uart0_driver->read(cmd, *len) != 0)
			break; // 接收到数据
			
		// 未接收到数据,其它处理
		.......................
	}
	
	// 接收超时退出
	.....................

***********************************************************/


#endif
