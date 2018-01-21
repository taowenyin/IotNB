//======================================================================
//文件名称：uart.h
//功能概要：UART底层驱动构件头文件
//版权所有：苏州大学嵌入式系统与物联网研究所(sumcu.suda.edu.cn)
//更新记录：2017-04-19 V1.0
//适用芯片：KL36(uart0暂未实现)
//======================================================================

#ifndef _UART_H         //防止重复定义（ 开头)
#define _UART_H

#include "common.h"    //包含公共要素头文件

//宏定义串口号
#define UART_0    0
#define UART_1    1
#define UART_2    2
//配置UARTx使用的引脚组(TX,RX)
//UART_0的引脚组配置：0:PTE20~21, 1:PTA2~1, 2:PTB17~16, 3:PTD7~6
#define UART_0_GROUP    0
//UART_1的引脚组配置：0:PTE0~1, 1:PTA19~18, 2:PTC4~3
#define UART_1_GROUP    0                         //与BC95交互
//UART_2的引脚组配置：0:PTE16~17, 1:PTE22~23, 2:PTD3~2, 3:PTD5~4
#define UART_2_GROUP    0
//======================================================================
//函数名称：uart_init
//功能概要：初始化uart模块                                                
//参数说明：uartNo:串口号：UART_0、UART_1、UART_2 
//          baud:波特率：300、600、1200、2400、4800、9600、19200、115200...
//函数返回：无
//======================================================================
void uart_init(uint_8 uartNo, uint_32 baud_rate);

//======================================================================
//函数名称：uart_send1
//参数说明：uartNo: 串口号:UART_0、UART_1、UART_2 
//          ch:要发送的字节
//函数返回：函数执行状态：1=发送成功；0=发送失败。
//功能概要：串行发送1个字节
//======================================================================
uint_8 uart_send1(uint_8 uartNo, uint_8 ch);

//======================================================================
//函数名称：uart_sendN
//参数说明：uartNo: 串口号:UART_0、UART_1、UART_2 
//         buff: 发送缓冲区
//         len:发送长度
//函数返回： 函数执行状态：1=发送成功；0=发送失败
//功能概要：串行 接收n个字节
//======================================================================
uint_8 uart_sendN(uint_8 uartNo ,uint_16 len ,uint_8* buff);

//======================================================================
//函数名称：uart_send_string
//参数说明：uartNo:UART模块号:UART_0、UART_1、UART_2 
//          buff:要发送的字符串的首地址
//函数返回： 函数执行状态：1=发送成功；0=发送失败
//功能概要：从指定UART端口发送一个以'\0'结束的字符串
//======================================================================
uint_8 uart_send_string(uint_8 uartNo, void *buff);

//======================================================================
//函数名称：uart_re1
//参数说明：uartNo: 串口号:UART_0、UART_1、UART_2 
//        *fp:接收成功标志的指针:*fp=1:接收成功；*fp=0:接收失败
//函数返回：接收返回字节
//功能概要：串行接收1个字节
//======================================================================
uint_8 uart_re1(uint_8 uartNo,uint_8 *fp);

//======================================================================
//函数名称：uart_reN
//参数说明：uartNo: 串口号:UART_0、UART_1、UART_2
//          buff: 接收缓冲区
//          len:接收长度
//函数返回：函数执行状态 1=接收成功;0=接收失败
//功能概要：串行 接收n个字节,放入buff中
//======================================================================
uint_8 uart_reN(uint_8 uartNo ,uint_16 len ,uint_8* buff);

//======================================================================
//函数名称：uart_enable_re_int
//参数说明：uartNo: 串口号:UART_0、UART_1、UART_2 
//函数返回：无
//功能概要：开串口接收中断
//======================================================================
void uart_enable_re_int(uint_8 uartNo);

//======================================================================
//函数名称：uart_disable_re_int
//参数说明：uartNo: 串口号 :UART_0、UART_1、UART_2 
//函数返回：无
//功能概要：关串口接收中断
//======================================================================
void uart_disable_re_int(uint_8 uartNo);

//======================================================================
//函数名称：uart_get_re_int
//参数说明：uartNo: 串口号 :UART_0、UART_1、UART_2
//函数返回：接收中断标志 1=有接收中断;0=无接收中断
//功能概要：获取串口接收中断标志,同时禁用发送中断
//======================================================================
uint_8 uart_get_re_int(uint_8 uartNo);

#endif     //防止重复定义（ 结尾）

//=====================================================================
//声明：
//（1）我们开发的源代码，在本中心提供的硬件系统测试通过，真诚奉献给社会，
//    不足之处，欢迎指正。
//（2）对于使用非本中心硬件系统的用户，移植代码时，请仔细根据自己的硬件匹配。
//
//苏州大学嵌入式系统与物联网研究所，0512-65214835，http://sumcu.suda.edu.cn