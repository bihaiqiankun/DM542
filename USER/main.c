/*******************************
��Ŀ��ʼʱ��:2021/09/29
��Ŀ�����д:bhqk@bhqk.top
��Ŀ״̬��
		���DM542��������--2021/09/29 19:30
		���DM542��������--2021/09/29 21:26
*******************************/

/* ����ͷ�ļ� */
#include "sys.h"
#include "delay.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_exti.h"
#include "DM542.h"
#include "key.h"
#include "exti.h"

//����Pitch, ��תRoll, ƫ��Yaw

u8 EulerPool[3]={0};//0-Pitch, 1-Roll, 3-Yaw, ��¼��������������
u8 StatePool[3]={0};//0-Pitch, 1-Roll, 3-Yaw, ��¼������ǰ��̬

//����Ϊ��Ŀ���Բ���
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
//����Ϊ��Ŀ���Բ���

/*����Ϊδ��ɵ���Ŀ����
int main(void)
{ 
	
	delay_init(168);
	DM542_Init();
	EXTIX_Init();
	
	while(1)
	{
		
	}

}
����Ϊδ��ɵ���Ŀ����*/
