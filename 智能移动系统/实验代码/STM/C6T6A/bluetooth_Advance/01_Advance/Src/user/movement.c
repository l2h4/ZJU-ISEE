#include "movement.h"


void run_time(uint8_t speed,uint16_t time)
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,speed);//设置占空比speed%
  __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,speed);//设置占空比speed%
  //左轮
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
	L298N_IN1 = 1; 
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
	L298N_IN2 = 0;
//右轮
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
	L298N_IN3 = 0; 
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
	L298N_IN4 = 1;
	//左轮调速
//	Left_motor_speed_control(speed);
	//右轮调速
//	Right_motor_speed_control(speed);
	HAL_Delay(time);  
}

void left_time(uint8_t speed,uint16_t time)
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,speed);//设置占空比speed%
  __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,speed);//设置占空比speed%
  //左轮
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
	L298N_IN1 = 0; 
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
	L298N_IN2 = 0;
//右轮
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
	L298N_IN3 = 0; 
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
	L298N_IN4 = 1;
	//左轮调速
//	Left_motor_speed_control(speed);
	//右轮调速
//	Right_motor_speed_control(speed);
	HAL_Delay(time); 
}

void right_time(uint8_t speed,uint16_t time)
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,speed);//设置占空比speed%
  __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,speed);//设置占空比speed%
  //左轮
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
	L298N_IN1 = 1; 
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
	L298N_IN2 = 0;
//右轮
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
	L298N_IN3 = 0; 
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
	L298N_IN4 = 0;
	//左轮调速
//	Left_motor_speed_control(speed);
	//右轮调速
//	Right_motor_speed_control(speed);
	HAL_Delay(time);  
}

void back_time(uint8_t speed,uint16_t time)
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,speed);//设置占空比speed%
  __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,speed);//设置占空比speed%
  //左轮
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
	L298N_IN1 = 0; 
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
	L298N_IN2 = 1;
//右轮
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
	L298N_IN3 = 1; 
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
	L298N_IN4 = 0;
	//左轮调速
//	Left_motor_speed_control(speed);
	//右轮调速
//	Right_motor_speed_control(speed);
	HAL_Delay(time);  
}

void spin_left(uint8_t speed,uint16_t time)
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,speed);//设置占空比speed%
  __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,speed);//设置占空比speed%
  //左轮
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
	L298N_IN1 = 0; 
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
	L298N_IN2 = 1;
//右轮
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
	L298N_IN3 = 0; 
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
	L298N_IN4 = 1;
	//左轮调速
//	Left_motor_speed_control(speed);
	//右轮调速
//	Right_motor_speed_control(speed);
	HAL_Delay(time);  
}

void spin_right(uint8_t speed,uint16_t time)
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,speed);//设置占空比speed%
  __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,speed);//设置占空比speed%
  //左轮
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
	L298N_IN1 = 1; 
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
	L298N_IN2 = 0;
//右轮
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
	L298N_IN3 = 1; 
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
	L298N_IN4 = 0;
	//左轮调速
//	Left_motor_speed_control(speed);
	//右轮调速
//	Right_motor_speed_control(speed);
	HAL_Delay(time);  
}

void brake()
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,0);//设置占空比speed%
  __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,0);//设置占空比speed%
  //左轮
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
	L298N_IN1 = 0; 
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
	L298N_IN2 = 0;
//右轮
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
	L298N_IN3 = 0; 
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
	L298N_IN4 = 0;
	//左轮调速
//	Left_motor_speed_control(speed);
	//右轮调速
//	Right_motor_speed_control(speed);  
}

void run(uint8_t speed)
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,speed);//设置占空比speed%
  __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,speed);//设置占空比speed%
  //左轮
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
	L298N_IN1 = 1; 
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
	L298N_IN2 = 0;
//右轮
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
	L298N_IN3 = 0; 
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
	L298N_IN4 = 1;
	//左轮调速
//	Left_motor_speed_control(speed);
	//右轮调速
//	Right_motor_speed_control(speed);
}

void right(uint8_t speed)
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,speed);//设置占空比speed%
  __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,speed);//设置占空比speed%
  //左轮
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
	L298N_IN1 = 1; 
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
	L298N_IN2 = 0;
//右轮
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
	L298N_IN3 = 0; 
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
	L298N_IN4 = 0;
	//左轮调速
//	Left_motor_speed_control(speed);
	//右轮调速
//	Right_motor_speed_control(speed);
}

void left(uint8_t speed)
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,speed);//设置占空比speed%
  __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,speed);//设置占空比speed%
  //左轮
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
	L298N_IN1 = 0; 
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
	L298N_IN2 = 0;
//右轮
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
	L298N_IN3 = 0; 
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
	L298N_IN4 = 1;
	//左轮调速
//	Left_motor_speed_control(speed);
	//右轮调速
//	Right_motor_speed_control(speed);
}

void back(uint8_t speed)
{
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,speed);//设置占空比speed%
  __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,speed);//设置占空比speed%
  //左轮
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
	L298N_IN1 = 0; 
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
	L298N_IN2 = 1;
//右轮
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
	L298N_IN3 = 1; 
//	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,GPIO_PIN_RESET);
	L298N_IN4 = 0;
	//左轮调速
//	Left_motor_speed_control(speed);
	//右轮调速
//	Right_motor_speed_control(speed);
}
