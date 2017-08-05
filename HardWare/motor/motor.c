#include "motor.h"
#include "SysTick.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

void MotorInit(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //����ṹ�����	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin=MOTOR_A|MOTOR_B|MOTOR_C|MOTOR_D;	   //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//�������  
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	   //���ô�������
	GPIO_Init(MOTOR_PORT,&GPIO_InitStructure);		  /* ��ʼ��GPIO */
}

/**/
void MotorFWD(u8 steps)
{
	u8 i,j;
	uint16_t FWD_table[]={0x03,0x06,0x0c,0x09};/*��ת��һ������һ��step��5.65��*/
	for(i=0;i<=steps;i++){
		for(j=0;j<4;j++)
			GPIO_Write(MOTOR_PORT,FWD_table[j]);	
		delay_ms(1);
	}
}

void MotorREV(u8 steps)
{
	u8 i,j;
	uint16_t REV_table[]={0x03,0x09,0x0c,0x06};/*��ת��һ������һ��step��5.65��*/
	for(i=0;i<=steps;i++){
		for(j=0;j<4;j++)
			GPIO_Write(MOTOR_PORT,REV_table[j]);	
		delay_ms(1);
	}

}
