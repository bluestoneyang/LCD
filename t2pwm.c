/**
  ******************************************************************************
  * @file t2pwm.c
  * @brief This file contains the function for pwm driver.
  * @author chengbo yang for ultrasonic operation
  * @version V1.0.0
  * @date 17-Dec-2016
  ******************************************************************************
  *
  * THE PRESENT FIRMWARE WHICH IS FOR PWM management.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "t2pwm.h"


/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define PWM_OPEN  1
#define PWM_CLOSE 0
/* Private macro -------------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/ 
char Pwm_status;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/
    
void Initial_pwm()
{
  Pwm_status = PWM_CLOSE;
  TIM2_DeInit();
  TIM2_TimeBaseInit(TIM2_PRESCALER_1, T2_P_SCALER);
  TIM2_OC1Init(TIM2_OCMODE_PWM2, TIM2_OUTPUTSTATE_ENABLE,T2_P_SCALER/2, TIM2_OCPOLARITY_LOW ); 
  TIM2_ARRPreloadConfig(ENABLE);
}
void Pwm_Width( uint16_t t_width)
{
  TIM2_SetCompare1(t_width);
}
void Pwm_close()
{
  TIM2_Cmd(DISABLE);
  TIM2_SetCounter(0);
}
void Pwm_open()
{
  TIM2_Cmd(ENABLE);
}


