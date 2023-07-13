#ifndef _MOVEMENT_H_
#define _MOVEMENT_H_

#include "tim.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_tim.h"
#include "stm32f1xx.h"



/*����PWM��ʱ��ǰ��һ��ʱ��*/
void run_time(uint8_t speed,uint16_t time);

/*����PWM��ʱ����תһ��ʱ��*/
void left_time(uint8_t speed,uint16_t time);

/*����PWM��ʱ����תһ��ʱ��*/
void right_time(uint8_t speed,uint16_t time);

/*����PWM��ʱ�����һ��ʱ��*/
void back_time(uint8_t speed,uint16_t time);

/*������ת*/
void spin_left(uint8_t speed,uint16_t time);

/*������ת*/
void spin_right(uint8_t speed,uint16_t time);

/*ֹͣ*/
void brake(void);

/*��ʱ�����Ƶ�ǰ��*/
void run(uint8_t speed);

/*��ʱ�����Ƶ���ת*/
void right(uint8_t speed);

/*��ʱ�����Ƶ���ת*/
void left(uint8_t speed);

/*��ʱ�����Ƶĺ���*/
void back(uint8_t speed);

#endif
