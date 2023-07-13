#include "movement.h"


void run_time(uint8_t speed,uint16_t time)
{
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,speed);//����ռ�ձ�speed%
  __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,speed);//����ռ�ձ�speed%
  //����
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_RESET);
//����
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
	//���ֵ���
//	Left_motor_speed_control(speed);
	//���ֵ���
//	Right_motor_speed_control(speed);
	HAL_Delay(time);  
}

void left_time(uint8_t speed,uint16_t time)
{
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,speed);//����ռ�ձ�speed%
  __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,speed);//����ռ�ձ�speed%
  //����
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_RESET);
//����
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
	//���ֵ���
//	Left_motor_speed_control(speed);
	//���ֵ���
//	Right_motor_speed_control(speed);
	HAL_Delay(time);  
}

void right_time(uint8_t speed,uint16_t time)
{
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,speed);//����ռ�ձ�speed%
  __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,speed);//����ռ�ձ�speed%
  //����
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_RESET);
//����
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
	//���ֵ���
//	Left_motor_speed_control(speed);
	//���ֵ���
//	Right_motor_speed_control(speed);
	HAL_Delay(time); 
}

void back_time(uint8_t speed,uint16_t time)
{
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,speed);//����ռ�ձ�speed%
  __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,speed);//����ռ�ձ�speed%
  //����
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_SET);
//����
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
	//���ֵ���
//	Left_motor_speed_control(speed);
	//���ֵ���
//	Right_motor_speed_control(speed);
	HAL_Delay(time);  
}

void spin_left(uint8_t speed,uint16_t time)
{
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,speed);//����ռ�ձ�speed%
  __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,speed);//����ռ�ձ�speed%
  //����
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_SET);
//����
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
	//���ֵ���
//	Left_motor_speed_control(speed);
	//���ֵ���
//	Right_motor_speed_control(speed);
	HAL_Delay(time);   
}

void spin_right(uint8_t speed,uint16_t time)
{
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,speed);//����ռ�ձ�speed%
  __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,speed);//����ռ�ձ�speed%
  //����
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_RESET);
//����
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
	//���ֵ���
//	Left_motor_speed_control(speed);
	//���ֵ���
//	Right_motor_speed_control(speed);
	HAL_Delay(time); 
}

void brake()
{
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,0);//����ռ�ձ�speed%
  __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,0);//����ռ�ձ�speed%
  //����
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_RESET);
//����
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
	//���ֵ���
//	Left_motor_speed_control(speed);
	//���ֵ���
//	Right_motor_speed_control(speed);
}

void run(uint8_t speed)
{
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,speed);//����ռ�ձ�speed%
  __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,speed);//����ռ�ձ�speed%
  //����
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_RESET);
//����
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
	//���ֵ���
//	Left_motor_speed_control(speed);
	//���ֵ���
//	Right_motor_speed_control(speed);
}

void right(uint8_t speed)
{
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,speed);//����ռ�ձ�speed%
  __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,speed);//����ռ�ձ�speed%
  //����
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_RESET);
//����
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
	//���ֵ���
//	Left_motor_speed_control(speed);
	//���ֵ���
//	Right_motor_speed_control(speed);
}

void left(uint8_t speed)
{
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,speed);//����ռ�ձ�speed%
  __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,speed);//����ռ�ձ�speed%
  //����
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_RESET);
//����
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
	//���ֵ���
//	Left_motor_speed_control(speed);
	//���ֵ���
//	Right_motor_speed_control(speed);
}

void back(uint8_t speed)
{
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,speed);//����ռ�ձ�speed%
  __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,speed);//����ռ�ձ�speed%
  //����
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_SET);
//����
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
	//���ֵ���
//	Left_motor_speed_control(speed);
	//���ֵ���
//	Right_motor_speed_control(speed);
}
