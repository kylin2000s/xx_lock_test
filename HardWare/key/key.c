#include "key.h"
#include "SysTick.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
/*******************************************************************************
* 函 数 名         : KEY_Init
* 函数功能		   : 按键初始化
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //定义结构体变量	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin=KEY_MENU_Pin;	   //选择你要设置的IO口
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//上拉输入  
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	   //设置传输速率
	GPIO_Init(KEY_MENU_Port,&GPIO_InitStructure);		  /* 初始化GPIO */
	
	GPIO_InitStructure.GPIO_Pin=KEY_CONFIRM_Pin|KEY_SELECT_Pin;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;	//上拉输入
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(KEY_CONFIRM_Port,&GPIO_InitStructure);
}

/*******************************************************************************
* 函 数 名         :  KEY_Scan
* 函数功能		   :  按键扫描检测
* 输    入         :  mode=0: 	   灭屏模式
					  mode=1：	   亮屏模式
* 输    出         :  KEY_IDEL     未有按键按下
					  KEY_MENU     KEY1键屏灭情况下长按3s
					  KEY_CANCE	   KEY1键屏亮情况下短按
					  KEY_SHUTDOWN KEY1键屏亮情况下长按3s
					  KEY_CONFIR   KEY2键按下
 					  KEY_SELECT   KEY3键按下	
*******************************************************************************/
u8 KEY_Scan(u8 mode)
{
	uint32_t   KeyCnt=0;
	switch(mode){
	 	case 0: 
			if(!KEY1){
				delay_ms(1864);
				if(!KEY1)				
				    return 	KEY_MENU;/*灭屏情况下长按3s，亮屏唤醒，延长时间需微调*/
			}
			return 	KEY_IDEL;	

		case 1:
			if (!KEY1){
			delay_ms(10);
				while (!KEY1){
					KeyCnt++;
					if(KeyCnt>300000)
						return KEY_SHUTDOWN; /*亮屏情况下长按3s，灭屏休眠,计数KeyCnt值需调试*/
					else
						return KEY_CANCE;/*亮屏短按，取消功能*/
				}
		    }
			if(!KEY2){
				delay_ms(10);
				if(!KEY2)
					return KEY_CONFIRM;	/*KEY2按下，返回确认功能*/
			}
				
			if(!KEY3){
				delay_ms(10);
				if(!KEY3)
					return KEY_SELECT;/*KEY3按下，返回滚动选择功能*/
			}
			return 	KEY_IDEL;
			
	}
	return 	KEY_IDEL;
}	



