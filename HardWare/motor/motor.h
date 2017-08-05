#include "system.h"

#ifndef _MOTOR_H
#define _MOTOR_H 

#define MOTOR_PORT (GPIOC)
#define MOTOR_A 	   (GPIO_Pin_3)
#define MOTOR_B 	   (GPIO_Pin_2)
#define MOTOR_C 	   (GPIO_Pin_1)
#define MOTOR_D		   (GPIO_Pin_0)
void MotorInit(void);
void MotorFWD(u8 steps);
void MotorREV(u8 steps);

#endif
