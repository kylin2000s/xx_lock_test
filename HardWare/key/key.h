#ifndef _key_H
#define _key_H


#include "system.h"
 
#define KEY_MENU_Pin    	GPIO_Pin_5    //定义菜单键管脚
#define KEY_CONFIRM_Pin     GPIO_Pin_0    //定义确认键管脚
#define KEY_SELECT_Pin   	GPIO_Pin_1    //定义选择键管脚


#define KEY_MENU_Port 		(GPIOC)    	//定义端口
#define KEY_CONFIRM_Port 	(GPIOB) 	//定义端口
#define KEY_SELECT_Port 	(GPIOB)  	//定义端口


//使用位操作定义
#define K_UP PAin(0)
#define K_DOWN PEin(3)
#define K_LEFT PEin(2)
#define K_RIGHT PEin(4)

//使用读取管脚状态库函数定义 
#define KEY1    GPIO_ReadInputDataBit(KEY_MENU_Port,KEY_MENU_Pin)
#define KEY2    GPIO_ReadInputDataBit(KEY_CONFIRM_Port,KEY_CONFIRM_Pin)
#define KEY3    GPIO_ReadInputDataBit(KEY_SELECT_Port,KEY_SELECT_Pin)



//定义各个按键值  
#define KEY_IDEL		 0
#define KEY_MENU 		 1
#define KEY_CANCE		 2
#define KEY_SHUTDOWN	 3
#define KEY_CONFIRM      4
#define KEY_SELECT		 5  



void KEY_Init(void);
u8 KEY_Scan(u8 mode);
#endif
