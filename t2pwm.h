/**
  ******************************************************************************
  * @file t2pwm.h
  * @brief This file contains the function for pwm driver.
  * @author chengbo yang for ultrasonic operation
  * @version V1.0.0
  * @date 24-Dec-2016
  ******************************************************************************
  *
  * THE PRESENT FIRMWARE WHICH IS FOR LED MANAGEMENT
  *
  ******************************************************************************
  */

#ifndef __T2PWM_H
#define __T2PWM_H

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

#define T2_P_SCALER 1600 

/* Private variables ---------------------------------------------------------*/ 


/* Private function prototypes -----------------------------------------------*/

/*public variables------------------------------------------------------------*/

/* Public functions ----------------------------------------------------------*/

void Initial_pwm();
void Pwm_Width( uint16_t t_width);
void Pwm_close();
void Pwm_open();
#endif  //__T2PWM_H



  