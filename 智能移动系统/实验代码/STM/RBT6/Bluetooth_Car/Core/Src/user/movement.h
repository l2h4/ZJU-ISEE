#ifndef _MOVEMENT_H_
#define _MOVEMENT_H_

#include "tim.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_tim.h"
#include "stm32f1xx.h"



/*设置PWM和时间前进一段时间*/
void run_time(uint8_t speed,uint16_t time);

/*设置PWM和时间左转一定时间*/
void left_time(uint8_t speed,uint16_t time);

/*设置PWM和时间右转一定时间*/
void right_time(uint8_t speed,uint16_t time);

/*设置PWM和时间后退一定时间*/
void back_time(uint8_t speed,uint16_t time);

/*快速左转*/
void spin_left(uint8_t speed,uint16_t time);

/*快速右转*/
void spin_right(uint8_t speed,uint16_t time);

/*停止*/
void brake(void);

/*无时间限制的前进*/
void run(uint8_t speed);

/*无时间限制的右转*/
void right(uint8_t speed);

/*无时间限制的左转*/
void left(uint8_t speed);

/*无时间限制的后退*/
void back(uint8_t speed);

#endif
