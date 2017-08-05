#include "key.h"
#include "SysTick.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
/*******************************************************************************
* �� �� ��         : KEY_Init
* ��������		   : ������ʼ��
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //����ṹ�����	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin=KEY_MENU_Pin;	   //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//��������  
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	   //���ô�������
	GPIO_Init(KEY_MENU_Port,&GPIO_InitStructure);		  /* ��ʼ��GPIO */
	
	GPIO_InitStructure.GPIO_Pin=KEY_CONFIRM_Pin|KEY_SELECT_Pin;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;	//��������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(KEY_CONFIRM_Port,&GPIO_InitStructure);
}

/*******************************************************************************
* �� �� ��         :  KEY_Scan
* ��������		   :  ����ɨ����
* ��    ��         :  mode=0: 	   ����ģʽ
					  mode=1��	   ����ģʽ
* ��    ��         :  KEY_IDEL     δ�а�������
					  KEY_MENU     KEY1����������³���3s
					  KEY_CANCE	   KEY1����������¶̰�
					  KEY_SHUTDOWN KEY1����������³���3s
					  KEY_CONFIR   KEY2������
 					  KEY_SELECT   KEY3������	
*******************************************************************************/
u8 KEY_Scan(u8 mode)
{
	uint32_t   KeyCnt=0;
	switch(mode){
	 	case 0: 
			if(!KEY1){
				delay_ms(1864);
				if(!KEY1)				
				    return 	KEY_MENU;/*��������³���3s���������ѣ��ӳ�ʱ����΢��*/
			}
			return 	KEY_IDEL;	

		case 1:
			if (!KEY1){
			delay_ms(10);
				while (!KEY1){
					KeyCnt++;
					if(KeyCnt>300000)
						return KEY_SHUTDOWN; /*��������³���3s����������,����KeyCntֵ�����*/
					else
						return KEY_CANCE;/*�����̰���ȡ������*/
				}
		    }
			if(!KEY2){
				delay_ms(10);
				if(!KEY2)
					return KEY_CONFIRM;	/*KEY2���£�����ȷ�Ϲ���*/
			}
				
			if(!KEY3){
				delay_ms(10);
				if(!KEY3)
					return KEY_SELECT;/*KEY3���£����ع���ѡ����*/
			}
			return 	KEY_IDEL;
			
	}
	return 	KEY_IDEL;
}	



