/**
  ******************************************************************************
  * @file timer.c
  * @brief This file contains the function for timer and counter.
  * @author chengbo yang for ultrasonic operation
  * @version V1.0.0
  * @date 17-Dec-2016
  ******************************************************************************
  *
  * THE PRESENT FIRMWARE WHICH IS FOR timer management.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "timer.h"


/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define TIME3_DIV  3  // 2^3 = 8
#define T3_AAR 20000   // 16000000/100 for 10ms
#define PWM_CLOSE 0
/* Private macro -------------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/ 
t_flag timer3_flag;
u16 timer_1s_count;
u16 timer_100ms_count;
u16 timer_20ms_count;
u16 timer1_count;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/
    
void InitTimer3()
{
  TIM3_DeInit();
  TIM3_TimeBaseInit(TIM3_PRESCALER_8, T3_AAR);  
  TIM3_UpdateRequestConfig(TIM3_UPDATESOURCE_GLOBAL);
  TIM3_ARRPreloadConfig(ENABLE);
  TIM3_ITConfig(TIM3_IT_UPDATE, ENABLE);
  TIM3_Cmd(ENABLE);  
  timer3_flag.ms_10 = 0;
  timer3_flag.ms_100 = 0;
  timer3_flag.second = 0;
  timer_1s_count = 0;
  timer_100ms_count = 0;  
}
void InitTimer1()
{
 // GPIO_Init(GPIOB, GPIO_PIN_3 ,GPIO_MODE_IN_FL_NO_IT);
  TIM1_DeInit();
 // TIM1_TimeBaseInit(0, TIM1_COUNTERMODE_UP,65535, 0);
//  TIM1_ETRClockMode2Config(TIM1_EXTTRGPSC_OFF,TIM1_EXTTRGPOLARITY_NONINVERTED, 0x08);
  
  TIM1_ETRClockMode1Config(TIM1_EXTTRGPSC_OFF,TIM1_EXTTRGPOLARITY_NONINVERTED, 0x08);
  TIM1_TIxExternalClockConfig(TIM1_TIXEXTERNALCLK1SOURCE_TI2,TIM1_ICPOLARITY_RISING,0x08);
  
  timer1_count = 0;
  TIM1_Cmd(ENABLE);
}


