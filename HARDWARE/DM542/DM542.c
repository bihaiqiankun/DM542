/************************************
�ļ�������STM32F4��DM542����
���ߣ�bhqk@bhqk.top
ʱ�䣺2021/09/29
*************************************/
/* ����ͷ�ļ� */
#include "DM542.h" 

/************************************
������GPIO����������
���ܣ�������ӦGPIO�ڵ�ѹ
ע�⣺//
*************************************/
void DM542_Set(uint16_t GPIO_Pin)
{
	GPIO_SetBits(GPIOPORT,GPIO_Pin);
}

/************************************
������GPIO�ڸ�λ����
���ܣ���λ��ӦGPIO�ڵ�ѹ
ע�⣺//
*************************************/
void DM542_Reset(uint16_t GPIO_Pin)
{
	GPIO_ResetBits(GPIOPORT,GPIO_Pin);
}

/************************************
��������ȡGPIO��״̬����
���ܣ���ȡGPIO��״̬
ע�⣺ָ��Pin�ڸߵ�ƽ����1���͵�ƽ����0
*************************************/
uint8_t DM542_ReadPin(uint16_t GPIO_Pin)
{
	uint8_t result=0;
	result=GPIO_ReadOutputDataBit(GPIOPORT,GPIO_Pin);
	return result;
}

/************************************
������DM542��ʼ������
���ܣ���ʼ��DM542���GPIO��
ע�⣺��ʼ����GPIO����PULP���ڸߵ�λ������ȫ�����ڵ͵�λ
*************************************/
void DM542_Init(void)
{    	 
  GPIO_InitTypeDef GPIO_InitStructure;
	
  RCC_AHB1PeriphClockCmd(GPIOPORTRCC, ENABLE);
	
  GPIO_InitStructure.GPIO_Pin = PULP | PULN | DIRP | DIRN ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//���ģʽ
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;//25MHz�㹻���ٸ�Ӱ���ȶ���
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOPORT, &GPIO_InitStructure);
	
	//����Pin�ڳ�ʼ̬
	DM542_Set(PULP);
	DM542_Reset(PULN);
	DM542_Reset(DIRP);
	DM542_Reset(DIRN);

}

/************************************
������DIR��ǰ�ӳ�6us
���ܣ����ڻ���ǰ��DIR 5us��ʱ
ע�⣺DIR ������ǰPUL�½���5��sȷ����״̬�߻�ͣ���Ŀȡ6us
*************************************/
void DM542_DIRDelay(void)
{
	delay_us(6);
}

/************************************
������PUL��ƽ��ʱ
���ܣ�����PUL�źŵı����ӳ�
ע�⣺PUL�ߵ͵�ƽ��Ⱦ����ٲ�С��2.5��s����Ŀȡ3us
*************************************/
void DM542_PULDelay(void)
{
	delay_us(3);
}

/************************************
������DM542ת��һ�����巢��
���ܣ����ڷ���ָ����������
ע�⣺��������Ч���˺���ʹ���ת��һ��
*************************************/
void DM542_Pulse(void)
{
	DM542_Reset(PULP);
	DM542_PULDelay();
	DM542_Set(PULP);
	DM542_PULDelay();
}

/************************************
������DM542������
���ܣ�����ת�����ת������,����6us��ʱ
ע�⣺����һ�κ��������ת��ת��һ��
*************************************/
void DM542_Direction(void)
{
	if (DM542_ReadPin(DIRP) ==1)
		DM542_Reset(DIRP);
	else 
		DM542_Set(DIRP);
	DM542_DIRDelay();
}
