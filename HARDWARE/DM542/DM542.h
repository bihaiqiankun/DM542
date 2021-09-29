#ifndef __DM542_H
#define __DM542_H

/* ����ͷ�ļ� */
#include "delay.h"

//��Ŀ˵����DM542.c�ļ�
//��Ŀʹ��GPIOB Pin 6,7,8,9.
//��Ŀ��PULN��DIRNӦʼ�ձ��ָ�λ״̬����ƽ��PULP��DIRP����
//����ĿGPIO����PULP����ɲ�����Ӧ���ָߵ�ƽ

#define GPIOPORT GPIOB	 //��Ŀʹ��GPIOB
#define GPIOPORTRCC RCC_AHB1Periph_GPIOB//GPIOB����ʱ�ӳ�ʼ���Ķ���
#define PULP GPIO_Pin_6	 //������
#define PULN GPIO_Pin_7	 //���帺
#define DIRP GPIO_Pin_8	 //������
#define DIRN GPIO_Pin_9	 //����

void DM542_Init(void);//DM542��ʼ������
void DM542_Set(uint16_t GPIO_Pin);
void DM542_Reset(uint16_t GPIO_Pin);
uint8_t DM542_ReadPin(uint16_t GPIO_Pin);
void DM542_DIRDelay(void);
void DM542_PULDelay(void);
void DM542_Pulse(void);//DM542ת��һ�κ���
void DM542_Direction(void);//DM542������

#endif
