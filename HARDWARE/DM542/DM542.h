#ifndef __DM542_H
#define __DM542_H

/* 包含头文件 */
#include "delay.h"

//项目说明见DM542.c文件
//项目使用GPIOB Pin 6,7,8,9.
//项目中PULN与DIRN应始终保持复位状态，电平由PULP与DIRP决定
//本项目GPIO口中PULP在完成操作后应保持高电平

#define GPIOPORT GPIOB	 //项目使用GPIOB
#define GPIOPORTRCC RCC_AHB1Periph_GPIOB//GPIOB用于时钟初始化的定义
#define PULP GPIO_Pin_6	 //脉冲正
#define PULN GPIO_Pin_7	 //脉冲负
#define DIRP GPIO_Pin_8	 //方向正
#define DIRN GPIO_Pin_9	 //方向负

void DM542_Init(void);//DM542初始化函数
void DM542_Set(uint16_t GPIO_Pin);
void DM542_Reset(uint16_t GPIO_Pin);
uint8_t DM542_ReadPin(uint16_t GPIO_Pin);
void DM542_DIRDelay(void);
void DM542_PULDelay(void);
void DM542_Pulse(void);//DM542转动一次函数
void DM542_Direction(void);//DM542换向函数

#endif
