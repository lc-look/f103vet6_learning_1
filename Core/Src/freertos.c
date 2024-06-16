/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include "../../Drivers/CMSIS/RTOS2/Include/cmsis_os2.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "driver_led.h"
#include "bsp.h"
// #include "driver_oled.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
void myTask(void *argument)
{
  while(1)
  {
     /* USER CODE BEGIN 2 */
 OLED_Init();                           //OLED初始
 OLED_Clear();                         //清屏
//上面的初始化以及清屏的代码在一开始处一定要写
 OLED_ShowString(0,0,"UNICORN_LI",16, 1);    //反相显示8X16字符串
 OLED_ShowString(0,2,"unicorn_li_123",12,0);//正相显示6X8字符串
 
 OLED_ShowCHinese(0,4,0,1); //反相显示汉字“独”
 OLED_ShowCHinese(16,4,1,1);//反相显示汉字“角”
 OLED_ShowCHinese(32,4,2,1);//反相显示汉字“兽”
 OLED_ShowCHinese(0,6,0,0); //正相显示汉字“独”
 OLED_ShowCHinese(16,6,1,0);//正相显示汉字“角”
 OLED_ShowCHinese(32,6,2,0);//正相显示汉字“兽”

 OLED_ShowNum(48,4,6,1,16, 0);//正相显示1位8X16数字“6”
 OLED_ShowNum(48,7,77,2,12, 1);//反相显示2位6X8数字“77”
 OLED_DrawBMP(90,0,122, 4,BMP1,0);//正相显示图片BMP1
 OLED_DrawBMP(90,4,122, 8,BMP1,1);//反相显示图片BMP1
 
 OLED_HorizontalShift(0x26);//全屏水平向右滚动播放

//显示正负浮点数的代码
//  float num1=-231.24;
//  float num2=23.375;

//OLED_ShowString(0,0,"Show Decimal",12,0);
//OLED_Showdecimal(0,4,num1,3,2,12, 0);
//OLED_Showdecimal(0,6,num2,2,3,16, 1);

 
  /* USER CODE END 2 */

  }
}
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  xTaskCreate(myTask,"myFirstTask",128,NULL,osPriorityNormal,NULL);
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    LED_Test();
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

