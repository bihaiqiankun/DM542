/************************************
文件：基于STM32F4的DM542驱动
作者：bhqk@bhqk.top
时间：2021/09/29
*************************************/
/* 包含头文件 */
#include "DM542.h" 

/************************************
函数：GPIO口上拉函数
功能：上拉对应GPIO口电压
注意：//
*************************************/
void DM542_Set(uint16_t GPIO_Pin)
{
	GPIO_SetBits(GPIOPORT,GPIO_Pin);
}

/************************************
函数：GPIO口复位函数
功能：复位对应GPIO口电压
注意：//
*************************************/
void DM542_Reset(uint16_t GPIO_Pin)
{
	GPIO_ResetBits(GPIOPORT,GPIO_Pin);
}

/************************************
函数：读取GPIO口状态函数
功能：读取GPIO口状态
注意：指定Pin口高电平返回1，低电平返回0
*************************************/
uint8_t DM542_ReadPin(uint16_t GPIO_Pin)
{
	uint8_t result=0;
	result=GPIO_ReadOutputDataBit(GPIOPORT,GPIO_Pin);
	return result;
}

/************************************
函数：DM542初始化函数
功能：初始化DM542相关GPIO口
注意：初始化后GPIO口中PULP处于高电位，其余全部处于低电位
*************************************/
void DM542_Init(void)
{    	 
  GPIO_InitTypeDef GPIO_InitStructure;
	
  RCC_AHB1PeriphClockCmd(GPIOPORTRCC, ENABLE);
	
  GPIO_InitStructure.GPIO_Pin = PULP | PULN | DIRP | DIRN ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;//25MHz足够，再高影响稳定性
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOPORT, &GPIO_InitStructure);
	
	//设置Pin口初始态
	DM542_Set(PULP);
	DM542_Reset(PULN);
	DM542_Reset(DIRP);
	DM542_Reset(DIRN);

}

/************************************
函数：DIR提前延迟6us
功能：用于换向前的DIR 5us延时
注意：DIR 至少提前PUL下降沿5μs确定其状态高或低，项目取6us
*************************************/
void DM542_DIRDelay(void)
{
	delay_us(6);
}

/************************************
函数：PUL电平延时
功能：用于PUL信号的保持延迟
注意：PUL高低电平宽度均至少不小于2.5μs，项目取3us
*************************************/
void DM542_PULDelay(void)
{
	delay_us(3);
}

/************************************
函数：DM542转动一次脉冲发生
功能：用于发生指定的脉冲数
注意：上升沿有效，此函数使电机转动一次
*************************************/
void DM542_Pulse(void)
{
	DM542_Reset(PULP);
	DM542_PULDelay();
	DM542_Set(PULP);
	DM542_PULDelay();
}

/************************************
函数：DM542换向函数
功能：用于转换电机转动方向,包含6us延时
注意：运行一次函数，电机转向转换一次
*************************************/
void DM542_Direction(void)
{
	if (DM542_ReadPin(DIRP) ==1)
		DM542_Reset(DIRP);
	else 
		DM542_Set(DIRP);
	DM542_DIRDelay();
}
