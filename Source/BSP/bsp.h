/*
*********************************************************************************************************
*                                     MICIRUM BOARD SUPPORT PACKAGE
*
*                             (c) Copyright 2007; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*               Knowledge of the source code may NOT be used to develop a similar product.
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                        BOARD SUPPORT PACKAGE
*
*                                     ST Microelectronics STM32
*                                              with the
*                                   STM3210B-EVAL Evaluation Board
*
* Filename      : bsp.h
* Version       : V1.00
* Programmer(s) : Brian Nagel
*********************************************************************************************************
*/
#ifndef  __BSP_H__
#define  __BSP_H__
#include "header.h"
/*
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*/

#ifdef   BSP_GLOBALS
#define  BSP_EXT
#else
#define  BSP_EXT  extern
#endif

#define TP_CS()  GPIO_ResetBits(GPIOG,GPIO_Pin_11)
#define TP_DCS() GPIO_SetBits(GPIOG,GPIO_Pin_11)
#define WaitTPReady() while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)==0)


#ifdef __cplusplus
#define     __I     volatile                  /*!< defines 'read only' permissions      */
#else
#define     __I     volatile const            /*!< defines 'read only' permissions      */
#endif
#define     __O     volatile                  /*!< defines 'write only' permissions     */
#define     __IO    volatile                  /*!< defines 'read / write' permissions   */

#define   RS422_LED   0x0800
#define   RS232_LED   0x1000
#define   PSAM_LED    0x2000
#define   RUN_LED     0x4000

/*
*********************************************************************************************************
*                                            FUNCTION PROTOTYPES
*********************************************************************************************************
*/
void BSP_Init(void);
//
void GPIO_Config(void);
//
void SPI_Config(void);
//
void NVIC_Configuration(void);
//
void CAN_Config(void);
//
void EXTI_Configuration(void);
//
void ADC1_Configuration(void);
//
void RTC_Configuration(void);
//
void DMA_Configuration(void);
//更新天线程序
void DownloadRsu(void);
//读取射频盒参数
void ReadRfv4Para(void);
//读取铁电参数
void ReadFm25v02Para(void);
void TIM_Init(void);
void NET_Init(void);
void WDT_Init(void);
void Time_Adjust(void);
void ALL_LEDInit(void);
uint16 GetTemp(uint16 advalue);//计算温度
uint16 GetVolt(uint16 advalue);//计算电压
void usdelay(uint32 dly);
void GPIO_Configuration(void);

#endif                            
