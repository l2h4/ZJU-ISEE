/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "./user/movement.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define KEY    HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15) //����״̬
#define KEY_PRES 1 //����������

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/*����ʶ��*/
uint8_t key=0;
uint8_t key_r=0;

/*����ѭ��*/
GPIO_PinState tr_L = GPIO_PIN_SET;
GPIO_PinState tr_R = GPIO_PIN_SET;

/*�������*/
GPIO_PinState av_L = GPIO_PIN_RESET;
GPIO_PinState av_R = GPIO_PIN_RESET;

/*����������*/
uint32_t val= 0;          //�����ֵ
float Length = 0;         //�������վ���
uint32_t aTxBuffer[30];     //����sprintf�Ĵ洢����
uint8_t  TIM3_IC_STA;		//���벶��״̬
uint16_t TIM3_IC_VAL;		//���벶��ֵ

/*��������*/
//uint8_t data;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

uint8_t KEY_scan(uint8_t mode);
void tracking(void);
void redavoid(void);
void key_test(void);
void Trig_Capture(void);
void ultrasonic(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(KEY == 0){
		if(key_r == 3){
			key_r=0;
		}else{
			key_r++;
		}
		
	}
	
	while(KEY == 0);
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef* tim_baseHandle)
{
	if(tim_baseHandle->Instance==TIM3)
	{
		if((TIM3_IC_STA&0x80)==0)	//��δ����ɹ�
		{
			if(TIM3_IC_STA&0x40)	//�ɹ�����һ���½���
			{
				TIM3_IC_STA |= 0X80;	//��ǳɹ�������һ�θߵ�ƽ���
				TIM3_IC_VAL  = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_2);	//��ȡ��ǰ����ֵ
				TIM_RESET_CAPTUREPOLARITY(&htim3, TIM_CHANNEL_2);			//���ԭ������
				TIM_SET_CAPTUREPOLARITY(&htim3, TIM_CHANNEL_2, TIM_ICPOLARITY_RISING);	//�����½��غ󣬽�����λ������������
			}
			else							//����һ��������
			{
				TIM3_IC_STA = 0;
				TIM3_IC_VAL = 0;
				TIM3_IC_STA |= 0x40;	//����λ���Ϊ����������
				__HAL_TIM_DISABLE(&htim3);		//�رն�ʱ��
				__HAL_TIM_SET_COUNTER(&htim3, 0);	//��ʱ����ʼֵ����Ϊ0
				TIM_RESET_CAPTUREPOLARITY(&htim3, TIM_CHANNEL_1);
				TIM_SET_CAPTUREPOLARITY(&htim3, TIM_CHANNEL_1, TIM_ICPOLARITY_FALLING);	//����������֮�󣬽���������Ϊ�½���
				__HAL_TIM_ENABLE(&htim3);
			}
		}
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* tim_baseHandle)
{
	if(tim_baseHandle->Instance==TIM3)
	{
		if((TIM3_IC_STA&0X80) ==0)		//��δ����ɹ�
		{
			if(TIM3_IC_STA&0X40)		//����һ���½���
			{
				if((TIM3_IC_STA&0X3F)==0X3F)	//�ߵ�ƽʱ��̫����
				{
					TIM3_IC_STA |= 0X80;	//��ǳɹ�����һ��
					TIM3_IC_VAL = 0XFFFF;	//
				}
				else
					TIM3_IC_STA++;			//�������������һ
			}
		}
	}
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  MX_USART2_UART_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
	
	HAL_TIM_IC_Start_IT(&htim3,TIM_CHANNEL_2);   //����TIM9�Ĳ���ͨ��1�����ҿ��������ж�
  __HAL_TIM_ENABLE_IT(&htim3,TIM_IT_UPDATE);   //ʹ�ܸ����ж�
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		
		
		
		switch(key_r)
		{
			case 1:
				tracking();
				break;
			case 2:
				redavoid();
				break;
			case 3:
				ultrasonic();
				break;
			default:
				brake();
				HAL_Delay(500);
				break;
		}
		
  }
	
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

uint8_t KEY_scan(uint8_t mode)
{
	static uint8_t key_up=1;
	
	if(mode)  key_up=1;
	
	if(key_up && KEY == 0){
		HAL_Delay(10);
		key_up=0;
		if(key >= 3){
			key=0;
		}else{
			key++;
		}
		return key;

	}else if(KEY==1){
		key_up=1;
	}
	
	return key;
	
}

void tracking()
{
	while(1){
		tr_L=HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14);
		tr_R=HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15);
		
		if(tr_L == GPIO_PIN_SET && tr_R == GPIO_PIN_SET){
			brake();
		}else if(tr_L == GPIO_PIN_RESET && tr_R == GPIO_PIN_RESET){
			run(40);
		}else if(tr_L == GPIO_PIN_SET && tr_R == GPIO_PIN_RESET){
			left(40);
		}else if(tr_L == GPIO_PIN_RESET && tr_R == GPIO_PIN_SET){
			right(40);
		}else{
			brake();
		}
		
		//key_r=KEY_scan(0);
		if(key_r!=1){
			brake();HAL_Delay(200);
			break;
		}
	}
}

void redavoid()
{
	while(1)
  {
    av_L = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12);
    av_R = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_13);
    if (av_L == GPIO_PIN_SET && av_R==GPIO_PIN_SET)
      run(40);   //����ǰ������
    else if (av_L == GPIO_PIN_SET && av_R == GPIO_PIN_RESET)// �ұ�̽�⵽���ϰ�����źŷ��أ�����ת 
        left(40);
    else if (av_L == GPIO_PIN_RESET && av_R == GPIO_PIN_SET) //���̽�⵽���ϰ�����źŷ��أ�����ת  
      right(40);
    else // �������ϰ���, ����
    {
      back_time(40,400);//����
      spin_right(40,400);//����ת����������
    }
		
		//key_r=KEY_scan(0);
		if(key_r!=2){
			brake();HAL_Delay(200);
			break;
		}
  }
}

void key_test()
{
	//key_r=KEY_scan(0);
		switch(key_r)
		{
			case 1:
				run(40);
				break;
			case 2:
				right(40);
				break;
			case 3:
				left(40);
				break;
			default:
				brake();
				HAL_Delay(500);
				break;
		}
}

void Trig_Capture(void)
{
	uint32_t i;
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
	for(i=0;i<72*40;i++)
		__NOP();                      //����ָ���ʱ������ʱ
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
}

float Get_Distance()
{
		Trig_Capture();
	  if(TIM3_IC_STA & 0x80)	//�ɹ�����һ������
	  {
		  val = TIM3_IC_STA & 0x3F;	//��ȡ�������
		  val *= 65536;		//��������ʱ��ֵ
		  val += TIM3_IC_VAL;	//�������һ��ȡ�õ�ֵ
		  Length = val * 338.38*100/2000000;
		  TIM3_IC_STA = 0;
	  }
		
		return Length;
}

void ultrasonic()
{
	while(1){
		Length=Get_Distance();
		if(Length<=50){
			back_time(40,200);
			spin_left(40,200);
		}else{
			run(40);
		}
		
		if(key!=3){
			break;
		}
	}
}


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
