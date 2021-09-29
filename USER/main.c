/*******************************
项目开始时间:2021/09/29
项目代码编写:bhqk@bhqk.top
项目状态：
		完成DM542控制驱动--2021/09/29 19:30
		完成DM542驱动测试--2021/09/29 21:26
*******************************/

/* 包含头文件 */
#include "sys.h"
#include "delay.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_exti.h"
#include "DM542.h"
#include "key.h"
#include "exti.h"

//俯仰Pitch, 滚转Roll, 偏航Yaw

u8 EulerPool[3]={0};//0-Pitch, 1-Roll, 3-Yaw, 记录传感器传来数据
u8 StatePool[3]={0};//0-Pitch, 1-Roll, 3-Yaw, 记录三环当前姿态

//以下为项目测试部分
int main(void)
{ 
	
	delay_init(168);
	DM542_Init();
	KEY_Init();
	EXTIX_Init();
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	while(1)
	{
		//DM542_Pulse();
		
	}

}
//以上为项目测试部分

/*以下为未完成的项目部分
int main(void)
{ 
	
	delay_init(168);
	DM542_Init();
	EXTIX_Init();
	
	while(1)
	{
		
	}

}
以上为未完成的项目部分*/
