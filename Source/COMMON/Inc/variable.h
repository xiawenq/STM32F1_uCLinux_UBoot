#ifndef _VARIABLE_H
#define _VARIABLE_H 
/***********************************************************
* 文 件 名：variable.h 
 
* 描    述：本文件为WEKK231控制器程序中用到的全局变量的声明

* 作    者：赵子兰

* 完成日期：2012年4月30日 11:58:51
***********************************************************/

#include "header.h"


typedef unsigned char  uint8;    /* 无符号8位整型变量 */
typedef signed   char  int8;     /* 有符号8位整型变量 */
typedef unsigned short uint16;   /* 无符号16位整型变量 */
typedef signed   short int16;    /* 有符号16位整型变量 */
typedef unsigned long   uint32;  /* 无符号32位整型变量 */
typedef signed   long   int32;   /* 有符号32位整型变量 */
typedef float          fp32;     /* 单精度浮点数（32位长度） */
typedef double         fp64;     /* 双精度浮点数（64位长度） */


extern volatile uint8 g_vucControllerTest;//0：运行态，0xAB：进入到测试指令

extern volatile uint8 g_ucPcCmdType;
extern uint8 gDBFRecvflag; // 测试DBF数据接收
extern uint8 gDBFSendBSTflag; // 在DBF D7/D8测试模式下发送BST测试
extern volatile int32 g_vulPsamRetStatus;	//psam返回状态
extern volatile uint8 g_vucPcOrder;	        //记录上位机的指令类型
extern volatile uint32 g_vulCurtime;
extern volatile uint8 g_vucPsamCommandType;	//psam命令类型
extern volatile uint8 g_vucControllerTest;
extern volatile uint8 g_vucLogInShow;
extern volatile uint8 g_vucHeartflag;
extern volatile uint8 g_vucPowerOnFlag; // 上电返回标志位，上电发送B0指令（在上电后控制器没有收到上位机的初始化指令前，会以一定间隔给上位机发送B0数据帧）
extern uint32 g_ulMacId;
extern volatile uint8 g_vucPhyType;
extern volatile uint8 g_vucCmdTarget;
extern uint8 llcVSI; // LLC层控制字段
extern uint8 gLlcSendInterval; 
extern volatile uint8 g_vucDownloadFlag;
extern volatile uint8 g_vucRfv4DataFlag;
extern volatile uint32 g_vucPsam1Ok; 
extern volatile uint32 g_vucPsam2Ok;
extern volatile uint8 g_vucSdOk;


extern volatile uint32 g_vulSdCount;//SD卡写入扇区号
extern volatile uint32 g_vulSdTimes;//交易次数记录
extern volatile uint32 g_vulSdDownInforLen;//写入SD卡空中下行内容长度
extern volatile uint32 g_vulSdUpInforLen;//写入SD卡空中上行内容长度
extern volatile uint32 g_vulSdWriteInforLen;//写入SD卡串口发往上位机内容长度
extern volatile uint32 g_vulSdReceiveInforaLen;//写入SD卡串口接收上位机内容长度
extern volatile uint8 g_vucCrcFlag; //CRC标识
extern uint32 g_ulSLen; 
extern uint32 g_ulTLen; 
extern volatile uint8 g_vucSendFlag; //发送标识标识

extern uint8 a_ucSBuf[];
extern uint8 a_ucTBuf[];
extern uint8 g_cRfv4DataBuf[];
extern uint8 a_ucVInforBuf[]; // 车辆信息缓存
extern uint8 a_ucRsuControllerVerInfoBuf[]; // 程序版本
extern uint8 a_ucRsuVerInfoBuf[];
extern uint8 a_ucRsuRfv4Buf[];

//  网管系统
extern uint8 g_uint8RSUVerInfo[]; // 主程序版本
extern uint8 g_uint8CTRLVerInfo[]; // 控制器子程序版本

extern uint8 a_ucSdDownInforBuf[]; //SD卡交互信息空中下行缓存
extern uint8 a_ucSdUpInforBuf[]; //SD卡交互信息空中上行缓存

extern uint8 a_ucSdWriteInforBuf[]; //SD卡交互信息串口发往上位机缓存
extern uint8 a_ucSdReceiveInforBuf[]; //SD卡交互信息串口接收上位机缓存

extern uint8 a_ucSDReadBuf[];
extern uint8 a_ucSDWriteBuf[];

extern uint8 a_ucShowinforBuf[10];
extern uint8 a_ucTransInforBuf[10];
extern volatile uint8 g_vucShowInforLen;
extern volatile uint8 g_vucShowInforType; // 显示信息标志
#endif  
