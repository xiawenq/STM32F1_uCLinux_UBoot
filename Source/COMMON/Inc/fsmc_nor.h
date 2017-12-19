/**
  ******************************************************************************
  * @file    FSMC/NOR/fsmc_nor.h 
  * @author  MCD Application Team
  * @version V3.1.0
  * @date    06/19/2009
  * @brief   Header for fsmc_nor.c file.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2009 STMicroelectronics</center></h2>
  */
   
/** @addtogroup STM32F10x_StdPeriph_Examples
  * @{
  */

/** @addtogroup FSMC_NOR
  * @{
  */ 
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FSMC_NOR_H
#define __FSMC_NOR_H

/* Includes ------------------------------------------------------------------*/

//#include "common.h"
//#include "pc.h"

//#define FSMC_NOR_CHANGE	  //当FSMC_NOR中增加或删除内容时打开
#define Bank1_NOR2_ADDR       ((uint32)0x64000000)
#define FSMCNORADDRESS        ((uint32)0x64010000)	//参数表地址为 0x64000000~ 0x64010000
/* Delay definition */   
#define BlockErase_Timeout    ((uint32)0x00A00000)
#define ChipErase_Timeout     ((uint32)0x30000000) 
#define Program_Timeout       ((uint32)0x00001400)

/* Private macro -------------------------------------------------------------*/
#define ADDR_SHIFT(A) (Bank1_NOR2_ADDR + (2 * (A)))
#define NOR_WRITE(Address, Data)  (*(__IO uint16 *)(Address) = (Data))
/* Exported types ------------------------------------------------------------*/
//FSMC_NOR操作错误代码
#define ERR_FSMC_NOR_ERASE      0x00000010
#define ERR_FSMC_NOR_WRITE      0x00000011
#define ERR_FSMC_NOR_READ       0x00000012

// 程序存放位置
#define  PROGRAM_MAXSIZE                0x30000                                   // 存储程序最大值，192k
#define  PROGRAM_BASEADDR               0x64000000                                // 程序存储基地址
#define  CONTROLLE_RPROGRAM_ADDR        PROGRAM_BASEADDR                          // 控制器主程序存放位置
#define  CONTROLLE_RPROGRAM_ADDR_BK     PROGRAM_BASEADDR + PROGRAM_MAXSIZE		  // 控制器备程序存放位置
#define  ANT_PROGRAM_ADDR               PROGRAM_BASEADDR + (PROGRAM_MAXSIZE * 2)  // 天线主程序存放位置
#define  ANT_PROGRAM_ADDR_BK            PROGRAM_BASEADDR + (PROGRAM_MAXSIZE * 3)  // 天线备程序存放位置
#define  DBF_PROGRAM_ADDR               PROGRAM_BASEADDR + (PROGRAM_MAXSIZE * 4)  // DBF主程序存放位置
#define  DBF_PROGRAM_ADDR_BK            PROGRAM_BASEADDR + (PROGRAM_MAXSIZE * 5)  // DBF备程序存放位置 


#define  FSMC_NOR_LEN     0x22//存储大小
typedef struct
{
	uint16 Manufacturer_Code;
	uint16 Device_Code1;
	uint16 Device_Code2;
	uint16 Device_Code3;
} NOR_IDTypeDef;

/* NOR Status */
typedef enum
{
	NOR_SUCCESS = 0,
	NOR_ONGOING,
	NOR_ERROR,
	NOR_TIMEOUT
}NOR_Status;

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void FSMC_NOR_Init(void);
void FSMC_NOR_ReadID(NOR_IDTypeDef* NOR_ID);
NOR_Status FSMC_NOR_EraseBlock(uint32 BlockAddr);
NOR_Status FSMC_NOR_EraseChip(void);
NOR_Status FSMC_NOR_WriteHalfWord(uint32 WriteAddr, uint16 Data);
NOR_Status FSMC_NOR_WriteBuffer(uint16* pBuffer, uint32 WriteAddr, uint32 NumHalfwordToWrite);
NOR_Status FSMC_NOR_ProgramBuffer(uint16* pBuffer, uint32 WriteAddr, uint32 NumHalfwordToWrite);
NOR_Status FSMC_NOR_ReturnToReadMode(void);
NOR_Status FSMC_NOR_Reset(void);
NOR_Status FSMC_NOR_GetStatus(uint32 Timeout);
uint16 FSMC_NOR_ReadHalfWord(uint32 ReadAddr);
void FSMC_NOR_ReadBuffer(uint16* pBuffer, uint32 ReadAddr, uint32 NumHalfwordToRead);


#endif /* __FSMC_NOR_H */

